
/**
 * \file
 *
 * \brief TCC related functionality implementation.
 *
 * Copyright (c) 2017 - 2019 Microchip Technology Inc. and its subsidiaries.
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

#include "tcc_lite.h"

/**
 * \brief Initialize TCC interface
 */
int8_t TIMER_1_init()
{

	if (!hri_tcc_is_syncing(TCC0, TCC_SYNCBUSY_SWRST)) {
		if (hri_tcc_get_CTRLA_reg(TCC0, TCC_CTRLA_ENABLE)) {
			hri_tcc_clear_CTRLA_ENABLE_bit(TCC0);
			hri_tcc_wait_for_sync(TCC0, TCC_SYNCBUSY_ENABLE);
		}
		hri_tcc_write_CTRLA_reg(TCC0, TCC_CTRLA_SWRST);
	}
	hri_tcc_wait_for_sync(TCC0, TCC_SYNCBUSY_SWRST);

	hri_tcc_write_CTRLA_reg(TCC0,
	                        0 << TCC_CTRLA_ALOCK_Pos             /* Auto Lock: disabled */
	                            | 0 << TCC_CTRLA_PRESCSYNC_Pos   /* Prescaler and Counter Synchronization: 0 */
	                            | 0 << TCC_CTRLA_RUNSTDBY_Pos    /* Run in Standby: disabled */
	                            | 3 << TCC_CTRLA_PRESCALER_Pos); /* Setting: 3 */

	// hri_tcc_write_CTRLB_reg(TCC0,0 << TCC_CTRLBSET_CMD_Pos /* TCC Command: 0 */
	//		 | 0 << TCC_CTRLBSET_IDXCMD_Pos /* Ramp Index Command: 0 */
	//		 | 0 << TCC_CTRLBSET_ONESHOT_Pos /* One-Shot: disabled */
	//		 | 0 << TCC_CTRLBSET_LUPD_Pos /* Lock Update: disabled */
	//		 | 0 << TCC_CTRLBSET_DIR_Pos); /* Counter Direction: disabled */

	// hri_tcc_write_FCTRLA_reg(TCC0,0x0 << TCC_FCTRLA_FILTERVAL_Pos /* Fault A Filter Value: 0x0 */
	//		 | 0 << TCC_FCTRLA_CHSEL_Pos /* Fault A Capture Channel: 0 */
	//		 | 0 << TCC_FCTRLA_HALT_Pos /* Fault A Halt Mode: 0 */
	//		 | 0 << TCC_FCTRLA_RESTART_Pos /* Fault A Restart: disabled */
	//		 | 0 << TCC_FCTRLA_BLANK_Pos /* Fault A Blanking Mode: 0 */
	//		 | 0 << TCC_FCTRLA_QUAL_Pos /* Fault A Qualification: disabled */
	//		 | 0 << TCC_FCTRLA_KEEP_Pos /* Fault A Keeper: disabled */
	//		 | 0); /* Fault A Source: 0 */

	// hri_tcc_write_FCTRLB_reg(TCC0,0x0 << TCC_FCTRLB_FILTERVAL_Pos /* Fault B Filter Value: 0x0 */
	//		 | 0 << TCC_FCTRLB_CHSEL_Pos /* Fault B Capture Channel: 0 */
	//		 | 0 << TCC_FCTRLB_HALT_Pos /* Fault B Halt Mode: 0 */
	//		 | 0 << TCC_FCTRLB_RESTART_Pos /* Fault B Restart: disabled */
	//		 | 0 << TCC_FCTRLB_BLANK_Pos /* Fault B Blanking Mode: 0 */
	//		 | 0 << TCC_FCTRLB_QUAL_Pos /* Fault B Qualification: disabled */
	//		 | 0 << TCC_FCTRLB_KEEP_Pos /* Fault B Keeper: disabled */
	//		 | 0); /* Fault B Source: 0 */

	// hri_tcc_write_DRVCTRL_reg(TCC0,0x0 << TCC_DRVCTRL_FILTERVAL1_Pos /* Non-Recoverable Fault Input 1 Filter Value:
	// 0x0 */
	//		 | 0x0 << TCC_DRVCTRL_FILTERVAL0_Pos /* Non-Recoverable Fault Input 0 Filter Value: 0x0 */
	//		 | 0 << TCC_DRVCTRL_NRV7_Pos /* Non-Recoverable State 7 Output Value: disabled */
	//		 | 0 << TCC_DRVCTRL_NRV6_Pos /* Non-Recoverable State 6 Output Value: disabled */
	//		 | 0 << TCC_DRVCTRL_NRV5_Pos /* Non-Recoverable State 5 Output Value: disabled */
	//		 | 0 << TCC_DRVCTRL_NRV4_Pos /* Non-Recoverable State 4 Output Value: disabled */
	//		 | 0 << TCC_DRVCTRL_NRV3_Pos /* Non-Recoverable State 3 Output Value: disabled */
	//		 | 0 << TCC_DRVCTRL_NRV2_Pos /* Non-Recoverable State 2 Output Value: disabled */
	//		 | 0 << TCC_DRVCTRL_NRV1_Pos /* Non-Recoverable State 1 Output Value: disabled */
	//		 | 0 << TCC_DRVCTRL_NRV0_Pos /* Non-Recoverable State 0 Output Value: disabled */
	//		 | 0 << TCC_DRVCTRL_NRE7_Pos /* Non-Recoverable State 7 Output Enable: disabled */
	//		 | 0 << TCC_DRVCTRL_NRE6_Pos /* Non-Recoverable State 6 Output Enable: disabled */
	//		 | 0 << TCC_DRVCTRL_NRE5_Pos /* Non-Recoverable State 5 Output Enable: disabled */
	//		 | 0 << TCC_DRVCTRL_NRE4_Pos /* Non-Recoverable State 4 Output Enable: disabled */
	//		 | 0 << TCC_DRVCTRL_NRE3_Pos /* Non-Recoverable State 3 Output Enable: disabled */
	//		 | 0 << TCC_DRVCTRL_NRE2_Pos /* Non-Recoverable State 2 Output Enable: disabled */
	//		 | 0 << TCC_DRVCTRL_NRE1_Pos /* Non-Recoverable State 1 Output Enable: disabled */
	//		 | 0 << TCC_DRVCTRL_NRE0_Pos); /* Non-Recoverable State 0 Output Enable: disabled */

	// hri_tcc_write_DBGCTRL_reg(TCC0,0 << TCC_DBGCTRL_FDDBD_Pos /* Fault Detection on Debug Break Detection: disabled
	// */
	//		 | 0); /* Run in debug: 0 */

	hri_tcc_write_CC_reg(TCC0, 0, 0x7f); /* Channel 0 Compare/Capture Value: 0x7f */

	hri_tcc_write_CC_reg(TCC0, 1, 0x7f); /* Channel 1 Compare/Capture Value: 0x7f */

	hri_tcc_write_CC_reg(TCC0, 2, 0x7f); /* Channel 2 Compare/Capture Value: 0x7f */

	hri_tcc_write_CC_reg(TCC0, 3, 0x7f); /* Channel 3 Compare/Capture Value: 0x7f */

	// hri_tcc_write_COUNT_reg(TCC0,0x0); /* Counter Value: 0x0 */

	hri_tcc_write_PER_reg(TCC0, 0xfe); /*  Period Value: 0xfe */

	// hri_tcc_write_EVCTRL_reg(TCC0,0 << TCC_EVCTRL_MCEO3_Pos /* Match or Capture Channel 3 Event Output Enable:
	// disabled */
	//		 | 0 << TCC_EVCTRL_MCEO2_Pos /* Match or Capture Channel 2 Event Output Enable: disabled */
	//		 | 0 << TCC_EVCTRL_MCEO1_Pos /* Match or Capture Channel 1 Event Output Enable: disabled */
	//		 | 0 << TCC_EVCTRL_MCEO0_Pos /* Match or Capture Channel 0 Event Output Enable: disabled */
	//		 | 0 << TCC_EVCTRL_MCEI3_Pos /* Match or Capture Channel 3 Event Input Enable: disabled */
	//		 | 0 << TCC_EVCTRL_MCEI2_Pos /* Match or Capture Channel 2 Event Input Enable: disabled */
	//		 | 0 << TCC_EVCTRL_MCEI1_Pos /* Match or Capture Channel 1 Event Input Enable: disabled */
	//		 | 0 << TCC_EVCTRL_MCEI0_Pos /* Match or Capture Channel 0 Event Input Enable: disabled */
	//		 | 0 << TCC_EVCTRL_TCEI1_Pos /* Timer/counter 1 Event Input Enable: disabled */
	//		 | 0 << TCC_EVCTRL_TCEI0_Pos /* Timer/counter 0 Event Input Enable: disabled */
	//		 | 0 << TCC_EVCTRL_TCINV1_Pos /* Inverted Event 1 Event Input Enable: disabled */
	//		 | 0 << TCC_EVCTRL_TCINV0_Pos /* Inverted Event 0 Event Input Enable: disabled */
	//		 | 0 << TCC_EVCTRL_CNTEO_Pos /* Timer/counter Output Event Enable: disabled */
	//		 | 0 << TCC_EVCTRL_TRGEO_Pos /* Retrigger Output Event Enable: disabled */
	//		 | 0 << TCC_EVCTRL_OVFEO_Pos /* Overflow/Underflow Event Output Enable: disabled */
	//		 | 0 << TCC_EVCTRL_CNTSEL_Pos /* Timer/counter Output Event Mode: 0 */
	//		 | 0 << TCC_EVCTRL_EVACT1_Pos /* Event 1 Action: 0 */
	//		 | 0); /* Event 0 Action: 0 */

	hri_tcc_write_INTEN_reg(TCC0,
	                        0 << TCC_INTENSET_MC3_Pos       /* Match or Capture Channel 3 Interrupt Enable: disabled */
	                            | 0 << TCC_INTENSET_MC2_Pos /* Match or Capture Channel 2 Interrupt Enable: disabled */
	                            | 0 << TCC_INTENSET_MC1_Pos /* Match or Capture Channel 1 Interrupt Enable: disabled */
	                            | 0 << TCC_INTENSET_MC0_Pos /* Match or Capture Channel 0 Interrupt Enable: disabled */
	                            | 0 << TCC_INTENSET_FAULT1_Pos /* Non-Recoverable Fault 1 Interrupt Enable: disabled */
	                            | 0 << TCC_INTENSET_FAULT0_Pos /* Non-Recoverable Fault 0 Interrupt Enable: disabled */
	                            | 0 << TCC_INTENSET_FAULTB_Pos /* Recoverable Fault B Interrupt Enable: disabled */
	                            | 0 << TCC_INTENSET_FAULTA_Pos /* Recoverable Fault A Interrupt Enable: disabled */
	                            | 0 << TCC_INTENSET_DFS_Pos /* Non-Recoverable Debug Fault Interrupt Enable: disabled */
	                            | 0 << TCC_INTENSET_ERR_Pos /* Error Interrupt Enable: disabled */
	                            | 0 << TCC_INTENSET_CNT_Pos /* Counter Interrupt Enable: disabled */
	                            | 0 << TCC_INTENSET_TRG_Pos /* Retrigger Interrupt Enable: disabled */
	                            | 1 << TCC_INTENSET_OVF_Pos); /* Overflow Interrupt enable: enabled */

	hri_tcc_write_CTRLA_ENABLE_bit(TCC0, 1 << TCC_CTRLA_ENABLE_Pos); /* Enable: enabled */

	return 0;
}

