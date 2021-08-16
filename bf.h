#ifndef __BF_H__
#define __BF_H__

#include <string>
#include <vector>
#include <unordered_map>

namespace bf
{
    class Interpreter
    {
        std::string _code;
        int _pc = 0;
        int _instruction_count;
        int _pointer = 0;
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