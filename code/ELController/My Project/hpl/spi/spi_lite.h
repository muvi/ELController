
/**
 * \file
 *
 * \brief SPI related functionality declaration.
 *
 * Copyright (c) 2017 Microchip Technology Inc. and its subsidiaries.
 *
 * \asf_license_start
 *
 * \page License
 *
 * Subject to your compliance with these terms, you may use Microchip
 * software and any derivatives exclusively with Microchip products.
 * It is your responsibility to comply with third party license terms applicable
 * to your use of third party software (including open source software) that
 * may accompany Microchip software.
 *
 * THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES,
 * WHETHER EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE,
 * INCLUDING ANY IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY,
 * AND FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT WILL MICROCHIP BE
 * LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, INCIDENTAL OR CONSEQUENTIAL
 * LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND WHATSOEVER RELATED TO THE
 * SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS BEEN ADVISED OF THE
 * POSSIBILITY OR THE DAMAGES ARE FORESEEABLE.  TO THE FULLEST EXTENT
 * ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN ANY WAY
 * RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
 * THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
 *
 * \asf_license_stop
 *
 */

#ifndef _SPI_LITE_H_INCLUDED
#define _SPI_LITE_H_INCLUDED

#include <compiler.h>
#include <peripheral_clk_config.h>

/**
 * \addtogroup spi SPI driver
 *
 * \section spi_rev Revision History
 * - v0.0.0.1 Initial Commit
 *
 *@{
 */

#ifdef __cplusplus
extern "C" {
#endif

// Calculate baud register value from requested baudrate value
#ifndef SERCOM4_BAUD_RATE
#define SERCOM4_BAUD_RATE ((float)CONF_GCLK_SERCOM4_CORE_FREQUENCY / (float)(2 * 230400)) - 1
#endif

#ifndef SERCOM4_RXPO
#define SERCOM4_RXPO 3
#endif

#ifndef SERCOM4_TXPO
#define SERCOM4_TXPO 0
#endif

/**
 * \brief Initialize usart interface
 *
 * \return Initialization status.
 */
int8_t SPI_0_init();

/**
 * \brief Enable SPI module
 */
void SPI_0_enable();

/**
 * \brief Disable SPI module
 */
void SPI_0_disable();

/**
 * \brief Exchange byte in SPI module
 */
uint32_t SPI_0_exchange_data(uint32_t data);

/**
 * \brief Exchange block in SPI module
 */
void SPI_0_exchange_block(void *block, uint8_t size);

/**
 * \brief Write block in SPI module
 */
void SPI_0_write_block(void *block, uint8_t size);

/**
 * \brief Read block in SPI module
 */
void SPI_0_read_block(void *block, uint8_t size);

#ifdef __cplusplus
}
#endif

#endif /* _SPI_LITE_H_INCLUDED */
