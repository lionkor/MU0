#include <iostream>
#include <thread>
#include <array>
#include <algorithm>
#include <chrono>
#include <fstream>
#include "bitops.h"

#define LFN() std::cout << "`" << __PRETTY_FUNCTION__ << "` called" << std::endl
#define LOG(x) std::cout << __FUNCTION__ << ":" << std::dec << __LINE__ << ": " << x << std::endl
#define LOG_V(x) LOG(#x << " = " << x)
#define LOG_VX(x) LOG(#x << " = " << std::hex << x)

using uint = unsigned int;

struct instruction_t {
    uint S : 12;
    uint opcode : 4;
};

class MU0
{
public:
    MU0(const std::string& filepath)
        : memory(new std::uint16_t[s_mem_size]), pc(0) {
        std::ifstream file(filepath, std::ios::binary | std::ios::in);

        file.read(reinterpret_cast<char*>(memory), s_mem_size);

        file.close();
    }
    ~MU0() {
        delete[] memory;
    }

    void step() {
        LOG_VX(pc);

        instruction_t* i = reinterpret_cast<instruction_t*>(&memory[pc]);

        LOG_VX(i->S);
        LOG_VX(i->opcode);

        execute(i);

        LOG_VX(acc);


        std::this_thread::sleep_for(std::chrono::milliseconds(400));
    }

    void execute(instruction_t* i) {
        switch (i->opcode) {
        case 0b0000:
            instr_lda(i);
            break;
        case 0b0001:
            instr_sto(i);
            break;
        case 0b0010:
            instr_add(i);
            break;
        case 0b0011:
            instr_sub(i);
            break;
        case 0b0100:
            instr_jmp(i);
            break;
        case 0b0101:
            instr_jge(i);
            break;
        case 0b0110:
            instr_jne(i);
            break;
        case 0b0111:
            instr_stp(i);
            break;
        default:
            LOG("not implemented: " << std::hex << i->opcode);
            break;
        }
    }

    std::uint16_t read_16(std::size_t i) {
        return *reinterpret_cast<std::uint16_t*>(memory + i);
    }

    void instr_lda(instruction_t* i) {
        LOG("Decoded => LDA 0x" << std::hex << i->S);
        acc = memory[i->S];
        ++pc;
    }
    void instr_sto(instruction_t* i) {
        LOG("Decoded => STO 0x" << std::hex << i->S);
        memory[i->S] = acc;
        ++pc;
    }
    void instr_add(instruction_t* i) {
        LOG("Decoded => ADD 0x" << std::hex << i->S);
        acc += memory[i->S];
        ++pc;
    }
    void instr_sub(instruction_t* i) {
        LOG("Decoded => SUB 0x" << std::hex << i->S);
        acc -= memory[i->S];
        ++pc;
    }
    void instr_jmp(instruction_t* i) {
        LOG("Decoded => JMP 0x" << std::hex << i->S);
        pc = i->S;
    }
    void instr_jge(instruction_t* i) {
        LOG("Decoded => JGE 0x" << std::hex << i->S);
        if (acc >= 0)
            pc = i->S;
        else
            ++pc;
    }
    void instr_jne(instruction_t* i) {
        LOG("Decoded => JNE 0x" << std::hex << i->S);
        if (acc != 0)
            pc = i->S;
        else
            ++pc;
    }
    void instr_stp(instruction_t* i) {
        LOG("Decoded => STP");
    }

    constexpr static std::size_t s_mem_size = 4096;

private:
    std::uint16_t* memory;
    std::uint16_t  pc;
    std::uint16_t  acc;
};

int main(int argc, char** argv) {
    std::string filename = "memory.bin";

    if (argc == 2) {
        filename = argv[1];
    }

    MU0 proc(filename);

    while (true) {
        proc.step();
    }
}
