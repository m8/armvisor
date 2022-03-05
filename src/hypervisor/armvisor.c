#include "hypervisor/armvisor.h"

/*
    vm_control.S > asm_start_vm
*/
extern void asm_enable_hypervisor();


void armvisor_init()
{
    SERIAL_LINE_N;

    uart_print_string("\
                            _                \n\
                           (_)               \n\
   __ _ _ __ _ __ _____   ___ ___  ___  _ __ \n\
  / _` | '__| '_ ` _ \\ \\ / / / __|/ _ \\| '__|\n\
 | (_| | |  | | | | | \\ V /| \\__ \\ (_) | |   \n\
  \\__,_|_|  |_| |_| |_|\\_/ |_|___/\\___/|_|   \n\
                                             \n\
                                             \n");

    uart_print_string("~~ armvisor started ~~");
    SERIAL_NEWLINE;
    uart_print_string("application: ");
    // uart_print_string(APPLICATION);
    SERIAL_NEWLINE;

    uart_print_string("Exception level: ");
    uart_print_hex(__arch_read_current_el());
    SERIAL_NEWLINE;

    SERIAL_LINE_N;


    /* Configure HCR_El2 register in assembly */
    asm_enable_hypervisor();
    // HYPERVISOR_STATUS.enabled = true;
    
    HYP_LOG_N("Init Success");
}


/*
    Initialize gic and register devices.
*/
void armvisor_set_interrupts(void)
{
    gic_init();
     
    gic_register_device(TIMER_EL2_IRQ);
    HYP_LOG_N("TIMER2 init");

    gic_register_device(UART_IRQ);
    HYP_LOG_N("UART init");
}


/*
    Enable devices and start interrupts
*/
void armvisor_enable_interrupts(void)
{
    HYP_LOG_N("Interrupts enabled");
    SERIAL_LINE_N;

    timer_el2_init();
    uart_enable_interrupts();
}