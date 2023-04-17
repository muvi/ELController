/**
 * \file
 *
 * \brief AC functionality implementation.
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

#include "hal_ac_async.h"
#include <utils_assert.h>
#include <utils.h>
#include <hal_atomic.h>

/**
 * \brief Driver version
 */
#define DRIVER_VERSION 0x00000001u

/* Private function */
static void ac_async_comparison_ready(struct _ac_async_device *device, const uint8_t comp, const uint8_t result);

/**
 * \brief Initialize the AC HAL instance and hardware.
 */
int32_t ac_async_init(struct ac_async_descriptor *const descr, void *const hw)
{
	int32_t init_status;

	ASSERT(descr && hw);

	init_status = _ac_async_init(&descr->device, hw);
	if (init_status) {
		return init_status;
	}
	descr->device.cb.comparison_ready_cb = ac_async_comparison_ready;

	return ERR_NONE;
}

/**
 * \brief Deinitialize the AC HAL instance and hardware.
 */
int32_t ac_async_deinit(struct ac_async_descriptor *const descr)
{
	ASSERT(descr);

	_ac_async_deinit(&descr->device);

	return ERR_NONE;
}

/**
 * \brief Enable AC
 */
int32_t ac_async_enable(struct ac_async_descriptor *const descr)
{
	ASSERT(descr);

	_ac_async_enable(&descr->device);

	return ERR_NONE;
}

/**
 * \brief Disable AC
 */
int32_t ac_async_disable(struct ac_async_descriptor *const descr)
{
	ASSERT(descr);

	_ac_async_disable(&descr->device);

	return ERR_NONE;
}

/**
 * \brief Register AC callback
 */
int32_t ac_async_register_callback(struct ac_async_descriptor *const descr, const enum ac_callback_type type,
                                   ac_cb_t cb)
{
	ASSERT(descr);

	switch (type) {
	case AC_COMPARISON_READY_CB:
		descr->cb.comparison_ready = cb;
		break;
	default:
		return ERR_INVALID_ARG;
	}

	return ERR_NONE;
}

/**
 * \brief Start comparison
 */
int32_t ac_async_start_comparison(struct ac_async_descriptor *const descr, uint8_t comp)
{
	ASSERT(descr);

	_ac_async_start_comparison(&descr->device, comp);

	return ERR_NONE;
}

/**
 * \brief Stop comparison
 */
int32_t ac_async_stop_comparison(struct ac_async_descriptor *const descr, uint8_t comp)
{
	ASSERT(descr);

	_ac_async_stop_comparison(&descr->device, comp);

	return ERR_NONE;
}

/**
 * \brief Get AC driver version
 */
uint32_t ac_async_get_version(void)
{
	return DRIVER_VERSION;
}

/**
 * \internal Comparison ready handler
 *
 * \param[in] device The pointer to AC device structure
 * \param[in] comp Comparator number
 */
static void ac_async_comparison_ready(struct _ac_async_device *device, const uint8_t comp, const uint8_t result)
{
	struct ac_async_descriptor *const descr = CONTAINER_OF(device, struct ac_async_descriptor, device);

	if (descr->cb.comparison_ready) {
		descr->cb.comparison_ready(descr, comp, result);
	}
}

//@}
