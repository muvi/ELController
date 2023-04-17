/*
 * adc_util.h
 *
 * Created: 05.07.2022 23:40:50
 *  Author: Christian
 */ 


#ifndef ADC_UTIL_H_
#define ADC_UTIL_H_

#include <hal_adc_async.h>
#include <hpl_adc_async.h>
#include <hri_adc_d21c.h>
#include <utils_ringbuffer.h>

#define ADC_MUXPOS_AIN0 0x00
#define ADC_MUXPOS_AIN1 0x01
#define ADC_MUXPOS_AIN2 0x02
#define ADC_MUXPOS_AIN3 0x03
#define ADC_MUXPOS_AIN4 0x04
#define ADC_MUXPOS_AIN5 0x05
#define ADC_MUXPOS_AIN6 0x06
#define ADC_MUXPOS_AIN7 0x07
#define ADC_MUXPOS_AIN8 0x08
#define ADC_MUXPOS_AIN9 0x09
#define ADC_MUXPOS_AIN10 0x0A
#define ADC_MUXPOS_AIN11 0x0B
#define ADC_MUXPOS_AIN12 0x0C
#define ADC_MUXPOS_AIN13 0x0D
#define ADC_MUXPOS_AIN14 0x0E
#define ADC_MUXPOS_AIN15 0x0F
#define ADC_MUXPOS_AIN16 0x10
#define ADC_MUXPOS_AIN17 0x11
#define ADC_MUXPOS_AIN18 0x12
#define ADC_MUXPOS_AIN19 0x13
#define ADC_MUXPOS_TEMPERATURE 0x18
#define ADC_MUXPOS_BANDGAP 0x19
#define ADC_MUXPOS_SCALED_CORE_SUPPLY 0x1A
#define ADC_MUXPOS_SCALED_IO_SUPPLY 0x1B
#define ADC_MUXPOS_DAC_OUTPUT 0x1C

#define ADC_MUXNEG_AIN0 0x00
#define ADC_MUXNEG_AIN1 0x01
#define ADC_MUXNEG_AIN2 0x02
#define ADC_MUXNEG_AIN3 0x03
#define ADC_MUXNEG_AIN4 0x04
#define ADC_MUXNEG_AIN5 0x05
#define ADC_MUXNEG_AIN6 0x06
#define ADC_MUXNEG_AIN7 0x07
#define ADC_MUXNEG_INTERNAL_GROUND 0x18
#define ADC_MUXNEG_IO_GROUND 0x19

#define ADC_RESOLUTION_12BIT 0x0
#define ADC_RESOLUTION_16BIT 0x1
#define ADC_RESOLUTION_10BIT 0x2
#define ADC_RESOLUTION_8BIT 0x3

int32_t adc_async_set_input_channels(struct adc_async_descriptor *const descr, const hri_adc_inputctrl_reg_t input_channels);
uint16_t adc_data_read(const struct adc_async_descriptor *const descr);

#endif /* ADC_UTIL_H_ */