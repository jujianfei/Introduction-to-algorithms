#include<bits/stdc++.h>
using namespace std;
/*
Num[col]:存放矩阵T中每一行非零元的个数
Cpot[col]:存放矩阵T中每一行非零元的当前存放的位置
初始时为每一行第一个非零元存放的位置
*/
struct Node{
    int i,j,e;
};
#define N 100
struct Matrix{

    int col,row;
    int n;
    Node a[N];
    void show(){
        for(int k=1;k<=n;k++){
            cout<<a[k].i<<" "<<a[k].j<<" "<<a[k].e<<" "<<endl;
        }
    }
    Matrix(){
        col=5,row=3,n=5;//n代表元素的个数
        a[1].i=1;a[1].j=2;a[1].e=14;
        a[2].i=1;a[2].j=5;a[2].e=-5;
        a[3].i=2;a[3].j=2;a[3].e=-7;
        a[4].i=3;a[4].j=1;a[4].e=36;
        a[5].i=3;a[5].j=4;a[5].e=28;
    }
};
Matrix transpose(Matrix m){
    const int CN=m.col;
    int numcol[CN+1];memset(numcol,0,sizeof(numcol));//0,index不使用
    int cpot[CN+1];memset(cpot,0,sizeof(cpot));
    for(int k=1;k<=m.n;k++){
        numcol[m.a[k].j]++;
    }//计算原来的矩阵每列有几个元素，也就是转置之后每行有几个元素

    cpot[1]=1;
    for(int i=2;i<=CN;i++){
        cpot[i]=numcol[i-1]+cpot[i-1];
        cout<<cpot[i]<<endl;
    }
    //计算每个元素在新的矩阵中，从那个位置开始写入
    Matrix ret;
    ret.col=m.row;
    ret.row=m.col;
    ret.n=m.n;
    for(int k=1;k<=ret.n;k++){
        int target_position=cpot[m.a[k].j]++;//这里注意要递增开始位置
        ret.a[target_position].i=m.a[k].j;
        ret.a[target_position].j=m.a[k].i;
        ret.a[target_position].e=m.a[k].e;
    }
    return ret;
}
int main(){
    Matrix a;

    transpose(a).show();
}
