// 4889365_AC_156ms_1860kB.cpp
#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
using namespace std;
struct data
{
  double java=-1;
  double food=-1;
  double pw=-1;
  data(double j,double f):java(j),food(f),pw(java/food){}

};
int main()
{
    int M,N;
    while(cin>>M>>N){
    if(M==-1&&N==-1)break;
    else
    {
        vector<data> vd;
        double jt,ft;
        for(int i=0;i<N;i++)
        {
            cin>>jt>>ft;
            data temp(jt,ft);
            vd.push_back(temp);
        }
        sort(vd.begin(),vd.end(),[](const data& d1,const data&d2){return d1.pw>d2.pw;});
        double now=0;
        double number=0;
        for(auto p=vd.begin();p!=vd.end();p++)
        {
            if(now+p->food<=M)
            {
                now=now+p->food;
                number=number+p->java;
            }
            else
            {
                double left=M-now;
                number=number+left*(p->pw);
                break;
            }
        }
        printf("%.3f\n",number);
    }
    }
}
