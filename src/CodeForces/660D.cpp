#include<stdio.h>
#include<map>
#include<iostream>
#include<algorithm>
using namespace std;
int n;
#define N 3007
struct Node{
    int x,y;

};
bool cmp(const Node&n1,const Node&n2){
    if(n1.x<n2.x)return true;
    else if(n1.x>n2.x)return false;
    else return n1.y<n2.y;
}

Node a[N];

struct Res{
    int dx,dy;
    bool operator <(const Res&r2)const{
        if(dx<r2.dx)return true;
        else if(dx>r2.dx)return  false;
        else return dy<r2.dy;
    }
};
Res p[N];
map<Res,int> m;
int main(){
    //freopen("D://in.txt","r",stdin);
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d%d",&a[i].x,&a[i].y);
    }
    sort(a,a+n,cmp);
    int cnt=0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){

            p[i].dx=a[j].x-a[i].x;
            p[i].dy=a[j].y-a[i].y;
            cnt+=m[p[i]];
            m[p[i]]++;
        }
    }
    cout<<cnt/2<<endl;

}