/**
 * \brief Initialize TCC interface
 */
int8_t TIMER_0_init()
{

	if (!hri_tcc_is_syncing(TCC1, TCC_SYNCBUSY_SWRST)) {
		if (hri_tcc_get_CTRLA_reg(TCC1, TCC_CTRLA_ENABLE)) {
			hri_tcc_clear_CTRLA_ENABLE_bit(TCC1);
			hri_tcc_wait_for_sync(TCC1, TCC_SYNCBUSY_ENABLE);
		}
		hri_tcc_write_CTRLA_reg(TCC1, TCC_CTRLA_SWRST);
	}
	hri_tcc_wait_for_sync(TCC1, TCC_SYNCBUSY_SWRST);

	// hri_tcc_write_CTRLA_reg(TCC1,0 << TCC_CTRLA_ALOCK_Pos /* Auto Lock: disabled */
	//		 | 0 << TCC_CTRLA_PRESCSYNC_Pos /* Prescaler and Counter Synchronization: 0 */
	//		 | 0 << TCC_CTRLA_RUNSTDBY_Pos /* Run in Standby: disabled */
	//		 | 0 << TCC_CTRLA_PRESCALER_Pos); /* Setting: 0 */

	// hri_tcc_write_CTRLB_reg(TCC1,0 << TCC_CTRLBSET_CMD_Pos /* TCC Command: 0 */
	//		 | 0 << TCC_CTRLBSET_IDXCMD_Pos /* Ramp Index Command: 0 */
	//		 | 0 << TCC_CTRLBSET_ONESHOT_Pos /* One-Shot: disabled */
	//		 | 0 << TCC_CTRLBSET_LUPD_Pos /* Lock Update: disabled */
	//		 | 0 << TCC_CTRLBSET_DIR_Pos); /* Counter Direction: disabled */

	// hri_tcc_write_FCTRLA_reg(TCC1,0x0 << TCC_FCTRLA_FILTERVAL_Pos /* Fault A Filter Value: 0x0 */
	//		 | 0 << TCC_FCTRLA_CHSEL_Pos /* Fault A Capture Channel: 0 */
	//		 | 0 << TCC_FCTRLA_HALT_Pos /* Fault A Halt Mode: 0 */
	//		 | 0 << TCC_FCTRLA_RESTART_Pos /* Fault A Restart: disabled */
	//		 | 0 << TCC_FCTRLA_BLANK_Pos /* Fault A Blanking Mode: 0 */
	//		 | 0 << TCC_FCTRLA_QUAL_Pos /* Fault A Qualification: disabled */
	//		 | 0 << TCC_FCTRLA_KEEP_Pos /* Fault A Keeper: disabled */
	//		 | 0); /* Fault A Source: 0 */

	// hri_tcc_write_FCTRLB_reg(TCC1,0x0 << TCC_FCTRLB_FILTERVAL_Pos /* Fault B Filter Value: 0x0 */
	//		 | 0 << TCC_FCTRLB_CHSEL_Pos /* Fault B Capture Channel: 0 */
	//		 | 0 << TCC_FCTRLB_HALT_Pos /* Fault B Halt Mode: 0 */
	//		 | 0 << TCC_FCTRLB_RESTART_Pos /* Fault B Restart: disabled */
	//		 | 0 << TCC_FCTRLB_BLANK_Pos /* Fault B Blanking Mode: 0 */
	//		 | 0 << TCC_FCTRLB_QUAL_Pos /* Fault B Qualification: disabled */
	//		 | 0 << TCC_FCTRLB_KEEP_Pos /* Fault B Keeper: disabled */
	//		 | 0); /* Fault B Source: 0 */

	// hri_tcc_write_DRVCTRL_reg(TCC1,0x0 << TCC_DRVCTRL_FILTERVAL1_Pos /* Non-Recoverable Fault Input 1 Filter Value:
	// 0x0 */
	//		 | 0x0 << TCC_DRVCTRL_FILTERVAL0_Pos /* Non-Recoverable Fault Input 0 Filter Value: 0x0 */
	//		 | 0 << TCC_DRVCTRL_NRV7_Pos /* Non-Recoverable State 7 Output Value: disabled */
	//		 | 0 << TCC_DRVCTRL_NRV6_Pos /* Non-Recoverable State 6 Output Value: disabled */
	//		 | 0 << TCC_DRVCTRL_NRV5_Pos /* Non-Recoverable State 5 Output Value: disabled */
	//		 | 0 << TCC_DRVCTRL_NRV4_Pos /* Non-Recoverable State 4 Output Value: disabled */
	//		 | 0 << TCC_DRVCTRL_NRV3_Pos /* Non-Recoverable State 3 Output Value: disabled */
	//		 | 0 << TCC_DRVCTRL_NRV2_Pos /* Non-Recoverable State 2 Output Value: disabled */
	//		 | 0 << TCC_DRVCTRL_NRV1_Pos /* Non-Recoverable State 1 Output Value: disabled */
	//		 | 0 << TCC_DRVCTRL_NRV0_Pos /* Non-Recoverable State 0 Output Value: disabled */
	//		 | 0 << TCC_DRVCTRL_NRE7_Pos /* Non-Recoverable State 7 Output Enable: disabled */
	//		 | 0 << TCC_DRVCTRL_NRE6_Pos /* Non-Recoverable State 6 Output Enable: disabled */
	//		 | 0 << TCC_DRVCTRL_NRE5_Pos /* Non-Recoverable State 5 Output Enable: disabled */
	//		 | 0 << TCC_DRVCTRL_NRE4_Pos /* Non-Recoverable State 4 Output Enable: disabled */
	//		 | 0 << TCC_DRVCTRL_NRE3_Pos /* Non-Recoverable State 3 Output Enable: disabled */
	//		 | 0 << TCC_DRVCTRL_NRE2_Pos /* Non-Recoverable State 2 Output Enable: disabled */
	//		 | 0 << TCC_DRVCTRL_NRE1_Pos /* Non-Recoverable State 1 Output Enable: disabled */
	//		 | 0 << TCC_DRVCTRL_NRE0_Pos); /* Non-Recoverable State 0 Output Enable: disabled */

	// hri_tcc_write_DBGCTRL_reg(TCC1,0 << TCC_DBGCTRL_FDDBD_Pos /* Fault Detection on Debug Break Detection: disabled
	// */
	//		 | 0); /* Run in debug: 0 */

	// hri_tcc_write_CC_reg(TCC1, 0 ,0x0); /* Channel 0 Compare/Capture Value: 0x0 */

	// hri_tcc_write_CC_reg(TCC1, 1 ,0x0); /* Channel 1 Compare/Capture Value: 0x0 */

	// hri_tcc_write_COUNT_reg(TCC1,0x0); /* Counter Value: 0x0 */

	hri_tcc_write_PER_reg(TCC1, 0xffff); /*  Period Value: 0xffff */

	hri_tcc_write_EVCTRL_reg(
	    TCC1,
	    0 << TCC_EVCTRL_MCEO3_Pos        /* Match or Capture Channel 3 Event Output Enable: disabled */
	        | 0 << TCC_EVCTRL_MCEO2_Pos  /* Match or Capture Channel 2 Event Output Enable: disabled */
	        | 0 << TCC_EVCTRL_MCEO1_Pos  /* Match or Capture Channel 1 Event Output Enable: disabled */
	        | 1 << TCC_EVCTRL_MCEO0_Pos  /* Match or Capture Channel 0 Event Output Enable: enabled */
	        | 0 << TCC_EVCTRL_MCEI3_Pos  /* Match or Capture Channel 3 Event Input Enable: disabled */
	        | 0 << TCC_EVCTRL_MCEI2_Pos  /* Match or Capture Channel 2 Event Input Enable: disabled */
	        | 0 << TCC_EVCTRL_MCEI1_Pos  /* Match or Capture Channel 1 Event Input Enable: disabled */
	        | 0 << TCC_EVCTRL_MCEI0_Pos  /* Match or Capture Channel 0 Event Input Enable: disabled */
	        | 0 << TCC_EVCTRL_TCEI1_Pos  /* Timer/counter 1 Event Input Enable: disabled */
	        | 0 << TCC_EVCTRL_TCEI0_Pos  /* Timer/counter 0 Event Input Enable: disabled */
	        | 0 << TCC_EVCTRL_TCINV1_Pos /* Inverted Event 1 Event Input Enable: disabled */
	        | 0 << TCC_EVCTRL_TCINV0_Pos /* Inverted Event 0 Event Input Enable: disabled */
	        | 0 << TCC_EVCTRL_CNTEO_Pos  /* Timer/counter Output Event Enable: disabled */
	        | 0 << TCC_EVCTRL_TRGEO_Pos  /* Retrigger Output Event Enable: disabled */
	        | 0 << TCC_EVCTRL_OVFEO_Pos  /* Overflow/Underflow Event Output Enable: disabled */
	        | 0 << TCC_EVCTRL_CNTSEL_Pos /* Timer/counter Output Event Mode: 0 */
	        | 0 << TCC_EVCTRL_EVACT1_Pos /* Event 1 Action: 0 */
	        | 0);                        /* Event 0 Action: 0 */

	hri_tcc_write_INTEN_reg(TCC1,
	                        0 << TCC_INTENSET_MC3_Pos       /* Match or Capture Channel 3 Interrupt Enable: disabled */
	                            | 0 << TCC_INTENSET_MC2_Pos /* Match or Capture Channel 2 Interrupt Enable: disabled */
	                            | 0 << TCC_INTENSET_MC1_Pos /* Match or Capture Channel 1 Interrupt Enable: disabled */
	                            | 0 << TCC_INTENSET_MC0_Pos /* Match or Capture Channel 0 Interrupt Enable: disabled */
	                            | 0 << TCC_INTENSET_FAULT1_Pos /* Non-Recoverable Fault 1 Interrupt Enable: disabled */
	                            | 0 << TCC_INTENSET_FAULT0_Pos /* Non-Recoverable Fault 0 Interrupt Enable: disabled */
	                            | 0 << TCC_INTENSET_FAULTB_Pos /* Recoverable Fault B Interrupt Enable: disabled */
	                            | 0 << TCC_INTENSET_FAULTA_Pos /* Recoverable Fault A Interrupt Enable: disabled */
	                            | 0 << TCC_INTENSET_DFS_Pos /* Non-Recoverable Debug Fault Interrupt Enable: disabled */
	                            | 0 << TCC_INTENSET_ERR_Pos /* Error Interrupt Enable: disabled */
	                            | 0 << TCC_INTENSET_CNT_Pos /* Counter Interrupt Enable: disabled */
	                            | 0 << TCC_INTENSET_TRG_Pos /* Retrigger Interrupt Enable: disabled */
	                            | 1 << TCC_INTENSET_OVF_Pos); /* Overflow Interrupt enable: enabled */

	hri_tcc_write_CTRLA_ENABLE_bit(TCC1, 1 << TCC_CTRLA_ENABLE_Pos); /* Enable: enabled */

	return 0;
}

