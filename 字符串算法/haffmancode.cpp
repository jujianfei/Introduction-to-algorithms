
#include<bits/stdc++.h>
using namespace std;

//哈夫曼树的节点信息
struct Node{
    int fre;//频率
    Node*lc,*rc;
    char con;//内容
    Node(int _fre,int _con,Node*l,Node*r){
        lc=l,rc=r,fre=_fre,con=_con;
    }
    Node(){}
};
bool operator<(const Node&n1,const Node&n2){return n1.fre>n2.fre;}

Node*outer;//总的根节点，全局变量

//构建小写字母对应的haffman编码辅助函数
void build(string*s,Node* root,string tmp){
    if(root->lc==NULL&&root->rc==NULL){
        s[root->con-'a']=tmp;
        return;
    }
    build(s,root->lc,tmp+'0');
    build(s,root->rc,tmp+'1');
}

/**
*给定一个字符串，返回其在小写字母表范围内的haffman编码
*/
string code(string s){
    //规定全是小写的字符，统计每个小写字符出现的频率
    int fre[26];
    memset(fre,0,sizeof(fre));
    for(int i=0;i<s.size();i++){
        fre[s[i]-'a']++;
    }

    priority_queue<Node*> q;
    for(int i=0;i<26;i++){
        Node* tmp=new Node(fre[i],i+'a',NULL,NULL);
        q.push(tmp);
    }
    while(q.size()!=1){
        Node*fir=q.top();
        q.pop();
        Node*sec=q.top();
        q.pop();
        Node*tmp=new Node(fir->fre+sec->fre,'#',fir,sec);
        q.push(tmp);
    }
    Node*root=q.top();
    outer=root;//将外部根节点复制这个节点
    string tar[26];
    string tmp="";
    //构建每个小写的字母对应的哈夫曼编码
    build(tar,root,tmp);
    string res="";
    for(int i=0;i<s.size();i++){
        res+=tar[s[i]-'a'];
    }
    return res;
}

//解码函数辅助
char search_from(Node*root,string &s,int &cur){
    if(root->lc==NULL&&root->rc==NULL){
        return root->con;
    }
    int now=cur;
    cur=cur+1;
    if(s[now]=='0'){
        return search_from(root->lc,s,cur);
    }else{
        return search_from(root->rc,s,cur);
    }
}


/**
*给定一个haffman编码，解码，可以通过编译表，或者haffman树（这里通过haffma树）
*/
void decode(string s){
    int cur=0;
    while(cur!=s.size()){
        cout<<search_from(outer,s,cur);
    }
}

int main(){
    cout<<code("zhanglanqing");
    decode(code("zhanglanqing"));
}
