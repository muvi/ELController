/*
 * pid.h
 *
 * Created: 08.08.2022 21:17:22
 *  Author: Christian
 */ 


#ifndef PID_H_
#define PID_H_

#define PID_CONTROLLER_TUNING

#define PID_VALUE_T int64_t

#ifdef PID_CONTROLLER_TUNING
	#define PID_CONTROL_CONST volatile
#else
	#define PID_CONTROL_CONST const
#endif

#include <atmel_start.h>

typedef struct {
		//tuning values
		PID_CONTROL_CONST PID_VALUE_T kp_factor;
		PID_CONTROL_CONST PID_VALUE_T ki_factor;
		PID_CONTROL_CONST PID_VALUE_T kpid_divisor;
		PID_CONTROL_CONST PID_VALUE_T kd_factor;
		PID_CONTROL_CONST PID_VALUE_T kd_divisor;
		PID_CONTROL_CONST PID_VALUE_T kd_filter_factor;
		PID_CONTROL_CONST PID_VALUE_T min;
		PID_CONTROL_CONST PID_VALUE_T max;
		PID_CONTROL_CONST PID_VALUE_T integral_min;
		PID_CONTROL_CONST PID_VALUE_T integral_max;
		//value history
		PID_VALUE_T last_error;
		PID_VALUE_T last_integral_value;
		PID_VALUE_T last_derivative_value;
		PID_VALUE_T last_output;
	} PidController;


#define PID_CONTROLLER(kp, ki, kd, gain_resolution, integrator_min, integrator_max, derivative_filter_cutoff_tau, sampling_time, min_output, max_output) { \
	.kp_factor = (PID_VALUE_T) (2.0 * kp * gain_resolution), \
	 /*since kp_factor has been multiplied by 2.0, kp_divisor would be equal to ki_divisor*/ \
	.ki_factor = (PID_VALUE_T) (ki* gain_resolution * sampling_time), \
	.kpid_divisor = 2.0 * gain_resolution, \
	.kd_factor = 2.0 * kd * 2.0 * gain_resolution, \
	.kd_divisor = ((2.0 * derivative_filter_cutoff_tau) + sampling_time), \
	.kd_filter_factor = ((2.0 * derivative_filter_cutoff_tau) - sampling_time), /*last derivative value is already multiplied by 2.0 * gain_resolution*/ \
	 /*kd_filter_divisor would be equal to kd_divisor*/ \
	.min = ((float) min_output) * 2.0 * gain_resolution, \
	.max = ((float) max_output) * 2.0 * gain_resolution, \
	.integral_min = integrator_min * 2.0 * gain_resolution, \
	.integral_max = integrator_max * 2.0 * gain_resolution \
}

#ifdef PID_CONTROLLER_TUNING
static inline void pid_controller_tune(PidController* controller, const PidController* tuneFrom) {
	controller->kp_factor = tuneFrom->kp_factor;
	controller->ki_factor = tuneFrom->ki_factor;
	controller->kpid_divisor = tuneFrom->kpid_divisor;
	controller->kd_factor = tuneFrom->kd_factor;
	controller->kd_divisor = tuneFrom->kd_divisor;
	controller->kd_filter_factor = tuneFrom->kd_filter_factor;
	controller->min = tuneFrom->min;
	controller->max = tuneFrom->max;
	controller->integral_min = tuneFrom->integral_min;
	controller->integral_max = tuneFrom->integral_max;
}
#endif

static inline void pid_controller_init(PidController* controller, PID_VALUE_T current_output) {
	controller->last_error = 0;
	controller->last_integral_value = 0;
	controller->last_derivative_value = 0;
	controller->last_output = current_output * controller->kpid_divisor;
}

static inline PID_VALUE_T pid_controller_update(PidController* controller, const PID_VALUE_T error) {
	//calculate basic p, i and d terms
	PID_VALUE_T proportional = (controller->kp_factor * error);
	PID_VALUE_T integral = (controller->ki_factor * (error + controller->last_error)) + controller->last_integral_value;
	PID_VALUE_T derivative = ((controller->kd_factor * (error - controller->last_error)) + (controller->kd_filter_factor * controller->last_derivative_value)) / controller->kd_divisor;

	//integrator anti-windup
	PID_VALUE_T integrator_limit;
	if (proportional < controller->integral_max) {
		integrator_limit = controller->integral_max - proportional;
	} else {
		integrator_limit = 0;
	}
	if (integral > integrator_limit) {
		integral = integrator_limit;
	}
	
	if (proportional > controller->integral_min) {
		integrator_limit = controller->integral_min - proportional;
	} else {
		integrator_limit = 0;
	}
	if (integral < integrator_limit) {
		integral = integrator_limit;
	}

	//store current values
	controller->last_error = error;
	controller->last_integral_value = integral;
	controller->last_derivative_value = derivative;
	
	PID_VALUE_T result = controller->last_output + proportional + integral + derivative;
	
	//gpio_set_pin_level(GPIO1, result > controller->min + (controller->max - controller->min) / 2);
	
	//if (result < controller->min) {
	//gpio_set_pin_level(LED1, error >= 0);
	//if (result <= controller->min + (controller->max - controller->min) / 2 && result >= controller->min) {
		//gpio_set_pin_level(LED2, false);
		//gpio_set_pin_level(LED2, result != 0);
		//gpio_set_pin_level(LED2, result <= controller->min + (controller->max - controller->min) / 2 && result >= controller->min);
		//gpio_set_pin_level(LED2, result >= controller->min + (controller->max - controller->min) / 2 && result <= controller->max);
	//}
	
	if (result > controller->max) {
		result = controller->max;
	}
	if (result < controller->min) {
		result = controller->min;
	}
	
	//gpio_set_pin_level(GPIO1, result > controller->min + (controller->max - controller->min) / 2);
	
	controller->last_output = result;
	return result / controller->kpid_divisor;
}
 
#endif /* PID_H_ */