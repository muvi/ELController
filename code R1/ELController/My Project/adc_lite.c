/*
 * adc_lite.c
 *
 * Created: 18.07.2022 22:09:11
 *  Author: Christian
 */ 

#include <adc_lite.h>
#include <peripheral_clk_config.h>
#include <utils.h>
#include <hal_init.h>
#include <hpl_gclk_base.h>
#include <hpl_pm_base.h>
#include <atmel_start_pins.h>

// <i> Select the clock source for ADC.
#define CONF_GCLK_ADC_SRC GCLK_CLKCTRL_GEN_GCLK0_Val

/* The channel amount for ADC */
#define ADC_0_CH_AMOUNT 1

/* The buffer size for ADC */
#define ADC_0_BUFFER_SIZE 16

/* The maximal channel number of enabled channels */
#define ADC_0_CH_MAX 0

struct adc_async_descriptor         ADC_0;
struct adc_async_channel_descriptor ADC_0_ch[ADC_0_CH_AMOUNT];

static uint8_t ADC_0_buffer[ADC_0_BUFFER_SIZE];
static uint8_t ADC_0_map[ADC_0_CH_MAX + 1];

void adc_init() {
	_pm_enable_bus_clock(PM_BUS_APBC, ADC);
	_gclk_enable_channel(ADC_GCLK_ID, CONF_GCLK_ADC_SRC);
	adc_async_init(&ADC_0, ADC, ADC_0_map, ADC_0_CH_MAX, ADC_0_CH_AMOUNT, &ADC_0_ch[0], (void *)NULL);
	adc_async_register_channel_buffer(&ADC_0, 0, ADC_0_buffer, ADC_0_BUFFER_SIZE);

	// Disable digital pin circuitry
	gpio_set_pin_direction(PWR_SENSE, GPIO_DIRECTION_OFF);

	gpio_set_pin_function(PWR_SENSE, PINMUX_PA02B_ADC_AIN0);

	// Disable digital pin circuitry
	gpio_set_pin_direction(HV_SENSE, GPIO_DIRECTION_OFF);

	gpio_set_pin_function(HV_SENSE, PINMUX_PA03B_ADC_AIN1);
}