传统的并查集往往容易引起严重的退化，降低算法的复杂度，因此一般采用某种方式让这棵树处于平衡状态。

## 路径压缩

```C++
#include<bits/stdc++.h>
using namespace std;
#define N 100

int fa[N];
int mark[N];
void Init(){
    for(int i=0;i<N;i++){
        fa[i]=i;
        mark[i]=0;
    }
}

//int getroot(int i){
//    if(fa[i]==i)return i;
//    return fa[i]=getroot(fa[i]);
//}

//norecursive-version
int getroot(int i){
    int root=i;
    while(fa[root]!=root){
        root=fa[root];
    }
    int tmp=i;
    while(tmp!=root){
        int next=fa[tmp];
        fa[tmp]=root;
        tmp=next;
    }
    return root;
}
bool q_m(int i,int j){
    return getroot(i)==getroot(j);
}

void merger(int i,int j){
    mark[i]=mark[j]=1;
    int a=getroot(i);
    int c=getroot(j);
    fa[a]=c;
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

```

## 按照子树的大小进行决定合并

```C++
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



```

## Pr

- POJ-2236-Wireless_Network
- POJ-1703-Find_them_Catch_them
