// 14963749_AC_172MS_864K.cc
#include <iostream>
#include<fstream>
#include<math.h>
#include<vector>
#include<stdio.h>
using namespace std;

int main()
{
//ifstream fin("in");
//
//streambuf *cinbackup;
//
//cinbackup= cin.rdbuf(fin.rdbuf());
double pi =3.1415926535898;
int cases;
cin>>cases;
while(cases--)
{
    int N,f;
    cin>>N>>f;
    int F=f+1;
    vector<int> v;
    int tmp;
    while(N--)
    {
        cin>>tmp;
        v.push_back(tmp);
    }
    //枚举每个人能获得数量，然后有pie的每个具体的值除以，加起来的数值如果大于，说明数量还可以升高，如果加起来的数值小于，说明数量要减
    //先假设每个人获得的数量是最大的那个pie除以人数

    double e=-(1<<12);

    for(int i=0;i<v.size();i++)
    {
        if(v[i]>e)
            e=v[i];
    }
     e=e*e*pi*F;

    double b=0;
    double mid=(e+b)/2;
    double pre=0;
    while(fabs(mid-pre)>1e-5)
    {

        pre=mid;
        int total=0;
        for(int i=0;i<v.size();i++)
        {
            total=total+floor(v[i]*v[i]*pi/mid);
        }
        if(total<F)
        {
            e=mid;
            mid=(b+e)/2;
        }
        else
        {
            b=mid;
            mid=(b+e)/2;
        }
    }
    printf("%.4f\n",mid);



}
}
