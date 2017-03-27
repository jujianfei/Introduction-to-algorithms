```C++
#include <sstream>  
#include <string> 

template<typename T>  
//int转化成string  
std::string ToString(T x){  
    std::stringstream sout;  
    sout << x;  
    return sout.str();  
}  
  
//string转化成int  
template<typename T>  
T StringTo(const std::string &s){  
    std::stringstream sout;  
    sout << s;  
    T tmp;  
    sout >> tmp;  
    return tmp;  
}  
//string 转化成vector  
template<typename T>  
std::vector<T> StringToVec(const std::string &s){  
    std::stringstream sout;  
    sout << s;  
    std::vector<T> res;  
    T tmp;  
    while(sout >> tmp){  
        res.push_back(tmp);  
    }  
    return res;  
}  
```
