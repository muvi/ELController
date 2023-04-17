/*
 * Code generated from Atmel Start.
 *
 * This file will be overwritten when reconfiguring your Atmel Start project.
 * Please copy examples or other code you want to keep to a separate file
 * to avoid losing it when reconfiguring.
 */

#include "driver_examples.h"
#include "driver_init.h"
#include "utils.h"

static void button_on_PB06_pressed(void)
{
}

static void button_on_PB07_pressed(void)
{
}

static void button_on_PB12_pressed(void)
{
}

static void button_on_PB13_pressed(void)
{
}

/**
 * Example of using EXTERNAL_IRQ_0
 */
void EXTERNAL_IRQ_0_example(void)
{

	ext_irq_register(PIN_PB06, button_on_PB06_pressed);
	ext_irq_register(PIN_PB07, button_on_PB07_pressed);
	ext_irq_register(PIN_PB12, button_on_PB12_pressed);
	ext_irq_register(PIN_PB13, button_on_PB13_pressed);
}

static uint8_t src_data[128];
static uint8_t chk_data[128];
/**
 * Example of using FLASH_0 to read and write Flash main array.
 */
void FLASH_0_example(void)
{
	uint32_t page_size;
	uint16_t i;

	/* Init source data */
	page_size = flash_get_page_size(&FLASH_0);

	for (i = 0; i < page_size; i++) {
		src_data[i] = i;
	}

	/* Write data to flash */
	flash_write(&FLASH_0, 0x3200, src_data, page_size);

	/* Read data from flash */
	flash_read(&FLASH_0, 0x3200, chk_data, page_size);
}

/**
 * Example of using FLASH_0 to read and write Flash RWWEE array.
 */
void RWW_FLASH_0_example(void)
{
	uint32_t page_size;
	uint16_t i;

	/* Init source data */
	page_size = _rww_flash_get_page_size(&FLASH_0.dev);

	for (i = 0; i < page_size; i++) {
		src_data[i] = i;
	}

	/* Write data to RWWEE flash */
	if (_rww_flash_write(&FLASH_0.dev, NVMCTRL_RWW_EEPROM_ADDR, src_data, page_size) != ERR_NONE) {
		while (1)
			; /* Trap here when flash write error happen */
	}

	/* Read data from RWWEE flash */
	if (_rww_flash_read(&FLASH_0.dev, NVMCTRL_RWW_EEPROM_ADDR, chk_data, page_size) != ERR_NONE) {
		while (1)
			; /* Trap here when flash read error happen */
	}

	/* Check data */
	for (i = 0; i < page_size; i++) {
		if (src_data[i] != chk_data[i]) {
			while (1)
				; /* Trap here when check error happen */
		}
	}
}

/*
 * \Write data to usart interface
 *
 * \param[in] buf Data to write to usart
 * \param[in] length The number of bytes to write
 *
 * \return The number of bytes written.
 */
static uint32_t USART_0_write(const uint8_t *const buf, const uint16_t length)
{
	uint32_t offset = 0;

	ASSERT(buf && length);

	while (!USART_0_is_byte_sent())
		;
	do {
		USART_0_write_byte(buf[offset]);
		while (!USART_0_is_byte_sent())
			;
	} while (++offset < length);

	return offset;
}

/*
 * \Read data from usart interface
 *
 * \param[in] buf A buffer to read data to
 * \param[in] length The size of a buffer
 *
 * \return The number of bytes read.
 */
static uint32_t USART_0_read(uint8_t *const buf, const uint16_t length)
{
	uint32_t offset = 0;

	ASSERT(buf && length);

	do {
		while (!USART_0_is_byte_received())
			;
		buf[offset] = USART_0_read_byte();
	} while (++offset < length);

	return offset;
}

/**
 * Example of using USART_0 to write the data which received from the usart interface to IO.
 */
void USART_0_example(void)
{
	uint8_t data[2];

	if (USART_0_read(data, sizeof(data)) == 2) {
		USART_0_write(data, 2);
	}
}

/**
 * Example of using SPI_0 to write "Hello World" using the IO abstraction.
 */
static uint8_t example_SPI_0[12] = "Hello World!";

void SPI_0_example(void)
{
	SPI_0_write_block((void *)example_SPI_0, 12);
}

static void ready_cb_AC_0(struct ac_async_descriptor *const descr, const uint8_t comp, const uint8_t result)
{
}

/**
 * Example of using AC_0 to generate waveform.
 */
void AC_0_example(void)
{
	ac_async_register_callback(&AC_0, AC_COMPARISON_READY_CB, (ac_cb_t)ready_cb_AC_0);
	ac_async_enable(&AC_0);
	ac_async_start_comparison(&AC_0, 0);
}

/**
 * Example of using DAC_0 to generate waveform.
 */
void DAC_0_example(void)
{
	uint16_t i = 0;

	dac_sync_enable_channel(&DAC_0, 0);

	for (;;) {
		dac_sync_write(&DAC_0, 0, &i, 1);
		i = (i + 1) % 1024;
	}
}
