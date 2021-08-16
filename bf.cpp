#include <iostream>
#include <cstdio>
#include <vector>
#include <unordered_map>
#include <cassert>
#include "./bf.h"

bf::Interpreter::Interpreter(std::string code)
{
    _code = code;
    _instruction_count = code.length();
    _tape = std::vector<char>(1024, '\0');
    _jmp_tb = std::unordered_map<int, int>();
    init_jmp_tb();
}

void bf::Interpreter::init_jmp_tb()
{
    std::vector<int> stack;
    for (unsigned int i = 0; i < _code.length(); i++)
    {
        if (_code[i] == '[')
            stack.push_back(i);
        else if (_code[i] == ']')
        {
            int temp = stack[stack.size() - 1];
            stack.pop_back();
            _jmp_tb.insert({i, temp});
            _jmp_tb.insert({temp, i});
        }
    }
    assert(stack.empty());
}

void bf::Interpreter::dec_ptr()
{
    _pointer = (_pointer - 1) % _tape.size();
}

void bf::Interpreter::inc_ptr()
{
    _pointer++;
    if (_pointer > _tape.size())
        _tape.resize((int)(2 * _tape.size()));
}

void bf::Interpreter::inc_mem()
{
    _tape[_pointer]++;
}

void bf::Interpreter::dec_mem()
{
    _tape[_pointer]--;
}

void bf::Interpreter::out()
{
    putchar(_tape[_pointer]);
}

void bf::Interpreter::in()
{
    _tape[_pointer] = getchar();
}

void bf::Interpreter::jmp_fw()
{
    if (!_tape[_pointer])
        _pc = _jmp_tb.at(_pc);
}

void bf::Interpreter::jmp_bck()
{
    if (_tape[_pointer])
        _pc = _jmp_tb.at(_pc);
}

void bf::Interpreter::run()
{
    while (_pc < _instruction_count)
    {
        switch (_code[_pc])
        {
        case '<':
            dec_ptr();
            break;
        case '>':
            inc_ptr();
            break;
        case '+':
            inc_mem();
            break;
        case '-':
            dec_mem();
            break;
        case '.':
            out();
            break;
        case ',':
            in();
            break;
        case '[':
            jmp_fw();
            break;
        case ']':
            jmp_bck();
            break;
        }
        _pc++;
    }
}