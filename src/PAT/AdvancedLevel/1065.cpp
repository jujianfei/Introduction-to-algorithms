//好题啊，前两天刚刚看了CSAPP的溢出的部分，
// 首先考虑是不是溢出，如果是上溢出了那么就是大于，如果是下溢出了，就是小于
// 如果没有溢出那么直接判断
// 但是这里注意一个情况，就是补码的范围没有MAX的数值，个人认为这个题目出错了，会给人产生误导

#include <cstdio>  
  
int main(){  
    int n,i;  
    long long int a,b,c;  
  
    scanf("%d",&n);  
    for(i=1;i<=n;++i){  
        bool flg = true;  
        scanf("%lld %lld %lld",&a,&b,&c);  
        long long res = a+b;  
        if(a>0 && b>0 && res<=0)flg = true;  
        else if(a<0 && b<0 && res>=0)flg = false;  
        else{  
            if(res<=c)flg = false;  
        }  
        if(flg){  
            printf("Case #%d: true\n",i);  
        }else{  
            printf("Case #%d: false\n",i);  
        }  
    }  
    return 0;  
}  


