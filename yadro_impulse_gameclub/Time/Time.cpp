#include"Time.hpp"

std::string Time::str() const
{
    int h=value/60;
    int m=value%60;
    std::string str=std::to_string(h/10)+std::to_string(h%10)+":"+std::to_string(m/10)+std::to_string(m%10);
    return str;
};

Time::Time(const std::string& s)
{
    if(s.empty())
    {
        throw std::runtime_error(s);
    }
    size_t pos = -1;
    bool first = 1;
    for(size_t i=0;i<s.size();++i)
    {
        char c = s[i];
        if('0' > c || c > '9')
        {
            if(c==':' && first && i>0 && i<s.size())
            {
                pos = i;
                first = 0;
            }
            else
            {
                throw std::runtime_error(s);
            }
        }
        
    }
    if(pos==std::string::npos)
        throw std::runtime_error(s);
    std::string hh = s.substr(0,pos);
    std::string mm = s.substr(pos+1,s.size() - pos - 1);
    if(hh.size()!=2 || mm.size()!=2)
        throw std::runtime_error(s);
    int HH = std::stoi(hh);
    int MM = std::stoi(mm);
    if(HH>24 || MM>60)
        throw std::runtime_error(s);
    value = HH*60+MM;
}
