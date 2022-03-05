#include "hypervisor/vm.h"
#include "aarch64/inc/uart.h"

/*
    vm_control.S > asm_start_vm
*/
extern void asm_start_vm();


void register_vm(struct VM* _vm)
{
    HYP_LOG_N("VM regiter start");
    HYP_LOG("VM id: ");
    uart_print_hex(_vm->VM_ID);
    SERIAL_NEWLINE;
    HYP_LOG("VM start addr: ");
    uart_print_hex(_vm->memory_region);
    SERIAL_NEWLINE;
}

struct VM* set_current_vm(struct VM* _vm)
{
    CURRENT_VM = _vm;
    return CURRENT_VM;
}

struct VM* get_current_vm()
{
    return CURRENT_VM;
}

void vm_start_current(void)
{
    asm_start_vm();
}
