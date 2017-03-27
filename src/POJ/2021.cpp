// 15110167_AC_16MS_764K.cc
#include<iostream>
#include<fstream>
using namespace std;
#include<map>
#include<algorithm>
#include<vector>
struct Node
{
    int age;
    string name;
    Node(string n,int a):age(a),name(n){}
};
bool com(const Node&n1,const Node&n2)
{
    if(n1.age > n2.age)return true;
    else if(n1.age<n2.age)return false;
    else
    {
        if(n1.name<n2.name)return true;
        else return false;
    }

}

int get_age(int time[106],int fa[106],int age[106], int i)
{
    if(i==-1)return 100;
    if(age[i]!=-1)return age[i];
    else
    {
        int fathe_loc=fa[i];
        return age[i]=get_age(time,fa,age,fathe_loc)-time[i];
    }
}


int main()
{

//    ifstream fin("/home/zlq/ACM/Acming/in");
//    streambuf *cinbackup;
//    cinbackup= cin.rdbuf(fin.rdbuf());

    int lines;
    cin>>lines;
    int ii=1;
    while(lines--)
    {


        vector<Node> v;
        int num;
        cin>>num;
        int people_num=num;
        string name[106];
        int fa[106];
        int time[106];
        int age[106];
        for(int i=0;i<106;i++){fa[i]=-2;}
        for(int i=0;i<106;i++){time[i]=-1;}
        for(int i=0;i<106;i++){age[i]=-1;}
        int cnt=0;
        map<string,int> loc;
        loc["Ted"]=-1;

        while(num--)
        {
            string father,ch;
            int t;
            cin>>father>>ch>>t;
            if(loc.find(father)==loc.end() && loc.find(ch)==loc.end())
            {

                name[cnt]=father;
                loc[father]=cnt;
                int tmp_fa=cnt;
                cnt++;
                name[cnt]=ch;
                loc[ch]=cnt;
                int tmp_ch=cnt;
                cnt++;
                fa[tmp_ch]=tmp_fa;
                time[tmp_ch]=t;

            }
            if(loc.find(father)!=loc.end() && loc.find(ch)==loc.end())
            {
                int tmp_fa=loc[father];
                name[cnt]=ch;
                loc[ch]=cnt;
                int tmp_ch=cnt;
                cnt++;
                fa[tmp_ch]=tmp_fa;
                time[tmp_ch]=t;

            }
            if(loc.find(father)!=loc.end()&&loc.find(ch)!=loc.end())
            {
                int tmp_ch=loc[ch];
                int tmp_fa=loc[father];
                fa[tmp_ch]=tmp_fa;
                time[tmp_ch]=t;
            }
         }

        for(int i=0;i<people_num;i++)
        {
            v.push_back(Node(name[i],get_age(time,fa,age,i)));
        }

        sort(v.begin(),v.end(),com);

        cout<<"DATASET "<<ii++<<endl;
        for(int i=0;i<v.size();i++)
        {
            cout<<v[i].name<<" "<<v[i].age<<endl;
        }


    }



}
