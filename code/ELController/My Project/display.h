/*
 * display.h
 *
 * Created: 2/6/2023 6:23:10 PM
 *  Author: Christian
 */ 


#ifndef DISPLAY_H_
#define DISPLAY_H_

#include <spi_lite.h>
#include <hpl_gpio.h>
#include <atmel_start_pins.h>

#define DISPLAY_NUMSEGMENTS 4

void display_init();
void display_update(uint16_t value);
void display_update_hex(uint16_t value);
void display_update_base(uint16_t value, uint8_t base);
void display_clear();
void display_update_string(char* str);
void display_test_pattern(uint8_t segment);
void display_render();

#endif /* DISPLAY_H_ */