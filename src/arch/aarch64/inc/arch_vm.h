#ifndef AV_ARCH_VM_H
#define AV_ARCH_VM_H

#include "arch_vcpu.h"

struct VM
{
    // page table entry point
    struct VCPU vcpu0;
    uint32_t VM_ID;
    uint64_t memory_region;
    uint64_t entry_point;
};


#endif