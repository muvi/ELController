
======================
RTC driver
======================
The RTC peripheral offers two timing functions: the Real-Time Counter (RTC) and a Periodic Interrupt Timer (PIT). 
RTC and PIT can be used at the same time. RTC can generate periodic peripheral events from outputs of the prescaler, 
as well as alarm/compare interrupts and peripheral events, which can trigger at any counter value.

Features
--------
* Initialization

Applications
------------
* Periodic Interrupt
* Delayed Applications

Dependencies
------------
* CLKCTRL for clocks
* PORT for I/O lines and connections
* EVSYS for events
* CPUINT for interrupt
* UPDI for debug 

Concurrency
-----------
N/A

Limitations
-----------
N/A

Knows issues and workarounds
----------------------------
N/A

