#include "aarch64/inc/ptable.h"


void setup_vm1_stage2_level1()
{
     ASM("MSR VTTBR_EL2, %0":: "r" (&pt_s2_l1_vm1));

     long VTCR_EL2_VAL = 32 | (0x1 << 6) | (0x1 << 8) | (0x1 << 10) | (0x3 << 12);
     
     ASM("MSR VTCR_EL2, %0":: "r" (VTCR_EL2_VAL));

     pt_s2_l1_vm1[0] = TT_S2_DEVICE_nGnRnE | TT_BLOCK | TT_S2_RW | TT_S2_AF | TT_S2_INNER_SHARED;
     pt_s2_l1_vm1[1] = 0x50000000 | TT_S2_DEVICE_nGnRnE | TT_BLOCK | TT_S2_RW | TT_S2_AF | TT_S2_INNER_SHARED;

     ASM("DSB SY");

     long HCR_EL_2_VAL = 1 | (1 << 3) | (1 << 4) | (1 << 31);

     ASM("MSR HCR_EL2, %0"::"r" (HCR_EL_2_VAL));
}

void setup_vm2_stage2_level1()
{
     ASM("MSR VTTBR_EL2, %0":: "r" (&pt_s2_l1_vm2));

     long VTCR_EL2_VAL = 32 | (0x1 << 6) | (0x1 << 8) | (0x1 << 10) | (0x3 << 12);
     
     ASM("MSR VTCR_EL2, %0":: [addr] "r" (VTCR_EL2_VAL));


     pt_s2_l1_vm2[0] = TT_S2_DEVICE_nGnRnE | TT_BLOCK | TT_S2_RW | TT_S2_AF | TT_S2_INNER_SHARED;
     pt_s2_l1_vm2[1] = 0x60000000 | TT_S2_DEVICE_nGnRnE | TT_BLOCK | TT_S2_RW | TT_S2_AF | TT_S2_INNER_SHARED;

     ASM("DSB SY");

     long HCR_EL_2_VAL = 1 | (1 << 3) | (1 << 4) | (1 << 31);

     ASM("MSR HCR_EL2, %0"::"r" (HCR_EL_2_VAL));
}