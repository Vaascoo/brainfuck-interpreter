#include "./bf.h"
#include <stdlib.h>
#include <cstdio>
#include <cstring>
#include <iostream>

#define BUF_SZ 1024

void print_help_exit()
{
    perror("Usage:\n\t./brainfuck.py -f <file-path> \n\t\tOR\n\t./braifuck.py -c <code>");
    exit(EXIT_FAILURE);
}

std::string* handle_file(char **argv, int argc, int index) {
    if(index < argc){
        char buffer[BUF_SZ];
        FILE* f = fopen(argv[index], "r");
        if(f){
            std::string *str = new std::string();
            int c;
            while(!feof(f) && (c = fread(buffer, sizeof(char), BUF_SZ - 1, f))){
                buffer[c] = 0;
                str->append(buffer);
            }
            fclose(f);
            return str;
            }
    }
    print_help_exit();
    return nullptr;
}

std::string* handle_arg_string(char **argv, int argc, int index) {
    return nullptr;
}

int main(int argc, char **argv)
{

    if (argc < 2)
        print_help_exit();

    std::string *code = nullptr;

    for(int i = 0; i < argc; i++){
        if (!strcmp("-f", argv[i])){
            code = handle_file(argv, argc, i + 1);
            break;
        }else if(!strcmp("-c", argv[i])){
            //code = handle_arg_string(argc, i + 1);
        }
    }

    if(code == nullptr)
        print_help_exit();

    bf::Interpreter intepreter = bf::Interpreter(*code);
    intepreter.run();

    delete code;
    return 0;
}