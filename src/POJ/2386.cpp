// 14943569_AC_16MS_596K.cpp
#include<iostream>
#include<vector>
#include<string>
using namespace std;
void dfs(vector<string> &G,int i,int j)
{

        G[i][j]='.';

        for(int m=-1;m<=1;m++)
        {
            for(int n=-1;n<=1;n++)
            {
                int i_=i+m;
                int j_=j+n;

                if(!(m==0&&n==0))
                {

                    if(i_<G.size()&&i_>=0&&j_>=0&&j_<G[0].size()&&G[i_][j_]!='.')
                    {

                        dfs(G,i_,j_);

                    }
                }
            }
        }

}


int main()
{



    int row;
    int col;
    while(cin>>row>>col)
    {
        vector<string> G;
        int lines=row;
        string tmp;
        int cnt=0;
        while(lines--)
        {
            cin>>tmp;
            G.push_back(tmp);
        }
        for(int i=0;i<G.size();i++)
        {
            for(int j=0;j<G[0].size();j++)
            {
                if(G[i][j]=='W')
                {
                dfs(G,i,j);
                cnt++;
                }
            }
        }
        cout<<cnt<<endl;


    }
}
