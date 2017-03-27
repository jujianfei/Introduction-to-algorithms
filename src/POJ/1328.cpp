// 15151194_AC_16MS_748K.cc
#include<iostream>
#include<stdio.h>
using namespace std;
#include<map>
#define N 1000+5
#include<math.h>
#include<algorithm>
int flag;//代表状态...
pair<double,double> begin_end(int x,int y,int d)
{
    if(d<0) {flag=0;return pair<double,double>(-1,-1);}
    if(d<y) {flag=0;return pair<double,double>(-1,-1);}
    double r_x=sqrt(d*d-y*y);
    return pair<double,double>(x-r_x,x+r_x);
}
struct Node
{
    double b,a;
    Node(double a_,double b_):a(a_),b(b_){}
    Node(){b=a=0;}
};
Node a[N];
bool compare(const Node&n1,const Node&n2)
{
    if(n1.b<n2.b)return true;
    if(n2.b<n1.b)return false;
    else if(n1.a<n2.a)return true;
    else return false;
}
int main()
{
    //贪心的题目,开始的尽量向右找圆的方法是错误的
    //应当转化成区间选点问题
    //freopen("/home/zlq/easy_acm/in","r",stdin);
    int n,d;
    int cases=0;
    while(~scanf("%d%d",&n,&d))
    {

        if(n==0&&d==0)break;
        cases++;
        cout<<"Case "<<cases<<": ";
        flag=1;//1代表默认是可以的
        int x,y;
        for(int cnt=0;cnt<n;cnt++)
        {
            scanf("%d%d",&x,&y);
            a[cnt]=Node(begin_end(x,y,d).first,begin_end(x,y,d).second);
        }
        sort(a,a+n,compare);
        if(flag==0)
        {
            cout<<"-1"<<endl;
            continue;
        }
        else
        {
            //处理
//            for(int i=0;i<n;i++)
//            {
//                cout<<a[i].a<<" "<<a[i].b<<endl;
//            }
            int count=1;
            int m=0;//现在所在的地点
            for(int i=1;i<n;i++)
            {
                if(a[i].a<=a[m].a)continue;
                if(a[m].b<=a[i].b && a[m].b>=a[i].a)continue;
                else
                {
                    count++;
                    m=i;
                }
            }
            cout<<count<<endl;
        }

    }


}
