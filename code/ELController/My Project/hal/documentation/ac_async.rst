======================
AC Asynchronous driver
======================

An analog comparator compares two analog voltage levels, and outputs a digital
value indicating which is larger. The comparator has usually two analog inputs,
V+ and V-, but internal sources in the MCU can also be used as source
for one of the inputs. The digital output value is outputted on Vout. A
callback function can be registered in the driver by the application and triggered
when a predefined condition occurs to let the application know that this
condition has been met.

The predefined conditions depends on with device is used, commonly supported
conditions:
* Rising: output value (Vout) changes from low state to high state
* Falling: output value (Vout) changes from high state to low state
* Toggle: output value (Vout) changes state

Features
--------
* Initialization and de-initialization
* Enabling and disabling
* Callback on comparison interrupt
* Multiple comparators per hardware instance supported

Applications
------------
* Monitor if sensor/battery voltage is exceeds than reference voltage.
* Monitor two sensor voltage, compare which is higher.

Dependencies
------------
* AC hardware with comparison result interrupt

Concurrency
-----------
N/A

Limitations
-----------
N/A

Knows issues and workarounds
----------------------------
N/A

