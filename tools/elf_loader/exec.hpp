#pragma once

#include <cstdio>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>
#include <array>


// Execute bash commands

std::string exec(const char* cmd) {
    std::string res;
    std::array<char, 256> buffer;
    std::unique_ptr<FILE, decltype(&pclose)> pipe(popen(cmd, "r"), pclose);
    
    while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr) 
    {
        res += buffer.data();
    }
    return res;
}