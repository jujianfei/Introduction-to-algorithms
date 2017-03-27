#include<bits/stdc++.h>
using namespace std;
class BLlist{
public:
    struct Node{
        Node*pre;
        Node*next;
        int val;
    };
    BLlist();
    void push_back(int val);//链表的尾部插入元素
    bool size();//链表的大小
    bool remove(int val);//删除是val的第一个元素
    void show();
private:
    Node*head;
    int sz;
};
BLlist::BLlist(){
    sz=0;
    head=nullptr;
}
void BLlist::push_back(int val){
    if(head==nullptr){
        head=new Node();
        head->val=val;
        head->next=head;
        head->pre=head;
        sz++;
    }else{
        auto q=head;
        for(int i=0;i<sz-1;i++){
            q=q->next;
        }
        auto p=q->next;//将p,q移动到要插入节点的那个地方
        Node* tmp=new Node();
        tmp->val=val;
        //一下四步很关键
        q->next=tmp;
        tmp->pre=q;
        tmp->next=p;
        p->pre=tmp;
        //元素个数+1
        sz++;
    }
}
void BLlist::show(){
    if(!head)return;
    auto p=head;
    for(int i=0;i<sz;i++){
        cout<<p->val<<endl;
        p=p->next;
    }
}
bool BLlist::remove(int val){
    if(!head)return false;
    auto p=head;
    for(int i=0;i<sz;i++){
        if(p->val==val){
            if(sz==1){
                delete head;
                head=nullptr;
                sz--;
                return true;
            }else{
                auto before=p->pre;
                auto behind=p->next;
                before->next=behind;
                behind->pre=before;
                delete p;
                sz--;
                return true;
            }
        }else{
            p=p->next;
        }

    }
    return false;
}
int main(){
}
