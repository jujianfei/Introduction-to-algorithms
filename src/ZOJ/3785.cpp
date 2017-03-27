// 5939823_AC_20ms_172kB.cpp
#include<stdio.h>
using namespace std;
char day[10][10]={"Saturday","Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday"};
int s[300];

int get(int n){
    int sum = 1;
    for(int i = 1;i<=n;i++){
        sum = sum*n;
        sum%=7;
    }
    return sum;
}

int main(){
    int t,n,i,j,len;
    s[0] = 0;
    for(i = 1;i<=294;i++){
        s[i] = s[i-1]+get(i);
        s[i]%=7;
    }

    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        n%=294;
        printf("%s\n",day[s[n]]);
    }


    return 0;
}
