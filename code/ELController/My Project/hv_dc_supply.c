/*
 * hv_dc_supply.c
 *
 * Created: 09.07.2022 01:30:13
 *  Author: Christian
 */ 

#include <hv_dc_supply.h>

//hardware properties8
#define HV_SW_TIMER TCC1
#define R24 22000
#define R27 680
#define HV_DC_SUPPLY_VOLTAGE_SENSE_MAX 0xFFF
#define TRANSFORMER_RATIO (10.0 / 1.0)
#define HV_DC_SUPPLY_BASE_VOLTAGE 12.0
#define HV_DC_SUPPLY_DIODE_VOLTAGE 0.88 //1.1

//configurable properties
#define HV_DC_SUPPLY_BURST_END_RIPPLE_TIME 0.0000004 //s
//#define HV_DC_SUPPLY_BURST_END_RIPPLE_TIME 0.000001 //s
#define HV_DC_SUPPLY_MAX_CYCLES 100000 //count
#define HV_DC_SUPPLY_MIN_BURST_TIME 0.000020 //s //changed from 15us
#define HV_DC_SUPPLY_MAX_BURST_TIME 0.005 //s
#define HV_DC_SUPPLY_BURST_SAFETY_MARGIN_TIME 0.000004 //s
//absolute maximum duty cycle should not exceed 0.0000025, exactly 6A are flowing through the transformers then
//#define HV_DC_SUPPLY_MIN_DUTY_CYCLE_TIME 0.0000018 //s
#define HV_DC_SUPPLY_MIN_DUTY_CYCLE_TIME 0.00000 //s
#define HV_DC_SUPPLY_MAX_DUTY_CYCLE_TIME 0.000006 //0.0000024 //s
#define HV_DC_SUPPLY_INIT_DUTY_CYCLE_TIME 0.000006 //0.0000024 //s
#define HV_DC_SUPPLY_MIN_MEASURABLE_DUTY_CYCLE_TIME 0.0000018//s
#define HV_DC_SUPPLY_NON_MEASURABLE_CYCLES 0b1111 //count
#define HV_DC_SUPPLY_TARGET_VOLTAGE 170.0 //V
#define HV_DC_SUPPLY_LOCKOUT_OVERVOLTAGE 190.0 //V
#define HV_DC_SUPPLY_NO_FREQUENCY_REGULATION_SAFETY_VOLTAGE 40.0 //V

//PID tuning
#define HV_DC_SUPPLY_PID_KP 0.1 //factor
#define HV_DC_SUPPLY_PID_KI 0.0 //factor
#define HV_DC_SUPPLY_PID_KD 0.1 //factor
//#define HV_DC_SUPPLY_PID_KD 0.01 //factor
#define HV_DC_SUPPLY_PID_GAIN_RESOLUTION 10000.0
#define HV_DC_SUPPLY_PID_INTEGRATOR_MIN HV_DC_SUPPLY_MIN_DUTY_CYCLE_TIME //s
#define HV_DC_SUPPLY_PID_INTEGRATOR_MAX HV_DC_SUPPLY_MAX_DUTY_CYCLE_TIME //s
#define HV_DC_SUPPLY_PID_SAMPLING_TIME 1.0 //No realistic unit. Should not be smaller than 1 to prevent divisions by 0
#define HV_DC_SUPPLY_PID_DERIVATIVE_FILTER_CUTOFF_TAU 3.0 //No realistic unit. Should not be smaller than 1 to prevent divisions by 0

//property generation macros
#define HV_DC_SUPPLY_GENERATE_NON_MEASURABLE_CYCLE_REGULATION_START(duty_cycle_regulation_start, duty_cycle_regulation_end) (duty_cycle_regulation_end + (((duty_cycle_regulation_start - duty_cycle_regulation_end) * (HV_DC_SUPPLY_MIN_MEASURABLE_DUTY_CYCLE_TIME - HV_DC_SUPPLY_MIN_DUTY_CYCLE_TIME)) / (HV_DC_SUPPLY_MAX_DUTY_CYCLE_TIME - HV_DC_SUPPLY_MIN_DUTY_CYCLE_TIME)))

