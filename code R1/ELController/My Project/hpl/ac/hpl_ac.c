
/**
 * \file
 *
 * \brief SAM Analog Comparator
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

#include <hpl_ac_async.h>
#include <hpl_ac_sync.h>
#include <hpl_ac_config.h>
#include <utils.h>
#include <utils_assert.h>

/**
 * \brief AC configuration type
 */
struct _ac_cfg {
	void *                hw; /*!< instance of I2SMCC */
	IRQn_Type             irq;
	hri_ac_ctrla_reg_t    ctrla;        /*!< Control A Register */
	hri_ac_evctrl_reg_t   ev_ctrl;      /*!< Event Control Register */
	hri_ac_compctrl_reg_t comp_ctrl0;   /*!< Comparator0 Control */
	hri_ac_compctrl_reg_t comp_ctrl1;   /*!< Comparator1 Control */
	hri_ac_scaler_reg_t   comp_scaler0; /*!< Comparator1 Vddana Scaler */
	hri_ac_scaler_reg_t   comp_scaler1; /*!< Comparator1 Vddana Scaler  */
};

/**
 * \internal Retrieve configuration
 *
 * \param[in] hw The pointer of I2SMCC base address
 *
 * \return The configuration
 */
static const struct _ac_cfg *_get_ac_cfg(void *hw);

/**
 * \brief Array of AC configurations
 */
static const struct _ac_cfg _cfgs[1] = {
    {(void *)AC,
     AC_IRQn,
     CONF_AC_CTRLA,
     CONF_AC_EVCTRL,
     CONF_AC_COMP_CTRL0,
     CONF_AC_COMP_CTRL1,
     CONF_AC_COMP_SCALER0,
     CONF_AC_COMP_SCALER1},
};

/*!< Pointer to hpl device */

static struct _ac_async_device *_ac_dev = NULL;

/** \cond INTERNAL */
static int32_t     _ac_init(void *const hw);
static inline void _ac_deinit(void *const hw);
static inline void _ac_start_comparison(void *const hw, const uint8_t comp);
/** \endcond */

/**
 * \brief Init irq param with the given ac hardware instance
 */
static void _ac_init_irq_param(const void *const hw, void *dev)
{
	if (hw == AC) {
		_ac_dev = (struct _ac_async_device *)dev;
	}
}

/**
 * \brief Initialize synchronous AC
 */
int32_t _ac_sync_init(struct _ac_sync_device *const device, void *const hw)
{
	ASSERT(device);

	device->hw = hw;

	return _ac_init(hw);
}

/**
 * \brief Initialize Asynchronous AC
 */
int32_t _ac_async_init(struct _ac_async_device *const device, void *const hw)
{
	int32_t init_status;

	ASSERT(device);

	init_status = _ac_init(hw);
	if (init_status) {
		return init_status;
	}
	device->hw = hw;

	const struct _ac_cfg *cfg = _get_ac_cfg(hw);
	if (cfg == NULL) {
		return ERR_NOT_FOUND;
	}

	_ac_init_irq_param(hw, (void *)device);

	hri_ac_set_INTEN_COMP0_bit(hw);
	hri_ac_set_INTEN_COMP1_bit(hw);
	hri_ac_set_INTEN_WIN0_bit(hw);

	NVIC_DisableIRQ(cfg->irq);
	NVIC_ClearPendingIRQ(cfg->irq);
	NVIC_EnableIRQ(cfg->irq);

	return ERR_NONE;
}

/**
 * \brief De-initialize AC
 */
void _ac_async_deinit(struct _ac_async_device *const device)
{
	NVIC_DisableIRQ(AC_IRQn);

	_ac_deinit(&device->hw);
}

/**
 * \brief De-initialize AC
 */
void _ac_sync_deinit(struct _ac_sync_device *const device)
{
	_ac_deinit(&device->hw);
}

/**
 * \brief Enable AC
 *
 */
void _ac_sync_enable(struct _ac_sync_device *const device)
{
	hri_ac_set_CTRLA_ENABLE_bit(device->hw);
}

/**
 * \brief Enable AC
 *
 */
void _ac_async_enable(struct _ac_async_device *const device)
{
	hri_ac_set_CTRLA_ENABLE_bit(device->hw);
}

/**
 * \brief Disable AC
 *
 */
void _ac_sync_disable(struct _ac_sync_device *const device)
{
	hri_ac_clear_CTRLA_ENABLE_bit(device->hw);
}

/**
 * \brief Disable AC
 *
 */
void _ac_async_disable(struct _ac_async_device *const device)
{
	hri_ac_clear_CTRLA_ENABLE_bit(device->hw);
}

/**
 * \brief Start AC comparison
 */
void _ac_sync_start_comparison(struct _ac_sync_device *const device, const uint8_t comp)
{
	_ac_start_comparison(device->hw, comp);
}

