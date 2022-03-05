// Elf-to-C-Header
#include <string>
#include <vector>
#include <memory.h>
#include <fstream>

#include "./elf.hpp"
#include "./exec.hpp"

std::vector<elf_parser::section_t> sections;

#define FILE_NAME "/home/musa/Documents/Hypervisor/arm-hypervisor/hypervisor/vm_ex/vm1/main.elf"

// Finds and returns section from name
elf_parser::section_t get_section_from_name (std::string name,std::vector<elf_parser::section_t> & secs = sections) 
{
    for(auto k: secs){
        if(k.section_name == name){
            return k;
        }
    }
    return {};
}

// Get entry point of elf folder each load.
long get_entry_address(std::string path)
{
    std::string command = "readelf -h \""+path+"\" | grep Entry";
    auto cmd = exec(command.c_str());
    auto parsed_address = cmd.substr(cmd.size()-7).substr(0, 7);
    return (strtol(parsed_address.c_str(), NULL, 16 ));
}

// Generate array for bytes
std::string line_gen(std::string section, std::string & ts, int size)
{
    std::string fake_arr = "unsigned char vm_" + section + "_section_data [] = { ";

    for(int l = 0; l < size; l++)
    {
        auto ss = (int)*((char*)ts.data() + l) ;
        fake_arr += std::to_string(ss);
        if(l+1 == size){} else{fake_arr += ',';}
    }
    
    fake_arr+= " };";
    return fake_arr;
}

// Parse elf file
void load_elf(std::string path)
{    
    std::cout << "burada\n";
    elf_parser::Elf_parser parser {path};
    auto map = parser.get_memory_map();
    auto segs = parser.get_segments();

    sections = parser.get_sections();
    std::ofstream file ("vm.h");
    auto l = get_entry_address(path);
    file << "#ifndef vm_elf_h\n#define vm_elf_h\n\n";
    file << "unsigned long vm_entry = " << std::to_string(l) << ";\n";

    std::cout << "burada\n";

    for(auto sec: sections)
    {
        if(sec.section_name == ""){continue;};
        std::string ts;
        ts.resize(sec.section_size);
        
        memcpy((char*)ts.data(), map + sec.section_offset, sec.section_size );


        file << line_gen(sec.section_name.substr(1, sec.section_name.size() - 1),ts,sec.section_size) + "\n";     

        file << "unsigned long vm_" << sec.section_name.substr(1, sec.section_name.size() - 1) << "_section_size = " << sec.section_size << ";\n";
        file << "unsigned long vm_" << sec.section_name.substr(1, sec.section_name.size() - 1) << "_section_offset = " << sec.section_offset << ";\n";
        
        if(sec.section_name != ".text"){continue;};
        file << "unsigned long vm_" << sec.section_name.substr(1, sec.section_name.size() - 1) << "_section_start = " << sec.section_addr << ";\n";
    }

    std::cout << "burada\n";

    file << "\n#endif\n";
    file.close();
}

int main(int argc,char** argv)
{
    std::cout << "burada\n";
    load_elf(FILE_NAME);
}
