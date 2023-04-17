/*
 * adc_util.c
 *
 * Created: 05.07.2022 23:40:34
 *  Author: Christian
 */ 

#include <adc_util.h>

/**
 * \brief SetADC resolution
 *
 * \param[in] hw The pointer to hardware instance
 * \param[in] input_channels the number of channels included in the scan
 */
static void _adc_set_input_channels(void *const hw, const hri_adc_inputctrl_reg_t input_channels)
{
	hri_adc_write_INPUTCTRL_INPUTSCAN_bf(hw, input_channels);
}

/**
 * \brief Set number of input channels included in scan
 */
void _adc_async_set_input_channels(struct _adc_async_device *const device, const hri_adc_inputctrl_reg_t input_channels)
{
	_adc_set_input_channels(device->hw, input_channels);
}

int32_t adc_async_set_input_channels(struct adc_async_descriptor *const descr, const hri_adc_inputctrl_reg_t input_channels)
{
	ASSERT(descr);
	_adc_async_set_input_channels(&descr->device, input_channels);
	return ERR_NONE;
}

static inline uint16_t adc_read_buffer(struct ringbuffer* buf) {
	return *((uint16_t*) (buf->buf + ((buf->write_index + buf->size - 1) & buf->size)));
}

uint16_t adc_data_read(const struct adc_async_descriptor *const descr) {
	return adc_read_buffer(&(descr->descr_ch->convert));
}