//property generation macros
#define HV_DC_SUPPLY_ADAPTED_TARGET_VOLTAGE(n) (n + HV_DC_SUPPLY_DIODE_VOLTAGE - HV_DC_SUPPLY_BASE_VOLTAGE)
#define HV_DC_SUPPLY_GENERATE_SENSE_TARGET(n) (uint16_t) (HV_DC_SUPPLY_ADAPTED_TARGET_VOLTAGE(n) / HV_DC_SUPPLY_VOLTAGE_SENSE_FACTOR)
#define HV_DC_SUPPLY_SECONDS_TO_CYCLES(n) ((uint32_t) (n * ((float) MAIN_CLOCK_SPEED) + 0.5))

//property retrieval macros
#define HV_DC_SUPPLY_UNADAPTED_TARGET_VOLTAGE(n) ((n) - HV_DC_SUPPLY_DIODE_VOLTAGE + HV_DC_SUPPLY_BASE_VOLTAGE)
#define HV_DC_SUPPLY_SENSE_TARGET_TO_VOLTAGE(n) HV_DC_SUPPLY_UNADAPTED_TARGET_VOLTAGE(n * HV_DC_SUPPLY_VOLTAGE_SENSE_FACTOR)

//intermediate values
#define HALF_VCC VCC / 2.0
#define HV_DC_SUPPLY_MAX_VOLTAGE ((HALF_VCC / R27) * (R24 + R27) * TRANSFORMER_RATIO)
#define HV_DC_SUPPLY_VOLTAGE_SENSE_FACTOR ((HV_DC_SUPPLY_MAX_VOLTAGE - HV_DC_SUPPLY_BASE_VOLTAGE) / HV_DC_SUPPLY_VOLTAGE_SENSE_MAX)
#define HV_DC_SUPPLY_DIODE_VOLTAGE_VALUE_DEF ((uint16_t) (HV_DC_SUPPLY_DIODE_VOLTAGE / HV_DC_SUPPLY_VOLTAGE_SENSE_FACTOR))
#define HV_DC_SUPPLY_MIN_BURST_CYCLES_DEF HV_DC_SUPPLY_SECONDS_TO_CYCLES(HV_DC_SUPPLY_MIN_BURST_TIME)
#define HV_DC_SUPPLY_MAX_BURST_CYCLES_DEF HV_DC_SUPPLY_SECONDS_TO_CYCLES(HV_DC_SUPPLY_MAX_BURST_TIME)
#define HV_DC_SUPPLY_MIN_DUTY_CYCLE_CYCLES_DEF HV_DC_SUPPLY_SECONDS_TO_CYCLES(HV_DC_SUPPLY_MIN_DUTY_CYCLE_TIME)
#define HV_DC_SUPPLY_MAX_DUTY_CYCLE_CYCLES_DEF HV_DC_SUPPLY_SECONDS_TO_CYCLES(HV_DC_SUPPLY_MAX_DUTY_CYCLE_TIME)
#define HV_DC_SUPPLY_INIT_DUTY_CYCLE_CYCLES_DEF HV_DC_SUPPLY_SECONDS_TO_CYCLES(HV_DC_SUPPLY_INIT_DUTY_CYCLE_TIME)
#define HV_DC_SUPPLY_BURST_SAFETY_MARGIN_CYCLES_DEF HV_DC_SUPPLY_SECONDS_TO_CYCLES(HV_DC_SUPPLY_BURST_SAFETY_MARGIN_TIME)
#define HV_DC_SUPPLY_CONDUCTION_TIME_FACTOR_DEF ((uint32_t) ((HV_DC_SUPPLY_BASE_VOLTAGE * TRANSFORMER_RATIO) / HV_DC_SUPPLY_VOLTAGE_SENSE_FACTOR))
/*to get this value, reformulate the calculation from hv_dc_supply_conduction_cycles
	conduction_cycles = ((duty_cycle * HV_DC_SUPPLY_CONDUCTION_TIME_FACTOR) / (voltage + HV_DC_SUPPLY_DIODE_VOLTAGE_VALUE)) + HV_DC_SUPPLY_BURST_SAFETY_MARGIN_CYCLES + duty_cycle
	conduction_cycles - HV_DC_SUPPLY_BURST_SAFETY_MARGIN_CYCLES - duty_cycle = (duty_cycle * HV_DC_SUPPLY_CONDUCTION_TIME_FACTOR) / (voltage + HV_DC_SUPPLY_DIODE_VOLTAGE_VALUE)
	(conduction_cycles - HV_DC_SUPPLY_BURST_SAFETY_MARGIN_CYCLES - duty_cycle) * (voltage + HV_DC_SUPPLY_DIODE_VOLTAGE_VALUE) = (duty_cycle * HV_DC_SUPPLY_CONDUCTION_TIME_FACTOR)
	voltage + HV_DC_SUPPLY_DIODE_VOLTAGE_VALUE = (duty_cycle * HV_DC_SUPPLY_CONDUCTION_TIME_FACTOR) / (conduction_cycles - HV_DC_SUPPLY_BURST_SAFETY_MARGIN_CYCLES - duty_cycle)
	voltage = (duty_cycle * HV_DC_SUPPLY_CONDUCTION_TIME_FACTOR) / (conduction_cycles - HV_DC_SUPPLY_BURST_SAFETY_MARGIN_CYCLES - duty_cycle) - HV_DC_SUPPLY_DIODE_VOLTAGE_VALUE
*/
#define HV_DC_SUPPLY_NO_FREQUENCY_REGULATION_VOLTAGE_MIN_TARGET ((HV_DC_SUPPLY_MAX_DUTY_CYCLE_CYCLES_DEF * HV_DC_SUPPLY_CONDUCTION_TIME_FACTOR_DEF) / (HV_DC_SUPPLY_MIN_BURST_CYCLES_DEF - HV_DC_SUPPLY_BURST_SAFETY_MARGIN_CYCLES_DEF - HV_DC_SUPPLY_MAX_DUTY_CYCLE_CYCLES_DEF) - HV_DC_SUPPLY_DIODE_VOLTAGE_VALUE_DEF)
#define HV_DC_SUPPLY_NO_FREQUENCY_REGULATION_VOLTAGE_SAFETY_TARGET HV_DC_SUPPLY_GENERATE_SENSE_TARGET(HV_DC_SUPPLY_NO_FREQUENCY_REGULATION_SAFETY_VOLTAGE)

