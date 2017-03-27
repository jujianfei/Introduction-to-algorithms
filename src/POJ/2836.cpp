// 6747409_AC_110ms_644kB.cpp
#include <cstdio>  
#include <cstring>  
#include <cmath>  
#include <algorithm>  
using namespace std;  
  
struct Rect {  
    int area;  
    int pset;  
}rect[300];  
  
int dp[1<<16];  
int x[20], y[20];  
int n;  
  
int main() {  
    while(scanf("%d", &n) && n) {  
        for(int i = 0; i < n; i++)  
            scanf("%d%d", &x[i], &y[i]);  
        int cnt = 0;  
        for(int i = 0; i < n-1; i++) {  
            for(int j = i+1; j < n; j++) {  
                rect[cnt].area = max(1, abs(x[i]-x[j]))*max(1, abs(y[i]-y[j]));  
                rect[cnt].pset = (1<<i) | (1<<j);  
                for(int k = 0; k < n; k++) {  
                    if((x[i]-x[k])*(x[j]-x[k]) <= 0 && (y[i]-y[k])*(y[j]-y[k]) <= 0)  //判断是不是在那个矩形的范围之内
                        rect[cnt].pset |= 1<<k;  
                }  
                cnt++;  
            }  
        }  
        fill(dp, dp+(1<<16), 1<<30);  
        dp[0] = 0;  
        for(int i = 0; i < cnt; i++) {  
            for(int j = 0; j < 1<<n; j++) {  
                int p = j|rect[i].pset;  
                if(dp[j] != 1<<30 && p != j) {  
                    dp[p] = min(dp[p], dp[j]+rect[i].area);  //因为有可能有很多个状态都指向这个状态，如果反向的搜索，复杂度会升高，并且有很多没有意义的搜索
                }  
            }  
        }  
        printf("%d\n", dp[(1<<n)-1]);  
    }  
    return 0;  
}  