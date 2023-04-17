/*
 * Code generated from Atmel Start.
 *
 * This file will be overwritten when reconfiguring your Atmel Start project.
 * Please copy examples or other code you want to keep to a separate file
 * to avoid losing it when reconfiguring.
 */

#include "driver_init.h"
#include <peripheral_clk_config.h>
#include <utils.h>
#include <hal_init.h>
#include <hpl_gclk_base.h>
#include <hpl_pm_base.h>

struct flash_descriptor FLASH_0;

struct ac_async_descriptor AC_0;

struct dac_sync_descriptor DAC_0;

void EXTERNAL_IRQ_0_init(void)
{
	_gclk_enable_channel(EIC_GCLK_ID, CONF_GCLK_EIC_SRC);

	// Set pin direction to input
	gpio_set_pin_direction(BTN1, GPIO_DIRECTION_IN);

	gpio_set_pin_pull_mode(BTN1,
	                       // <y> Pull configuration
	                       // <id> pad_pull_config
	                       // <GPIO_PULL_OFF"> Off
	                       // <GPIO_PULL_UP"> Pull-up
	                       // <GPIO_PULL_DOWN"> Pull-down
	                       GPIO_PULL_UP);

	gpio_set_pin_function(BTN1, PINMUX_PA16A_EIC_EXTINT0);

	// Set pin direction to input
	gpio_set_pin_direction(BTN2, GPIO_DIRECTION_IN);

	gpio_set_pin_pull_mode(BTN2,
	                       // <y> Pull configuration
	                       // <id> pad_pull_config
	                       // <GPIO_PULL_OFF"> Off
	                       // <GPIO_PULL_UP"> Pull-up
	                       // <GPIO_PULL_DOWN"> Pull-down
	                       GPIO_PULL_UP);

	gpio_set_pin_function(BTN2, PINMUX_PA17A_EIC_EXTINT1);

	// Set pin direction to input
	gpio_set_pin_direction(BTN3, GPIO_DIRECTION_IN);

	gpio_set_pin_pull_mode(BTN3,
	                       // <y> Pull configuration
	                       // <id> pad_pull_config
	                       // <GPIO_PULL_OFF"> Off
	                       // <GPIO_PULL_UP"> Pull-up
	                       // <GPIO_PULL_DOWN"> Pull-down
	                       GPIO_PULL_UP);

	gpio_set_pin_function(BTN3, PINMUX_PA21A_EIC_EXTINT5);

	// Set pin direction to input
	gpio_set_pin_direction(PWR_GOOD, GPIO_DIRECTION_IN);

	gpio_set_pin_pull_mode(PWR_GOOD,
	                       // <y> Pull configuration
	                       // <id> pad_pull_config
	                       // <GPIO_PULL_OFF"> Off
	                       // <GPIO_PULL_UP"> Pull-up
	                       // <GPIO_PULL_DOWN"> Pull-down
	                       GPIO_PULL_UP);

	gpio_set_pin_function(PWR_GOOD, PINMUX_PA14A_EIC_EXTINT14);

	ext_irq_init();
}

void FLASH_0_CLOCK_init(void)
{

	_pm_enable_bus_clock(PM_BUS_APBB, NVMCTRL);
}

void FLASH_0_init(void)
{
	FLASH_0_CLOCK_init();
	flash_init(&FLASH_0, NVMCTRL);
}

/**
 * \brief USART Clock initialization function
 *
 * Enables register interface and peripheral clock
 */
void USART_0_CLOCK_init()
{

	_pm_enable_bus_clock(PM_BUS_APBC, SERCOM3);
	_gclk_enable_channel(SERCOM3_GCLK_ID_CORE, CONF_GCLK_SERCOM3_CORE_SRC);
}

/**
 * \brief USART pinmux initialization function
 *
 * Set each required pin to USART functionality
 */
