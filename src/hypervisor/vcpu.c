#include "aarch64/inc/uart.h"
#include "hypervisor/vcpu.h"

void vcpu_print_registers(struct VCPU* _vcpu)
{
    uart_print_string("> VCPU: Register Log");
    SERIAL_NEWLINE;

    uart_print_register_colon("X1", _vcpu->regset.x1 ,"X2", _vcpu->regset.x2);
    uart_print_register_colon("X3", _vcpu->regset.x3,"X4", _vcpu->regset.x4);
    uart_print_register_colon("X5", _vcpu->regset.x5,"X6", _vcpu->regset.x6);
    uart_print_register_colon("X7", _vcpu->regset.x7,"X8", _vcpu->regset.x8);
    uart_print_register_colon("X9", _vcpu->regset.x9,"X10", _vcpu->regset.x10);
    uart_print_register_colon("X11", _vcpu->regset.x11,"X12", _vcpu->regset.x12);
    uart_print_register_colon("X13", _vcpu->regset.x13,"X14", _vcpu->regset.x14);

    uart_print_string("> VCPU: End Register Log");
    SERIAL_NEWLINE;
}