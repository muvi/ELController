/*
 * dip_switch.h
 *
 * Created: 29.06.2022 17:58:17
 *  Author: Christian
 */ 


#ifndef DIP_SWITCH_H_
#define DIP_SWITCH_H_

#include <atmel_start.h>
#include <utils_ringbuffer.h>
#include <hal_ac_async.h>
#include <hal_dac_sync.h>
#include <ac_util.h>
#include <interrupt_util.h>
#include <rtc_util.h>
#include <dac_util.h>

//data ready callback
void dip_switch_data_ready(uint16_t data);

void dip_switch_init();
void dip_switch_read();

#endif /* DIP_SWITCH_H_ */