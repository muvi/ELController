/* Auto-generated config file hpl_ac_config.h */
#ifndef HPL_AC_CONFIG_H
#define HPL_AC_CONFIG_H

// <<< Use Configuration Wizard in Context Menu >>>

// <h> Comparator0 Settings

// <o> Positive Input Mux Selection
// <i> These bits select which input will be connected to the positive input.
// <0x0=>I/O PIN 0
// <0x1=>I/O PIN 1
// <0x2=>I/O PIN 2
// <0x3=>I/O PIN 3
// <id> ac_arch_compctrl0_muxpos
#ifndef CONF_AC_COMPCTRL0_MUXPOS
#define CONF_AC_COMPCTRL0_MUXPOS 0
#endif

// <o> Negative Input Mux Selection
// <i> These bits select which input will be connected to the negative input.
// <0x0=>I/O PIN 0
// <0x1=>I/O PIN 1
// <0x2=>I/O PIN 2
// <0x3=>I/O PIN 3
// <0x4=>Ground
// <0x5=>Vddana scaler
// <0x6=>Internal bandgap voltage
// <0x7=>DAC output
// <id> ac_arch_compctrl0_muxneg
#ifndef CONF_AC_COMPCTRL0_MUXNEG
#define CONF_AC_COMPCTRL0_MUXNEG 0x7
#endif

// <o> Output
// <i> These bits configure the output selection.
// <0x0=>OFF
// <0x1=>ASYNC
// <0x2=>SYNC
// <id> ac_arch_compctrl0_out
#ifndef CONF_AC_COMPCTRL0_OUT
#define CONF_AC_COMPCTRL0_OUT 0
#endif

// <e> Comparator0 Advanced Settings
// <id> ac_arch_comp0_advanced_settings
#ifndef COMP0_ADVANCED_SETTINGS
#define COMP0_ADVANCED_SETTINGS 1
#endif

// <o> Filter Length
// <i> These bits define the filtering length.
// <0x0=>No Filtering
// <0x1=>3-bit majority function
// <0x2=>5-bit majority function
// <id> ac_arch_compctrl0_flen
#ifndef CONF_AC_COMPCTRL0_FLEN
#define CONF_AC_COMPCTRL0_FLEN 0
#endif

// <q> Hysteresis Enable
// <i> Indicates whether the hysteresis mode is enabled or disable.
// <id> ac_arch_compctrl0_hyst
#ifndef CONF_AC_COMPCTRL0_HYST
#define CONF_AC_COMPCTRL0_HYST 0
#endif

// <q> Swap Inputs and Invert
// <i> This bit swaps the positive and negative inputs and inverts the output.
// <id> ac_arch_compctrl0_swap
#ifndef CONF_AC_COMPCTRL0_SWAP
#define CONF_AC_COMPCTRL0_SWAP 0
#endif

// <o> Interrupt Selection
// <i> These bits select the condition to generate an interrupt or event.
// <0x0=>Interrupt on comparator output toggle
// <0x1=>Interrupt on comparator output rising
// <0x2=>Interrupt on comparator output falling
// <0x3=>Interrupt on end of comparison(single-shot mode only)
// <id> ac_arch_compctrl0_intsel
#ifndef CONF_AC_COMPCTRL0_INTSEL
#define CONF_AC_COMPCTRL0_INTSEL 3
#endif

// <o> Speed Selection
// <i> This bit indicates the speed/propagation delay mode.
// <0x0=>Low speed
// <0x1=>High speed
// <id> ac_arch_compctrl0_speed
#ifndef CONF_AC_COMPCTRL0_SPEED
#define CONF_AC_COMPCTRL0_SPEED 0
#endif

// <o> Single-Shot Mode
// <i> This bit indicates the operation mode.
// <0x0=>Continuous measurement mode
// <0x1=>Single-shot mode
// <id> ac_compctrl0_single
#ifndef CONF_AC_COMPCTRL0_SINGLE
#define CONF_AC_COMPCTRL0_SINGLE 1
#endif

// <o> Scaler Value for Vddana <0x0000-0x3F>
// <i> These bits define the scaling factor for comparator of the VDD voltage scaler
// <id> ac_arch_scaler0
#ifndef CONF_AC_SCALER0
#define CONF_AC_SCALER0 0x0
#endif

// </e>
// </h>

// <h> Comparator1 Settings

// <o> Positive Input Mux Selection
// <i> These bits select which input will be connected to the positive input.
// <0x0=>I/O PIN 0
// <0x1=>I/O PIN 1
// <0x2=>I/O PIN 2
// <0x3=>I/O PIN 3
// <id> ac_arch_compctrl1_muxpos
#ifndef CONF_AC_COMPCTRL1_MUXPOS
#define CONF_AC_COMPCTRL1_MUXPOS 1
#endif

