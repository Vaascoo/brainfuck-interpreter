#ifndef __BF_H__
#define __BF_H__

#include <string>
#include <vector>
#include <unordered_map>

#define BF_DEC_PTR '<'
#define BF_INC_PTR '>'
#define BF_INC_MEM '+'
#define BF_DEC_MEM '-'
#define BF_OUT '.'
#define BF_IN ','
#define BF_JMP_FW '['
#define BF_JMP_BCK ']'

namespace bf
{
    class Interpreter
    {
        std::string _code;
        int _pc = 0;
        int _instruction_count;
        long unsigned int _pointer = 0;
        std::vector<char> _tape;
        std::unordered_map<int, int> _jmp_tb;

        void init_jmp_tb();

        void dec_ptr();
        void inc_ptr();
        void inc_mem();
        void dec_mem();
        void out();
        void in();
        void jmp_fw();
        void jmp_bck();

    public:
        Interpreter(std::string code);

        void run();
    };
}

#endif