#ifndef AV_REGS_H
#define AV_REGS_H

#include <stdint.h>

#define REG32   uint32_t    // 32 bit register
#define REG64   uint64_t    // 64 bit register
#define SREG64  uint64_t    // special registers

struct REGISTER_SET
{
    REG64 x1;
    REG64 x2;
    REG64 x3;
    REG64 x4;
    REG64 x5;
    REG64 x6;
    REG64 x7;
    REG64 x8;
    REG64 x9;
    REG64 x10;
    REG64 x11;
    REG64 x12;
    REG64 x13;
    REG64 x14;
    REG64 x15;
    REG64 x16;
    REG64 x17;
    REG64 x18;
    REG64 x19;
    REG64 x20;
    REG64 x21;
    REG64 x22;
    REG64 x23;
    REG64 x24;
    REG64 x25;
    REG64 x26;
    REG64 x27;
    REG64 x28;
    REG64 x29;
    REG64 x30;
};

struct REGISTER_SET TEMP_REGSET;

#endif  