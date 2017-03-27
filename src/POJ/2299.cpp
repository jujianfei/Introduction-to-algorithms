// 15117557_AC_3344MS_7804K.cc
#include<iostream>
#include<algorithm>
#include<fstream>
#include<stdio.h>
#include<vector>
using namespace std;
//归并排序求逆序数对的个数
long long cnt=0;
void conquer_sort(vector<long long>&v,long long x,long long y,vector<long long>&T)
{
   if(y-x>1){
       long long m=x+(y-x)/2;
       long long p=x,q=m,i=x;
       conquer_sort(v,x,m,T);
       conquer_sort(v,m,y,T);
       while(p<m||q<y)//只要有一方没有到达终点就能够
       {
           if(q>=y||p<m&&v[p]<=v[q])//第二个序列是空(第一个序列一定非空)
           {
                T[i++]=v[p++];
           }
           else
           {
               T[i++]=v[q++];
               cnt+=m-p;
           }
       }
       for(long long i=x;i<y;i++)
       {
           v[i]=T[i];
       }
   }
}

int main()
{
//        ifstream fin("/home/zlq/acming2/in");
//        streambuf *cinbackup;
//        cinbackup= cin.rdbuf(fin.rdbuf());

        long long nums;
        while(cin>>nums)
        {
            if(nums==0)break;
            vector<long long> v;
            long long n=nums;
            long long tmp;
            while(nums--)
            {
                cin>>tmp;
                v.push_back(tmp);
            }
            cnt=0;
            vector<long long> tmp_(v.size());

            conquer_sort(v,0,n,tmp_);
            cout<<cnt<<endl;
        }
}
