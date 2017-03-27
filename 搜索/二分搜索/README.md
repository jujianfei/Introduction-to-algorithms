## 实现lower/upper/bound

```C++
#include<bits/stdc++.h>
using namespace std;
#define N 10000
int a[N]={1,2,3,3,3,4,4,4,5,6};
bool b[N]={0,0,0,1,1,1,1,1,1,1};
int lower_iter(int lo,int hi,int target){ // [)区间
    int res;
    while(lo<hi){
        int mid=lo+(hi-lo)/2;
        if(a[mid]<target){
            lo=mid+1;
            res=lo;
        }else{
            hi=mid;
            res=hi;
        }
    }
    return res;
}

int upper_iter(int lo,int hi,int target){ // [)区间
    int res;
    while(lo<hi){
        int mid=lo+(hi-lo)/2;
        if(a[mid]<=target){
            lo=mid+1;
            res=lo;
        }else{
            hi=mid;
            res=hi;
        }
    }
    return res;
}

int indexoffirst(int lo,int hi){ // [)区间
    int res;
    while(lo<hi){
        int mid=lo+(hi-lo)/2;
        if(!b[mid]){
            lo=mid+1;
            res=lo;
        }else{
            hi=mid;
            res=hi;
        }
    }
    return res;
}

int upper_recur(int lo,int hi,int target){
    if(lo==hi)return lo;
    int mid=lo+(hi-lo)/2;
    if(a[mid]<target){
        return upper_recur(mid+1,hi,target);
    }else{
        return upper_recur(lo,mid,target);
    }
}

int main(){
 
}

```