//calculated properties scaled to uint
const uint16_t HV_DC_SUPPLY_BURST_END_RIPPLE_CYCLES = (uint16_t) (MAIN_CLOCK_SPEED * HV_DC_SUPPLY_BURST_END_RIPPLE_TIME);
const uint16_t HV_DC_SUPPLY_SENSE_TARGET = HV_DC_SUPPLY_GENERATE_SENSE_TARGET(HV_DC_SUPPLY_TARGET_VOLTAGE);
const uint16_t HV_DC_SUPPLY_LOCKOUT_OVERVOLTAGE_TARGET = HV_DC_SUPPLY_GENERATE_SENSE_TARGET(HV_DC_SUPPLY_LOCKOUT_OVERVOLTAGE);
const uint16_t HV_DC_SUPPLY_REGULATION_END_TARGET = HV_DC_SUPPLY_NO_FREQUENCY_REGULATION_VOLTAGE_MIN_TARGET + HV_DC_SUPPLY_NO_FREQUENCY_REGULATION_VOLTAGE_SAFETY_TARGET;
const uint16_t HV_DC_SUPPLY_DIODE_VOLTAGE_VALUE = HV_DC_SUPPLY_DIODE_VOLTAGE_VALUE_DEF;
const uint32_t HV_DC_SUPPLY_CONDUCTION_TIME_FACTOR = HV_DC_SUPPLY_CONDUCTION_TIME_FACTOR_DEF;
const uint32_t HV_DC_SUPPLY_MIN_BURST_CYCLES = HV_DC_SUPPLY_MIN_BURST_CYCLES_DEF;
const uint32_t HV_DC_SUPPLY_MAX_BURST_CYCLES = HV_DC_SUPPLY_MAX_BURST_CYCLES_DEF;
const uint16_t HV_DC_SUPPLY_BURST_SAFETY_MARGIN_CYCLES = HV_DC_SUPPLY_BURST_SAFETY_MARGIN_CYCLES_DEF;
const uint16_t HV_DC_SUPPLY_MIN_DUTY_CYCLE_CYCLES = HV_DC_SUPPLY_MIN_DUTY_CYCLE_CYCLES_DEF;
const uint16_t HV_DC_SUPPLY_MAX_DUTY_CYCLE_CYCLES = HV_DC_SUPPLY_MAX_DUTY_CYCLE_CYCLES_DEF;
const uint16_t HV_DC_SUPPLY_INIT_DUTY_CYCLE_CYCLES = HV_DC_SUPPLY_INIT_DUTY_CYCLE_CYCLES_DEF;
const uint16_t HV_DC_SUPPLY_MIN_MEASURABLE_DUTY_CYCLE_CYCLES = ((uint16_t) (HV_DC_SUPPLY_MIN_MEASURABLE_DUTY_CYCLE_TIME * ((float) MAIN_CLOCK_SPEED) + 0.5));


