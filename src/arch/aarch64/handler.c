#include "inc/uart.h"

extern void timer_handler2(void);
extern void uart_handler(void);

#define DEBUG

#ifdef DEBUG
static unsigned counter = 0;
#endif


void interrupt_handler() 
{
	uint32_t interrupt_id = __arch_acknowledge_interrupt();

	uart_print_string("> IRQ: ");	
	uart_print_hex(interrupt_id);
	SERIAL_NEWLINE;



#ifdef DEBUG
	counter ++;
	if(counter == 25)
	{
		while(1){}
	}
#endif

	switch (interrupt_id)
	{
		case (TIMER_EL2_IRQ): 
		{
			timer_handler2();
			break;
		}
		case (UART_IRQ): 
		{
			uart_handler();
			break;
		}
		default:
			break;
	}

	__arch_end_of_interrupt(interrupt_id);
	uart_print_string("> IRQ: Cleared");
	SERIAL_NEWLINE;
	SERIAL_LINE_N;
}
