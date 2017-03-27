// 15149732_AC_16MS_780K.cc
#include<iostream>
#include<fstream>
#include<map>
#include<algorithm>
#include<vector>

using namespace std;
int first[106];
int second[106];
int visit[106];

bool recursion(vector<int>&res,int first[],int second[],int visit[],int i)
{
    //cout<<"try.."<<i<<endl;
    if(visit[i]==1)return false;
    if(first[i]==-2)return false;
    if(first[i]==-1){res.push_back(i);return true;}

    res.push_back(i);
    visit[i]=1;
    bool res_=recursion(res,first,second,visit,first[i])==0&&recursion(res,first,second,visit,second[i])==0;
    if(res_)
    {
        res.pop_back();
        visit[i]=0;
        return false;
    }
    else
    {
        return true;
    }
}

int main()
{
//    ifstream fin("/home/zlq/Desktop/in");
//    streambuf *cinbackup;
//    cinbackup= cin.rdbuf(fin.rdbuf());

    int lines;
    cin>>lines;
    for(int now_location=1;now_location<=lines;now_location++)
    {
        int pages;
        cin>>pages;
        for(int i=0;i<106;i++){
            first[i]=-3;
            second[i]=-1;
            visit[i]=0;
        }
        vector<vector<string> > v;
        for(int i=0;i<pages;i++)
        {
            char type;
            string ends;
            cin>>type;
            string tmp;
            vector<string> line;
            do
           {
                cin>>tmp;
                line.push_back(tmp);
                if(*(tmp.end()-1)=='\"')
                {

                   break;
                }
            }while(1);

            v.push_back(line);
            if(type=='C'){

                int x,y;
                cin>>x>>y;
                first[i]=x-1;
                second[i]=y-1;
            }
            else{
                cin>>ends;
                if(ends=="HAPPY")
                {
                    first[i]=second[i]=-1;
                }
                else if(ends=="GRISLY")
                {
                    first[i]=second[i]=-2;
                }

            }
        }

        //以下采用递归的方式找到一条通路
        vector<int>res;
        recursion(res,first,second,visit,0);

//        for(int i=0;i<res.size();i++)
//        {
//            cout<<res[i]<<" ";
//        }
//        cout<<endl;

        cout<<"STORY "<<now_location<<endl;
        for(int i=0;i<res.size();i++)
        {
            int loc=res[i];
            if(v[loc].size()==1)
            {
                cout<<string(v[loc][0].begin()+1,v[loc][0].end()-1)<<endl;
                continue;
            }

            for(int i=0;i<v[loc].size();i++)
            {
                if(i==v[loc].size()-1)
                    cout<<string(v[loc][i].begin(),v[loc][i].end()-1);
                else if(i==0)
                    cout<<string(v[loc][i].begin()+1,v[loc][i].end())<<" ";
                else
                    cout<<v[loc][i]<<" ";

            }
            cout<<endl;
            //cout<<res[i]<<endl;
        }


    }

}
