/*
    Setup 2 stage address translation for virtual machines.
*/
#include "utils.h"

#define TT_BLOCK    0x1
#define TT_S2_RW    0x3 << 6
#define TT_S2_AF    0x1 << 10
#define TT_S2_INNER_SHARED  (0x3 << 8)
#define TT_S2_DEVICE_nGnRnE (0x0 << 2)
#define TT_S2_NORMAL_WBWA   (0xF << 2)

unsigned long pt_s2_l1_vm1 [512]            __attribute__ ((aligned (4096)));
unsigned long pt_s2_l1_vm2 [512]            __attribute__ ((aligned (4096)));