typedef enum {HV_DC_SUPPLY_STATE_OFF = 0, HV_DC_SUPPLY_STATE_INITIALIZE = 1, HV_DC_SUPPLY_STATE_ON = 1, HV_DC_SUPPLY_STATE_REGULATE} HvDcSupplyState;
volatile HvDcSupplyState hv_dc_supply_state = HV_DC_SUPPLY_STATE_OFF;
volatile uint16_t hv_dc_supply_sensed_voltage = 0;

volatile uint16_t hv_dc_supply_counter = 0;
volatile PID_VALUE_T hv_dc_supply_duty_cycle = 0;
volatile uint32_t hv_dc_supply_period = HV_DC_SUPPLY_MAX_BURST_CYCLES_DEF;
PidController controller = PID_CONTROLLER(
	HV_DC_SUPPLY_PID_KP,
	HV_DC_SUPPLY_PID_KI,
	HV_DC_SUPPLY_PID_KD,
	HV_DC_SUPPLY_PID_GAIN_RESOLUTION,
	HV_DC_SUPPLY_SECONDS_TO_CYCLES(HV_DC_SUPPLY_PID_INTEGRATOR_MIN),
	HV_DC_SUPPLY_SECONDS_TO_CYCLES(HV_DC_SUPPLY_PID_INTEGRATOR_MAX),
	HV_DC_SUPPLY_PID_DERIVATIVE_FILTER_CUTOFF_TAU,
	HV_DC_SUPPLY_PID_SAMPLING_TIME,
	HV_DC_SUPPLY_MIN_DUTY_CYCLE_CYCLES_DEF,
	HV_DC_SUPPLY_MAX_DUTY_CYCLE_CYCLES_DEF);

static inline bool hv_dc_supply_is_measurable(const uint16_t duty_cycle) {
	return duty_cycle >= HV_DC_SUPPLY_MIN_MEASURABLE_DUTY_CYCLE_CYCLES;
}

static inline void hv_dc_supply_set_timer(const PID_VALUE_T duty_cycle, const uint32_t period, const bool measure) {
	//if there is a pending update, do that first
	if (!hri_tcc_get_STATUS_PERBV_bit(HV_SW_TIMER)) {
		hri_tcc_set_CTRLB_LUPD_bit(HV_SW_TIMER);

		hri_tcc_write_CCB_reg_no_lock(HV_SW_TIMER, 1, duty_cycle);
		hri_tcc_write_CCB_reg_no_lock(HV_SW_TIMER, 0, (measure && hv_dc_supply_is_measurable(duty_cycle)) ? duty_cycle + HV_DC_SUPPLY_BURST_END_RIPPLE_CYCLES : 0xFFFFFF);
		hri_tcc_write_PERB_reg_no_lock(HV_SW_TIMER, period);

		hri_tcc_clear_CTRLB_LUPD_bit(HV_SW_TIMER);
	}
}

static inline void hv_dc_supply_configure_timer(const PID_VALUE_T duty_cycle, const uint32_t period) {
	hv_dc_supply_duty_cycle = duty_cycle;
	hv_dc_supply_period = period;
	/*
	if (hv_dc_supply_is_measurable(duty_cycle)) {
		hv_dc_supply_set_timer(duty_cycle, period);
	}
	*/
}

static inline uint32_t hv_dc_supply_check_min_max(const uint32_t value, const uint32_t min, const uint32_t max) {
	if (value < min) {
		return min;
	}
	if (value > max) {
		return max;
	}
	return value;
}

static inline uint32_t hv_dc_supply_conduction_time(const uint32_t voltage, const uint32_t duty_cycle) {
	return (duty_cycle * HV_DC_SUPPLY_CONDUCTION_TIME_FACTOR) / (voltage + HV_DC_SUPPLY_DIODE_VOLTAGE_VALUE);
}

static inline uint16_t hv_dc_supply_conduction_cycles(const uint16_t voltage, const uint16_t duty_cycle) {
	return hv_dc_supply_conduction_time(voltage, duty_cycle) + HV_DC_SUPPLY_BURST_SAFETY_MARGIN_CYCLES + duty_cycle;
}

