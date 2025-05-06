#pragma once
#include "Time.hpp"
#include "Output.hpp"
#include <vector>
#include <algorithm>

class Table
{
private:
    std::string client;
    bool full=0;
    Time start;
    int value=0;
    Time work_time;
public:
    Table():work_time("00:00"),start("00:00"){};
    bool empty(){return !full;}
    void setClient(const std::string& clt,const Time& t)
    {
        if(full) return;
        client=clt;
        full=1;
        start=t;
    }
    void free(int cost,Time& t)
    {
        client="";
        full=0;
        int total_time =  t - start;
        work_time+=total_time;
        total_time = (total_time+59)/60;
        value+=cost*total_time;

    }
    int getValue() {return value;}
    std::string getWorkTime(){return work_time.str();}
    const std::string& getName() {return client;}
};

class TableMaster
{
private:
    std::vector<Table> tables;
    const size_t sz;
    int cost;
public:
    TableMaster(size_t sz):sz(sz),tables(sz+1){tables[0].setClient("#",static_cast<std::string>("00:00"));}
    int chngTable(std::string& client,int from,int to,Time& t1);
    void rmGamer(int table,Time& t1);
    void finalize();
    void setCost(int cst)
    {
        if(cst>=0)
            cost=cst;
    }
    bool full()
    {
        return std::none_of(tables.begin(),tables.end(),
        [](Table& tbl)->bool
        {
            return tbl.empty();
        });
    }
    size_t size() {return sz;}
};