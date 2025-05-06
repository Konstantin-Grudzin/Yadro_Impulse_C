#include "GamerMaster.hpp"

bool GamerMaster::checkName(const std::string& name)
{
    return std::all_of(begin(name),end(name),
    [](char c)->bool
    {
        return ('a'<=c && c<='z') || (c=='_') || (c=='-') || ('0'<=c && c<='9');
    });
}

bool GamerMaster::inClub(const std::string& client)
{
    return gamer_list.count(client);
}

int GamerMaster::addGamer(std::string& client,Time& t1)
{
    Output& out = Output::getOutput();
    if(!checkName(client))
        throw std::runtime_error(client);
    if(gamer_list.count(client))
    {
        out.out(t1.str()+" 13"+" YouShallNotPass");
        return 1;
    }
    gamer_list[client] = 0;
    return 0;
}

void GamerMaster::chngTable(std::string& client,int table,TableMaster& tm,Time& t1)
{
    Output& out = Output::getOutput();
    if(!gamer_list.count(client))
    {
        out.out(t1.str()+" 13"+" ClientUnknown");
        return;
    }
    gamer_list[client]=tm.chngTable(client,gamer_list[client],table,t1);
}

void GamerMaster::wait(std::string& client,TableMaster& tm,GamerQueue& gq,Time& t1)
{
    Output& out = Output::getOutput();
    if(!gamer_list.count(client))
    {
        out.out(t1.str()+" 13"+" ClientUnknown");
        return;
    }
    if(!tm.full() || gamer_list[client]!=0)
    {
        out.out(t1.str()+" 13"+" ICanWaitNoLonger!");
        return;
    }
    if(gq.full(tm.size()))
    {
        out.out(t1.str()+" 11"+" "+client);
        gamer_list.erase(client);
        return;
    }
    gq.push(client);
}

void GamerMaster::rmGamer(std::string& client,TableMaster& tm,GamerQueue& gq,Time& t1)
{
    Output& out = Output::getOutput();
    if(!gamer_list.count(client))
    {
        out.out(t1.str()+" 13"+" ClientUnknown");
        return;
    }
    tm.rmGamer(gamer_list[client],t1);
    if(!gq.empty())
    {
        
        std::string nblood=gq.front();
        gq.pop();
        gamer_list[nblood]=tm.chngTable(nblood,gamer_list[nblood],gamer_list[client],t1);
        out.out(t1.str()+" 12 "+nblood+" "+ std::to_string(gamer_list[nblood]));
    }
    gamer_list.erase(client);
}

void GamerMaster::rmAll(TableMaster& tm,GamerQueue& gq,Time& t1)
{
    Output& out = Output::getOutput();
    for(auto& [client,table]:gamer_list)
    {
        tm.rmGamer(table,t1);
        out.out(t1.str()+" 11"+" "+client);
    }
}