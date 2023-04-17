/*
 * dip_switch.c
 *
 * Created: 29.06.2022 17:58:34
 *  Author: Christian
 */ 
#include <dip_switch.h>

#define DIP_SWITCH_VALUES_PER_CHANNEL 16
#define DIP_SWITCH_BITS 4
#define DIP_SWITCH_BLOCKS 3
#define DIP_SWITCH_BITS_PER_CHANNEL 10
const uint16_t DIP_SWITCH_THRESHOLDS[DIP_SWITCH_VALUES_PER_CHANNEL] = {0x000, 0x019, 0x04E, 0x080, 0x0A7, 0x0C9, 0x0EF, 0x111, 0x133, 0x152, 0x16C, 0x185, 0x198, 0x1AA, 0x1BE, 0x1D1};

//converts the block index (0 to 2) to the corresponding AC AIN pin
// 0x0 AIN0 / PA04
// 0x1 AIN1 / PA05
// 0x2 AIN2 / PA06
// 0x3 AIN3 / PA07
// in this case the block number can be exactly mapped to the pin number
#define DIP_SWITCH_BLOCK_TO_AC_MUXPOS_PIN(n) n

volatile uint8_t dip_switch_bit_pos = DIP_SWITCH_BITS_PER_CHANNEL - 1;
volatile uint16_t dip_switch_dac_data = 1 << (DIP_SWITCH_BITS_PER_CHANNEL - 1);
volatile uint8_t dip_switch_block = 0;
volatile uint16_t dip_switch_data = 0;


uint8_t dip_switch_read_group(uint16_t data) {
	uint8_t result = 0;
	uint8_t pos = 0;
	for (int i = DIP_SWITCH_BITS-1; i >= 0; i--) {
		pos |= 1 << i;
		if (data < DIP_SWITCH_THRESHOLDS[pos]) {
			result |= 1 << (DIP_SWITCH_BITS - i - 1);
			pos ^= 1 << i;
		}
	}
	
	return result;
}

void dip_switch_data_read(const uint16_t data) {
	uint8_t nibble = dip_switch_read_group(data);
	if (!dip_switch_block) {
		dip_switch_data = 0;
	}
	dip_switch_data |= nibble << ((DIP_SWITCH_BLOCKS - dip_switch_block - 1) * DIP_SWITCH_BITS);
	dip_switch_block = (dip_switch_block + 1) % DIP_SWITCH_BLOCKS;

	ac_async_set_positive_input(&AC_0, 0, DIP_SWITCH_BLOCK_TO_AC_MUXPOS_PIN(dip_switch_block));
	
	if (!dip_switch_block) {
		dip_switch_data_ready(dip_switch_data);
	}
}

//volatile bool comparisonStarted = false;

void dip_switch_comparison_ready(const struct ac_async_descriptor *const descr, const uint8_t comp, const uint8_t result) {
	//gpio_set_pin_level(LED1, false);

	dip_switch_dac_data ^= ((uint16_t) (!result)) << dip_switch_bit_pos;
	
	
	if (dip_switch_bit_pos) {
		dip_switch_bit_pos--;
	} else {
		dip_switch_bit_pos = DIP_SWITCH_BITS_PER_CHANNEL - 1;
		dip_switch_data_read(dip_switch_dac_data);
		dip_switch_dac_data = 0;
	}

	dip_switch_dac_data |= 1 << dip_switch_bit_pos;
	uint16_t dac_data = dip_switch_dac_data;
	//dac_sync_write(&DAC_0, 0, &dac_data, 1);
	hri_dac_write_DATA_reg_no_lock(DAC, dac_data);
	//comparisonStarted = false;
	
	//start timer to wait for the sample to be ready
	hri_rtcmode0_set_CTRL_ENABLE_bit_no_lock(RTC);

	//gpio_set_pin_level(LED1, true);
}

void dip_switch_init() {
	dac_sync_enable_channel(&DAC_0, 0);
	uint16_t dac_data = dip_switch_dac_data;
	dac_sync_write(&DAC_0, 0, &dac_data, 1);
	ac_async_register_callback(&AC_0, AC_COMPARISON_READY_CB, dip_switch_comparison_ready);
	//Lower dip switch reading priority. This is a really unimportant task.
	NVIC_SetPriority(AC_IRQn, INTERRUPT_PRIORITY_IDLE);
	ac_async_enable(&AC_0);
	
	//initialize RTC
	NVIC_DisableIRQ(RTC_IRQn);
	NVIC_ClearPendingIRQ(RTC_IRQn);
	NVIC_SetPriority(RTC_IRQn, INTERRUPT_PRIORITY_IDLE);
	NVIC_EnableIRQ(RTC_IRQn);
	//hri_rtcmode0_write_CTRL_MODE_bf(RTC, 0);
	
	//start first comparison
	//ac_async_start_comparison(&AC_0, 0);
	hri_ac_set_COMPCTRL_ENABLE_bit_no_lock(AC, 0);
	hri_ac_write_CTRLB_reg_no_lock(AC, AC_CTRLB_START0);
}

void RTC_Handler() {
	hri_rtcmode0_clear_CTRL_ENABLE_bit_no_lock(RTC);
	hri_rtcmode0_clear_interrupt_CMP0_bit(RTC);
	hri_rtcmode0_write_COUNT_reg_no_lock(RTC, 0);
	
	//start comparison
	//ac_async_start_comparison(&AC_0, 0);
	hri_ac_set_COMPCTRL_ENABLE_bit_no_lock(AC, 0);
	hri_ac_write_CTRLB_reg_no_lock(AC, AC_CTRLB_START0);
}

void dip_switch_read() {
	/*
	if (!comparisonStarted) {
		comparisonStarted = true;
		ac_async_start_comparison(&AC_0, 0);
	}
	*/
}
