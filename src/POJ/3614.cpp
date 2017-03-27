// 15234493_AC_172MS_796K.cc
#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
#define N 2500+7
int n,m;
struct Node{
    int b,e,id;
    Node(int b,int e,int id):b(b),e(e),id(id){}
    Node(){}
};
bool operator <(const Node&n1,const Node&n2){
    if(n1.e>n2.e) return true;
    else if(n1.e<n2.e)return false;
    else return n1.b<n2.b;
}
struct Pro{
    int x,num,id;
};
bool compare(const Pro&n1,const Pro&n2){
    return n1.x<n2.x;
}

priority_queue<Node> d;
Node a[N];
Pro b[N];
bool visited[N];
int main(){
    for(int i=0;i<N;i++){visited[i]=false;}
    //freopen("D://in.txt","r",stdin);
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++){
        scanf("%d%d",&a[i].b,&a[i].e);
        a[i].id=i+1;
    }
    for(int i=0;i<m;i++){
        scanf("%d%d",&b[i].x,&b[i].num);
    }
    sort(b,b+m,compare);
    for(int i=0;i<m;i++){
        while(d.empty()==false){d.pop();}
        for(int j=0;j<n;j++){
            if(visited[a[j].id]==false && a[j].b<=b[i].x && a[j].e>=b[i].x){
                d.push(a[j]);

            }
        }

        int numbers=b[i].num;
        while(numbers--&&d.empty()==false){
            Node fro = d.top();
            visited[fro.id] = true;

            d.pop();
        }
    }
    int ans=0;
    for(int i=0;i<N;i++){
        if(visited[i]==true)ans++;
    }
    cout<<ans<<endl;

}
