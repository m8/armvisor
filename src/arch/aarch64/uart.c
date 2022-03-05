#include "aarch64/inc/uart.h"

void uart_print_char(const char c)
{
    volatile unsigned int* uartx = (unsigned int *)(0x09000000);
	*uartx = (unsigned int)c;
}

void uart_print_string(const char *s) 
{
	uint32_t i = 0;
	do {
		uart_print_char((unsigned char)s[i++]);
	} while(s[i] != '\0');
}

void uart_print_hex(uint64_t n)
{
	const char *hexdigits = "0123456789ABCDEF";

	for (int i = 60; i >= 0; i -= 4){
		uart_print_char(hexdigits[(n >> i) & 0xf]);
	}
}

void uart_enable_interrupts()
{
    /* Disable the UART */
    UART_DEVICE->CR &= ~CR_UARTEN;

    /* Enable FIFOs */
    UART_DEVICE->LCRH |= LCRH_FEN;

    // Interrupt mask register
    UART_DEVICE->IMSC |= IMSC_RXIM;

    // Interrupt clear register
    UART_DEVICE->ICR  = BE_INTERRUPT;

    /* Enable the UART */
    UART_DEVICE->CR |= CR_UARTEN;
}

void uart_print_register(const char *s,uint64_t n) 
{
	int i = 0;
    uart_print_string("REG:");
	do{
		uart_print_char((unsigned char)s[i++]);
	}while(s[i] != '\0');
    uart_print_string("=");
    uart_print_hex(n);
}

void uart_print_register_colon(const char *s,uint64_t n,const char *s1,uint64_t n1) 
{
	uart_print_register(s,n);
    uart_print_char(' ');
    uart_print_register(s1,n1);
    SERIAL_NEWLINE;
}

// Handle uart interrupt
void uart_handler(void) 
{
    uint32_t status = UART_DEVICE->MIS;

    if (status & RX_INTERRUPT) 
    {
        char c = UART_DEVICE->DR & DR_DATA_MASK;
        uart_print_char(c);
        uart_print_char('\n');
    }
}