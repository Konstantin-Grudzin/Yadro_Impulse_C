#pragma once
#include<queue>

class GamerQueue
{
private:
    std::queue<std::string> q;
public:
    bool full(size_t tm_size){ return q.size()==tm_size;}
    void push(std::string& client){q.push(client);}
    bool empty(){return q.empty();}
    void pop(){return q.pop();}
    std::string& front(){return q.front();}
};