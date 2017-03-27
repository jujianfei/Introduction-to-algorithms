#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

#define N 1007
int n,m;
int a[N][N];
int dp1[N][N];
int dp2[N][N];
int dp3[N][N];
int dp4[N][N];

void init() {

}

int main() {
    //freopen("in.txt", "r", stdin);
    scanf("%d%d", &n, &m);
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    //左上角往右下角
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            if (i-1 == 0 && j-1 == 0) { dp1[1][1] = a[1][1]; }
            else if (i==1) {
                dp1[i][j] = dp1[i][j-1] + a[i][j];
            } else if (j==1) {
                dp1[i][j] = dp1[i-1][j] + a[i][j];
            }  else {
                dp1[i][j] = max(dp1[i-1][j], dp1[i][j-1]) + a[i][j];
            }
        }
    }
    //左下角往右上角
    for (int i=n; i>=1; i--) {
        for (int j=1; j<=m; j++) {
            if (i==n&&j==1) {dp2[i][j] = a[n][1];}
            else if(i==n) {//只能向上走
                dp2[i][j] = dp2[i][j-1] + a[i][j];
            } else if(j==1) {//只能向右边走
                dp2[i][j] = dp2[i+1][j] + a[i][j];
            } else {
                dp2[i][j] = max(dp2[i+1][j] + a[i][j], dp2[i][j-1] + a[i][j]);
            }
        }
    }

    //右上角往左下角
    for (int i=1; i<=n; i++) {
        for (int j=m; j>=1; j--) {
            if (i==1 && j==m) {dp3[i][j] = a[i][j];}
            else if (i==1) { //只能向左走
                dp3[i][j] = dp3[i][j+1] + a[i][j];
            } else if (j==m) { //只能向下走
                dp3[i][j] = dp3[i-1][j] + a[i][j];
            } else {
                dp3[i][j] = max(dp3[i][j+1] + a[i][j], dp3[i-1][j] + a[i][j]);
            }
        }
    }

    //右下角往左上角
    for (int i=n; i>=1; i--) {
        for (int j=m;j>=1; j--) {
            if (i==n&&j==m) {
                dp4[i][j] = a[i][j];
            } else if(i==n) {//只能左走
                dp4[i][j] = dp4[i][j+1] + a[i][j];
            } else if(j==m) {//只能上走
                dp4[i][j] = dp4[i+1][j] + a[i][j];
            } else {
                dp4[i][j] = max(dp4[i+1][j] + a[i][j], dp4[i][j+1] + a[i][j]);
            }
        }
    }

    //枚举相遇的位置
     int ans = 0;
        for ( int i = 2; i < n ; i++ )
            for ( int j = 2; j < m ; j++ )
            {
                ans = max ( ans , dp1[i-1][j]+dp4[i+1][j]+dp2[i][j-1]+dp3[i][j+1] );
                ans = max ( ans , dp1[i][j-1]+dp4[i][j+1]+dp2[i+1][j]+dp3[i-1][j] );
            }
        printf ( "%d\n" , ans );

}



