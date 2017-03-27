// 14969297_AC_125MS_772K.cc
#include<stdio.h>
#include<math.h>
int v[1000000+6];
int max(const int& a,const int&b)
{
    if(a<b)return b;
    else return a;
}
int main()
{


    int n;
    scanf("%d",&n);
    while(n--)
    {
        int nums,L;
        scanf("%d%d",&L,&nums);

        for(int i=0;i<nums;i++)
        {
         scanf("%d",v+i);
        }

        int miner=1000000*2;
        int maxer=-1;
        int mider=2*10000000;
        int index=-1;
        for(int i=0;i<nums;i++)
        {
            if(v[i]<miner)
            {
                miner=v[i];
            }
            if(v[i]>maxer)
            {
                maxer=v[i];
            }
            if(fabs(v[i]-L/2.0)<mider)
            {
                mider=fabs(v[i]-L/2);
                index=i;
            }
        }
        int zuiduan;
        if(v[index]<L/2.0)
        {
            zuiduan=v[index];
        }
        else
        {
            zuiduan=L-v[index];
        }
        int zuichang=max(L-miner,maxer);
        printf("%d %d\n",zuiduan,zuichang);

    }

}
