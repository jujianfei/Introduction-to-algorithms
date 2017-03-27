// 14956922_AC_16MS_764K.cc
#include<iostream>
#include<fstream>
using namespace std;
int main()
{
//ifstream fin("in");
//
//streambuf *cinbackup;
//
//cinbackup= cin.rdbuf(fin.rdbuf());


int lines=12;
float sum=0;
float tmp;
while(lines--)
{
    cin>>tmp;
    sum+=tmp;
}
cout<<"$"<<sum/12;
}
