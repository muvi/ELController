/*
 * tcc_util.h
 *
 * Created: 17.08.2022 19:25:26
 *  Author: Christian
 */ 


#ifndef TCC_UTIL_H_
#define TCC_UTIL_H_

static inline void hri_tcc_write_CCB_reg_no_lock(const void *const hw, uint8_t index, hri_tcc_ccb_reg_t data)
{
	((Tcc *)hw)->CCB[index].reg = data;
}

static inline void hri_tcc_write_PERB_reg_no_lock(const void *const hw, hri_tcc_perb_reg_t data)
{
	((Tcc *)hw)->PERB.reg = data;
}

#endif /* TCC_UTIL_H_ */