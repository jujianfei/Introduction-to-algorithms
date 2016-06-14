#include<bits/stdc++.h>
using namespace std;
#define N 10000
int a[N];
int n=100;
void swaper(int i,int j){
    std::swap(a[i],a[j]);
}
bool test(){
    for(int i=0;i<n-1;i++){
        if(a[i]>a[i+1]){
            cout<<"failed"<<endl;
            return false;
        }
    }
    cout<<"OK"<<endl;
    return true;
}
int partation(int lo,int hi){//前闭后开的区间[lo,hi)
    int begin=lo;
    int end=hi;
    if(lo+1==hi)return lo;
    int tmp=a[lo];
    while(true){
        while(a[--hi]>tmp){if(hi==lo)break;}//这样实际上是可以的
        while(a[++lo]<tmp){if(lo==hi)break;}
        if(lo>=hi)break;//可能出现lo+1>=hi的情况,不要lo==hi
        else swaper(lo,hi);
    }
    swaper(begin,hi);//注意这里是右端点?为什么应该返回右端点?
    return hi;
}
void quicksort(int lo,int hi){
    if(lo+1>=hi)return;//会出现lo左边的区间和右边的区间端点值相同的情况，如果没有>会进入死循环
    int piv=partation(lo,hi);
    quicksort(lo,piv);
    quicksort(piv+1,hi);//一定要注意这里piv放好之后就不能再移动了，否则会进入死循环
}


int main(){
    default_random_engine e;
    for(int i=0;i<n;i++){
        a[i]=e()%100;
    }
    for(int i=0;i<8;i++){
        cout<<a[i]<<" ";
    }cout<<endl;

    quicksort(0,n);

    test();
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }cout<<endl;
}