/**
 * \brief Initialize TCC interface
 */
int8_t TIMER_2_init()
{

	if (!hri_tcc_is_syncing(TCC2, TCC_SYNCBUSY_SWRST)) {
		if (hri_tcc_get_CTRLA_reg(TCC2, TCC_CTRLA_ENABLE)) {
			hri_tcc_clear_CTRLA_ENABLE_bit(TCC2);
			hri_tcc_wait_for_sync(TCC2, TCC_SYNCBUSY_ENABLE);
		}
		hri_tcc_write_CTRLA_reg(TCC2, TCC_CTRLA_SWRST);
	}
	hri_tcc_wait_for_sync(TCC2, TCC_SYNCBUSY_SWRST);

	hri_tcc_write_CTRLA_reg(TCC2,
	                        0 << TCC_CTRLA_ALOCK_Pos             /* Auto Lock: disabled */
	                            | 0 << TCC_CTRLA_PRESCSYNC_Pos   /* Prescaler and Counter Synchronization: 0 */
	                            | 0 << TCC_CTRLA_RUNSTDBY_Pos    /* Run in Standby: disabled */
	                            | 3 << TCC_CTRLA_PRESCALER_Pos); /* Setting: 3 */

	// hri_tcc_write_CTRLB_reg(TCC2,0 << TCC_CTRLBSET_CMD_Pos /* TCC Command: 0 */
	//		 | 0 << TCC_CTRLBSET_IDXCMD_Pos /* Ramp Index Command: 0 */
	//		 | 0 << TCC_CTRLBSET_ONESHOT_Pos /* One-Shot: disabled */
	//		 | 0 << TCC_CTRLBSET_LUPD_Pos /* Lock Update: disabled */
	//		 | 0 << TCC_CTRLBSET_DIR_Pos); /* Counter Direction: disabled */

	// hri_tcc_write_FCTRLA_reg(TCC2,0x0 << TCC_FCTRLA_FILTERVAL_Pos /* Fault A Filter Value: 0x0 */
	//		 | 0 << TCC_FCTRLA_CHSEL_Pos /* Fault A Capture Channel: 0 */
	//		 | 0 << TCC_FCTRLA_HALT_Pos /* Fault A Halt Mode: 0 */
	//		 | 0 << TCC_FCTRLA_RESTART_Pos /* Fault A Restart: disabled */
	//		 | 0 << TCC_FCTRLA_BLANK_Pos /* Fault A Blanking Mode: 0 */
	//		 | 0 << TCC_FCTRLA_QUAL_Pos /* Fault A Qualification: disabled */
	//		 | 0 << TCC_FCTRLA_KEEP_Pos /* Fault A Keeper: disabled */
	//		 | 0); /* Fault A Source: 0 */

	// hri_tcc_write_FCTRLB_reg(TCC2,0x0 << TCC_FCTRLB_FILTERVAL_Pos /* Fault B Filter Value: 0x0 */
	//		 | 0 << TCC_FCTRLB_CHSEL_Pos /* Fault B Capture Channel: 0 */
	//		 | 0 << TCC_FCTRLB_HALT_Pos /* Fault B Halt Mode: 0 */
	//		 | 0 << TCC_FCTRLB_RESTART_Pos /* Fault B Restart: disabled */
	//		 | 0 << TCC_FCTRLB_BLANK_Pos /* Fault B Blanking Mode: 0 */
	//		 | 0 << TCC_FCTRLB_QUAL_Pos /* Fault B Qualification: disabled */
	//		 | 0 << TCC_FCTRLB_KEEP_Pos /* Fault B Keeper: disabled */
	//		 | 0); /* Fault B Source: 0 */

	// hri_tcc_write_DRVCTRL_reg(TCC2,0x0 << TCC_DRVCTRL_FILTERVAL1_Pos /* Non-Recoverable Fault Input 1 Filter Value:
	// 0x0 */
	//		 | 0x0 << TCC_DRVCTRL_FILTERVAL0_Pos /* Non-Recoverable Fault Input 0 Filter Value: 0x0 */
	//		 | 0 << TCC_DRVCTRL_NRV7_Pos /* Non-Recoverable State 7 Output Value: disabled */
	//		 | 0 << TCC_DRVCTRL_NRV6_Pos /* Non-Recoverable State 6 Output Value: disabled */
	//		 | 0 << TCC_DRVCTRL_NRV5_Pos /* Non-Recoverable State 5 Output Value: disabled */
	//		 | 0 << TCC_DRVCTRL_NRV4_Pos /* Non-Recoverable State 4 Output Value: disabled */
	//		 | 0 << TCC_DRVCTRL_NRV3_Pos /* Non-Recoverable State 3 Output Value: disabled */
	//		 | 0 << TCC_DRVCTRL_NRV2_Pos /* Non-Recoverable State 2 Output Value: disabled */
	//		 | 0 << TCC_DRVCTRL_NRV1_Pos /* Non-Recoverable State 1 Output Value: disabled */
	//		 | 0 << TCC_DRVCTRL_NRV0_Pos /* Non-Recoverable State 0 Output Value: disabled */
	//		 | 0 << TCC_DRVCTRL_NRE7_Pos /* Non-Recoverable State 7 Output Enable: disabled */
	//		 | 0 << TCC_DRVCTRL_NRE6_Pos /* Non-Recoverable State 6 Output Enable: disabled */
	//		 | 0 << TCC_DRVCTRL_NRE5_Pos /* Non-Recoverable State 5 Output Enable: disabled */
	//		 | 0 << TCC_DRVCTRL_NRE4_Pos /* Non-Recoverable State 4 Output Enable: disabled */
	//		 | 0 << TCC_DRVCTRL_NRE3_Pos /* Non-Recoverable State 3 Output Enable: disabled */
	//		 | 0 << TCC_DRVCTRL_NRE2_Pos /* Non-Recoverable State 2 Output Enable: disabled */
	//		 | 0 << TCC_DRVCTRL_NRE1_Pos /* Non-Recoverable State 1 Output Enable: disabled */
	//		 | 0 << TCC_DRVCTRL_NRE0_Pos); /* Non-Recoverable State 0 Output Enable: disabled */

	// hri_tcc_write_DBGCTRL_reg(TCC2,0 << TCC_DBGCTRL_FDDBD_Pos /* Fault Detection on Debug Break Detection: disabled
	// */
	//		 | 0); /* Run in debug: 0 */

	hri_tcc_write_CC_reg(TCC2, 0, 0x7f); /* Channel 0 Compare/Capture Value: 0x7f */

	hri_tcc_write_CC_reg(TCC2, 1, 0x7f); /* Channel 1 Compare/Capture Value: 0x7f */

	// hri_tcc_write_COUNT_reg(TCC2,0x0); /* Counter Value: 0x0 */

	hri_tcc_write_PER_reg(TCC2, 0xfe); /*  Period Value: 0xfe */

	// hri_tcc_write_EVCTRL_reg(TCC2,0 << TCC_EVCTRL_MCEO3_Pos /* Match or Capture Channel 3 Event Output Enable:
	// disabled */
	//		 | 0 << TCC_EVCTRL_MCEO2_Pos /* Match or Capture Channel 2 Event Output Enable: disabled */
	//		 | 0 << TCC_EVCTRL_MCEO1_Pos /* Match or Capture Channel 1 Event Output Enable: disabled */
	//		 | 0 << TCC_EVCTRL_MCEO0_Pos /* Match or Capture Channel 0 Event Output Enable: disabled */
	//		 | 0 << TCC_EVCTRL_MCEI3_Pos /* Match or Capture Channel 3 Event Input Enable: disabled */
	//		 | 0 << TCC_EVCTRL_MCEI2_Pos /* Match or Capture Channel 2 Event Input Enable: disabled */
	//		 | 0 << TCC_EVCTRL_MCEI1_Pos /* Match or Capture Channel 1 Event Input Enable: disabled */
	//		 | 0 << TCC_EVCTRL_MCEI0_Pos /* Match or Capture Channel 0 Event Input Enable: disabled */
	//		 | 0 << TCC_EVCTRL_TCEI1_Pos /* Timer/counter 1 Event Input Enable: disabled */
	//		 | 0 << TCC_EVCTRL_TCEI0_Pos /* Timer/counter 0 Event Input Enable: disabled */
	//		 | 0 << TCC_EVCTRL_TCINV1_Pos /* Inverted Event 1 Event Input Enable: disabled */
	//		 | 0 << TCC_EVCTRL_TCINV0_Pos /* Inverted Event 0 Event Input Enable: disabled */
	//		 | 0 << TCC_EVCTRL_CNTEO_Pos /* Timer/counter Output Event Enable: disabled */
	//		 | 0 << TCC_EVCTRL_TRGEO_Pos /* Retrigger Output Event Enable: disabled */
	//		 | 0 << TCC_EVCTRL_OVFEO_Pos /* Overflow/Underflow Event Output Enable: disabled */
	//		 | 0 << TCC_EVCTRL_CNTSEL_Pos /* Timer/counter Output Event Mode: 0 */
	//		 | 0 << TCC_EVCTRL_EVACT1_Pos /* Event 1 Action: 0 */
	//		 | 0); /* Event 0 Action: 0 */

	hri_tcc_write_INTEN_reg(TCC2,
	                        0 << TCC_INTENSET_MC3_Pos       /* Match or Capture Channel 3 Interrupt Enable: disabled */
	                            | 0 << TCC_INTENSET_MC2_Pos /* Match or Capture Channel 2 Interrupt Enable: disabled */
	                            | 0 << TCC_INTENSET_MC1_Pos /* Match or Capture Channel 1 Interrupt Enable: disabled */
	                            | 0 << TCC_INTENSET_MC0_Pos /* Match or Capture Channel 0 Interrupt Enable: disabled */
	                            | 0 << TCC_INTENSET_FAULT1_Pos /* Non-Recoverable Fault 1 Interrupt Enable: disabled */
	                            | 0 << TCC_INTENSET_FAULT0_Pos /* Non-Recoverable Fault 0 Interrupt Enable: disabled */
	                            | 0 << TCC_INTENSET_FAULTB_Pos /* Recoverable Fault B Interrupt Enable: disabled */
	                            | 0 << TCC_INTENSET_FAULTA_Pos /* Recoverable Fault A Interrupt Enable: disabled */
	                            | 0 << TCC_INTENSET_DFS_Pos /* Non-Recoverable Debug Fault Interrupt Enable: disabled */
	                            | 0 << TCC_INTENSET_ERR_Pos /* Error Interrupt Enable: disabled */
	                            | 0 << TCC_INTENSET_CNT_Pos /* Counter Interrupt Enable: disabled */
	                            | 0 << TCC_INTENSET_TRG_Pos /* Retrigger Interrupt Enable: disabled */
	                            | 1 << TCC_INTENSET_OVF_Pos); /* Overflow Interrupt enable: enabled */

	hri_tcc_write_CTRLA_ENABLE_bit(TCC2, 1 << TCC_CTRLA_ENABLE_Pos); /* Enable: enabled */

	return 0;
}
