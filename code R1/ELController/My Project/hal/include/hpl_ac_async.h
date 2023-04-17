/**
 * \file
 *
 * \brief AC related functionality declaration.
 *
 * Copyright (c) 2015-2018 Microchip Technology Inc. and its subsidiaries.
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
#ifndef _HPL_AC_ASYNC_H_INCLUDED
#define _HPL_AC_ASYNC_H_INCLUDED

#include <compiler.h>
#include "hpl_irq.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * \brief AC async device structure
 *
 * The AC device structure forward declaration.
 */
struct _ac_async_device;

/**
 * \brief AC interrupt handlers structure
 */
struct _ac_async_callback {
	/** Comparator comparison ready handler */
	void (*comparison_ready_cb)(struct _ac_async_device *device, const uint8_t comp, const uint8_t result);
};

/**
 * \brief AC descriptor device structure.
 */
struct _ac_async_device {
	struct _ac_async_callback cb;  /*!< Interrupt handers  */
	struct _irq_descriptor    irq; /*!< Interrupt descriptor */
	void *                    hw;  /*!< Hardware instance */
};

/**
 * \brief Initialize Asynchronous AC.
 *
 * This function does low level AC configuration.
 *
 * \param[in] device The pointer to device instance
 * \param[in] hw The pointer to hardware instance
 *
 * \return Initialization status.
 */
int32_t _ac_async_init(struct _ac_async_device *const device, void *const hw);

/**
 * \brief Deinitialize AC.
 *
 * \param[in] device The pointer to device instance
 */
void _ac_async_deinit(struct _ac_async_device *const device);

/**
 * \brief Enable AC
 *
 * \param[in] device The pointer to device instance
 */
void _ac_async_enable(struct _ac_async_device *const device);

/**
 * \brief Disable AC
 *
 * \param[in] device The pointer to device instance
 */
void _ac_async_disable(struct _ac_async_device *const device);

/**
 * \brief Start AC Comparison.
 *
 * \param[in] device The pointer to device instance
 * \param[in] comp Comparator index number
 */
void _ac_async_start_comparison(struct _ac_async_device *const device, const uint8_t comp);

/**
 * \brief Stop AC Comparison
 *
 * \param[in] device The pointer to device instance
 * \param[in] comp Comparator index number
 */
void _ac_async_stop_comparison(struct _ac_async_device *const device, const uint8_t comp);

#ifdef __cplusplus
}
#endif

#endif /* _HPL_AC_H_INCLUDED */
