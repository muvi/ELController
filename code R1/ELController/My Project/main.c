#include <atmel_start.h>
#include <io_util.h>
#include <dmx.h>
#include <dip_switch.h>
#include <hv_dc_supply.h>
#include <pid.h>
#include <output_channels.h>
#include <display.h>
#include <math.h>
#include <user_settings.h>

#define OUTPUT_CHANNEL_DMX_OFFSET 0

void btn1_pressed() {
	//hv_dc_supply_disable_output();
	hv_dc_supply_cancel();
}

void btn2_pressed() {
	//make shure to call output_channels_init() first!
	hv_dc_supply_enable_output();
	hv_dc_supply_power_pulse();
}

void btn3_pressed() {
	hv_dc_supply_disable_output();
}

void dip_switch_data_ready(uint16_t data) {
	dmx_set_address(data & DMX_ADDRESS_MASK);
}

uint8_t dmx_buffer[DMX_CHANNELS];

void dmx_received() {
	uint8_t dmx_pos = OUTPUT_CHANNEL_DMX_OFFSET;
	for (uint8_t i = 0; i < OUTPUT_CHANNELS_COUNT; i++) {
		uint8_t frequency = dmx[dmx_pos++];
		uint8_t amplitude = dmx[dmx_pos++];
		output_channels_update(i, frequency, amplitude);
	}
}

uint8_t stepCounter = 0;
//uint32_t counter = 0;

void SysTick_Handler() {
	stepCounter++;
	if (!(stepCounter & 0b11111)) {
		//counter = (counter + 1) % 200;
		//display_update(counter);
		
		/*switch (counter / 10) {
			case 1:
			case 2: {
				display_update_string("DMX");
				break;
			}
			case 3:
			case 4: {
				display_clear();
				break;
			}
			case 5:
			case 6: {
				display_update_string("K*ab");
				break;
			}
			default: {
				display_update(counter);
				break;
			}
		}*/

		//counter2 = (counter2 + 1) % 9;
		//display_test_pattern(counter2);
		
		float voltage = round(hv_dc_supply_get_voltage() * 10);
		display_update(voltage);
	}
	display_render();
}

volatile uint32_t prio;

void init() {
	user_settings_load();
	
	gpio_set_pin_drive_strength(LED1);
	gpio_set_pin_drive_strength(LED2);
	
	ext_irq_register(BTN1, btn1_pressed);
	ext_irq_register(BTN2, btn2_pressed);
	ext_irq_register(BTN3, btn3_pressed);
	
	dmx_set_address(1);
	dmx_init();
	
	hv_dc_supply_init();
	
	dip_switch_init();
	
	output_channels_init();
	
	display_init();
	
	//lower SysTick priority to minimum, so the dip switch reading does not interfere with power supply regulation
	NVIC_SetPriority(SysTick_IRQn, INTERRUPT_PRIORITY_IDLE);
	SysTick_Config(100000);
	//SysTick_Config(160000);
}

int main(void)
{
	/* Initializes MCU, drivers and middleware */
	atmel_start_init();

	init();
	
	while (1) {
	}
}
