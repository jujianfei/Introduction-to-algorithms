
#include <cstdio>
#include <iostream>
using namespace std;
int a[20]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,4,8,9,25,49},ans=0;
char s[20][5];
int main() {
    for(int i=0;i<20;i++){printf("%d\n",a[i]);fflush(stdout);scanf("%s",s[i]);}
    for(int i=0;i<20;i++)if(s[i][0]=='y')ans++;
    if(ans>=2)printf("composite\n");
    else printf("prime\n");
}