void USART_0_PORT_init()
{

	gpio_set_pin_function(DMX_TX, PINMUX_PA22C_SERCOM3_PAD0);

	gpio_set_pin_function(DMX_RX, PINMUX_PA23C_SERCOM3_PAD1);
}

void SPI_0_PORT_init(void)
{

	gpio_set_pin_level(DISPLAY_MOSI,
	                   // <y> Initial level
	                   // <id> pad_initial_level
	                   // <false"> Low
	                   // <true"> High
	                   false);

	// Set pin direction to output
	gpio_set_pin_direction(DISPLAY_MOSI, GPIO_DIRECTION_OUT);

	gpio_set_pin_function(DISPLAY_MOSI, PINMUX_PB12C_SERCOM4_PAD0);

	gpio_set_pin_level(DISPLAY_SCK,
	                   // <y> Initial level
	                   // <id> pad_initial_level
	                   // <false"> Low
	                   // <true"> High
	                   false);

	// Set pin direction to output
	gpio_set_pin_direction(DISPLAY_SCK, GPIO_DIRECTION_OUT);

	gpio_set_pin_function(DISPLAY_SCK, PINMUX_PB13C_SERCOM4_PAD1);

	// Set pin direction to input
	gpio_set_pin_direction(DISPLAY_MISO, GPIO_DIRECTION_IN);

	gpio_set_pin_pull_mode(DISPLAY_MISO,
	                       // <y> Pull configuration
	                       // <id> pad_pull_config
	                       // <GPIO_PULL_OFF"> Off
	                       // <GPIO_PULL_UP"> Pull-up
	                       // <GPIO_PULL_DOWN"> Pull-down
	                       GPIO_PULL_OFF);

	gpio_set_pin_function(DISPLAY_MISO, PINMUX_PB15C_SERCOM4_PAD3);
}

void SPI_0_CLOCK_init(void)
{
	_pm_enable_bus_clock(PM_BUS_APBC, SERCOM4);
	_gclk_enable_channel(SERCOM4_GCLK_ID_CORE, CONF_GCLK_SERCOM4_CORE_SRC);
}

/**
 * \brief Rtc initialization function
 *
 * Enables Rtc peripheral, clocks and initializes driver
 */
void TIMER_8_CLOCK_init(void)
{
	_pm_enable_bus_clock(PM_BUS_APBA, RTC);
	_gclk_enable_channel(RTC_GCLK_ID, CONF_GCLK_RTC_SRC);
}

void TIMER_3_CLOCK_init(void)
{
	_pm_enable_bus_clock(PM_BUS_APBC, TC3);

	_gclk_enable_channel(TC3_GCLK_ID, CONF_GCLK_TC3_SRC);
}

void TIMER_5_CLOCK_init(void)
{
	_pm_enable_bus_clock(PM_BUS_APBC, TC4);

	_gclk_enable_channel(TC4_GCLK_ID, CONF_GCLK_TC4_SRC);
}

void TIMER_6_CLOCK_init(void)
{
	_pm_enable_bus_clock(PM_BUS_APBC, TC5);

	_gclk_enable_channel(TC5_GCLK_ID, CONF_GCLK_TC5_SRC);
}

void TIMER_4_CLOCK_init(void)
{
	_pm_enable_bus_clock(PM_BUS_APBC, TC6);

	_gclk_enable_channel(TC6_GCLK_ID, CONF_GCLK_TC6_SRC);
}

void TIMER_7_CLOCK_init(void)
{
	_pm_enable_bus_clock(PM_BUS_APBC, TC7);

	_gclk_enable_channel(TC7_GCLK_ID, CONF_GCLK_TC7_SRC);
}

