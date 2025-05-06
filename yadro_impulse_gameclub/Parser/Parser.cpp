#include "Parser.hpp"

void Parser::process()
{
    try
    {
        Output& out = Output::getOutput();
        std::string st,fn;in>>st>>fn;
        Time open(st);
        Time close(fn);
        if(open>=close)
        {
            throw std::runtime_error(st+" "+fn);
        }

        Time Last_requst_time("00:00");
        int table_cost;
        in>>table_cost;

        if(table_cost<=0)
        {
            throw std::runtime_error(std::to_string(table_cost));
        }
        tm.setCost(table_cost);
        out.out(st);
        for(;;)
        {
            std::string time,id,client,table;
            try
            {
                in>>time>>id;
                if(in.fail())
                {
                    break;
                }
                Time t1(time);
                if(t1 < Last_requst_time) throw std::runtime_error(time+" "+id+" "+client+" "+table);
                
                if(id == "1")
                {
                    in>>client;
                    out.out(time+" "+id+" "+client);
                    if(gm.inClub(client))
                    {
                        out.out(t1.str()+" 13"+" YouShallNotPass");
                        continue;
                    }
                    if(t1 < open || t1 > close)
                    {
                        out.out(t1.str()+" 13"+" NotOpenYet");
                        continue;
                    }
                    gm.addGamer(client, t1);
                }
                else if(id == "2")
                {
                    in>>client;
                    in>>table;
                    out.out(time+" "+id+" "+client+" "+table);
                    int table_int=std::stoi(table);
                    if(table_int<=0 || table_int>tm.size())
                    {
                        throw std::runtime_error(time+" "+id+" "+client+" "+table);
                    }
                    gm.chngTable(client,table_int,tm,t1);
                }
                else if(id == "3")
                {
                    in>>client;
                    out.out(time+" "+id+" "+client);
                    gm.wait(client,tm,gq,t1);
                }
                else if(id == "4")
                {
                    in>>client;
                    out.out(time+" "+id+" "+client);
                    gm.rmGamer(client,tm,gq,t1);
                }
                else
                {
                    throw std::runtime_error(time+" "+id+" "+client+" "+table);
                }
                if(in.fail())
                {
                    throw std::runtime_error(time+" "+id+" "+client+" "+table);
                }
                Last_requst_time = t1;
            }
            catch(const std::exception& e)
            {
                throw std::runtime_error(time+" "+id+" "+client+" "+table);
            }
        }
        gm.rmAll(tm,gq,close);
        out.out(fn);
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << '\n';
        exit(0);
    }
    
    
}

void Parser::finalize()
{
    Output& out = Output::getOutput();
    tm.finalize();
    out.finalize();
}
