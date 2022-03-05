#include "aarch64/inc/arch_vm.h"
#include "aarch64/inc/arch_vcpu.h"
#include "aarch64/inc/regs.h"
#include "hypervisor/vcpu.h"

void vm_save(struct VM* _vm)
{
    // Should be changed with all cores
    vcpu_save(&_vm->vcpu0, &TEMP_REGSET);

}