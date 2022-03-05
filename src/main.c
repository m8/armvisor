#include "aarch64/inc/uart.h"
#include "lib/std.h"
#include "aarch64/inc/arch_vm.h"

#include "hypervisor/loader.h"
#include "hypervisor/armvisor.h"

struct VM vm1;
struct VCPU vcpu1;

int main()
{
     armvisor_init();
     armvisor_set_interrupts();

     vm1.VM_ID = 1;
     vm1.vcpu0.regset.x18 = 0xfeed;
     vm1.vcpu0.regset.x2 = 0xdead;
     vm1.vcpu0.regset.x7 = 0xbeef;
     vm1.vcpu0.regset.x15 = 12;
     vm1.memory_region = 0x60000000;
     load_guest_vm((void *) &vm1, vm1.memory_region);
     // vm1.vcpu0.elr_el2 = vm1.entry_point;
     vm1.vcpu0.spsr_el1 = 0x5;

     register_vm(&vm1);


     CURRENT_VM = &vm1;
     
     armvisor_enable_interrupts();
     vm_start_current();

     while (1)
     {
          __arch_wfi();
     } 

     return 0;
}
