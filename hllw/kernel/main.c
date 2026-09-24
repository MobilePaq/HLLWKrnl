#include <stdint.h>
#include <hllw/uart.h>
#include <hllw/uartfunc.h>

void main(void) {
	char input_buffer[64];
    uart_puts("Welcome to booting HLLWKrnl!!!\n");
    uart_puts("Debug shell!:\n");
    while (1) {
        uart_puts("hllw> ");
        uart_gets(input_buffer, sizeof(input_buffer));
        uart_puts("\n");
        if(strcmp(input_buffer, "help") == 0){
			uart_puts("There is no help. \n");
		}
    }
}
