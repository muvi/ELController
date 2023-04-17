#ifndef DMX_H
#define DMX_H

#include <atmel_start.h>
#include <interrupt_util.h>

#define DMX_ADDRESS_BITS 9
#define DMX_ADDRESS_MASK ((2 << (DMX_ADDRESS_BITS + 1)) - 1)

#define DMX_CHANNELS 18
volatile uint8_t dmx[DMX_CHANNELS];

//callback
void dmx_received();

void dmx_init();
void dmx_set_address(unsigned short address);

#endif