// 6409765_AC_20ms_0kB.cpp
#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;

#define N 100007

int tail,cur,nexter[N],n;
char v[N];

int main() {
    //freopen("in.txt", "r", stdin);
    while (gets(v+1)){

        n = strlen(v+1);
        tail = cur = 0;
        nexter[0] = 0;//空表

        for (int i=1; i<=n; i++) {
            char c = v[i];
            if (c == '[') { cur = 0; }
            else if (c == ']') { cur = tail; }
            else {
                nexter[i] = nexter[cur];
                nexter[cur] = i;
                if (cur == tail) { tail = i; }
                cur = i;
            }
        }
        for (int i=nexter[0]; i!=0; i=nexter[i]){
            printf("%c", v[i]);
        }
        printf("\n");
    }
}



