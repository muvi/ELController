/*
 * ac_util.c
 *
 * Created: 17.07.2022 19:38:09
 *  Author: Christian
 */ 

#include <ac_util.h>

/*
void _ac_async_set_positive_input(struct _ac_async_device *const device, uint8_t comp, hri_ac_compctrl_reg_t muxpos) {
	hri_ac_clear_COMPCTRL_ENABLE_bit(device->hw, comp);
	hri_ac_write_COMPCTRL_MUXPOS_bf(device->hw, comp, muxpos);
}

void ac_async_set_positive_input(struct ac_async_descriptor *const descr, uint8_t comp, hri_ac_compctrl_reg_t muxpos) {
	_ac_async_set_positive_input(&descr->device, comp, muxpos);
}

*/