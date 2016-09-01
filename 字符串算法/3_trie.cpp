#include<bits/stdc++.h>

//为了简便，不再统计单词的个数，只是标记每个单词是否出现过
using namespace std;
struct Node{
    char con;
    int flag;
    Node*lc,*mc,*rc;
    Node(char _con){
        con=_con;
        flag=0;//标记没有单词出现
        lc=mc=rc=NULL;
    }
};

void Insert(string s,Node*&root,int cur){
    if(!root){
        root=new Node(s[cur]);
        if(cur==s.size()-1){
            root->flag=1;
            return;
        }
    }
    if(root->con==s[cur]){
        Insert(s,root->mc,cur+1);
    }else if(root->con<s[cur]){
        Insert(s,root->lc,cur);
    }else{
        Insert(s,root->rc,cur);
    }
}


bool Intree(string s,Node*root,int cur){
    if(!root)return false;
    if(root->con==s[cur]){
        if(cur+1==s.size()){
            if(root->flag==1)return true;
            else return false;
        }else{
            return Intree(s,root->mc,cur+1);
        }
    }else if(root->con<s[cur]){
        return Intree(s,root->lc,cur);
    }else{
        return Intree(s,root->rc,cur);
    }
}
//TODO:unimplemented
vector<string> Keythatmatch(const string&re){
    //匹配re单词的所有单词，支持模糊匹配
}
vector<string> KeywithPrefix(const string&s){
    //拥有前缀s的所有单词
}
void deleter(const string& s){
    //使用二叉查找树删除算法
}

int main(){
    Node*root=NULL;
    Insert("zhang",root,0);
    cout<<Intree("zhang",root,0);

}
