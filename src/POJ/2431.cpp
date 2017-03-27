// 14970889_AC_344MS_892K.cc
#include<iostream>
#include<fstream>
#include<functional>
#include<vector>
#include<algorithm>
#include <queue>
using namespace std;
struct Node
{
    int len;
    int has;
    Node(int i,int j):len(i),has(j){}
};


bool operator<(const Node&n1,const Node&n2){return n1.has<n2.has;}
struct cmp2{
    bool operator ()(int &a,int &b){
        return a<b;//最大值优先
    }
};


bool com(const Node&n1,const Node&n2){return n1.len>n2.len;}

int main()
{

//ifstream fin("in");
//streambuf *cinbackup;
//cinbackup= cin.rdbuf(fin.rdbuf());


int lines;
cin>>lines;
{
    vector<Node>info;
    int a,b;
    while(lines--)
    {
        cin>>a>>b;
        info.push_back(Node(a,b));
    }
    std::sort(info.begin(),info.end(),com);

    int L;
    cin>>L;
    int LP;
    cin>>LP;

    int i=0;
    priority_queue<Node>d;
    int cnt=0;

    int lefter=L;
    for(;lefter>0;)
    {
        if(i!=info.size()&&info[i].len==lefter)
        {
            //cout<<"has_a_stop_"<<lefter<<endl;
            d.push(info[i]);
            i++;
        }
        if(LP==0)
        {
            //cout<<"no_LP_"<<lefter<<endl;
            if(d.size()==0){break;}
            LP=LP+d.top().has;
            cnt++;
            d.pop();
        }

        lefter--;
        LP--;
    }

    if(lefter==0)cout<<cnt<<endl;
    else cout<<"-1"<<endl;

}

}
