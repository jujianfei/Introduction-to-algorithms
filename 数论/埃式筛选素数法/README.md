```C++
#define MAXN 100000  
#include<iostream>  
using namespace std;  
bool is_primer[MAXN];  
int primer[MAXN];  

//获取1-n之间的素数的个数  

int get_primer_num(int n) {  
    int cnt=0;  
    for(int i=0;i<=n;i++) 
        is_primer[i]=true;

    is_primer[0]=is_primer[1]=false;

    for(int i=2;i<=n;i++) {  
        if(is_primer[i]) {  
            primer[cnt++]=i;  
            for(int k=i*i;k<=n;k+=i) {
                is_primer[k]=false;  
            }  
        }  
    }  
    return cnt;  
}  

int main()  
{  
    cout<<get_primer_num(100)<<endl;  
    for(int i=0;i<get_primer_num(100);i++) {  
        cout<<primer[i]<<" ";  
    }cout<<endl;  
}  
```


复杂度是==O(nlgn)，可以在很短的时间内，获得10^6之内的素数。


那么素数的个数是多少

```
pi(x) ~ x/ln(x)
```

