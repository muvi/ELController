/*
 * OutputChannels.h
 *
 * Created: 24.08.2022 20:35:23
 *  Author: Christian
 */ 


#ifndef OUTPUTCHANNELS_H_
#define OUTPUTCHANNELS_H_

#include <atmel_start.h>
#include <hpl_pm_base.h>
#include <tcc_util.h>
#include <interrupt_util.h>
#include <io_util.h>
#include <sine_wave.h>
#include <hri_tc_d21c.h>
#include <tc_util.h>

#define OUTPUT_CHANNELS_COUNT 8
#define OUTPUT_CHANNELS_MIN_FREQUENCY 500.0 //Hz
#define OUTPUT_CHANNELS_MAX_FREQUENCY 4000.0 //Hz
#define OUTPUT_CHANNELS_DEFAULT_FREQUENCY 2000.0 //Hz

extern SineWave output_channels_wave_form[];

#define OUTPUT_CHANNELS_MIN_FREQUENCY_VALUE_DEF SINE_WAVE_FREQUENCY(OUTPUT_CHANNELS_MIN_FREQUENCY)
#define OUTPUT_CHANNELS_MAX_FREQUENCY_VALUE_DEF SINE_WAVE_FREQUENCY(OUTPUT_CHANNELS_MAX_FREQUENCY)
#define OUTPUT_CHANNELS_DEFAULT_FREQUENCY_VALUE_DEF SINE_WAVE_FREQUENCY(OUTPUT_CHANNELS_DEFAULT_FREQUENCY)

static const sine_wave_frequency_t OUTPUT_CHANNELS_MIN_FREQUENCY_VALUE = OUTPUT_CHANNELS_MIN_FREQUENCY_VALUE_DEF;
static const sine_wave_frequency_t OUTPUT_CHANNELS_MAX_FREQUENCY_VALUE = OUTPUT_CHANNELS_MAX_FREQUENCY_VALUE_DEF;
static const sine_wave_frequency_t OUTPUT_CHANNELS_FREQUENCY_RANGE_VALUE = OUTPUT_CHANNELS_MAX_FREQUENCY_VALUE_DEF - OUTPUT_CHANNELS_MIN_FREQUENCY_VALUE_DEF;

void output_channels_init();

static inline void output_channels_update(uint8_t channel, uint8_t frequency, uint8_t amplitude) {
	sine_wave_update(&(output_channels_wave_form[channel]), OUTPUT_CHANNELS_MIN_FREQUENCY_VALUE + (frequency * OUTPUT_CHANNELS_FREQUENCY_RANGE_VALUE / 0xFF), amplitude);
}

#endif /* OUTPUTCHANNELS_H_ */