static inline void hv_dc_supply_sense(const uint16_t voltage) {
	hv_dc_supply_sensed_voltage = voltage;
	switch (hv_dc_supply_state) {
		case HV_DC_SUPPLY_STATE_INITIALIZE: {
			if (voltage >= HV_DC_SUPPLY_SENSE_TARGET) {
				hv_dc_supply_state = HV_DC_SUPPLY_STATE_REGULATE;
				pid_controller_init(&controller, HV_DC_SUPPLY_MIN_DUTY_CYCLE_CYCLES);
			}
			break;
		}
		case HV_DC_SUPPLY_STATE_REGULATE: {
			if (voltage <= HV_DC_SUPPLY_REGULATION_END_TARGET) {
				hv_dc_supply_state = HV_DC_SUPPLY_STATE_INITIALIZE;
			}
			break;
		}
		case HV_DC_SUPPLY_STATE_OFF:
		default: {
			return;
		}
	}
	
	//over-voltage lockout
	if (voltage >= HV_DC_SUPPLY_LOCKOUT_OVERVOLTAGE_TARGET) {
		hv_dc_supply_cancel();
		return;
	}

	switch (hv_dc_supply_state) {
		case HV_DC_SUPPLY_STATE_INITIALIZE: {
			uint32_t period = hv_dc_supply_check_min_max(hv_dc_supply_conduction_cycles(voltage, HV_DC_SUPPLY_INIT_DUTY_CYCLE_CYCLES), HV_DC_SUPPLY_MIN_BURST_CYCLES, HV_DC_SUPPLY_MAX_BURST_CYCLES);
			hv_dc_supply_configure_timer(HV_DC_SUPPLY_INIT_DUTY_CYCLE_CYCLES, period);
			break;
		}
		case HV_DC_SUPPLY_STATE_REGULATE: {
			//TODO: regulate!
			//currently, the duty cycle is just set to min
			int32_t error = ((int32_t) HV_DC_SUPPLY_SENSE_TARGET) - ((int32_t) voltage);
			PID_VALUE_T duty_cycle = pid_controller_update(&controller, error);
			
			hv_dc_supply_configure_timer(duty_cycle, HV_DC_SUPPLY_MIN_BURST_CYCLES);
			//hv_dc_supply_configure_timer(HV_DC_SUPPLY_MIN_DUTY_CYCLE_CYCLES, HV_DC_SUPPLY_MIN_BURST_CYCLES);
			break;
		}
		case HV_DC_SUPPLY_STATE_OFF:
		default: {
			
		}
	}
}

void ADC_Handler() {
	hri_adc_clear_interrupt_RESRDY_bit(ADC);
	uint16_t data = hri_adc_read_RESULT_reg(ADC);
	hv_dc_supply_sense(data);
}

void TCC1_Handler() {
	//only the OVF interrupt is enabled, so no interrupt flags need to be checked
	hri_tcc_clear_interrupt_OVF_bit(HV_SW_TIMER);
	
	hv_dc_supply_counter++;
	if (!hv_dc_supply_state || hv_dc_supply_counter >= HV_DC_SUPPLY_MAX_CYCLES) {
		hv_dc_supply_cancel();
	} else {
		if (!(hv_dc_supply_counter & HV_DC_SUPPLY_NON_MEASURABLE_CYCLES)) {
			if (hv_dc_supply_is_measurable(hv_dc_supply_duty_cycle)) {
				hv_dc_supply_set_timer(hv_dc_supply_duty_cycle, hv_dc_supply_period, true);
			} else {
				hv_dc_supply_set_timer(HV_DC_SUPPLY_MIN_MEASURABLE_DUTY_CYCLE_CYCLES, HV_DC_SUPPLY_MIN_BURST_CYCLES, true);
			}
			/*
			switch (hv_dc_supply_counter & HV_DC_SUPPLY_NON_MEASURABLE_CYCLES) {
				case 0: {
					hv_dc_supply_set_timer(hv_dc_supply_duty_cycle, HV_DC_SUPPLY_MIN_BURST_CYCLES);
					break;
				}
				case HV_DC_SUPPLY_NON_MEASURABLE_CYCLES: {
					hv_dc_supply_set_timer(HV_DC_SUPPLY_MIN_MEASURABLE_DUTY_CYCLE_CYCLES, HV_DC_SUPPLY_MIN_BURST_CYCLES);
					break;
				}
			}
			*/
		} else {
			hv_dc_supply_set_timer(hv_dc_supply_duty_cycle, hv_dc_supply_period, false);
		}
	}
}

