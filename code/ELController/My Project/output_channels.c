/*
 * output_channels.c
 *
 * Created: 24.08.2022 20:36:14
 *  Author: Christian
 */ 

#include <output_channels.h>

SineWave output_channels_wave_form[OUTPUT_CHANNELS_COUNT] = {
	SINE_WAVE(OUTPUT_CHANNELS_DEFAULT_FREQUENCY_VALUE_DEF, SINE_WAVE_MAX_VALUE),
	SINE_WAVE(OUTPUT_CHANNELS_DEFAULT_FREQUENCY_VALUE_DEF, SINE_WAVE_MAX_VALUE),
	SINE_WAVE(OUTPUT_CHANNELS_DEFAULT_FREQUENCY_VALUE_DEF, SINE_WAVE_MAX_VALUE),
	SINE_WAVE(OUTPUT_CHANNELS_DEFAULT_FREQUENCY_VALUE_DEF, SINE_WAVE_MAX_VALUE),
	SINE_WAVE(OUTPUT_CHANNELS_DEFAULT_FREQUENCY_VALUE_DEF, SINE_WAVE_MAX_VALUE),
	SINE_WAVE(OUTPUT_CHANNELS_DEFAULT_FREQUENCY_VALUE_DEF, SINE_WAVE_MAX_VALUE),
	SINE_WAVE(OUTPUT_CHANNELS_DEFAULT_FREQUENCY_VALUE_DEF, SINE_WAVE_MAX_VALUE),
	SINE_WAVE(OUTPUT_CHANNELS_DEFAULT_FREQUENCY_VALUE_DEF, SINE_WAVE_MAX_VALUE)
};

void output_channels_init_pins(const uint8_t positive_pin, const uint8_t negative_pin) {
	gpio_set_pin_level(positive_pin, true);
	gpio_set_pin_level(negative_pin, false);
	gpio_set_pin_direction(positive_pin, GPIO_DIRECTION_OUT);
	gpio_set_pin_direction(negative_pin, GPIO_DIRECTION_OUT);
	gpio_set_pin_drive_strength(positive_pin);
	gpio_set_pin_drive_strength(negative_pin);
}

void output_channels_init_1_and_2() {
	NVIC_DisableIRQ(TCC0_IRQn);
	NVIC_ClearPendingIRQ(TCC0_IRQn);

	hri_tcc_write_WAVE_reg(TCC0,
	0 << TCC_WAVE_SWAP3_Pos
	| 0 << TCC_WAVE_SWAP2_Pos
	| 0 << TCC_WAVE_SWAP1_Pos
	| 0 << TCC_WAVE_SWAP0_Pos
	| 1 << TCC_WAVE_POL3_Pos
	| 0 << TCC_WAVE_POL2_Pos
	| 1 << TCC_WAVE_POL1_Pos
	| 0 << TCC_WAVE_POL0_Pos
	| 0 << TCC_WAVE_CICCEN3_Pos
	| 0 << TCC_WAVE_CICCEN2_Pos
	| 0 << TCC_WAVE_CICCEN1_Pos
	| 0 << TCC_WAVE_CICCEN0_Pos
	| 0 << TCC_WAVE_CIPEREN_Pos
	| 0 << TCC_WAVE_RAMP_Pos
	| TCC_WAVE_WAVEGEN_NPWM_Val << TCC_WAVE_WAVEGEN_Pos
	);

	output_channels_init_pins(CH1P, CH1N);
	output_channels_init_pins(CH2P, CH2N);
	gpio_set_pin_function(CH1P, PINMUX_PA10F_TCC0_WO2);
	gpio_set_pin_function(CH1N, PINMUX_PA11F_TCC0_WO3);
	gpio_set_pin_function(CH2P, PINMUX_PB30E_TCC0_WO0);
	gpio_set_pin_function(CH2N, PINMUX_PB31E_TCC0_WO1);
	
	NVIC_SetPriority(TCC0_IRQn, INTERRUPT_PRIORITY_MEDIUM);
	NVIC_EnableIRQ(TCC0_IRQn);
}

