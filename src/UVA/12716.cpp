// 6632183_AC_820ms_0kB.cpp
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
const int RA = 30000000;

int T,N;
int ans[RA + 5];

void Init(){
    int top = RA >> 1,b;
    for(int c = 1; c <= top; ++c){
        for(int a = c + c; a <= RA; a += c){
            b = a - c;
            if((a ^ b) == c) ++ans[a];
        }
    }
    for(int i = 2; i <= RA; ++i) ans[i] += ans[i - 1];
}

int main(){
    Init();
    scanf("%d",&T);
    for(int t = 1; t <= T; ++t){
        scanf("%d",&N);
        printf("Case %d: %d\n",t,ans[N]);
    }
    return 0;
}