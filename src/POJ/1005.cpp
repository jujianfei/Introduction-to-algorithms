// 14957070_AC_16MS_748K.cc
#include<iostream>
#include<fstream>
#include<math.h>
using namespace std;
double f(double year)
{
    return 10*sqrt(year/3.1415926);
}

int main()
{
//ifstream fin("in");
//
//streambuf *cinbackup;
//
//cinbackup= cin.rdbuf(fin.rdbuf());



int cases;
cin>>cases;
double x,y;
int cnt=0;
while(cases--)
{
    cnt++;
    cin>>x>>y;
    double dis=sqrt(x*x+y*y);
    int i;
    for(i=1;i;i++)
    {
        if(f(i)>dis)break;
    }
    cout<<"Property "<<cnt<<": This property will begin eroding in year "<<i<<"."<<endl;
}
cout<<"END OF OUTPUT."<<endl;

}
