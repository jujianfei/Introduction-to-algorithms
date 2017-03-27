// 6998738_AC_0ms_388kB.cpp
#include<cstdio>  
  
int get2 ( int n )  
{  
    if ( n == 0 )  
        return 0;  
    return n/2 + get2(n/2);  
}  
  
int get5 ( int n )  
{  
    if ( n == 0 )  
        return 0;  
    return n/5 + get5(n/5);  
}  
  
int g ( int n, int x )  
{  
    if ( n == 0 )  
        return 0;  
    return n/10 + ( n%10 >= x ) + g(n/5,x);  
}  
  
int getx ( int n, int x )  
{  
    if ( n == 0 )  
        return 0;  
    return getx ( n/2, x ) + g ( n, x );  
}  
  
int table[4][4] =  
{  
    6,2,4,8, // 2的循环节。2^0 = 1，需要特殊处理。  
    1,3,9,7, // 3  
    1,7,9,3, // 7  
    1,9,1,9,  // 9  
};  
  
int main()  
{  
    int n, m;  
    while ( scanf("%d%d",&n,&m) != EOF )  
    {  
        int num2 = get2(n) - get2(n-m);  
        int num5 = get5(n) - get5(n-m);  
        int num3 = getx(n,3) - getx(n-m,3);  
        int num7 = getx(n,7) - getx(n-m,7);  
        int num9 = getx(n,9) - getx(n-m,9);  
        int res = 1;  
        if ( num5 > num2 )  
        {  
            printf("5\n");  
            continue;  
        }  
        else  
        {  
            if ( num5 != num2 )  
            {  
                res *= table[0][(num2-num5)%4];  
                res %= 10;  
            }  
            res *= table[1][num3%4];  
            res %= 10;  
            res *= table[2][num7%4];  
            res %= 10;  
            res *= table[3][num9%4];  
            res %= 10;  
        }  
        printf("%d\n",res);  
    }  
    return 0;  
}