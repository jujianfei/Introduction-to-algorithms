// 14957470_AC_63MS_736K.cc
#include<iostream>
#include<fstream>
#include<math.h>
#include<vector>
#include<algorithm>
using namespace std;
int invest(const string &s)
{
    int cnt=0;
    for(int i=0;i<s.size();i++)
    {
        for(int j=i+1;j<s.size();j++)
        {
            if(s[j]<s[i]){cnt++;}
        }
    }
    return cnt;
}

bool compare(const string &s1,const string &s2)
{
    if(invest(s1)<invest(s2))return true;
    else return false;
}

int main()
{
//ifstream fin("in");
//
//streambuf *cinbackup;
//
//cinbackup= cin.rdbuf(fin.rdbuf());

vector<string> v;
int len;
int lines;
string tmp;
cin>>len>>lines;
while(lines--)
{
    cin>>tmp;
    v.push_back(tmp);
}
std::stable_sort(v.begin(),v.end(),compare);
for(int i=0;i<v.size();i++)
{
    cout<<v[i]<<endl;
}

}
