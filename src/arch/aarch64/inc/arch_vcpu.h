#ifndef AV_ARCH_VCPU_H
#define AV_ARCH_VCPU_H

#include "regs.h"

struct VCPU
{
    struct REGISTER_SET regset;
    SREG64 spsr_el1;
    SREG64 elr_el2;
    SREG64 sp_el1;
    SREG64 pc;
    // floating point register F_REGISTER_SET
};

void vcpu_save(struct VCPU* _vcpu, struct REGISTER_SET* _regset);
void vcpu_save_current();
void vcpu_restore();


#endif