// <o> Negative Input Mux Selection
// <i> These bits select which input will be connected to the negative input.
// <0x0=>I/O PIN 0
// <0x1=>I/O PIN 1
// <0x2=>I/O PIN 2
// <0x3=>I/O PIN 3
// <0x4=>Ground
// <0x5=>Vddana scaler
// <0x6=>Internal bandgap voltage
// <0x7=>DAC output
// <id> ac_arch_compctrl1_muxneg
#ifndef CONF_AC_COMPCTRL1_MUXNEG
#define CONF_AC_COMPCTRL1_MUXNEG 0x7
#endif

// <o> Output
// <i> These bits configure the output selection.
// <0x0=>OFF
// <0x1=>ASYNC
// <0x2=>SYNC
// <id> ac_arch_compctrl1_out
#ifndef CONF_AC_COMPCTRL1_OUT
#define CONF_AC_COMPCTRL1_OUT 0
#endif

// <e> Comparator1 Advanced Settings
// <id> ac_arch_comp1_advanced_settings
#ifndef COMP1_ADVANCED_SETTINGS
#define COMP1_ADVANCED_SETTINGS 0
#endif

// <o> Filter Length
// <i> These bits define the filtering length.
// <0x0=>No Filtering
// <0x1=>3-bit majority function
// <0x2=>5-bit majority function
// <id> ac_arch_compctrl1_flen
#ifndef CONF_AC_COMPCTRL1_FLEN
#define CONF_AC_COMPCTRL1_FLEN 0
#endif

// <q> Hysteresis Enable
// <i> Indicates whether the hysteresis mode is enabled or disable.
// <id> ac_arch_compctrl1_hyst
#ifndef CONF_AC_COMPCTRL1_HYST
#define CONF_AC_COMPCTRL1_HYST 0
#endif

// <q> Swap Inputs and Invert
// <i> This bit swaps the positive and negative inputs and inverts the output.
// <id> ac_arch_compctrl1_swap
#ifndef CONF_AC_COMPCTRL1_SWAP
#define CONF_AC_COMPCTRL1_SWAP 0
#endif

// <o> Interrupt Selection
// <i> These bits select the condition to generate an interrupt or event.
// <0x0=>Interrupt on comparator output toggle
// <0x1=>Interrupt on comparator output rising
// <0x2=>Interrupt on comparator output falling
// <0x3=>Interrupt on end of comparison(single-shot mode only)
// <id> ac_arch_compctrl1_intsel
#ifndef CONF_AC_COMPCTRL1_INTSEL
#define CONF_AC_COMPCTRL1_INTSEL 3
#endif

// <o> Speed Selection
// <i> This bit indicates the speed/propagation delay mode.
// <0x0=>Low speed
// <0x1=>High speed
// <id> ac_arch_compctrl1_speed
#ifndef CONF_AC_COMPCTRL1_SPEED
#define CONF_AC_COMPCTRL1_SPEED 0
#endif

// <o> Single-Shot Mode
// <i> This bit indicates the operation mode.
// <0x0=>Continuous measurement mode
// <0x1=>Single-shot mode
// <id> ac_arch_compctrl1_single
#ifndef CONF_AC_COMPCTRL1_SINGLE
#define CONF_AC_COMPCTRL1_SINGLE 1
#endif

// <o> Scaler Value for Vddana <0x0000-0x3F>
// <i> These bits define the scaling factor for comparator of the VDD voltage scaler
// <id> ac_arch_scaler1
#ifndef CONF_AC_SCALER1
#define CONF_AC_SCALER1 0
#endif

// </e>

// </h>

// <e> Advanced Settings
// <id> ac_arch_advanced_settings
#ifndef AC_ADVANCED_SETTINGS
#define AC_ADVANCED_SETTINGS 1
#endif

// <q> Run in standby
// <i> Indicates whether the AC will continue running in standby sleep mode or not
// <id> ac_arch_runstdby
#ifndef CONF_AC_RUNSTDBY
#define CONF_AC_RUNSTDBY 0
#endif

// <q> Low power Mux
// <i> Indicates whether the AC consume less power at lower voltages.
// <id> ac_arch_lpmux
#ifndef CONF_AC_LPMUX
#define CONF_AC_LPMUX 0
#endif

// </e>

// <e> Event Settings
// <id> ac_arch_event_settings
#ifndef EVENT_ADVANCED_SETTINGS
#define EVENT_ADVANCED_SETTINGS 1
#endif

