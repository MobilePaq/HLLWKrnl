#include <stdint.h>
#include <stdbool.h>

#ifndef UART
#define UART

void uart_putc(char c);

bool uart_cavailable(void);

char uart_getc(void);

void uart_init(int speed);

#endif
