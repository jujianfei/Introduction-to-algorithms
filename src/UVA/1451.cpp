// 6602998_AC_110ms_0kB.cpp
#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
#define MAX 100010
int n, L;
char str[MAX];
int sum[MAX], qu[MAX];
double ans;
inline double getK(int i, int j) {
 return (sum[j]-sum[i]) * 1.0 / (j-i);
}
int main() {
    // freopen("in.txt", "r", stdin);
    int caseNum, i;
    scanf("%d", &caseNum);
    while(caseNum--) {
        scanf("%d %d", &n, &L);
        scanf("%s", str+1);
        memset(sum, 0, sizeof(int)*(n+5));
        memset(qu, 0, sizeof(int)*(n+5));
        for(i = 1; i <= n; ++i)
        sum[i] = sum[i-1]+str[i]-'0';
        int len = L;

        ans = getK(0, L);

        int start = 0, end = L;
        int front = 0, rear = -1;


        for(i = L; i <= n; ++i) {
            int temp = i-L;
            //维护下凸曲线
            while(front < rear && getK(qu[rear], temp) <= getK(qu[rear-1], qu[rear])) rear--;
            qu[++rear] = temp;


            //将不是当前最优的点, 从队列里面删除
            while(front < rear && getK(qu[front], i) <= getK(qu[front+1], i)) front++;

            double t = getK(qu[front], i);
            if(t == ans && len > i-qu[front]) {
                len = i-qu[front];
                start = qu[front];
                end = i;
            } else if(t > ans) {
                ans = t;
                len = i-qu[front];
                start = qu[front];
                end = i;
            }
        }
        printf("%d %d\n", start+1, end);
    }
    return 0;
}