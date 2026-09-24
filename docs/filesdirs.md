# File structure

* **hllw**
  * **arch**
    * **arm926** >Dir for ARM926 stuff
      * **linker1.ld** >Linker for VersatilePB (may be or not be universal)
      * **startuparm.s** >ASM boot shim for ARM926
      * **versatilepb** >Dir for VersatilePB
        * **uart.c** >Early/UART driver
  * **driver** >Non-early drivers (see docs/readme)
    * **audio**
    * **i2c**
    * **screen**
    * **spi**
  * **include** >headers
    * **hllw**
      * **uartfunc.h**
      * **uart.h**
  * **kernel** >Dir with main kernel file
    * **main.c** 
    * **uartfunc.c** >Additional UART stuff (uart_puts,gets,strcmp)
  * **Makefile** >Makefile?
