#include <stdint.h>
#include <hllw/uart.h>
#include <hllw/uartfunc.h>
void uart_puts(const char *str) {
    while (*str) {
        uart_putc(*str++);
    }
}
uint32_t uart_gets(char *buf, int max_len) {
    int i=0;
    while(i< max_len - 1){
		while(!uart_cavailable()){
			//I'm still waiting!
		}
		char c = uart_getc();

		if(c=='\n' || c=='\r'){
			break;
		}
		if (c == 0x7F || c == '\b') {
            if (i > 0) {
                i--;
                // erase the char visually
                uart_putc('\b');
                uart_putc(' ');
                uart_putc('\b');
            }
            continue;
        }        
        buf[i++] = c;
        uart_putc(c);
	}
	buf[i] = '\0';
    
    return i;
}

int strcmp(const char *s1, const char *s2) {
    while (*s1 && (*s1 == *s2)) {
        s1++;
        s2++;
    }
    return *(const unsigned char *)s1 - *(const unsigned char *)s2;
}
