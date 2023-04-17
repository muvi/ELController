/*
 * hv_dc_supply.h
 *
 * Created: 09.07.2022 01:29:59
 *  Author: Christian
 */ 


#ifndef HV_DC_SUPPLY_H_
#define HV_DC_SUPPLY_H_

#include <atmel_start.h>
#include <adc_util.h>
#include <hpl_pm_base.h>
#include <hpl_gclk_base.h>
#include <io_util.h>
#include <adc_lite.h>
#include <pid.h>
#include <interrupt_util.h>
#include <tcc_util.h>
#include <base_util.h>

void hv_dc_supply_init();
void hv_dc_supply_power_pulse();
void hv_dc_supply_cancel();

static inline void hv_dc_supply_enable_output() {
	gpio_set_pin_drive_strength(OUTPUT_ENABLE);
	gpio_set_pin_direction(OUTPUT_ENABLE, GPIO_DIRECTION_OUT);
	gpio_set_pin_level(OUTPUT_ENABLE, false);
}

static inline void hv_dc_supply_disable_output() {
	gpio_set_pin_level(OUTPUT_ENABLE, true);
}

float hv_dc_supply_get_voltage();
uint16_t hv_dc_supply_get_voltage_raw();
float hv_dc_supply_get_max_voltage();
uint16_t hv_dc_supply_get_sense_target(float voltage);

#endif /* HV_DC_SUPPLY_H_ */