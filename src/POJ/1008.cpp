// 15149154_AC_32MS_768K.cc
#include<iostream>
#include<stdio.h>
#include<fstream>
using namespace std;
#include <map>
map<string,int> info;
string ss[20]={"imix", "ik", "akbal", "kan", "chicchan", "cimi", "manik", "lamat", "muluk", "ok", "chuen", "eb", "ben", "ix", "mem", "cib", "caban", "eznab", "canac", "ahau"};
int cnt=0;
void init()
{
    info.insert(make_pair("pop",cnt++));
    info.insert(make_pair("no",cnt++));
     info.insert(make_pair("zip",cnt++));
      info.insert(make_pair("zotz",cnt++));
       info.insert(make_pair("tzec",cnt++));
       info.insert(make_pair("xul",cnt++));
       info.insert(make_pair("yoxkin",cnt++));
       info.insert(make_pair("mol",cnt++));
       info.insert(make_pair("chen",cnt++));
       info.insert(make_pair("yax",cnt++));
       info.insert(make_pair("zac",cnt++));
       info.insert(make_pair("ceh",cnt++));
       info.insert(make_pair("mac",cnt++));
       info.insert(make_pair("kankin",cnt++));
       info.insert(make_pair("muan",cnt++));
       info.insert(make_pair("pax",cnt++));
       info.insert(make_pair("koyab",cnt++));
       info.insert(make_pair("cumhu",cnt++));
        info.insert(make_pair("uayet",cnt++));
}

int main()
{

    //freopen("/home/zlq/easy_acm/in","r",stdin);

//    ifstream fin("/home/zlq/easy_acm/in");
//    streambuf *cinbackup;
//    cinbackup= cin.rdbuf(fin.rdbuf());

    init();
    int cases;
    cin>>cases;
    int d,y;
    string m;
    char dot;
    int whole=0;
    cout<<cases<<endl;
    for(int now=1;now<=cases;now++)
    {
        cin>>d>>dot>>m>>y;

        whole=y*365+info[m]*20+d+1;
        if(whole%260==0)
        {
            cout<<"13 ahau "<<whole/260-1<<endl;
        }
        else
        {

            int le=whole%260;
            if(le%13==0)
            {
                cout<<"13 ";
            }
            else
                cout<<le%13<<" ";

            if(le%20==0)
            {
                cout<<ss[19]<<" ";
            }
            else
            {
                cout<<ss[le%20-1]<<" ";
            }

            cout<<whole/260<<endl;
        }




    }

}
