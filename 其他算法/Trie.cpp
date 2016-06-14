//主要功能：
//插入单词
//查询单词存在字典中的个数，（包括模糊查询），输出全部的单词，
//删除一个单词
#include<bits/stdc++.h>
#include<stdio.h>
#include<vector>
using namespace std;
struct Node{
    int num;
    Node* next[26];
    Node(){
        num=0;
        for(int i=0;i<26;i++){
            next[i]=NULL;
        }
    }
};

///////////////////////////////////////////////////////////////////////////////////////
//match函数辅助变量
vector<string> ans;
string t;

void match(string s,int cur,Node*root,string&tmp){
    if(cur==s.size()){
        if(root->num!=0){
            ans.push_back(string(tmp.begin(),tmp.begin()+cur+1));
        }
        return;
    }

    if(s[cur]=='.'){
        for(int i=0;i<26;i++){
            tmp[cur]='a'+i;
            if(root->next[i])
                match(s,cur+1,root->next[i],tmp);
        }
    }else{
        int tar=s[cur]-'a';//0-25
        if(root->next[tar]){
            tmp[cur]=s[cur];
            match(s,cur+1,root->next[tar],tmp);
        }
    }
}
//////////////////////////////////////////////////////////////////////////////////////
void insert(string s,int cur,Node*&root){

    if(root->next[s[cur]-'a']==NULL){
        root->next[s[cur]-'a']=new Node();
    }

    if(cur+1==s.size()){//到了结尾
        root->next[s[cur]-'a']->num ++;
    }else{
        insert(s,cur+1,root->next[s[cur]-'a']);
    }
}

int getnum(string s,int cur,Node*&root){
    if(root->next[s[cur]-'a']==NULL)return 0;
    if(cur+1==s.size())return root->next[s[cur]-'a']->num;
    return getnum(s,cur+1,root->next[s[cur]-'a']);
}


///////////////////////////////////////////////////////////////////////////////////////
//show函数外部辅助变量
vector<string> res;
string tmp;
int cnt;
void show(Node*&root,int depth){

    //显示所有的字符串
    for(int i=0;i<26;i++){
        if(root->next[i]){
            tmp[depth]='a'+i;
            if(root->next[i]->num>0){
                for(int k=0;k< root->next[i]->num;k++){
                    res.push_back(string(tmp.begin(),tmp.begin()+depth+1));
                }
            }
            show(root->next[i],depth+1);
        }
    }
}

//////////////////////////////////////////////////////////////////////////////////////
void deleter(Node*&root,string s,int cur){
    if(root->next[s[cur]-'a']==NULL)return ;//无法删除,因为不存在
    if(cur+1==s.size()){
        root->next[s[cur]-'a']->num --;
        if(root->next[s[cur]-'a']->num==0){
            root->next[s[cur]-'a']=NULL;
        }
        return;//成功删除
    }else{
        deleter(root->next[s[cur]-'a'],s,cur+1);
    }
}

//////////////////////////////////////////////////////////////////////////////////////

string temp;

vector<string> stringwithprefix(const string&s){
    //TODO:unimplemented
    //以s开始的字符串有哪些
}
int main(){

    tmp.resize(100);
    t.resize(100);
    Node*root=new Node();
    insert("zhang",0,root);
    insert("zha",0,root);
    insert("zha",0,root);
    insert("qing",0,root);
    deleter(root,"zha",0);

    show(root,0);
    for(auto &m:res){
        cout<<m<<endl;
    }

}
