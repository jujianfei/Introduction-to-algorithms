#include<bits/stdc++.h>
using namespace std;
#define N 100
int size[N];
int fa[N];
int mark[N];
void Init(){
    for(int i=0;i<N;i++){
        fa[i]=i;
        mark[i]=0;
        size[i]=0;
    }
}

int getroot(int i){
    if(fa[i]==i)return i;
    return getroot(fa[i]);
}

bool q_m(int i,int j){
    return getroot(i)==getroot(j);
}

void merger(int i,int j){
    mark[i]=mark[j]=1;
    int a=getroot(i);
    int b=getroot(j);
    if(size[a]>=size[b]){
        fa[b]=a;
        size[a]+=size[b];
    }else{
        fa[a]=b;
        size[b]+=size[a];
    }
}

int counter(){
    set<int> res;
    for(int i=0;i<N;i++){
        if(mark[i]){
            res.insert(getroot(i));
        }
    }
    return res.size();
}

int main(){
    Init();
    merger(1,2);
    merger(2,3);
    merger(4,5);

    cout<<q_m(3,4)<<endl;
    cout<<counter()<<endl;
}


