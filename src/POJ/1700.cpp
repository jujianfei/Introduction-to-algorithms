// 4890284_AC_16ms_236kB.cpp
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
   int n;
   cin>>n;
   while(n--)
   {
       int num;
       cin>>num;
       vector<int> v;
       int tmp;
       while(num--)
       {
           cin>>tmp;
           v.push_back(tmp);
       }
       sort(v.begin(),v.end());
       int time=0;
       while(1)
       {
          if(v.size()==0)
          {
              break;
          }
          else if(v.size()==1)
          {time=time+v[0];break;}
          else if(v.size()==2)
          {
              time=time+max(v[0],v[1]);
              break;
          }

          else if(v.size()==3)
          {
              time=time+v[0]+v[1]+v[2];
              break;
          }


          else  if(v.size()>=4)
          {
              int s=v.size();
              time=time+min(v[0]+2*v[1]+v[s-1],2*v[0]+v[s-1]+v[s-2]);

//               vector<int>::iterator p=v.begin();
//              p=v.erase(p);
//              p=v.erase(p);
              v.pop_back();
              v.pop_back();
              //cout<<v.size()<<"--"<<endl;


          }


       }
       cout<<time<<endl;
    }
   }
