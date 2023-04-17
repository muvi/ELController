/*
 * dac_util.h
 *
 * Created: 11/1/2022 7:46:03 PM
 *  Author: Christian
 */ 


#ifndef DAC_UTIL_H_
#define DAC_UTIL_H_

static inline void hri_dac_write_DATA_reg_no_lock(const void *const hw, hri_dac_data_reg_t data)
{
	((Dac *)hw)->DATA.reg = data;
}

#endif /* DAC_UTIL_H_ */