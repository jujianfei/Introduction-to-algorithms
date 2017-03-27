// 15132239_AC_0MS_272K.cpp
#include<iostream>
#include<stdio.h>
#include<fstream>
using namespace std;
#include<vector>
vector<int> v;
int a[40];
int main()
{
//    ifstream fin("/home/zlq/acming7/in");
//    streambuf *cinbackup;
//    cinbackup= cin.rdbuf(fin.rdbuf());
    int cases;
    cin>>cases;
    while(cases--)
    {
        v.clear();
        int num;
        cin>>num;
        int former=0;
        int tmp;
        while(num--)
        {
            cin>>tmp;
            int x=tmp-former;
            while(x--){v.push_back(1);}
            v.push_back(2);
            former=tmp;
        }

        for(int i=0;i<40;i++){a[i]=0;}
        for(int i=0;i<v.size();i++)
        {
            if(v[i]==1)
                a[i]=1;
            else
            {
                a[i]=-1;
                int j=i-1;
                int cnt=1;
                while(a[j]!=1)
                {
                    if(a[j]==-1)
                        cnt++;
                    j--;
                }
                a[j]=0;
                cout<<cnt<<" ";
            }
        }
        cout<<endl;
    }


}
