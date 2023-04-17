
/**
 * \file
 *
 * \brief RTC related functionality implementation.
 *
 * Copyright (c) 2017 Microchip Technology Inc. and its subsidiaries.
 *
 * \asf_license_start
 *
 * \page License
 *
 * Subject to your compliance with these terms, you may use Microchip
 * software and any derivatives exclusively with Microchip products.
 * It is your responsibility to comply with third party license terms applicable
 * to your use of third party software (including open source software) that
 * may accompany Microchip software.
 *
 * THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES,
 * WHETHER EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE,
 * INCLUDING ANY IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY,
 * AND FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT WILL MICROCHIP BE
 * LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, INCIDENTAL OR CONSEQUENTIAL
 * LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND WHATSOEVER RELATED TO THE
 * SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS BEEN ADVISED OF THE
 * POSSIBILITY OR THE DAMAGES ARE FORESEEABLE.  TO THE FULLEST EXTENT
 * ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN ANY WAY
 * RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
 * THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
 *
 * \asf_license_stop
 *
 */

#include "rtc_lite.h"

#define hri_rtcmode0_wait_for_sync(a) hri_rtc_wait_for_sync(a)
#define hri_rtcmode0_write_READREQ_reg(a, b) hri_rtc_write_READREQ_reg(a, b)

/**
 * \brief Initialize RTC interface
 */
int8_t TIMER_8_init()
{

	hri_rtcmode0_wait_for_sync(RTC);
	if (hri_rtcmode0_get_CTRL_ENABLE_bit(RTC)) {
		hri_rtcmode0_clear_CTRL_ENABLE_bit(RTC);
		hri_rtcmode0_wait_for_sync(RTC);
	}
	hri_rtcmode0_set_CTRL_SWRST_bit(RTC);
	hri_rtcmode0_wait_for_sync(RTC);

	// hri_rtcmode0_write_CTRL_reg(RTC,0 << RTC_MODE0_CTRL_PRESCALER_Pos /* Setting: 0 */
	//		 | 0 << RTC_MODE0_CTRL_MATCHCLR_Pos /* Clear on Match: disabled */
	//		 | 0x0 << RTC_MODE0_CTRL_MODE_Pos); /* Operating Mode: 0x0 */

	hri_rtcmode0_write_READREQ_reg(RTC,
	                               0 << RTC_READREQ_RREQ_Pos          /*  Read Request: disabled */
	                                   | 1 << RTC_READREQ_RCONT_Pos); /*  Read Request: enabled */

	// hri_rtcmode0_write_DBGCTRL_reg(RTC,0); /* Run in debug: 0 */

	// hri_rtcmode0_write_FREQCORR_reg(RTC,0 << RTC_FREQCORR_SIGN_Pos /* Correction Sign: disabled */
	//		 | 0x0); /* Correction Value: 0x0 */

	// hri_rtcmode0_write_COUNT_reg(RTC,0x0); /* Counter Value: 0x0 */

	hri_rtcmode0_write_COMP_reg(RTC, 0, 0xf00); /* Compare Value: 0xf00 */

	// hri_rtcmode0_write_EVCTRL_reg(RTC,0 << RTC_MODE0_EVCTRL_OVFEO_Pos /* Overflow Event Output Enable: disabled */
	//		 | 0 << RTC_MODE0_EVCTRL_PEREO0_Pos /* Periodic Interval 0 Event Output Enable: disabled */
	//		 | 0 << RTC_MODE0_EVCTRL_PEREO1_Pos /* Periodic Interval 1 Event Output Enable: disabled */
	//		 | 0 << RTC_MODE0_EVCTRL_PEREO2_Pos /* Periodic Interval 2 Event Output Enable: disabled */
	//		 | 0 << RTC_MODE0_EVCTRL_PEREO3_Pos /* Periodic Interval 3 Event Output Enable: disabled */
	//		 | 0 << RTC_MODE0_EVCTRL_PEREO4_Pos /* Periodic Interval 4 Event Output Enable: disabled */
	//		 | 0 << RTC_MODE0_EVCTRL_PEREO5_Pos /* Periodic Interval 5 Event Output Enable: disabled */
	//		 | 0 << RTC_MODE0_EVCTRL_PEREO6_Pos /* Periodic Interval 6 Event Output Enable: disabled */
	//		 | 0 << RTC_MODE0_EVCTRL_PEREO7_Pos /* Periodic Interval 7 Event Output Enable: disabled */
	//		 | 0 << RTC_MODE0_EVCTRL_CMPEO_Pos); /* Compare 0 Event Output Enable: disabled */

	hri_rtcmode0_write_INTEN_reg(
	    RTC,
	    1 << RTC_MODE0_INTENSET_CMP_Pos           /* Compare 0 Interrupt Enable: enabled */
	        | 0 << RTC_MODE0_INTENSET_SYNCRDY_Pos /* Synchronization Ready Interrupt Enable: disabled */
	        | 0 << RTC_MODE0_INTENSET_OVF_Pos);   /* Overflow Interrupt enable: disabled */

	// hri_rtcmode0_write_CTRL_ENABLE_bit(RTC,0 << RTC_MODE0_CTRL_ENABLE_Pos); /* Enable: disabled */

	return 0;
}
