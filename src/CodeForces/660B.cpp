#include<stdio.h>
#include<iostream>
#include<list>
#define N 107
using namespace std;
struct Node{
    int fir,sec;
    Node(){
        fir=sec=-1;
    }

};
Node a[N],b[N];
int main(){
    int n,m,cnt=1;
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++){
        a[i].fir=cnt++;
        if(cnt==m+1){
            break;
        }
        b[i].fir=cnt++;
        if(cnt==m+1){
            break;
        }
    }
    if(cnt<m+1){
        for(int i=0;i<n;i++){
            a[i].sec=cnt++;
            if(cnt==m+1){
                break;
            }
            b[i].sec=cnt++;
            if(cnt==m+1){
                break;
            }
        }
    }


    for(int i=0;i<n;i++){
        if(a[i].sec!=-1){
            cout<<a[i].sec<<" ";
        }
        if(a[i].fir!=-1){
            cout<<a[i].fir<<" ";
        }
        if(b[i].sec!=-1){
            cout<<b[i].sec<<" ";
        }
        if(b[i].fir!=-1){
            cout<<b[i].fir<<" ";
        }
    }
    cout<<endl;
}
