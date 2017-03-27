// 15242627_AC_16MS_720K.cc
#include<stdio.h>
#include<iostream>

using namespace std;
int a[7];
int b[4]={0,5,3,1};
void Init(){
    for(int i=0;i<7;i++){
        a[i]=0;
    }
}
bool End(){
    for(int i=1;i<=6;i++){
        if(a[i]!=0)return false;
    }
    return true;
}
int Solve(){
    int ans=0;
    /*****6*****/
    ans+=a[6];
    /*****5*****/
    ans+=a[5];
    for(int i=1;i<=11*a[5];i++){
        if(a[1]==0)break;
        else a[1]--;
    }
    /*****4*****/
    ans+=a[4];
    int used=0;
    for(int i=1;i<=5*a[4];i++){
        if(a[2]==0)break;
        else {
            a[2]--;
            used++;
        }
    }
    int left=a[4]*5-used;
    for(int i=1;i<=left;i++){
        if(a[1]==0)break;
        else a[1]--;
    }
    /*****3*****/
    if(a[3]!=0){

        ans+=(a[3]-1)/4+1;
        used=a[3]%4;
        if(used!=0){
            int can_use=b[used];
            int use=0;
            for(int i=1;i<=can_use;i++){
                if(a[2]==0)break;
                else{
                    a[2]--;
                    use++;
                }
            }
            left=36-used*9-use*4;
            //如何将left转化成最小方格的个数

            for(int i=1;i<=left;i++){
                if(a[1]==0)break;
                else{
                    a[1]--;
                }
            }
        }
    }
    /*****2*****/
    if(a[2]!=0){
        ans+=(a[2]-1)/9+1;
        used=a[2]%9;
        if(used!=0){
            left=(9-used)*4;
            for(int i=1;i<=left;i++){
                if(a[1]==0)break;
                else{
                    a[1]--;
                }
            }
        }
    }
    /*****1*****/
    if(a[1]!=0){
        ans+=(a[1]-1)/36+1;
    }
    return ans;
}

int main(){
    //freopen("D://in.txt","r",stdin);
    while(1){
        for(int i=1;i<=6;i++){
            scanf("%d",&a[i]);
        }
        if(End())break;
        cout<<Solve()<<endl;
    }
}
