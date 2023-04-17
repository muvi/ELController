/*
 * dmx.c
 *
 * Created: 28.06.2022 20:41:10
 *  Author: Christian
 */ 
#include <dmx.h>


volatile unsigned short dmxNextAddress = 1;
volatile unsigned short dmxNextAddress2 = 1;
unsigned short dmxStartAddress = 1;
unsigned short currentChannel = 0;

void SERCOM3_Handler() {
	gpio_toggle_pin_level(LED1);
	if (hri_sercomusart_get_interrupt_ERROR_bit(SERCOM3)) {
		hri_sercomusart_clear_interrupt_ERROR_bit(SERCOM3);
		hri_sercomusart_clear_STATUS_reg(SERCOM3, SERCOM_USART_STATUS_MASK);
		hri_sercomusart_read_DATA_reg(SERCOM3);
		currentChannel = 0;
		unsigned short newAddress = dmxNextAddress;
		if (newAddress == dmxNextAddress2) {
			dmxStartAddress = newAddress;
		}
	} else if (hri_sercomusart_get_interrupt_RXC_bit(SERCOM3)) {
		hri_sercomusart_clear_interrupt_RXC_bit(SERCOM3);
		if (hri_sercomusart_read_STATUS_reg(SERCOM3) & (SERCOM_USART_STATUS_PERR | SERCOM_USART_STATUS_FERR | SERCOM_USART_STATUS_BUFOVF | SERCOM_USART_STATUS_ISF | SERCOM_USART_STATUS_COLL)) {
			hri_sercomusart_clear_STATUS_reg(SERCOM3, SERCOM_USART_STATUS_MASK);
			hri_sercomusart_read_DATA_reg(SERCOM3);
			return;
		}
		uint8_t dmx_value = hri_sercomusart_read_DATA_reg(SERCOM3);
		
		if (currentChannel >= dmxStartAddress) {
			if (currentChannel < dmxStartAddress + DMX_CHANNELS) {
				//relevant DMX data is currently being sent
				dmx[currentChannel - dmxStartAddress] = dmx_value;
			}
		}
		if (currentChannel == dmxStartAddress + DMX_CHANNELS - 1) {
			dmx_received();
		}
		currentChannel++;
	}
}

void dmx_set_address(unsigned short address) {
	dmxNextAddress = address;
	dmxNextAddress2 = address;
}

void dmx_init() {
	NVIC_DisableIRQ(SERCOM3_IRQn);
	NVIC_ClearPendingIRQ(SERCOM3_IRQn);
	NVIC_SetPriority(SERCOM3_IRQn, INTERRUPT_PRIORITY_MEDIUM);
	NVIC_EnableIRQ(SERCOM3_IRQn);
}