// 14940164_AC_844MS_8496K.cc
#include<iostream>
#include<vector>
#include<fstream>
using namespace std;
int diff(const string &s1,const string &s2)
{
    int resdiff=0;
    for(int i=0;i<s1.size();i++)
    {
        if(s1[i]!=s2[i])
        {
            resdiff++;
        }
    }
    return resdiff;
}

short G[2001][2001];

int main()
{

//ifstream fin("in1789");
////ofstream fout("out.txt");
//streambuf *cinbackup;
////streambuf *coutbackup;
////coutbackup= cout.rdbuf(fout.rdbuf()); //用 rdbuf() 重新定向
//cinbackup= cin.rdbuf(fin.rdbuf());


    int maxn;

    while(cin>>maxn)
    {
        int lines=maxn;
        if(maxn==0)
            break;
        vector<string> info;
        string tmp;
        while(lines--)
        {
            cin>>tmp;
            info.push_back(tmp);
        }

        for(int i=0;i<info.size();i++)
        {
            for(int j=0;j<info.size();j++)
            {
                G[i+1][j+1]=diff(info[i],info[j]);
            }
        }
        int total=0;
        //初始化图完毕
        const int sz=maxn+1;
        short low[sz];
        //short who[sz];
        //for(int i=1;i<=maxn;i++){who[i]=1;}

        for(int k=1;k<=maxn;k++)
        {
            low[k]=G[1][k];//用第一个节点初始化
        }

        for(int times=2;times<=maxn;times++)
        {
            short miner=8;
            short index=-1;
            for(int i=1;i<=maxn;i++)
            {
                if(low[i]!=0&&low[i]<miner)
                {
                    miner=low[i];
                    index=i;
                }
            }
            //int hh=who[index];
            total=total+miner;
            low[index]=0;
            for(int i=1;i<=maxn;i++)
            {
                if(low[i]!=0&&G[index][i]<low[i])
                {
                    low[i]=G[index][i];
                    //who[i]=index;
                }
            }


        }

        cout<<"The highest possible quality is 1/"<<total<<"."<<endl;
    }
}
