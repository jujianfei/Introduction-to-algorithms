// 15109029_AC_0MS_728K.cc
#include<iostream>
#include<fstream>
#include<stdio.h>
using namespace std;
int main()
{

//    ifstream fin("/home/zlq/ACM/Acming/in");
//    streambuf *cinbackup;
//    cinbackup= cin.rdbuf(fin.rdbuf());


    int a[101][101];
    for(int i=1;i<101;i++){
        for(int j=1;j<101;j++){
            a[i][j]=0;
        }
    }

    int lines;
    cin>>lines;
    while(lines--)
    {
        string kind;
        int x,y,l;
        cin>>kind>>x>>y>>l;
        if(kind=="WHITE")
        {
            for(int i=x;i<x+l;i++)
            {
                for(int j=y;j<y+l;j++)
                {
                    a[i][j]=0;
                }
            }
        }
        else if(kind=="BLACK")
        {
            for(int i=x;i<x+l;i++)
            {
                for(int j=y;j<y+l;j++)
                {
                    a[i][j]=1;
                }
            }
        }
        else if(kind=="TEST")
        {
            int cnt=0;
            for(int i=x;i<x+l;i++)
            {
                for(int j=y;j<y+l;j++)
                {
                    if(a[i][j]==1)
                        cnt++;
                }
            }
            printf("%d\n",cnt);
        }
        else
        {
            cout<<"error"<<endl;
        }
    }
}
