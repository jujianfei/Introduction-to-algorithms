// 15149892_AC_47MS_8540K.cc
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#define MAXN 1000005
#define RST(N)memset(N, 0, sizeof(N))
using namespace std;

int father[MAXN], flag[MAXN];   //Tag array, 
int n, m, Max, key, cnt, cas = 1;

void Init()   //Initialization, 
{
    for(int i=1; i<=MAXN; i++) father[i] = i;
    RST(flag);
    Max = 0, key = 0, cnt = 0;
}

int Find(int x)   //Look for the root node, 
{
    if(x != father[x]) {
        father[x] = Find(father[x]);
    }
    return father[x];
}

int Union(int x, int y)  //And operation, 
{
    int fx = Find(x), fy = Find(y);
    if(fy != y) return 1;   //Y connected to the X, to ensure that the Y is a root node, or y have two parent node, 
    if(fx == fy) return 1;  //If x, y on the same tree, if in and operation will produce ring, 
    else father[fy] = fx;  //If there are no more than two kinds of operation, merge x, y;
    return 0;
}

int main()
{

    Init();
    while(1) {
        scanf("%d %d", &n, &m);
        if(n <0 && m <0) break;
        if(n > Max) Max = n;
        if(m > Max) Max = m;
        if(n == 0 && m == 0) {
            for(int i=1; i<=Max; i++) {
                if(father[i] == i && flag[i]) cnt++;  //In calculating the number of roots is greater than 2, 
                if(cnt >= 2) break;
            }
            if(key > 0 || cnt >= 2) printf("Case %d is not a tree.\n", cas++);
            else printf("Case %d is a tree.\n", cas++);
            Init(); continue;   //After each test data initialization, 
        }
        flag[n] = 1, flag[m] = 1;  //Mark, 
        key += Union(n, m);   //If there are no legal situation, the value of key will be greater than 0, 
    }
    return 0;
}