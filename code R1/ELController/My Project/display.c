/*
 * display.c
 *
 * Created: 2/6/2023 6:23:25 PM
 *  Author: Christian
 */ 

#include <display.h>

#define DISPLAY_COUNT 40

const uint8_t DISPLAY_VALUES_OUTER[DISPLAY_COUNT] = {0b00000001, 0b01001111, 0b00010010, 0b00000110, 0b01001100, 0b00100100, 0b00100000, 0b00001111, 0b00000000, 0b00000100, 0b00001000, 0b00110000, 0b00110001, 0b01111001, 0b00110000, 0b00111000, 0b00100001, 0b01001000, 0b01111111, 0b01000011, 0b01111000, 0b01110001, 0b01001001, 0b01001001, 0b00000001, 0b00011000, 0b00000001, 0b00011000, 0b00100100, 0b00111111, 0b01000001, 0b01111001, 0b01001001, 0b01111111, 0b01111111, 0b00110111, 0b01111111, 0b01111110, 0b01110111, 0b01111110};
const uint8_t DISPLAY_VALUES_INNER[DISPLAY_COUNT] = {0b01111111, 0b01111111, 0b00111111, 0b00111111, 0b00111111, 0b00111111, 0b00111111, 0b01111111, 0b00111111, 0b00111111, 0b00111111, 0b01110011, 0b01111111, 0b01011110, 0b01111111, 0b01111111, 0b00111111, 0b00111111, 0b01101101, 0b01111111, 0b01110011, 0b01111111, 0b01010111, 0b01011011, 0b01111111, 0b00111111, 0b01111011, 0b00111011, 0b00111111, 0b01101101, 0b01111111, 0b01110110, 0b01111010, 0b01010010, 0b01010101, 0b01110110, 0b01111111, 0b00111111, 0b01111111, 0b00000000};

#define DISPLAY_BLANK 0b01111111
#define DISPLAY_FULL 0b00000000

#define DISPLAY_VALUE_SPACE 36
#define DISPLAY_VALUE_MINUS 37
#define DISPLAY_VALUE_UNDERLINE 38
#define DISPLAY_VALUE_STAR 39
#define DISPLAY_VALUE_A 10
#define DISPLAY_VALUE_0 0

const uint16_t DISPLAY_SEGMENTS[DISPLAY_NUMSEGMENTS * 2] = {0b0000000000000011, 0b0000000000001100, 0b0000000000110000, 0b0000000011000000, 0b0000001100000000, 0b0000110000000000, 0b0011000000000000, 0b1100000000000000};

volatile uint8_t display_current_segment = 0;
volatile uint8_t display_current_digits[DISPLAY_NUMSEGMENTS * 2] = {DISPLAY_BLANK, DISPLAY_BLANK, DISPLAY_BLANK, DISPLAY_BLANK, DISPLAY_BLANK, DISPLAY_BLANK, DISPLAY_BLANK, DISPLAY_BLANK};

void display_init() {
	SPI_0_enable();
	gpio_set_pin_function(DISPLAY_SS, GPIO_PIN_FUNCTION_OFF);
	gpio_set_pin_direction(DISPLAY_SS, GPIO_DIRECTION_OUT);
	gpio_set_pin_level(DISPLAY_SS, true);
}

void display_test_pattern(uint8_t segment) {
	for (int i = DISPLAY_NUMSEGMENTS * 2 - 1; i >= 0; i--) {
		display_current_digits[i] = segment == i ? DISPLAY_FULL : DISPLAY_BLANK;
	}
}

static inline void display_set_digit(uint8_t segment, uint8_t value_index) {
	display_current_digits[segment * 2] = DISPLAY_VALUES_OUTER[value_index];
	display_current_digits[segment * 2 + 1] = DISPLAY_VALUES_INNER[value_index];
}

static inline uint8_t display_get_digit_ascii(char value) {
	switch (value) {
		case ' ': return DISPLAY_VALUE_SPACE;
		case '-': return DISPLAY_VALUE_MINUS;
		case '_': return DISPLAY_VALUE_UNDERLINE;
		case '*': return DISPLAY_VALUE_STAR;
		default: {
			if (value >= '0' && value <= '9') return value - '0' + DISPLAY_VALUE_0;
			else if (value >= 'A' && value <= 'Z') return value - 'A' + DISPLAY_VALUE_A;
			else if (value >= 'a' && value <= 'z') return value - 'a' + DISPLAY_VALUE_A;
			else return DISPLAY_VALUE_SPACE;
		}
	}
}

static inline void display_set_digit_ascii(uint8_t segment, char value) {
	display_set_digit(segment, display_get_digit_ascii(value));
}

void display_clear() {
	for (int i = 0; i < DISPLAY_NUMSEGMENTS; i++) {
		display_set_digit(i, DISPLAY_VALUE_SPACE);
	}
}

void display_update_string(char* str) {
	int i;
	for (i = 0; i < DISPLAY_NUMSEGMENTS; i++) {
		if (str[i] == 0) {
			break;
		}
		display_set_digit_ascii(i, str[i]);
	}
	
	//fill missing digits
	for (; i < DISPLAY_NUMSEGMENTS; i++) {
		display_set_digit(i, DISPLAY_VALUE_SPACE);
	}
}

void display_update_base(uint16_t value, uint8_t base) {
	uint16_t val = value;
	for (int i = DISPLAY_NUMSEGMENTS - 1; i >= 0; i--) {
		if (val > 0 || i == DISPLAY_NUMSEGMENTS - 1) {
			display_set_digit(i, val % base);
			val /= base;
		} else {
			display_set_digit(i, DISPLAY_VALUE_SPACE);
		}
	}
}

void display_update(uint16_t value) {
	display_update_base(value, 10);
}

void display_update_hex(uint16_t value) {
	display_update_base(value, 16);
}

void display_render() {
	display_current_segment = (display_current_segment + 1) % (DISPLAY_NUMSEGMENTS * 2);
	uint8_t block;
	gpio_set_pin_level(DISPLAY_SS, false);
	
	block = DISPLAY_SEGMENTS[display_current_segment] >> 8;
	SPI_0_exchange_block(&block, 1);
	
	block = DISPLAY_SEGMENTS[display_current_segment] & 0xFF;
	SPI_0_exchange_block(&block, 1);
	
	block = display_current_digits[display_current_segment];
	SPI_0_exchange_block(&block, 1);
	
	gpio_set_pin_level(DISPLAY_SS, true);
}