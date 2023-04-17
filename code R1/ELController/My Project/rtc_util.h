/*
 * rtc_util.h
 *
 * Created: 11/1/2022 5:14:40 PM
 *  Author: Christian
 */ 


#ifndef RTC_UTIL_H_
#define RTC_UTIL_H_


static inline void hri_rtcmode0_set_CTRL_ENABLE_bit_no_lock(const void *const hw)
{
	((Rtc *)hw)->MODE0.CTRL.reg |= RTC_MODE0_CTRL_ENABLE;
}

static inline void hri_rtcmode0_clear_CTRL_ENABLE_bit_no_lock(const void *const hw)
{
	((Rtc *)hw)->MODE0.CTRL.reg &= ~RTC_MODE0_CTRL_ENABLE;
}

static inline void hri_rtcmode0_write_COUNT_reg_no_lock(const void *const hw, hri_rtcmode0_count_reg_t data)
{
	((Rtc *)hw)->MODE0.COUNT.reg = data;
}


#endif /* RTC_UTIL_H_ */