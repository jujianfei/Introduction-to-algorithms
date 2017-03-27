// 15280818_AC_94MS_1468K.cc
#include <iostream>  
#include <cstdio>  
#include <cstring>  
#include <set>  
#include <queue>  
#include <algorithm>  
#define MAXN 111111  
#define MAXM 222222  
#define INF 1000000000  
using namespace std;  
struct node  
{  
    int x, y;  
}a[MAXN];  
int n;  
bool cmp(node x, node y)  
{  
    return x.x * y.y < x.y * y.x;  
}  
int main()  
{  
    scanf("%d", &n);  
    for(int i = 0; i < n; i++)  
    {  
        scanf("%d%d", &a[i].x, &a[i].y);  
        a[i].x *= 2;  
    }  
    sort(a, a + n, cmp);  
    long long ans = 0;  
    long long sum = 0;  
    for(int i = 0; i < n; i++)  
    {  
        ans += sum * (long long)a[i].y;  
        sum += a[i].x;  
    }  
    printf("%I64d\n", ans);  
    return 0;  
}  