// 15149434_AC_0MS_744K.cc
#include<iostream>
#include<stdio.h>
#include<fstream>
#include<set>
#include<vector>
#include<math.h>
using namespace std;
int zero[13];
int t[13];

int main()
{

//    ifstream fin("/home/zlq/easy_acming/in");
//    streambuf *cinbackup;
//    cinbackup= cin.rdbuf(fin.rdbuf());
    //模拟比较麻烦...

    int cases;
    cin>>cases;
    string l,r,d;
    while(cases--)
    {
        for(int i=1;i<=12;i++)
        {
            zero[i]=t[i]=0;
        }
        for(int now=1;now<=3;now++)
        {
            cin>>l>>r>>d;
            if(d=="even")
            {
                for(int i=0;i<l.size();i++){zero[l[i]-64]=1;}//标记为真说明,以后不用考虑了,因为一定是真的
                for(int i=0;i<r.size();i++){zero[r[i]-64]=1;}
            }
            if(d=="up")
            {
                for(int i=0;i<l.size();i++){t[l[i]-64]++;}
                for(int i=0;i<r.size();i++){t[r[i]-64]--;}
            }
            if(d=="down")
            {
                for(int i=0;i<l.size();i++){t[l[i]-64]--;}
                for(int i=0;i<r.size();i++){t[r[i]-64]++;}
            }
        }

        int max=-1;
        int index=-1;
        for(int i=1;i<=12;i++)
        {
            if(zero[i]==0&&fabs(t[i])>max)
            {
                index=i;
                max=fabs(t[i]);
            }
        }
        if(t[index]>0)printf("%c is the counterfeit coin and it is heavy.\n",index+64);
        else printf("%c is the counterfeit coin and it is light.\n",index+64);
    }
}
