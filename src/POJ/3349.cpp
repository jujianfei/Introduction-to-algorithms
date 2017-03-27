// 15118687_AC_2110MS_6464K.cpp
#include<iostream>
#include<algorithm>
#include<fstream>
#include<stdio.h>
#include<vector>
#include<algorithm>
#define MOD 100079
using namespace std;
int cur=0;
struct Node
{
    int num[6];
    int index;
    Node(int a,int b,int c,int d,int e,int f)
    {
        num[0]=a;
        num[1]=b;
        num[2]=c;
        num[3]=d;
        num[4]=e;
        num[5]=f;
        int sum=0;
        for(int i=0;i<6;i++){sum+=num[i];}
        index=sum%MOD;
    }
    Node()
    {num[0]=-1;
           num[1]=-1;
           num[2]=-1;
           num[3]=-1;
           num[4]=-1;
           num[5]=-1;
           index=-1;
    }
};

struct LinkNode
{
  int i;
  LinkNode*next;
  LinkNode(int ii):i(ii){next=NULL;}
};

Node info[100000+7];
LinkNode* hash_table[MOD+6];


//这里需要能够从node的信息索引到哈希表,也能够从哈希表索引到node信息
//需要用到挂链存储


LinkNode* find_the_null(int location)
{
    LinkNode *res=hash_table[location];
    while(res!=NULL)
    {
        res=res->next;
    }
    return res;
}

bool sub_compare(Node&s,Node&t)
{

    int a[12];
    for(int i=0;i<6;i++)
    {
        a[i]=a[i+6]=s.num[i];
    }
    for(int i=0;i<6;i++)
    {
        int k=0;
        int now=i;
        while(a[now]==t.num[k])
        {
            k++;
            now++;
            if(k==6){break;}

        }
        if(k==6)return true;

    }

    for(int i=0;i<6;i++)
    {
        a[i]=a[i+6]=s.num[5-i];
    }
    for(int i=0;i<6;i++)
    {
        int k=0;
        int now=i;
        while(a[now]==t.num[k])
        {
            k++;
            now++;
            if(k==6){break;}

        }
        if(k==6)return true;

    }


    return false;

}

bool compare(Node& tmp,LinkNode*pt)
{
    //cout<<"the compare"<<endl;
    LinkNode*pf=pt;
    while(pf)
    {
        //cout<<"the compare"<<endl;
        if(sub_compare(tmp,info[pf->i]))
        {
            return true;
        }
        pf=pf->next;
    }
    return false;
}


int main()
{

//    ifstream fin("/home/zlq/acming2/in");
//    streambuf *cinbackup;
//    cinbackup= cin.rdbuf(fin.rdbuf());

    int lines;
    scanf("%d",&lines);
    int a,b,c,d,e,f;
    int flag=0;

    while(lines--)
    {
        scanf("%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f);
        Node tmp(a,b,c,d,e,f);
        int x=tmp.index;
        //cout<<"the x is "<<x<<endl;
        if(hash_table[x]==NULL)
        {
            //cout<<"cannot find"<<endl;
            info[cur]=tmp;
            hash_table[x]=new LinkNode(cur);
            cur++;
        }
        else
        {
            //cout<<"find"<<endl;
            if(compare(tmp,hash_table[x]))
            {
                flag=1;
                //cout<<"twins!!"<<endl;
                break;
            }
            else
            {
                //cout<<"find but not equal"<<endl;
                info[cur]=tmp;
                LinkNode*pt=find_the_null(x);
                pt=new LinkNode(cur);
                cur++;
            }
        }

    }
    if(flag==1)
        cout<<"Twin snowflakes found."<<endl;
    else
        cout<<"No two snowflakes are alike."<<endl;

}
