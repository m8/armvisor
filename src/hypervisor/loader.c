#include "hypervisor/loader.h"
#include "guest_vm_data.h"


void load_guest_vm(struct VM *_vm, long offset)
{
    av_memcpy((void *)(offset),(void *)vm_text_section_data,vm_text_section_size);
    // av_memcpy((void *)(offset+vm_data_section_offset - 0x00010000) ,(void *)vm_data_section_data,vm_data_section_size);
    // av_memcpy((void *)(offset+vm_v8_aarch64_gicv3_cpuif_section_offset - 0x00010000),(void *)vm_v8_aarch64_gicv3_cpuif_section_data,vm_v8_aarch64_gicv3_cpuif_section_size);
    av_memcpy((void *)(offset+vm_bss_section_offset),(void *)vm_bss_section_data,vm_bss_section_size);
    av_memcpy((void *)(offset+vm_symtab_section_offset),(void *)vm_symtab_section_data,vm_symtab_section_size);
    av_memcpy((void *)(offset+vm_strtab_section_offset),(void *)vm_strtab_section_data,vm_strtab_section_size);
    av_memcpy((void *)(offset+vm_shstrtab_section_offset),(void *)vm_shstrtab_section_data,vm_shstrtab_section_size);
    // av_memcpy((void *)(offset+vm_got_plt_section_offset - 0x00010000),(void *)vm_got_plt_section_data,vm_got_plt_section_size);
    // av_memcpy((void *)(offset+vm_got_section_offset - 0x00010000),(void *)vm_got_section_data,vm_got_section_size);

    _vm->vcpu0.elr_el2 = vm_text_section_start + vm_entry ;
}

