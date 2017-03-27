// 15160438_AC_875MS_756K.cc
//介绍直接在数组上建堆的方法

#include<iostream>
#include<stdio.h>
#include<string.h>
#include<string>
#include<algorithm>
#include<vector>
#include<set>
#include<queue>
#define N 2000+7
using namespace std;
int n,m,data1[N],data2[N],dataq[N];
priority_queue<int,vector<int>,less<int> > d;//默认是大的值在上面.

int main()
{
    //freopen("/home/zlq/easy_acm/in","r",stdin);
    int cases;
    scanf("%d",&cases);
    while(cases--)
    {
        scanf("%d%d",&m,&n);
        //读入第一行数据到data1
        for(int i=0;i<n;i++){scanf("%d",&data1[i]);}
        //如果有的话,读入后面的数据
        for(int line=1;line<m;line++)
        {
            for(int i=0;i<n;i++)
                scanf("%d",&data2[i]);
            sort(data1,data1+n);
            sort(data2,data2+n);
            //建堆
            for(int i=0;i<n;i++)
            {
                dataq[i]=data1[0]+data2[i];
            }
            make_heap(dataq,dataq+n);
            //刚才使用的data1[0],下面将data1[1]~data1[n-1]添加到堆里面
            for(int i=1;i<n;i++)
            {
                for(int k=0;k<n;k++)
                {
                    int temp=data1[i]+data2[k];
                    if(temp>=dataq[0])//是最大的元素
                        break;
                    //拿掉堆顶的元素
                    pop_heap(dataq,dataq+n);
                   //添加上temp
                    dataq[n-1]=temp;
                    push_heap(dataq,dataq+n);

                }

            }
            //将dataq复制到data1
            for(int i=0;i<n;i++)
            {data1[i]=dataq[i];}

        }
        sort(data1,data1+n);
        for(int i=0;i<n;i++)
        {
            cout<<data1[i]<<" ";
        }cout<<endl;
    }


}

