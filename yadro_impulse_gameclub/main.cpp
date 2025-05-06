//TODO: убрать!!!!!!!!!!!
#include<bits/stdc++.h>
#include"Parser.hpp"

//TODO:добавить консты на неизменяемые объекты

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: task.exe <input_file>\n";
        return 1;
    }

    std::ifstream in(argv[1]);
    if (!in.is_open()) {
        std::cerr << "Failed to open file: " << argv[1] << '\n';
        return 1;
    }

    int table_size;
    in>>table_size;
    
    Parser Pars(in,table_size);
    Pars.process();
    Pars.finalize();
    return 0;
}