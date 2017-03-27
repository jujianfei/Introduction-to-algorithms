// 14957151_AC_125MS_724K.cc
#include<iostream>
#include<fstream>
#include<math.h>
using namespace std;

int main()
{
//ifstream fin("in");
//
//streambuf *cinbackup;
//
//cinbackup= cin.rdbuf(fin.rdbuf());



    int a,b,c,d;
    int cnt=0;
    while(cin>>a>>b>>c>>d)
    {
      if(a==-1&&b==-1&&c==-1&&d==-1)
      {
        break;
      }

      cnt++;
      while(b>d)
      {
        b=b-28;
      }
       while(a>d)
      {
        a=a-23;
      }
       while(c>d)
      {
        c=c-33;
      }

      int res;
      for(int i=1;;i++)
      {
        if(((23*i+a-b)%28==0)&&((23*i+a-c)%33==0))
        {
            if(23*i+a>d){ res=23*i+a;break;}
        }
      }

      cout<<"Case "<<cnt<<": the next triple peak occurs in "<<res-d<<" days."<<endl;
    }

}
