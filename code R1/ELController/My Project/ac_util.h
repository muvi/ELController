/*
 * ac_util.h
 *
 * Created: 17.07.2022 19:37:57
 *  Author: Christian
 */ 


#ifndef AC_UTIL_H_
#define AC_UTIL_H_

#include <hri_ac_d21c.h>
#include <hal_ac_async.h>
#include <hal_atomic.h>

#define AC_MUXPOS_AIN0 0x1
#define AC_MUXPOS_AIN1 0x2
#define AC_MUXPOS_AIN2 0x3
#define AC_MUXPOS_AIN3 0x4

#define AC_MUXNEG_AIN0 0x0
#define AC_MUXNEG_AIN1 0x1
#define AC_MUXNEG_AIN2 0x2
#define AC_MUXNEG_AIN3 0x3
#define AC_MUXNEG_GND 0x4
#define AC_MUXNEG_VSCALE 0x5
#define AC_MUXNEG_BANDGAP 0x6
#define AC_MUXNEG_DAC 0x7

static inline void hri_ac_write_CTRLB_reg_no_lock(const void *const hw, hri_ac_ctrlb_reg_t data)
{
	((Ac *)hw)->CTRLB.reg = data;
}

static inline void hri_ac_set_COMPCTRL_ENABLE_bit_no_lock(const void *const hw, uint8_t index)
{
	((Ac *)hw)->COMPCTRL[index].reg |= AC_COMPCTRL_ENABLE;
}

static inline void hri_ac_clear_COMPCTRL_ENABLE_bit_no_lock(const void *const hw, uint8_t index)
{
	((Ac *)hw)->COMPCTRL[index].reg &= ~AC_COMPCTRL_ENABLE;
}

static inline void hri_ac_write_COMPCTRL_MUXPOS_bf_no_lock(const void *const hw, uint8_t index, hri_ac_compctrl_reg_t data)
{
	uint32_t tmp;
	tmp = ((Ac *)hw)->COMPCTRL[index].reg;
	tmp &= ~AC_COMPCTRL_MUXPOS_Msk;
	tmp |= AC_COMPCTRL_MUXPOS(data);
	((Ac *)hw)->COMPCTRL[index].reg = tmp;
}

static inline void _ac_async_set_positive_input(struct _ac_async_device *const device, uint8_t comp, hri_ac_compctrl_reg_t muxpos) {
	hri_ac_clear_COMPCTRL_ENABLE_bit_no_lock(device->hw, comp);
	hri_ac_write_COMPCTRL_MUXPOS_bf_no_lock(device->hw, comp, muxpos);
}

static inline void ac_async_set_positive_input(struct ac_async_descriptor *const descr, uint8_t comp, hri_ac_compctrl_reg_t muxpos) {
	_ac_async_set_positive_input(&descr->device, comp, muxpos);
}

#endif /* AC_UTIL_H_ */