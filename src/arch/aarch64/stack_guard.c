#include <stdint.h>

unsigned long __stack_chk_guard;

void __stack_chk_guard_setup(void)
{
    __stack_chk_guard = 0xDEADBEEF;
}

void __stack_chk_fail(void)                         
{
}