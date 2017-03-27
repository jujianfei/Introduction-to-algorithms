// 6736398_AC_63ms_748kB.cpp
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


//矩阵快速幂模板
typedef vector<LL> vec;
typedef vector<vec> mat;
const LL M = 10007;

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
    LL cases;
    cin >> cases;
    mat A(3, vec(3));

    LL n;
    while (cases--) {
        A[0][0] = 2; A[0][1] = 1; A[0][2] = 0;
        A[1][0] = 2; A[1][1] = 2; A[1][2] = 2;
        A[2][0] = 0; A[2][1] = 1; A[2][2] = 2;
            cin >> n;
        A = pow(A, n);
        cout << A[0][0] << endl;
    }
}
