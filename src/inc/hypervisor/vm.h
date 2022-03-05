#ifndef AV_VM_H
#define AV_VM_H

#include "aarch64/inc/arch_vm.h"

struct VM* CURRENT_VM;
struct VM* NEXT_VM;


/*
    getters-setters
*/
struct VM* vm_set_current(struct VM*);
struct VM* vm_get_current();

/*
    functions
*/
void vm_print_registers(void);
void vm_start_current(void);
void vm_register(struct VM*);


#endif