// 5987558_AC_0ms_1484kB.cpp
#include<cstdio>    
#include<cstring>    
#include<cstdlib>    
#include<cmath>    
#include<iostream>    
#include<algorithm>    
using namespace std;  
#define N int(2e3+10)    
#define inf int(0x3f3f3f3f)    
#define mod int(1e9+7)    
typedef long long LL;  
int main()  
{  
#ifdef OFFLINE    
    freopen("t.txt", "r", stdin);  
#endif    
  
    LL t, n, m, a, k, num;  
    scanf("%lld", &t);  
    while (t--){  
        LL ans = 0, sum = 0;  
        scanf("%lld%lld%lld", &m, &a, &k);  
        if (k == 1){  
            ans += m / a;  
            if (m%a) ans++;  
        }  
        else{  
            num = k / 2;  
            sum = 2 * a * (num*(num + 1) / 2);//需要num人  
            if (sum >= m){  
                while (sum >= m){  
                    sum -= 2 * a * num;  
                    num--;  
                }  
                num++;//通过while找到确切的num  
                ans = num;  
            }  
            else{  
                if (k % 2 == 0){  
                    ans = num;  
                    m -= sum;  
                    if (m > 0){//切记防止让负数参与  
                        //还需加入的人数，这时加入的每个人贡献(2 * a*num)点攻击力  
                        ans += m / (2 * a*num);  
                        if (m % (2 * a*num)) ans++;  
                    }  
                }  
                else{  
                    ans = num;  
                    sum += 2 * a*num + a;//加上留到最后一秒的人的攻击力  
                    m -= sum;  
                    ans++;  
                    if (m > 0){  
                        ans += m / (2 * a*num + a);  
                        if (m % (2 * a*num + a)) ans++;  
                    }  
                }  
            }  
        }  
        printf("%lld\n", ans);  
    }  
    return 0;  
}  