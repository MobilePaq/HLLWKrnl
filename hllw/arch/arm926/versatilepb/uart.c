#include <stdint.h>
#include <stdbool.h>
#include <hllw/uart.h>

#define UART0_BASE 0x101F1000
#define UART0_DR   ((volatile unsigned int *)(UART0_BASE + 0x00))
#define UART0_FR   ((volatile unsigned int *)(UART0_BASE + 0x18))

#define UART_FR_RXFE (1 << 4)

// (early)UART Driver for ARM926->VersatilePB

void uart_putc(char c) {
    *UART0_DR = (uint32_t)c;
}

bool uart_cavailable(void) {
    return !(*UART0_FR & UART_FR_RXFE);
}

char uart_getc(void) {
    return (char)(*UART0_DR & 0xFF);
}

void uart_init(int speed) {
	// does not need init
    // your (platform specific) code here
}