void output_channels_init_3() {
	NVIC_DisableIRQ(TCC2_IRQn);
	NVIC_ClearPendingIRQ(TCC2_IRQn);

	hri_tcc_write_WAVE_reg(TCC2,
	0 << TCC_WAVE_SWAP1_Pos
	| 0 << TCC_WAVE_SWAP0_Pos
	| 1 << TCC_WAVE_POL1_Pos
	| 0 << TCC_WAVE_POL0_Pos
	| 0 << TCC_WAVE_CICCEN1_Pos
	| 0 << TCC_WAVE_CICCEN0_Pos
	| 0 << TCC_WAVE_CIPEREN_Pos
	| 0 << TCC_WAVE_RAMP_Pos
	| TCC_WAVE_WAVEGEN_NPWM_Val << TCC_WAVE_WAVEGEN_Pos
	);

	output_channels_init_pins(CH3P, CH3N);
	gpio_set_pin_function(CH3P, PINMUX_PA16E_TCC2_WO0);
	gpio_set_pin_function(CH3N, PINMUX_PA17E_TCC2_WO1);
	
	NVIC_SetPriority(TCC2_IRQn, INTERRUPT_PRIORITY_MEDIUM);
	NVIC_EnableIRQ(TCC2_IRQn);
}

void output_channels_init_tc(const IRQn_Type IRQn, const void *const hw, uint32_t pin_p, uint32_t pin_n, uint32_t function_p, uint32_t function_n) {
	NVIC_DisableIRQ(IRQn);
	NVIC_ClearPendingIRQ(IRQn);

	hri_tc_write_CTRLC_reg(hw,
	0 << TC_CTRLC_CPTEN0_Pos
	| 0 << TC_CTRLC_CPTEN1_Pos
	| 0 << TC_CTRLC_INVEN0_Pos
	| 1 << TC_CTRLC_INVEN1_Pos
	);

	output_channels_init_pins(pin_p, pin_n);
	gpio_set_pin_function(pin_p, function_p);
	gpio_set_pin_function(pin_n, function_n);
	
	NVIC_SetPriority(IRQn, INTERRUPT_PRIORITY_MEDIUM);
	NVIC_EnableIRQ(IRQn);
}

void output_channels_init_4_5_6_7_8() {
	output_channels_init_tc(TC3_IRQn, TC3, CH4P, CH4N, PINMUX_PA14E_TC3_WO0, PINMUX_PA15E_TC3_WO1);
	output_channels_init_tc(TC6_IRQn, TC6, CH5P, CH5N, PINMUX_PB02E_TC6_WO0, PINMUX_PB03E_TC6_WO1);
	output_channels_init_tc(TC5_IRQn, TC5, CH6P, CH6N, PINMUX_PB10E_TC5_WO0, PINMUX_PB11E_TC5_WO1);
	output_channels_init_tc(TC4_IRQn, TC4, CH7P, CH7N, PINMUX_PB08E_TC4_WO0, PINMUX_PB09E_TC4_WO1);
	output_channels_init_tc(TC7_IRQn, TC7, CH8P, CH8N, PINMUX_PB22E_TC7_WO0, PINMUX_PB23E_TC7_WO1);
}

void TCC0_Handler() {
	hri_tcc_clear_interrupt_OVF_bit(TCC0);

	//channel 1
	SineWaveSample next_value = sine_wave_next(&(output_channels_wave_form[0]));
	hri_tcc_write_CCB_reg_no_lock(TCC0, 2, next_value.pos);
	hri_tcc_write_CCB_reg_no_lock(TCC0, 3, next_value.neg);
		
	//channel 2
	next_value = sine_wave_next(&(output_channels_wave_form[1]));
	hri_tcc_write_CCB_reg_no_lock(TCC0, 0, next_value.pos);
	hri_tcc_write_CCB_reg_no_lock(TCC0, 1, next_value.neg);
	//gpio_set_pin_level(LED2, next_value.pos != 0);
}

void TCC2_Handler() {
	hri_tcc_clear_interrupt_OVF_bit(TCC2);

	//channel 3
	SineWaveSample next_value = sine_wave_next(&(output_channels_wave_form[2]));
	hri_tcc_write_CCB_reg_no_lock(TCC2, 0, next_value.pos);
	hri_tcc_write_CCB_reg_no_lock(TCC2, 1, next_value.neg);
}

#define TC_HANDLER(hw, channel) void hw##_Handler() { \
	hri_tc_clear_interrupt_OVF_bit(hw); \
	SineWaveSample next_value = sine_wave_next(&(output_channels_wave_form[channel])); \
	hri_tccount8_write_CC_reg_no_lock(hw, 0, next_value.pos); \
	hri_tccount8_write_CC_reg_no_lock(hw, 1, next_value.neg); \
}

TC_HANDLER(TC3, 3)
TC_HANDLER(TC6, 4)
TC_HANDLER(TC5, 5)
TC_HANDLER(TC4, 6)
TC_HANDLER(TC7, 7)

void output_channels_init() {
	output_channels_init_1_and_2();
	output_channels_init_3();
	output_channels_init_4_5_6_7_8();
}