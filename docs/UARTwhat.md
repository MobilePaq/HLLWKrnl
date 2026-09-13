# Uart what it need
Base Uart driver for ANY platform should implement these functions
```C
void uart_putc(char c) {
    // your (platform specific) code here
    // e.g.
    *(volatile uint32_t *)UART_TX = c;
    *(volatile uint32_t *)UART_TX_CTRL = 1;
    while (*(volatile uint32_t *)UART_STATUS & BUSY) {
        // I'm still waiting...
    }
}

bool uart_cavailable(void) {
    // your (platform specific) code here
    // returns true if RX buffer contains at least 1 byte
    return *(volatile uint32_t *)UART_RX_BUFFER_COUNT > 0;
}

char uart_getc(void) {
    // your (platform specific) code here
    return (char)(*(volatile uint32_t *)UART_RX);
}

void uart_init(int speed) {
    // your (platform specific) code here
    *(volatile uint32_t *)UART_MAGIC = 0x171DEAD1;
    *(volatile uint32_t *)UART_SPEED = speed;
}
```
- In kernel, there should be functions for writing a char array (for cycle) and reading string till end (\n)
- Drivers should be placed in (this repo, HLLWKrnl)/hllw/arch/(your arch)/driver/(your soc)/(your thing/UART).c
- e.g HLLWKrnl/hllw/arch/arm/driver/sun4i/UART.c
