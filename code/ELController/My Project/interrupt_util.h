/*
 * interrupt_util.h
 *
 * Created: 16.08.2022 23:08:04
 *  Author: Christian
 */ 


#ifndef INTERRUPT_UTIL_H_
#define INTERRUPT_UTIL_H_


#define INTERRUPT_PRIORITY_IDLE 0b11
#define INTERRUPT_PRIORITY_LOW 0b10
#define INTERRUPT_PRIORITY_MEDIUM 0b01
#define INTERRUPT_PRIORITY_HIGH 0b00


/**
 * \brief Retrieve ordinal number of the given sercom hardware instance
 */
static inline uint8_t _sercom_get_hardware_index(const void *const hw)
{
#ifdef _UNIT_TEST_
	return ((uint32_t)hw - (uint32_t)SERCOM0) / sizeof(Sercom);
#endif

	return ((uint32_t)hw - (uint32_t)SERCOM0) >> 10;
}

static inline uint8_t sercom_get_irq_num(const void *const hw)
{
	return SERCOM0_IRQn + _sercom_get_hardware_index(hw);
}

#endif /* INTERRUPT_UTIL_H_ */