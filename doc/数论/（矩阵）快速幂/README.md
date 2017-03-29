
## 快速幂

迭代的解法

```C++
#include<iostream>  
using namespace std;  
  
long long quickmod(long long a, long long b, long long m) 
{  
    long long ans = 1;  
    while(b)//用一个循环从右到左遍历b的所有二进制位  
    {  
        if(b&1)//判断此时b[i]的二进制位是否为1  
        {  
            ans = (ans*a)%m;//乘到结果上，这里a是a^(2^i)%m  
            b--;//把该为变0  
        }  
        b/=2;  
        a = a*a%m;  
    }  
    return ans;  
}  

```

递归的解法

```C++
ll mod_pow_recurion(ll x,ll n,ll mod)  
{  
    if(n==0)return 1;  
    ll res=mod_pow_recurion(x*x%mod,n/2,mod);  
    if(n&1)res=res*x%mod;  
    return res;  
}  
  
int main(){  
      
}  
```


- 改进：如果上面的乘法可能发生溢出怎么办

```
// return (a * b) % m
LL mod_mult(LL a, LL b, LL m)
{
    LL res = 0;
    LL exp = a % m;
    while (b)
    {
        if (b & 1)
        {
            res += exp;
            if (res > m) res -= m;
        }
        exp <<= 1;
        if (exp > m) exp -= m;
        b >>= 1;
    }
    return res;
}

// return (a ^ b) % m
LL quickmod(LL a, LL b, LL m)
{
    LL res = 1;
    LL exp = a % m;
    while (b)
    {
        if (b & 1) res = mod_mult(res, exp, m);
        exp = mod_mult(exp, exp, m);
        b >>= 1;
    }
    return res;
}
```


## 矩阵快速幂

```C++
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
```


## Pr

- UVA-10006-Carmichael_Number
- POJ-3641-Pseudoprime_numbers
- POJ-1995-Raising_Modulo_Numbers
