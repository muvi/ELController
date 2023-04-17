/*
 * Code generated from Atmel Start.
 *
 * This file will be overwritten when reconfiguring your Atmel Start project.
 * Please copy examples or other code you want to keep to a separate file
 * to avoid losing it when reconfiguring.
 */
#ifndef ATMEL_START_PINS_H_INCLUDED
#define ATMEL_START_PINS_H_INCLUDED

#include <hal_gpio.h>

// SAMD21 has 8 pin functions

#define GPIO_PIN_FUNCTION_A 0
#define GPIO_PIN_FUNCTION_B 1
#define GPIO_PIN_FUNCTION_C 2
#define GPIO_PIN_FUNCTION_D 3
#define GPIO_PIN_FUNCTION_E 4
#define GPIO_PIN_FUNCTION_F 5
#define GPIO_PIN_FUNCTION_G 6
#define GPIO_PIN_FUNCTION_H 7

#define PWR_SENSE GPIO(GPIO_PORTA, 2)
#define HV_SENSE GPIO(GPIO_PORTA, 3)
#define CONFIG1 GPIO(GPIO_PORTA, 4)
#define CONFIG2 GPIO(GPIO_PORTA, 5)
#define CONFIG3 GPIO(GPIO_PORTA, 6)
#define HV_SW GPIO(GPIO_PORTA, 7)
#define CH1P GPIO(GPIO_PORTA, 8)
#define CH1N GPIO(GPIO_PORTA, 9)
#define CH2P GPIO(GPIO_PORTA, 10)
#define CH2N GPIO(GPIO_PORTA, 11)
#define CH3P GPIO(GPIO_PORTA, 12)
#define CH3N GPIO(GPIO_PORTA, 13)
#define PWR_GOOD GPIO(GPIO_PORTA, 14)
#define BTN1 GPIO(GPIO_PORTA, 16)
#define BTN2 GPIO(GPIO_PORTA, 17)
#define CH4P GPIO(GPIO_PORTA, 18)
#define CH4N GPIO(GPIO_PORTA, 19)
#define OUTPUT_ENABLE GPIO(GPIO_PORTA, 20)
#define BTN3 GPIO(GPIO_PORTA, 21)
#define DMX_TX GPIO(GPIO_PORTA, 22)
#define DMX_RX GPIO(GPIO_PORTA, 23)
#define LED1 GPIO(GPIO_PORTA, 27)
#define LED2 GPIO(GPIO_PORTA, 28)
#define GPIO1 GPIO(GPIO_PORTB, 0)
#define GPIO2 GPIO(GPIO_PORTB, 1)
#define CH5P GPIO(GPIO_PORTB, 2)
#define CH5N GPIO(GPIO_PORTB, 3)
#define CH6P GPIO(GPIO_PORTB, 8)
#define CH6N GPIO(GPIO_PORTB, 9)
#define CH7P GPIO(GPIO_PORTB, 10)
#define CH7N GPIO(GPIO_PORTB, 11)
#define DISPLAY_MOSI GPIO(GPIO_PORTB, 12)
#define DISPLAY_SCK GPIO(GPIO_PORTB, 13)
#define DISPLAY_SS GPIO(GPIO_PORTB, 14)
#define DISPLAY_MISO GPIO(GPIO_PORTB, 15)
#define GPIO10 GPIO(GPIO_PORTB, 17)
#define CH8P GPIO(GPIO_PORTB, 22)
#define CH8N GPIO(GPIO_PORTB, 23)
#define GPIO11 GPIO(GPIO_PORTB, 30)

#endif // ATMEL_START_PINS_H_INCLUDED
