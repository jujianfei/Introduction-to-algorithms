// 5700046_AC_0ms_0kB.cpp
#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
#define MAX 1005

char str[MAX];
int a[3];

int main()
{
//    freopen("input.txt", "r", stdin);
    int caseNum, num = 1;
    scanf("%d", &caseNum);
    while(caseNum--)
    {
        scanf("%s", str);
        memset(a, 0, sizeof(a));
        int len = strlen(str);
        int sum = 0;
        for(int i = 0; i < len; ++i)
        {
            a[ (str[i]-'0')%3 ]++;
            sum += str[i]-'0';
        }
       
        int step = 0;
        if( a[sum%3] )
        {
            step = 1;
            a[sum%3]--;
        }
        if(step) step += a[0];
        printf("Case %d: %s\n", num++, step%2 == 1 ? "S" : "T");
    }
   
    return 0;
}