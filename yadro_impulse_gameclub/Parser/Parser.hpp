#pragma once
#include <fstream>
#include "Time.hpp"
#include "GamerMaster.hpp"


class Parser
{
private:
    std::ifstream& in;
    TableMaster tm;
    GamerQueue gq;
    GamerMaster gm;
public:
    Parser(std::ifstream& in,int table_size):in(in),tm(table_size){};
    void process();
    void finalize();
    ~Parser() = default;
};

