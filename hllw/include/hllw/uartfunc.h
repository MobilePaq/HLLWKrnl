#include <stdint.h>
#include <stdbool.h>
#ifndef UARTFUNC
#define UARTFUNC

void uart_puts(const char *str);
uint32_t uart_gets(char *buf, int max_len);
int strcmp(const char *s1, const char *s2);

#endif
