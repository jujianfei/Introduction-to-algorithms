## 欧几里得算法

```C++
int gcd(int a, int b) {
    return b == 0? a: gcd(b, a%b);
}
```

这里需要注意的是负数的gcd 

12 , 18 -> 6 
-12, 18 ->6 
-12 , -18->-6 
12, -18->-6

因此总结出，结果为正数或者负数由 绝对值 大的那个数字决定

gcd的递归层数 4.785lgN + 1.673

- 思考如何利用gcd不溢出地求lcm（最小公倍数）


## 扩展的欧几里得算法
基本算法：对于不完全为 0 的 a，b，gcd（a，b）表示 a，b 的最大公约数，必然存在整数对 x，y ，使得 gcd（a，b）=ax+by。
```C++
*int exgcd(int a,int b,int &x,int &y)
{
    if(b==0)
    {
        x=1;
        y=0;
        return a;
    }
    int r=exgcd(b,a%b,x,y);
    int t=x;
    x=y;
    y=t-a/b*y;
    return r;
}*
```

对于ax+by=c这个方程
只有c MOD gcd(a,b) == 0的时候才有解。

设 k = c / gcd(a,b)

首先得到ax+by=gcd(a,b)一组整数解,(x0, y0)

因此原来方程的一组特殊解是 ```x0*(c/g), y0*(c/g)```
一般解是
```x0*(c/g) + k*(b/g), y0*(c/g) - k*(a/g) ```


## Pr

- POJ-2429-GCD_&_LCM_Inverse
- POJ-1930-Dead_Fraction

