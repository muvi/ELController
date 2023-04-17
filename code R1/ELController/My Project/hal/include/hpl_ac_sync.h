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
#ifndef _HPL_AC_SYNC_H_INCLUDED
#define _HPL_AC_SYNC_H_INCLUDED

#include <compiler.h>
#include "hpl_irq.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * \brief AC sync device structure
 *
 * The AC device structure forward declaration.
 */
struct _ac_sync_device;

/**
 * \brief AC descriptor device structure.
 */
struct _ac_sync_device {
	void *hw; /*!< Hardware instance */
};

/**
 * \brief Initialize synchronous AC.
 *
 * This function does low level AC configuration.
 *
 * \param[in] device The pointer to device instance
 * \param[in] hw The pointer to hardware instance
 *
 * \return Initialization status
 */
int32_t _ac_sync_init(struct _ac_sync_device *const device, void *const hw);

/**
 * \brief Deinitialize AC.
 *
 * \param[in] device The pointer to device instance
 */
void _ac_sync_deinit(struct _ac_sync_device *const device);

/**
 * \brief Enable AC
 *
 * \param[in] device The pointer to device instance
 */
void _ac_sync_enable(struct _ac_sync_device *const device);

/**
 * \brief Disable AC
 *
 * \param[in] device The pointer to device instance
 */
void _ac_sync_disable(struct _ac_sync_device *const device);

/**
 * \brief Start AC Comparison.
 *
 * \param[in] device The pointer to device instance
 * \param[in] comp Comparator index number
 */
void _ac_sync_start_comparison(struct _ac_sync_device *const device, const uint8_t comp);

/**
 * \brief Stop AC Comparison
 *
 * \param[in] device The pointer to device instance
 * \param[in] comp Comparator index number
 */
void _ac_sync_stop_comparison(struct _ac_sync_device *const device, const uint8_t comp);

/**
 * \brief Read Comparison result.
 *
 * \param[in] device The pointer to device instance
 * \param[in] comp Comparator number
 *
 * \return The comparison result or -1 if input parameters are not correct.
 * \retval -1 Passed parameters were invalid or an AC is not initialized
 * \retval 0 The comparison result is 0
 * \retval 1 The comparison result is 1
 */
int32_t _ac_sync_get_result(struct _ac_sync_device *const device, const uint8_t comp);

#ifdef __cplusplus
}
#endif

#endif /* _HPL_AC_H_INCLUDED */
