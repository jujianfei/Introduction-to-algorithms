#include<bits/stdc++.h>
using namespace std;
#define N 100
int a[N];
void sorter(int lo,int hi){
    if(lo>=hi)return;
    int v=a[lo];
    int i=lo+1;
    int lt=lo,gt=hi;
    while(i<=gt){
        int tmp=a[i];
        if(tmp==v)i++;
        else if(tmp>v) std::swap(a[i],a[gt--]);
        else std::swap(a[i++],a[lt++]);
    }
    sorter(lo,lt-1);
    sorter(lt,gt);
    sorter(gt+1,hi);
}
void test(){
    default_random_engine e;
    for(int i=0;i<N;i++){
        a[i]=e();
    }
    sorter(0,N-1);
    for(int i=0;i<N-1;i++){
        if(a[i]>a[i+1]){
            cout<<"fail"<<endl;
            return;
        }
    }
    cout<<"OK"<<endl;
    return;
}


int main(){
    test();
}
