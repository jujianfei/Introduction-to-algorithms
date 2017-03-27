// 15156996_AC_0MS_716K.cc
#include<iostream>
#include<stdio.h>
#include<string.h>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
int a[5];
vector<int> v;
//x ===> 0-31
int Cwx(int w,int x)
{
    if(w==1&&x==0)return 0;
    else return 1;
}
bool f(string & s,int x)
{
    //先由int i构造出来那个数列
    for(int i=0;i<5;i++)
    {
        if(x&(1<<i)){a[i]=1;}
        else{a[i]=0;}
    }
    //返回false代表这一种组合不是真的
    v.clear();
    for(int i=s.size()-1;i>=0;i--)
    {
        if(s[i]<='t'&&s[i]>='p')
        {
            v.push_back(a[s[i]-'p']);
        }
        else
        {
            switch (s[i]) {
            case 'K':
            {
                int tmp=v[v.size()-1]&&v[v.size()-2];
                v.pop_back();v.pop_back();
                v.push_back(tmp);
            }
                break;
            case 'A':
            {
                int tmp=v[v.size()-1]||v[v.size()-2];
                v.pop_back();v.pop_back();
                v.push_back(tmp);
            }
                break;
            case 'N':
            {
                int tmp=!v[v.size()-1];
                v.pop_back();
                v.push_back(tmp);
            }
                break;
            case 'C':
            {
                int tmp=Cwx(v[v.size()-1], v[v.size()-2]);
                v.pop_back();v.pop_back();
                v.push_back(tmp);
            }
                break;
            case 'E':
            {
                int tmp=v[v.size()-1]==v[v.size()-2];
                v.pop_back();v.pop_back();
                v.push_back(tmp);
            }
                break;
            }
        }

    }
    if(v.size()==1)
    {
        if(v[0]==1)
            return true;
        else
            return false;
    }
    else
    {
        cout<<"wrong"<<endl;
    }
}

int main()
{
    //freopen("/home/zlq/easy_acm/in","r",stdin);
    //关键点应该是"栈的应用"
    string tmp;
    while(cin>>tmp)
    {
        if(tmp=="0"){break;}
        int flag=1;//默认是保证来永远是真的
        for(int i=0;i<32;i++)
        {
            if(!f(tmp,i))
            {
                flag=0;
                break;
            }
        }
        if(flag==0)
        {
            cout<<"not"<<endl;
        }
        else
        {
            cout<<"tautology"<<endl;
        }

    }


}

