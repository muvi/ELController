/*
 * io_util.h
 *
 * Created: 26.06.2022 12:16:21
 *  Author: Christian
 */ 


#ifndef IO_UTIL_H_
#define IO_UTIL_H_

#include <hri_port_d21c.h>

/**
 * \brief Set pin drive strength
 */
static inline void _gpio_set_pin_drive_strength(const enum gpio_port port, const uint8_t pin)
{
	hri_port_set_PINCFG_DRVSTR_bit(PORT, port, pin);
}

/**
 * \brief Set pin drive strength
 */
static inline void gpio_set_pin_drive_strength(const uint8_t pin)
{
	_gpio_set_pin_drive_strength((enum gpio_port)GPIO_PORT(pin), pin & 0x1F);
}

/**
 * \brief Get pin drive strength
 */
static inline bool _gpio_get_pin_drive_strength(const enum gpio_port port, const uint8_t pin)
{
	return hri_port_get_PINCFG_DRVSTR_bit(PORT, port, pin);
}

/**
 * \brief Get pin drive strength
 */
static inline bool gpio_get_pin_drive_strength(const uint8_t pin)
{
	return _gpio_get_pin_drive_strength((enum gpio_port)GPIO_PORT(pin), pin & 0x1F);
}

#endif /* IO_UTIL_H_ */