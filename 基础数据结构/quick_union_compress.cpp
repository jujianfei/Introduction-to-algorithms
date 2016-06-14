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


