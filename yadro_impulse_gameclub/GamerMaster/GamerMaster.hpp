#pragma once
#include <string>
#include <map>
#include <algorithm>
#include "Time.hpp"
#include "GamerQueue.hpp"
#include "TableMaster.hpp"
#include "Output.hpp"

class GamerMaster
{
private:
    std::map<std::string,int> gamer_list;
public:
    GamerMaster()=default;
    int addGamer(std::string& client,Time& t1);
    void chngTable(std::string& client,int table,TableMaster& tm,Time& t1);
    void wait(std::string& client,TableMaster& tm,GamerQueue& gq,Time& t1);
    void rmGamer(std::string& client,TableMaster& tm,GamerQueue& gq,Time& t1);
    void rmAll(TableMaster& tm,GamerQueue& gq,Time& t1);
    bool inClub(const std::string& client);
    static bool checkName(const std::string& name);
};