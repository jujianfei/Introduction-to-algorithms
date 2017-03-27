// 15151109_AC_16MS_996K.cc
#include<iostream>
#include<stdio.h>
#include<deque>
#define N 65533+3
using namespace std;
int a[N];
int c[16][4]={
    {1,4,-1,-1},
    {0,2,5,-1},
    {1,6,3,-1},
    {2,7,-1,-1},

    {0,5,8,-1},
    {1,4,6,9},
    {2,5,7,10},
    {3,6,11,-1},

    {4,9,12,-1},
    {5,8,10,13},
    {6,9,11,14},
    {7,10,15,-1},

    {8,13,-1,-1},
    {9,12,14,-1},
    {13,10,15,-1},
    {11,14,-1,-1}
};

unsigned int get_start(int *A)
{
    unsigned int x=0;
    for(int i=0;i<16;i++)
    {
        if(A[i])
        {
            x|=(1<<i);
        }
    }
    return x;

}


int start[16];
int main()
{
    //freopen("/home/zlq/easy_acming/in","r",stdin);
    for(int i=0;i<N;i++){a[i]=-1;}//全部设置成-1;
    string tmp;
    for(int line=0;line<4;line++)
    {
        cin>>tmp;
        for(int i=0;i<4;i++)
        {
            if(tmp[i]=='b')
            {
                start[line*4+i]=1;
            }
        }
    }

//    for(int i=0;i<16;i++)
//    {
//        cout<<start[i]<<" ";
//    }cout<<endl;
    //cout<<get_start(start)<<endl;

    int begin=get_start(start);
    a[begin]=0;
    deque<unsigned int> d;
    d.push_back(begin);
    int now;
    int flag=0;
    while(d.empty()==false)
    {
        now=d.front();
        //cout<<"now_front_is"<<now<<endl;
        d.pop_front();
        if(now==65535||now==0){flag=1;break;}
        else
        {
            for(int i=0;i<16;i++)//一共可以有16种选择..16中变换
            {
                unsigned int gen=now;
                gen=gen^(1<<i);
                for(int j=0;j<4;j++)//每种变换,将其中的4位进行取反操作
                {
                    if(c[i][j]!=-1)
                    gen=gen^(1<<c[i][j]);
                }
                //cout<<"gen_is_"<<gen<<endl;
                if(a[gen]==-1)
                {
                    a[gen]=a[now]+1;
                    d.push_back(gen);
                }

            }
        }
    }
    if(flag==1)
    cout<<a[now]<<endl;
    else
    cout<<"Impossible"<<endl;

}