void hv_dc_supply_cancel() {
	hv_dc_supply_state = HV_DC_SUPPLY_STATE_OFF;
	//CAUTION: This step can be skipped by a pending update. Sometimes, it has to be done again in TCC1_Handler
	hv_dc_supply_set_timer(0x000000, HV_DC_SUPPLY_MAX_BURST_CYCLES, true);
	hv_dc_supply_sensed_voltage = 0;
}

void hv_dc_supply_power_pulse() {
	hv_dc_supply_counter = 0;
	hv_dc_supply_state = HV_DC_SUPPLY_STATE_ON;
	hv_dc_supply_configure_timer(HV_DC_SUPPLY_INIT_DUTY_CYCLE_CYCLES, HV_DC_SUPPLY_MAX_BURST_CYCLES);
}

void hv_dc_supply_enable_adc() {
	gpio_set_pin_direction(PWR_SENSE, GPIO_DIRECTION_OFF);
	gpio_set_pin_function(PWR_SENSE, PINMUX_PA02B_ADC_AIN0);

	gpio_set_pin_direction(HV_SENSE, GPIO_DIRECTION_OFF);
	gpio_set_pin_function(HV_SENSE, PINMUX_PA03B_ADC_AIN1);
	
	adc_async_set_inputs(&ADC_0, ADC_MUXPOS_AIN1, ADC_MUXNEG_AIN0, 0);
	
	hri_adc_write_INTEN_RESRDY_bit(ADC, true);
	adc_async_enable_channel(&ADC_0, 0);
}

void hv_dc_supply_init_timer() {
	
	hri_tcc_write_PER_reg(HV_SW_TIMER, HV_DC_SUPPLY_MAX_BURST_CYCLES);
	hri_tcc_write_CC_reg(HV_SW_TIMER, 1, 0x000000);
	hri_tcc_write_CC_reg(HV_SW_TIMER, 0, 0xFFFFFF);
	
	hri_tcc_write_WAVE_reg(HV_SW_TIMER,
		  0 << TCC_WAVE_SWAP1_Pos
		| 0 << TCC_WAVE_SWAP0_Pos
		| 1 << TCC_WAVE_POL1_Pos
		| 0 << TCC_WAVE_POL0_Pos
		| 0 << TCC_WAVE_CICCEN1_Pos
		| 0 << TCC_WAVE_CICCEN0_Pos
		| 0 << TCC_WAVE_CIPEREN_Pos
		| 0 << TCC_WAVE_RAMP_Pos
		| TCC_WAVE_WAVEGEN_NPWM_Val << TCC_WAVE_WAVEGEN_Pos
	);

	gpio_set_pin_level(HV_SW, true);
	gpio_set_pin_direction(HV_SW, GPIO_DIRECTION_OUT);
	gpio_set_pin_drive_strength(HV_SW);
	gpio_set_pin_function(HV_SW, PINMUX_PA07E_TCC1_WO1);

	//for debugging only---
	//TODO: DELETE!
	gpio_set_pin_level(USB_DM, true);
	gpio_set_pin_direction(USB_DM, GPIO_DIRECTION_OUT);
	gpio_set_pin_drive_strength(USB_DM);
	gpio_set_pin_function(USB_DM, PINMUX_PA24F_TCC1_WO2);
	//---
	
	NVIC_DisableIRQ(TCC1_IRQn);
	NVIC_ClearPendingIRQ(TCC1_IRQn);
	NVIC_EnableIRQ(TCC1_IRQn);
}

void hv_dc_supply_init() {
	adc_init();
	hv_dc_supply_init_timer();
	hv_dc_supply_enable_adc();
}

float hv_dc_supply_get_voltage() {
	return HV_DC_SUPPLY_SENSE_TARGET_TO_VOLTAGE((float) hv_dc_supply_sensed_voltage);
}

float hv_dc_supply_get_max_voltage() {
	return HV_DC_SUPPLY_SENSE_TARGET_TO_VOLTAGE((float) HV_DC_SUPPLY_VOLTAGE_SENSE_MAX);
}

uint16_t hv_dc_supply_get_sense_target(float voltage) {
	return HV_DC_SUPPLY_GENERATE_SENSE_TARGET(voltage);
}

uint16_t hv_dc_supply_get_voltage_raw() {
	return hv_dc_supply_sensed_voltage;
}