/**
 * \brief Start AC comparison
 */
void _ac_async_start_comparison(struct _ac_async_device *const device, const uint8_t comp)
{
	_ac_start_comparison(device->hw, comp);
}

/**
 * \brief Stop AC Comparison
 */
void _ac_sync_stop_comparison(struct _ac_sync_device *const device, const uint8_t comp)
{
	hri_ac_clear_COMPCTRL_ENABLE_bit(device->hw, comp);
}

/**
 * \brief Stop AC Comparison
 */
void _ac_async_stop_comparison(struct _ac_async_device *const device, const uint8_t comp)
{
	hri_ac_clear_COMPCTRL_ENABLE_bit(device->hw, comp);
}

/**
 * \brief write synchronous AC data for output
 */
int32_t _ac_sync_get_result(struct _ac_sync_device *const device, const uint8_t comp)
{
	if (comp == 0) {
		if (!hri_ac_get_STATUSB_READY0_bit(device->hw)) {
			return ERR_NOT_READY;
		}
		return hri_ac_get_STATUSA_STATE0_bit(device->hw);
	} else if (comp == 1) {
		if (!hri_ac_get_STATUSB_READY1_bit(device->hw)) {
			return ERR_NOT_READY;
		}
		return hri_ac_get_STATUSA_STATE1_bit(device->hw);
	}
	return ERR_NOT_READY;
}

/** \cond INTERNAL */
/*
 * \brief AC interrupt handler
 */
void AC_Handler(void)
{
	void *const hw    = _ac_dev->hw;
	uint8_t     state = 0;

	if (_ac_dev->cb.comparison_ready_cb == NULL) {
		return;
	}

	if (hri_ac_get_interrupt_COMP0_bit(hw)) {
		state = hri_ac_get_STATUSA_STATE0_bit(hw);
		hri_ac_clear_interrupt_COMP0_bit(hw);
		_ac_dev->cb.comparison_ready_cb(_ac_dev, 0, state);
	} else if (hri_ac_get_interrupt_COMP1_bit(hw)) {
		state = hri_ac_get_STATUSA_STATE1_bit(hw);
		hri_ac_clear_interrupt_COMP1_bit(hw);
		_ac_dev->cb.comparison_ready_cb(_ac_dev, 1, state);
	}
}

/**
 * \brief Initialize AC
 *
 * \param[in] hw The pointer to hardware instance
 */
static int32_t _ac_init(void *const hw)
{
	ASSERT(hw);
	const struct _ac_cfg *cfg = _get_ac_cfg(hw);
	if (cfg == NULL) {
		return ERR_NOT_FOUND;
	}

	hri_ac_wait_for_sync(hw);
	if (hri_ac_get_CTRLA_reg(hw, AC_CTRLA_ENABLE)) {
		hri_ac_write_CTRLA_reg(hw, 0);
		hri_ac_wait_for_sync(hw);
	}
	hri_ac_write_CTRLA_reg(hw, AC_CTRLA_SWRST);
	hri_ac_wait_for_sync(hw);

	hri_ac_write_COMPCTRL_reg(hw, 0, cfg->comp_ctrl0);
	hri_ac_write_COMPCTRL_reg(hw, 1, cfg->comp_ctrl1);
	hri_ac_write_SCALER_reg(hw, 0, cfg->comp_scaler0);
	hri_ac_write_SCALER_reg(hw, 1, cfg->comp_scaler1);
	hri_ac_write_EVCTRL_reg(hw, cfg->ev_ctrl);
	hri_ac_write_CTRLA_reg(hw, cfg->ctrla);

	return ERR_NONE;
}

/**
 * \brief De-initialize AC
 *
 * \param[in] hw The pointer to hardware instance
 */
static inline void _ac_deinit(void *const hw)
{
	hri_ac_clear_CTRLA_ENABLE_bit(hw);
	hri_ac_set_CTRLA_SWRST_bit(hw);
}

/**
 * \brief Start AC comparison
 *
 * \param[in] hw The pointer to hardware instance
 */
static inline void _ac_start_comparison(void *const hw, const uint8_t comp)
{
	hri_ac_set_COMPCTRL_ENABLE_bit(hw, comp);
	if (hri_ac_get_COMPCTRL_SINGLE_bit(hw, comp) == false) {
		return;
	}
	if (comp == 0) {
		hri_ac_write_CTRLB_reg(hw, AC_CTRLB_START0);
	} else {
		hri_ac_write_CTRLB_reg(hw, AC_CTRLB_START1);
	}
}

static const struct _ac_cfg *_get_ac_cfg(void *hw)
{
	uint8_t i;

	for (i = 0; i < ARRAY_SIZE(_cfgs); i++) {
		if (_cfgs[i].hw == hw) {
			return &(_cfgs[i]);
		}
	}
	return NULL;
}
