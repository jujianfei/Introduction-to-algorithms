//本文件使用顺序单链表实现了一份键-值对的API
#ifndef LINKLISTST
#define LINKLISTST
#include<stdio.h>
#include<iostream>
#include<set>
#include<stdexcept>
#include<cstdlib>
using namespace std;

template<typename Key,typename Value>
struct Linklist{
    struct Node{
        Key key;
        Value value;
        Node*next;
        Node(){next=NULL;}
        Node(Key key,Value value):key(key),value(value){}
    };
    Node*head;
    Linklist<Key,Value>();
    void Put(Key key,Value value);
    Value Get(Key key);

    bool Isempty(){return head->next==NULL;}
    int Size();
    Key Min(){if(Isempty()==true) throw runtime_error("ST is empty!");return head->next->key;}
    Key Max();
    int Rank(Key key);
    bool Contains(Key key);

    void Delete(Key key);
    int Size(Key lo,Key hi);

    void Clear();
    ~Linklist<Key,Value>(){Clear();delete head;}
    void Test();
};

template<typename Key,typename Value>
Linklist<Key,Value>::Linklist(){
    head=new Node();
}
template<typename Key,typename Value>
void Linklist<Key,Value>::Clear(){
    Node*q=head;
    Node*p=head->next;
    while(p){
        q=p;
        Node*tmp=q->next;
        delete q;
        p=tmp;
    }
    head->next=NULL;
}
template<typename Key,typename Value>
bool Linklist<Key,Value>::Contains(Key key){
    Node*p=head->next;
    while(p){
        if(p->key==key)break;
        p=p->next;
    }
    return false;
}
template<typename Key,typename Value>
Value Linklist<Key,Value>::Get(Key key){
    if(Isempty())
        throw runtime_error("ST is empty!");
    Node*p=head->next;
    while(p){
        if(p->key==key) return p->value;
        p=p->next;
    }
    return Value();
}
template<typename Key,typename Value>
Key Linklist<Key,Value>::Max(){
    if(Isempty())
        throw runtime_error("ST is empty!");
    Node*p=head->next;
    Node*q=head;
    while(p){
        q=p;
        p=p->next;
    }
    return q->key;
}
template<typename Key,typename Value>
int Linklist<Key,Value>::Rank(Key key){
    if(Isempty())
        throw runtime_error("ST is empty");
    int res=0;
    Node*p=head->next;
    while(p){
        if(p->key>=key)return res;
        ++res;
        p=p->next;
    }
    return res;
}
template<typename Key,typename Value>
int Linklist<Key,Value>::Size(){
    if(Isempty())return 0;
    int sz=0;
    Node*p=head->next;
    while(p){
        ++sz;
        p=p->next;
    }
    return sz;
}
template<typename Key,typename Value>
void Linklist<Key,Value>::Put(Key key,Value value){
    Node*tmp=new Node();
    tmp->key=key,tmp->value=value;
    Node*q=head,*p=head->next;
    while(p){
        if(p->key==key){
            p->value=value;
            return;
        }else if(p->key>key){
            q->next=tmp;
            tmp->next=q;
            return;
        }else{
            q=p;
            p=p->next;
        }
    }
    q->next=tmp;
    tmp->next=NULL;
}
template<typename Key,typename Value>
void Linklist<Key,Value>::Test(){
    Node*p=head->next;
    while(p){
        cout<<p->key<<" "<<p->value<<endl;
        p=p->next;
    }
}
template<typename Key,typename Value>
void Linklist<Key,Value>::Delete(Key key){
    if(Isempty())return;
    Node*q=head,*p=head->next;
    while(p){
        if(p->key==key){
            q->next=p->next;
            delete p;
            return;
        }else{
            q=p;
            p=p->next;
        }
    }
    return;
}

#endif // LINKLISTST

