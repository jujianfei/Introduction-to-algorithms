// 14962513_AC_16MS_732K.cc
#include<iostream>
#include <stdlib.h>
#include <stdio.h>
#include<vector>
#include<fstream>
using namespace std;
int d[10][150];
int cnt=0;
int mark[10];
int factorial(int t) //阶乘计算函数 ，返回t的阶乘
{
   if(t==0||t==1) return 1;
   return t*factorial(t-1);
}

int  cmn(int n,int m)
{
   return factorial(n)/(factorial(m)*factorial(n-m)) ;//组合数计算公式
}


int how=0;
int dfs(vector<string>&G,int level,int k,int n,int line)
{
    //cout<<"indfs->level"<<level<<" "<<"lines"<<line<<endl;
    if(level==k)
    {
        how++;
    }
    else
    {
        for(int i=0;i<n;i++)
        {
            if(G[i][d[line][level]]=='#'&&mark[i]==0)
            {
                mark[i]=1;
                G[i][d[line][level]]='.';
                dfs(G,level+1,k,n,line);
                G[i][d[line][level]]='#';
                mark[i]=0;
            }
        }
    }
}




void printCombo(int idx_arr[], int eArr[],int m)
{

    int i;
    for (i=0;i<m;i++)
        {
            d[cnt][i]=eArr[idx_arr[i]];
            //cout<<d[cnt][i]<<" ";
        }
        //cout<<"*******"<<endl;

   cnt++;
}



// combos是一个递归函数，使用回溯法，求从n个元素中取m个元素的组合
// 取到元素的序号保存在数组idx_arr中，每个序号的范围为从0到n-1
// level为递归深度,取值范围为0到m-1,当level==m-1时, 所有的m个元素已经取到，打印这m个元素的这个组合

void combos(int n, int m, int idx_arr[], int eArr[], int level )
{
    int i,begin,end;
    if (level==0)
        begin=0;
    else
        begin=idx_arr[level-1]+1;

    end=n-m+level;//这个地方应该怎么理解，如果换成是下面的，是否仍然成立？
    //end=n-1;
    for (i=begin;i<=end;i++)
    {
        idx_arr[level]=i;
        if ( level==m-1)
            printCombo(idx_arr,eArr,m); //打印这m个打印生成的这个组合
        else
            combos(n,m,idx_arr,eArr,level+1); //继续去下一个元素
    }
}


int main()
{

//ifstream fin("in");
////ofstream fout("out.txt");
//streambuf *cinbackup;
////streambuf *coutbackup;
////coutbackup= cout.rdbuf(fout.rdbuf()); //用 rdbuf() 重新定向
//cinbackup= cin.rdbuf(fin.rdbuf());

    int n,k;
    while(cin>>n>>k)
    {
        if(n==-1&&k==-1)break;


        for(int i=0;i<10;i++)
        {
            for(int j=0;j<150;j++)
            {
                d[i][j]=0;
            }
        }
        how=0;
        cnt=0;

        vector<string> G;
        const int maxn=n;
        string tmp;
        while(n--)
        {
            cin>>tmp;
            G.push_back(tmp);
        }


        int eArr[10];
        int idx_arr[10];
        for(int i=0;i<maxn;i++)
        {
            eArr[i]=i;
        }


        combos(maxn,k,idx_arr, eArr, 0);

//
//        for(int i=0;i<10;i++)
//        {
//            for(int j=0;j<10;j++)
//            {
//                cout<<d[i][j]<<" ";
//            }
//            cout<<endl;
//        }
        //共有几种组合数//先假设有4种
         //cout<<"her"<<endl;
         int x=cmn(maxn,k);
         //cout<<"her"<<endl;
        for(int i=0;i<x;i++)
        {
            //cout<<"her"<<endl;
            dfs(G,0,k,maxn,i);
        }
        cout<<how<<endl;



    }







}




