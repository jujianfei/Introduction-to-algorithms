// 6741999_AC_16ms_744kB.cpp
#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <algorithm>
#include <deque>
#include <queue>
#include <set>
#define INF 0x3f3f3f3f
using namespace std;
typedef int LL;
int n;

//矩阵快速幂模板
typedef vector<LL> vec;
typedef vector<vec> mat;
LL M;

mat mul(mat & A, mat & B) {
    LL m = A.size(), n = A[0].size(), p = B[0].size();
    mat C(m, vec(p)); //A:m*n B:n*p C:m*p
    for (LL i=0; i<m; i++) {
        for (LL j=0; j<p; j++) {
            for (LL k=0; k<n; k++)
                C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % M;
        }
    }
    return C;
}

mat pow(mat A, LL n) {

    mat B(A.size(), vec(A.size()));
    for (LL i=0; i<A.size(); i++) B[i][i] = 1;
    while (n > 0) {
        if (n & 1) B = mul(B, A);
        A = mul(A, A);
        n >>= 1;
    }
    return B;
}

int main () {
    //freopen("in.txt", "r", stdin);
    mat B(5, vec(1));
    B[0][0] = 1, B[1][0] = 0, B[2][0] = 0, B[3][0] = 0, B[4][0] = 0;
    while (cin >> n >> M) {
        if (n == 0 && M == 0) break;


        mat a(5, vec(5));
        a[0][0]=1,a[0][1]=1,a[0][2]=1,a[0][3]=2,a[0][4]=0;
        a[1][0]=1,a[1][1]=0,a[1][2]=0,a[1][3]=0,a[1][4]=0;
        a[2][0]=1,a[2][1]=0,a[2][2]=0,a[2][3]=0,a[2][4]=1;
        a[3][0]=1,a[3][1]=0,a[3][2]=0,a[3][3]=1,a[3][4]=0;
        a[4][0]=0,a[4][1]=0,a[4][2]=1,a[4][3]=0,a[4][4]=0;
        a=pow(a, n);
        a=mul(a, B);
        cout << a[0][0] << endl;
    }


}
