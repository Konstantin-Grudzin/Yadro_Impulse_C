#include "TableMaster.hpp"

int TableMaster::chngTable(std::string& client,int from,int to,Time& t1)
{
    Output& out = Output::getOutput();
    if(to && !tables[to].empty())
    {
        out.out(t1.str()+" 13"+" PlaceIsBusy");
        return from;
    }
    if(from)
        tables[from].free(cost,t1);
    if(to)
        tables[to].setClient(client,t1);
    return to;
}

void TableMaster::rmGamer(int table,Time& t1)
{
    if(table)
        tables[table].free(cost,t1);
}

void TableMaster::finalize()
{
    Output& out = Output::getOutput();
    for(int i=1;i<=sz;++i)
    {
        out.out(std::to_string(i)+" "+std::to_string(tables[i].getValue())+" "+tables[i].getWorkTime());
    }
}