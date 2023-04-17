/*
 * tc_util.h
 *
 * Created: 10/30/2022 3:03:55 PM
 *  Author: Christian
 */ 


#ifndef TC_UTIL_H_
#define TC_UTIL_H_

static inline void hri_tccount8_write_CC_reg_no_lock(const void *const hw, uint8_t index, hri_tccount8_cc_reg_t data)
{
	((Tc *)hw)->COUNT8.CC[index].reg = data;
}

#endif /* TC_UTIL_H_ */