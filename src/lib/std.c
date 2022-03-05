#include "lib/std.h"

void av_memcpy(void * dest, void * src, int byte)
{
    char *cpy_src = (char *)src;
    char *cpy_dest = (char *)dest;
    
    size_t i = 0;
    for (i = 0; i < byte; i++)
    {
       cpy_dest[i] = cpy_src[i];
    }
    return;
}


