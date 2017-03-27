#include <iostream>  
    int main()  
    {  
        __int64 n,m,a;  
        std::cin>>n>>m>>a;  
        __int64 sum=(n/a+(n%a+a-1)/a)*(m/a+(m%a+a-1)/a);  
        std::cout<<sum<<std::endl;  
        return 0;  
    } 