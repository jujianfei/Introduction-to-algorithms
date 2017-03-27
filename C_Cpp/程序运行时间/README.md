
```C++
#include <time.h>

class StopWatch  
{  
public:  
    StopWatch(){ start = clock();}  
    double ElapseTime(){  
        finish = finish=clock();  
        totaltime=(double)(finish-start)/CLOCKS_PER_SEC;  
        return totaltime;  
    }  
  
private:  
    clock_t start,finish;  
    double totaltime;  
  
};  
```