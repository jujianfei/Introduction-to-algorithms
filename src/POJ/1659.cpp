// 14961547_AC_0MS_716K.cc
#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
using namespace std;
int G[21][21];
struct Node
{
    int in;
    int l;
    Node(int i_,int l_):in(i_),l(l_){}
};

bool com(const Node&n1,const Node&n2)
{
    return n1.l>n2.l;
}

int main()
{

//ifstream fin("in");
//streambuf *cinbackup;
//cinbackup= cin.rdbuf(fin.rdbuf());



    int cases;
    cin>>cases;

    while(cases--)
    {
        //初始化为0
        for(int i=0;i<21;i++)
        {
            for(int j=0;j<21;j++)
            {
                G[i][j]=0;
            }
        }

        int n;

        cin>>n;
        int n_=n;
        vector<Node> v;
        int cnt=0;
        int a;
        while(n--)
        {
            cnt++;
            cin>>a;
            v.push_back(Node(cnt,a));
        }




        int flag=0;


        for(int i=0;i<v.size();i++)
        {
             sort(v.begin()+i,v.end(),com);
            //cout<<"v[i] "<<i<<endl;
                int cnt=0;
                //往后找
                int now=i+1;
                while(now<v.size())
                {
                    if(cnt==v[i].l){break;}
                    if(v[now].l)
                    {
                    //cout<<"fong"<<now<<endl;
                        v[now].l--;
                        cnt++;
                        G[v[i].in][v[now].in]=G[v[now].in][v[i].in]=1;

                    }

                    now++;
                }
                if(cnt<v[i].l)
                {
                    flag=1;
                    break;
                }

        }



        if(flag==0)
        {

        //打印图

            cout<<"YES"<<endl;
            for(int i=1;i<=n_;i++)
            {
                for(int j=1;j<=n_;j++)
                {
                    cout<<G[i][j]<<" ";
                }
                cout<<endl;
            }

        }
        else
        cout<<"NO"<<endl;

        cout<<endl;



    }
}

