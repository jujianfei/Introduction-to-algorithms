// 15700530_AC_32MS_4004K.cc

//http://poj.org/problem?id=1014

using namespace std;
#include <iostream>
#include <stdio.h>
#define INF 0x3f3f3f3f
#include <vector>
#include <algorithm>
#include <cstring>
#define N 120007

int dp[7][N];
int w[7];
int v[7];
int sum = 0;
int n = 0;
int casenumber = 1;

void init() {

    sum = 0;
    n = 0;
    memset(w, 0, sizeof(w));
    memset(v, 0, sizeof(v));
    memset(dp, -1, sizeof(dp));

}


void debug(int M) {

    for (int i=0; i<=6; i++) {
        for (int j=0; j<=M; j++) {
            cout <<dp[i][j]<< " ";
        }cout << endl;
    }

}


int main() {

    //freopen("in.txt", "r", stdin);
    init();
    while (1) {

        int temp;
        for (int i=1; i<7; i++) {
            scanf("%d", &temp);
            if (temp) {
                w[n] = temp;
                sum += i*temp;
                v[n++] = i;
            }
        }

        if (sum == 0) break;
        int flag = 0; //ok
        if (sum % 2 == 1) {
            flag = 1; //not ok
        } else {
            dp[0][0] = 0; // 剩余0个
            for (int i=1; i<=n; i++) {
            //前i-1个物品能不能刚好凑出j-value[i-1] * 数量
                for (int j=0; j<=sum/2; j++) {
                    if (dp[i-1][j] >= 0) {
                        dp[i][j] = w[i-1];//如果上一个就能够凑出来那么本次全部剩余
                    } else if (j < v[i-1]) {
                        dp[i][j] = -1;
                    } else {
                        dp[i][j] = dp[i][j - v[i-1]] - 1;
                    }
                }
            }

            if(dp[n][sum/2]<0) { flag = 1; } //not ok

        }


        printf("Collection #%d:\n", casenumber++);
        if (flag == 0) {
            cout << "Can be divided." << endl << endl;
        } else {
            cout << "Can't be divided." << endl << endl;
        }
        init();
    }

}
