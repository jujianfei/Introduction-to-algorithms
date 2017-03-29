```C++
#include <stdio.h>  
#include <iostream>  
#include <cstring>  
using namespace std;  
#define N 1007  
  
int n, m;  
int tre[N][N];  
int lowbit(int x) {  
    return x&(-x);  
}  
  
void modify(int x,int y,int delta)  
{  
    for(int i = x; i <= n; i+= lowbit(i)) {  
        for(int j = y; j <= n; j += lowbit(j)) {  
            tre[i][j] += delta;  
        }  
    }  
}  
int get_sum(const int& x,const int& y)  
{  
    int sum = 0;  
    for(int i = x; i > 0; i -= lowbit(i)) {  
        for(int j = y; j > 0; j -= lowbit(j)) {  
            sum += tre[i][j];  
        }  
    }  
    return sum;  
}  
  
  
int main() {  
    //这里数组的下标也是从1开始算起的  
}  
```