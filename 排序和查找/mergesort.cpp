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

void merger(int lo,int mid,int hi){//合并元素前闭后开的区间[lo,mid)[mid,hi)
    if(lo+1==hi)return;//边界条件检查，只有一个元素
    int aid[N];
    for(int i=lo;i<hi;i++){
        aid[i]=a[i];
    }
    int k=lo,p=lo,q=mid;
    while(k<hi){
        if(q==hi){
            a[k++]=aid[p++];
        }else if(p==mid){
            a[k++]=aid[q++];
        }else if(aid[p]<aid[q]){
            a[k++]=aid[p++];
        }else{
            a[k++]=aid[q++];
        }
    }
}
void merge_sort(int lo,int hi){
    if(lo+1>=hi)return;
    int mid=lo+(hi-lo)/2;
    merge_sort(lo,mid);
    merge_sort(mid,hi);
    merger(lo,mid,hi);
}

int main(){
    default_random_engine e;
    for(int i=0;i<n;i++){
        a[i]=e()%100;
    }
    merge_sort(0,n);
    test();
    for(int i=0;i<100;i++){
        cout<<a[i]<<" ";
    }cout<<endl;
}
