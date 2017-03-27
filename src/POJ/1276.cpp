// 15187259_AC_16MS_1120K.cc
#include<stdio.h>
#include<iostream>//iostream一定要放在stdio的后面
#include<cmath>
#include<vector>
#include<map>
#define N 100000+7
#define INF 0xfffffff
using namespace std;
//典型的多重部分和问题
int d[N];
int a[11];
int m[11];
int W,n;
int main(){
    //freopen("D://in.txt","r",stdin);
    while(cin>>W>>n){

        for(int pair=0;pair<n;pair++){
            cin>>m[pair]>>a[pair];
        }
        for(int i=0;i<N;i++) d[i]=-1;
        d[0]=0;

        //记录前i种物品,凑出j重量是还剩下多少个重复利用数组

        for(int i=0;i<n;i++){
            for(int j=0;j<=W;j++){
                if(d[j]>=0){
                    d[j]=m[i];
                }else if(j<a[i]){
                    d[j]=-1;//不能使用这个数加和得到j的条件下,输出-1
                }else{
                    d[j]=d[j-a[i]]-1;
                }
            }
        }

        int ans=W;
        while(d[ans]<0){
            ans--;
        }
        cout<<ans<<endl;


    }
}