// <q> Comparator0 Event Output
// <i> This bit indicates whether the comparator 0 output can generate a peripheral event or not.
// <id> ac_arch_compeo0
#ifndef CONF_AC_COMPEO0
#define CONF_AC_COMPEO0 0
#endif
// <q> Comparator1 Event Output
// <i> This bit indicates whether the comparator 1 output can generate a peripheral event or not.
// <id> ac_arch_compeo1
#ifndef CONF_AC_COMPEO1
#define CONF_AC_COMPEO1 0
#endif

// <q> Comparator0 Event Input
// <i> This bit indicates whether a comparison will be triggered on any incoming event.
// <id> ac_arch_compei0
#ifndef CONF_AC_COMPEI0
#define CONF_AC_COMPEI0 0
#endif
// <q> Comparator1 Event Input
// <i> This bit indicates whether a comparison will be triggered on any incoming event.
// <id> ac_arch_compei1
#ifndef CONF_AC_COMPEI1
#define CONF_AC_COMPEI1 0
#endif

// <q> Window 0 Event Output
// <i> This bit indicates whether the window 0 function can generate a peripheral event or not.
// <id> ac_arch_wineo0
#ifndef CONF_AC_WINEO0
#define CONF_AC_WINEO0 0
#endif

// </e>

#define CONF_AC_CTRLA (CONF_AC_RUNSTDBY << AC_CTRLA_RUNSTDBY_Pos) | (CONF_AC_LPMUX << AC_CTRLA_LPMUX_Pos)
#define CONF_AC_EVCTRL                                                                                                 \
	(CONF_AC_WINEO0 << AC_EVCTRL_WINEO0_Pos) | (CONF_AC_COMPEI0 << AC_EVCTRL_COMPEI0_Pos)                              \
	    | (CONF_AC_COMPEI1 << AC_EVCTRL_COMPEI1_Pos) | (CONF_AC_COMPEO0 << AC_EVCTRL_COMPEO0_Pos)                      \
	    | (CONF_AC_COMPEO1 << AC_EVCTRL_COMPEO1_Pos)
#define CONF_AC_COMP_CTRL0                                                                                             \
	(CONF_AC_COMPCTRL0_FLEN << AC_COMPCTRL_FLEN_Pos) | (CONF_AC_COMPCTRL0_HYST << AC_COMPCTRL_HYST_Pos)                \
	    | (CONF_AC_COMPCTRL0_OUT << AC_COMPCTRL_OUT_Pos) | (CONF_AC_COMPCTRL0_SWAP << AC_COMPCTRL_SWAP_Pos)            \
	    | (CONF_AC_COMPCTRL0_MUXPOS << AC_COMPCTRL_MUXPOS_Pos) | (CONF_AC_COMPCTRL0_MUXNEG << AC_COMPCTRL_MUXNEG_Pos)  \
	    | (CONF_AC_COMPCTRL0_INTSEL << AC_COMPCTRL_INTSEL_Pos) | (CONF_AC_COMPCTRL0_SPEED << AC_COMPCTRL_SPEED_Pos)    \
	    | (CONF_AC_COMPCTRL0_SINGLE << AC_COMPCTRL_SINGLE_Pos)
#define CONF_AC_COMP_CTRL1                                                                                             \
	(CONF_AC_COMPCTRL1_FLEN << AC_COMPCTRL_FLEN_Pos) | (CONF_AC_COMPCTRL1_HYST << AC_COMPCTRL_HYST_Pos)                \
	    | (CONF_AC_COMPCTRL1_OUT << AC_COMPCTRL_OUT_Pos) | (CONF_AC_COMPCTRL1_SWAP << AC_COMPCTRL_SWAP_Pos)            \
	    | (CONF_AC_COMPCTRL1_MUXPOS << AC_COMPCTRL_MUXPOS_Pos) | (CONF_AC_COMPCTRL1_MUXNEG << AC_COMPCTRL_MUXNEG_Pos)  \
	    | (CONF_AC_COMPCTRL1_INTSEL << AC_COMPCTRL_INTSEL_Pos) | (CONF_AC_COMPCTRL1_SPEED << AC_COMPCTRL_SPEED_Pos)    \
	    | (CONF_AC_COMPCTRL1_SINGLE << AC_COMPCTRL_SINGLE_Pos)
#define CONF_AC_COMP_SCALER0 (CONF_AC_SCALER0 << AC_SCALER_VALUE_Pos)
#define CONF_AC_COMP_SCALER1 (CONF_AC_SCALER1 << AC_SCALER_VALUE_Pos)

// <<< end of configuration section >>>

#endif // HPL_AC_CONFIG_H