void AC_0_PORT_init(void)
{

	// Disable digital pin circuitry
	gpio_set_pin_direction(CONFIG1, GPIO_DIRECTION_OFF);

	gpio_set_pin_function(CONFIG1, PINMUX_PA04B_AC_AIN0);

	// Disable digital pin circuitry
	gpio_set_pin_direction(CONFIG2, GPIO_DIRECTION_OFF);

	gpio_set_pin_function(CONFIG2, PINMUX_PA05B_AC_AIN1);

	// Disable digital pin circuitry
	gpio_set_pin_direction(CONFIG3, GPIO_DIRECTION_OFF);

	gpio_set_pin_function(CONFIG3, PINMUX_PA06B_AC_AIN2);
}

void AC_0_CLOCK_init(void)
{

	_pm_enable_bus_clock(PM_BUS_APBC, AC);
	_gclk_enable_channel(AC_GCLK_ID_DIG, CONF_GCLK_DIG_AC_SRC);
	_gclk_enable_channel(AC_GCLK_ID_ANA, CONF_GCLK_ANA_AC_SRC);
}

void AC_0_init(void)
{
	AC_0_CLOCK_init();
	ac_async_init(&AC_0, AC);
	AC_0_PORT_init();
}

void DAC_0_PORT_init(void)
{
}

void DAC_0_CLOCK_init(void)
{

	_pm_enable_bus_clock(PM_BUS_APBC, DAC);
	_gclk_enable_channel(DAC_GCLK_ID, CONF_GCLK_DAC_SRC);
}

void DAC_0_init(void)
{
	DAC_0_CLOCK_init();
	dac_sync_init(&DAC_0, DAC);
	DAC_0_PORT_init();
}

void EVENT_SYSTEM_0_init(void)
{
	_gclk_enable_channel(EVSYS_GCLK_ID_0, CONF_GCLK_EVSYS_CHANNEL_0_SRC);

	_pm_enable_bus_clock(PM_BUS_APBC, EVSYS);

	event_system_init();
}

void TIMER_1_CLOCK_init(void)
{
	_pm_enable_bus_clock(PM_BUS_APBC, TCC0);
	_gclk_enable_channel(TCC0_GCLK_ID, CONF_GCLK_TCC0_SRC);
}

void TIMER_0_CLOCK_init(void)
{
	_pm_enable_bus_clock(PM_BUS_APBC, TCC1);
	_gclk_enable_channel(TCC1_GCLK_ID, CONF_GCLK_TCC1_SRC);
}

void TIMER_2_CLOCK_init(void)
{
	_pm_enable_bus_clock(PM_BUS_APBC, TCC2);
	_gclk_enable_channel(TCC2_GCLK_ID, CONF_GCLK_TCC2_SRC);
}

