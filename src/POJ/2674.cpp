// 6716914_AC_2688ms_3132kB.cpp
#include <iostream>
#include<math.h>
#include<algorithm>
#include <iomanip>
#include<stdio.h>
#define N 33000
using namespace std;
typedef struct
{
    char direct;
    double pos;
    string name;
}People;
bool cmp(const People &a,const People &b)
{
    return a.pos<b.pos;
}
People p[N];
int n;

int main()
{
    while(cin>>n&&n)
    {
         int z=0,i=0;
            double s=0.0,s1=0.0;
            double L,v;
            cin>>L>>v;
            int k=0,num=0,d=0;
            for(i=0;i<n;i++)
            {
                char ch=getchar();
                scanf("%c%lf",&p[i].direct,&p[i].pos);
                cin>>p[i].name;
            }
                //cin>>p[i].direct>>p[i].pos>>p[i].name;
            sort(p,p+n,cmp);
            for(i=0;i<n;i++)
            {
                if(p[i].direct=='p'||p[i].direct=='P')
                    s1=L-p[i].pos;
                else
                    s1=p[i].pos;
                if(s<s1)
                {
                    s=s1;
                    k=i;
                }
            }
            if(p[k].direct=='p'||p[k].direct=='P')
            {
                for(i=k+1;i<n;i++)
                {
                    if(p[i].direct=='n'||p[i].direct=='N')
                        num++;
                }
                d=k+num;
            }
            else
            {
                for(i=0;i<k;i++)
                {
                    if(p[i].direct=='p'||p[i].direct=='P')
                        num++;
                }
                d=k-num;
            }
            cout << setw(13) << fixed << setprecision(2) << (int)(s/v * 100) / 100.0 << ' ' << p[d].name <<endl;

    }
    return 0;
}