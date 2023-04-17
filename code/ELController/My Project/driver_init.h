/*
 * Code generated from Atmel Start.
 *
 * This file will be overwritten when reconfiguring your Atmel Start project.
 * Please copy examples or other code you want to keep to a separate file
 * to avoid losing it when reconfiguring.
 */
#ifndef DRIVER_INIT_INCLUDED
#define DRIVER_INIT_INCLUDED

#include "atmel_start_pins.h"

#ifdef __cplusplus
extern "C" {
#endif

#include <hal_atomic.h>
#include <hal_delay.h>
#include <hal_gpio.h>
#include <hal_init.h>
#include <hal_io.h>
#include <hal_sleep.h>

#include <hal_ext_irq.h>

#include <hal_flash.h>

#include <usart_lite.h>
#include <spi_lite.h>
#include <rtc_lite.h>
#include <tc_lite.h>
#include <tc_lite.h>
#include <tc_lite.h>
#include <tc_lite.h>
#include <tc_lite.h>

#include <hal_ac_async.h>

#include <hal_dac_sync.h>

#include <hal_evsys.h>

#include <tcc_lite.h>
#include <tcc_lite.h>
#include <tcc_lite.h>

extern struct flash_descriptor FLASH_0;

extern struct ac_async_descriptor AC_0;

extern struct dac_sync_descriptor DAC_0;

void FLASH_0_init(void);
void FLASH_0_CLOCK_init(void);

void   USART_0_PORT_init(void);
void   USART_0_CLOCK_init(void);
int8_t USART_0_init(void);

void   SPI_0_PORT_init(void);
void   SPI_0_CLOCK_init(void);
int8_t SPI_0_init(void);

void   TIMER_8_CLOCK_init(void);
int8_t TIMER_8_init(void);

void TIMER_3_CLOCK_init(void);

int8_t TIMER_3_init(void);

void TIMER_5_CLOCK_init(void);

int8_t TIMER_5_init(void);

void TIMER_6_CLOCK_init(void);

int8_t TIMER_6_init(void);

void TIMER_4_CLOCK_init(void);

int8_t TIMER_4_init(void);

void TIMER_7_CLOCK_init(void);

int8_t TIMER_7_init(void);

void AC_0_PORT_init(void);
void AC_0_CLOCK_init(void);
void AC_0_init(void);

void DAC_0_PORT_init(void);
void DAC_0_CLOCK_init(void);
void DAC_0_init(void);

void TIMER_1_CLOCK_init(void);

int8_t TIMER_1_init(void);

void TIMER_0_CLOCK_init(void);

int8_t TIMER_0_init(void);

void TIMER_2_CLOCK_init(void);

int8_t TIMER_2_init(void);

/**
 * \brief Perform system initialization, initialize pins and clocks for
 * peripherals
 */
void system_init(void);

#ifdef __cplusplus
}
#endif
#endif // DRIVER_INIT_INCLUDED
