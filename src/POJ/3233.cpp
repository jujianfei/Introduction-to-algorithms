// 6743835_AC_1141ms_840kB.cpp
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
typedef long long LL;
LL n,k, M;


//矩阵快速幂模板
typedef vector<LL> vec;
typedef vector<vec> mat;


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


int main() {
    //freopen("in.txt","r", stdin);
    cin >> n >> k >> M;
    mat A(n, vec(n));
    for (LL i=0; i<n; i++)  {
        for (LL j=0; j<n; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    mat B(n*2, vec(n*2));
    for (LL i=0; i<n; i++) {
        for (LL j=0; j<n; j++) {
            B[i][j] = A[i][j];
        }
        B[n+i][i] = B[n+i][n+i] = 1;
    }
    B = pow(B, k+1);
    for (LL i=0; i<n; i++) {
        for (LL j=0; j<n; j++) {
            LL a=B[n+i][j] % M;
            if (i==j) a=(a+M-1)%M;
            printf("%lld%c", a, j+1==n? '\n' : ' ');
        }
    }
}
