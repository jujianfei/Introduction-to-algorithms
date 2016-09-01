#include<bits/stdc++.h>
using namespace std;
#include<hash_map>
#include<hash_set>
#include<unordered_map>
#include<unordered_set>


int hash_fun(string s){
    int res=0;
    for(int i=0;i<s.size();i++){
        res+=s[i];
    }
    return res%10;
}
struct Node{
    string con;
    int next;
    Node(string s,int n){
        con=s;
        next=n;
    }
    Node(){}
};

Node pointer[100];
int head[10];
int cnt;


void init(){

    memset(head,-1,sizeof(head));
    cnt=0;
}


bool Inmap(string s){
    int begin=hash_fun(s);
    int nexter=head[begin];

    while(nexter!=-1){

        if(pointer[nexter].con==s)return true;
        nexter=pointer[nexter].next;

    }

    return false;
}


void Insert(string s){

    if(Inmap(s)){
            cout<<"fail"<<endl;
            return;
    }
    pointer[cnt]=Node(s,-1);
    int begin=hash_fun(s);
    int tmpnext=head[begin];

    if(tmpnext==-1){
        head[begin]=cnt;

    }else{

        int bk=tmpnext;
        pointer[cnt].next=bk;
        head[begin]=cnt;
    }
    cnt++;
}

void test(){
    for(int i=0;i<10;i++){
        int next=head[i];
        while(next!=-1){
            cout<<pointer[next].con<<" ";
            next=pointer[next].next;
        }
        cout<<endl;
    }
}

int main(){
    init();

    Insert("zhang");
    Insert("lan");
    Insert("qing");
    Insert("zhang");
    Insert("hahahh");
    Insert("ILOVEYOU");
    test();

}