void system_init(void)
{
	init_mcu();

	// GPIO on PA02

	// Set pin direction to input
	gpio_set_pin_direction(PWR_SENSE, GPIO_DIRECTION_IN);

	gpio_set_pin_pull_mode(PWR_SENSE,
	                       // <y> Pull configuration
	                       // <id> pad_pull_config
	                       // <GPIO_PULL_OFF"> Off
	                       // <GPIO_PULL_UP"> Pull-up
	                       // <GPIO_PULL_DOWN"> Pull-down
	                       GPIO_PULL_OFF);

	gpio_set_pin_function(PWR_SENSE, GPIO_PIN_FUNCTION_OFF);

	// GPIO on PA03

	// Set pin direction to input
	gpio_set_pin_direction(HV_SENSE, GPIO_DIRECTION_IN);

	gpio_set_pin_pull_mode(HV_SENSE,
	                       // <y> Pull configuration
	                       // <id> pad_pull_config
	                       // <GPIO_PULL_OFF"> Off
	                       // <GPIO_PULL_UP"> Pull-up
	                       // <GPIO_PULL_DOWN"> Pull-down
	                       GPIO_PULL_OFF);

	gpio_set_pin_function(HV_SENSE, GPIO_PIN_FUNCTION_OFF);

	// GPIO on PA07

	// Set pin direction to input
	gpio_set_pin_direction(HV_SW, GPIO_DIRECTION_IN);

	gpio_set_pin_pull_mode(HV_SW,
	                       // <y> Pull configuration
	                       // <id> pad_pull_config
	                       // <GPIO_PULL_OFF"> Off
	                       // <GPIO_PULL_UP"> Pull-up
	                       // <GPIO_PULL_DOWN"> Pull-down
	                       GPIO_PULL_OFF);

	gpio_set_pin_function(HV_SW, GPIO_PIN_FUNCTION_OFF);

	// GPIO on PA20

	// Set pin direction to input
	gpio_set_pin_direction(OUTPUT_ENABLE, GPIO_DIRECTION_IN);

	gpio_set_pin_pull_mode(OUTPUT_ENABLE,
	                       // <y> Pull configuration
	                       // <id> pad_pull_config
	                       // <GPIO_PULL_OFF"> Off
	                       // <GPIO_PULL_UP"> Pull-up
	                       // <GPIO_PULL_DOWN"> Pull-down
	                       GPIO_PULL_OFF);

	gpio_set_pin_function(OUTPUT_ENABLE, GPIO_PIN_FUNCTION_OFF);

	// GPIO on PA27

	gpio_set_pin_level(LED1,
	                   // <y> Initial level
	                   // <id> pad_initial_level
	                   // <false"> Low
	                   // <true"> High
	                   true);

	// Set pin direction to output
	gpio_set_pin_direction(LED1, GPIO_DIRECTION_OUT);

	gpio_set_pin_function(LED1, GPIO_PIN_FUNCTION_OFF);

	// GPIO on PA28

	gpio_set_pin_level(LED2,
	                   // <y> Initial level
	                   // <id> pad_initial_level
	                   // <false"> Low
	                   // <true"> High
	                   true);

	// Set pin direction to output
	gpio_set_pin_direction(LED2, GPIO_DIRECTION_OUT);

	gpio_set_pin_function(LED2, GPIO_PIN_FUNCTION_OFF);

	// GPIO on PB00

	gpio_set_pin_level(GPIO1,
	                   // <y> Initial level
	                   // <id> pad_initial_level
	                   // <false"> Low
	                   // <true"> High
	                   true);

	// Set pin direction to output
	gpio_set_pin_direction(GPIO1, GPIO_DIRECTION_OUT);

	gpio_set_pin_function(GPIO1, GPIO_PIN_FUNCTION_OFF);

	// GPIO on PB01

	gpio_set_pin_level(GPIO2,
	                   // <y> Initial level
	                   // <id> pad_initial_level
	                   // <false"> Low
	                   // <true"> High
	                   false);

	// Set pin direction to output
	gpio_set_pin_direction(GPIO2, GPIO_DIRECTION_OUT);

	gpio_set_pin_function(GPIO2, GPIO_PIN_FUNCTION_OFF);

	// GPIO on PB14

	gpio_set_pin_level(DISPLAY_SS,
	                   // <y> Initial level
	                   // <id> pad_initial_level
	                   // <false"> Low
	                   // <true"> High
	                   false);

	// Set pin direction to output
	gpio_set_pin_direction(DISPLAY_SS, GPIO_DIRECTION_OUT);

	gpio_set_pin_function(DISPLAY_SS, GPIO_PIN_FUNCTION_OFF);

	// GPIO on PB17

	gpio_set_pin_direction(GPIO10,
	                       // <y> Pin direction
	                       // <id> pad_direction
	                       // <GPIO_DIRECTION_OFF"> Off
	                       // <GPIO_DIRECTION_IN"> In
	                       // <GPIO_DIRECTION_OUT"> Out
	                       GPIO_DIRECTION_OUT);

	gpio_set_pin_level(GPIO10,
	                   // <y> Initial level
	                   // <id> pad_initial_level
	                   // <false"> Low
	                   // <true"> High
	                   false);

	gpio_set_pin_pull_mode(GPIO10,
	                       // <y> Pull configuration
	                       // <id> pad_pull_config
	                       // <GPIO_PULL_OFF"> Off
	                       // <GPIO_PULL_UP"> Pull-up
	                       // <GPIO_PULL_DOWN"> Pull-down
	                       GPIO_PULL_OFF);

	gpio_set_pin_function(GPIO10,
	                      // <y> Pin function
	                      // <id> pad_function
	                      // <i> Auto : use driver pinmux if signal is imported by driver, else turn off function
	                      // <GPIO_PIN_FUNCTION_OFF"> Auto
	                      // <GPIO_PIN_FUNCTION_OFF"> Off
	                      // <GPIO_PIN_FUNCTION_A"> A
	                      // <GPIO_PIN_FUNCTION_B"> B
	                      // <GPIO_PIN_FUNCTION_C"> C
	                      // <GPIO_PIN_FUNCTION_D"> D
	                      // <GPIO_PIN_FUNCTION_E"> E
	                      // <GPIO_PIN_FUNCTION_F"> F
	                      // <GPIO_PIN_FUNCTION_G"> G
	                      // <GPIO_PIN_FUNCTION_H"> H
	                      GPIO_PIN_FUNCTION_H);

	// GPIO on PB30

	gpio_set_pin_direction(GPIO11,
	                       // <y> Pin direction
	                       // <id> pad_direction
	                       // <GPIO_DIRECTION_OFF"> Off
	                       // <GPIO_DIRECTION_IN"> In
	                       // <GPIO_DIRECTION_OUT"> Out
	                       GPIO_DIRECTION_OUT);

	gpio_set_pin_level(GPIO11,
	                   // <y> Initial level
	                   // <id> pad_initial_level
	                   // <false"> Low
	                   // <true"> High
	                   false);

	gpio_set_pin_pull_mode(GPIO11,
	                       // <y> Pull configuration
	                       // <id> pad_pull_config
	                       // <GPIO_PULL_OFF"> Off
	                       // <GPIO_PULL_UP"> Pull-up
	                       // <GPIO_PULL_DOWN"> Pull-down
	                       GPIO_PULL_OFF);

	gpio_set_pin_function(GPIO11,
	                      // <y> Pin function
	                      // <id> pad_function
	                      // <i> Auto : use driver pinmux if signal is imported by driver, else turn off function
	                      // <GPIO_PIN_FUNCTION_OFF"> Auto
	                      // <GPIO_PIN_FUNCTION_OFF"> Off
	                      // <GPIO_PIN_FUNCTION_A"> A
	                      // <GPIO_PIN_FUNCTION_B"> B
	                      // <GPIO_PIN_FUNCTION_C"> C
	                      // <GPIO_PIN_FUNCTION_D"> D
	                      // <GPIO_PIN_FUNCTION_E"> E
	                      // <GPIO_PIN_FUNCTION_F"> F
	                      // <GPIO_PIN_FUNCTION_G"> G
	                      // <GPIO_PIN_FUNCTION_H"> H
	                      GPIO_PIN_FUNCTION_F);

	EXTERNAL_IRQ_0_init();

	FLASH_0_init();

	USART_0_CLOCK_init();
	USART_0_init();
	USART_0_PORT_init();

	SPI_0_CLOCK_init();
	SPI_0_init();
	SPI_0_PORT_init();

	TIMER_8_CLOCK_init();
	TIMER_8_init();

	TIMER_3_CLOCK_init();

	TIMER_3_init();

	TIMER_5_CLOCK_init();

	TIMER_5_init();

	TIMER_6_CLOCK_init();

	TIMER_6_init();

	TIMER_4_CLOCK_init();

	TIMER_4_init();

	TIMER_7_CLOCK_init();

	TIMER_7_init();

	AC_0_init();

	DAC_0_init();

	EVENT_SYSTEM_0_init();

	TIMER_1_CLOCK_init();

	TIMER_1_init();

	TIMER_0_CLOCK_init();

	TIMER_0_init();

	TIMER_2_CLOCK_init();

	TIMER_2_init();
}
