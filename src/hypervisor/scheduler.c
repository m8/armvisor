#include "hypervisor/vm.h"


int hyp_start_sched()
{
    if(CURRENT_VM->VM_ID == 1)
    {
        setup_vm1_stage2_level1();
    }
    else
    {     
        setup_vm1_stage2_level1();
    }

    asm_start_vm();   
}



void schedule_switch_order()
{
    struct VM* buf = CURRENT_VM;
    CURRENT_VM = NEXT_VM;
    NEXT_VM = buf;
}


void schedule_start()
{

}