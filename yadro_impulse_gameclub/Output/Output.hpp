#pragma once
#include<vector>
#include<string>
#include<iostream>

class Output
{
private:
    std::vector<std::string> output;
    static Output* ptr;
    Output() = default;
public:
    Output(const Output&) = delete;
    Output& operator=(const Output&) = delete;
    static Output& getOutput()
    {
        if(ptr==nullptr)
            ptr=new Output;
        return *ptr;
    }
    void out(const std::string& str){output.push_back(str);}
    void finalize()
    {
        for(auto& el:output)
        {
            std::cout<<el<<"\n";
        }
    }
};
