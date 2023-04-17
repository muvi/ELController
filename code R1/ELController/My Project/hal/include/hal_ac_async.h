/**
 * \file
 *
 * \brief AC functionality declaration.
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

#ifndef HAL_AC_ASYNC_H_INCLUDED
#define HAL_AC_ASYNC_H_INCLUDED

#include <hpl_ac_async.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * \addtogroup doc_driver_hal_ac_async
 *
 *@{
 */

/**
 * \brief AC Asynchronous descriptor
 *
 * The AC descriptor forward declaration.
 */
struct ac_async_descriptor;

/**
 * \brief AC callback type
 *
 * \param[in] descr  An AC descriptor
 * \param[in] comp   Comparator number
 * \param[in] result Comparison result,
 *            0 positive input less than negative input,
 *            1 positive input high than negative input
 */
typedef void (*ac_cb_t)(const struct ac_async_descriptor *const descr, const uint8_t comp, const uint8_t result);

/**
 * \brief AC callback types
 */
enum ac_callback_type {
	AC_COMPARISON_READY_CB /*!< Comparison ready handler */
};

/**
 * \brief AC callbacks
 */
struct ac_callbacks {
	ac_cb_t comparison_ready;
};

/**
 * \brief AC descriptor
 */
struct ac_async_descriptor {
	struct _ac_async_device device; /*!< AC HPL device descriptor */
	struct ac_callbacks     cb;     /*!< AC Callback handlers */
};

/**
 * \brief Initialize AC
 *
 * This function initializes the given AC descriptor.
 * It checks if the given hardware is not initialized and if the given hardware
 * is permitted to be initialized.
 *
 * \param[out] descr An AC descriptor to initialize
 * \param[in] hw The pointer to hardware instance
 *
 * \return Initialization status.
 */
int32_t ac_async_init(struct ac_async_descriptor *const descr, void *const hw);

/**
 * \brief Deinitialize AC
 *
 * This function deinitializes the given AC descriptor.
 * It checks if the given hardware is initialized and if the given hardware is
 * permitted to be deinitialized.
 *
 * \param[in] descr An AC descriptor to deinitialize
 *
 * \return De-initialization status.
 */
int32_t ac_async_deinit(struct ac_async_descriptor *const descr);

/**
 * \brief Enable AC
 *
 * This function enables the AC by the given AC descriptor.
 *
 * \param[in] descr An AC descriptor to enable
 *
 * \return Enabling status.
 */
int32_t ac_async_enable(struct ac_async_descriptor *const descr);

/**
 * \brief Disable AC
 *
 * This function disables the AC by the given AC descriptor.
 *
 * \param[in] descr An AC descriptor to disable
 *
 * \return Disabling status.
 */
int32_t ac_async_disable(struct ac_async_descriptor *const descr);

/**
 * \brief Register AC callback
 *
 * \param[in] descr An AC descriptor
 * \param[in] type Callback type
 * \param[in] cb A callback function, passing NULL will de-register any
 *               registered callback
 *
 * \return The status of callback assignment.
 * \retval -1 Passed parameters were invalid or the AC is not initialized
 * \retval 0 A callback is registered successfully
 */
int32_t ac_async_register_callback(struct ac_async_descriptor *const descr, const enum ac_callback_type type,
                                   ac_cb_t cb);

/**
 * \brief Start comparison
 *
 * This function starts the AC comparator comparison.
 *
 * \param[in] descr The pointer to AC descriptor
 * \param[in] comp Comparator number
 *
 * \return The result of comparator n start operation.
 */
int32_t ac_async_start_comparison(struct ac_async_descriptor *const descr, uint8_t comp);

/**
 * \brief Stop comparison
 *
 * This function stops the AC comparator comparison.
 *
 * \param[in] descr The pointer to AC descriptor
 * \param[in] comp Comparator number
 *
 * \return The result of comparator n stop the operation.
 */
int32_t ac_async_stop_comparison(struct ac_async_descriptor *const descr, uint8_t comp);

/**
 * \brief Retrieve the current driver version
 *
 * \return Current driver version.
 */
uint32_t ac_async_get_version(void);
/**@}*/

#ifdef __cplusplus
}
#endif

#endif
