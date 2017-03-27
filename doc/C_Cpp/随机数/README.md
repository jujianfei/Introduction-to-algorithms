```C++
#include<cstdlib> 

//理论上生成0-1之间的实数  
double random(){  
    srand(time(NULL));  
    return (double)(rand()*1.0/RAND_MAX);  
}  

```