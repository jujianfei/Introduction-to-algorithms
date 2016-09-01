#define INF 0x3f3f3f3f
#include <bits/stdc++.h>
using namespace std;
struct Node{
    double p;
    int e;
    Node*next;
    Node(double p=INF,double e=INF,Node*next=NULL):p(p),e(e),next(next){}
};

class Linklist{
public:
    Linklist(istream& cin);
    Linklist(){head=NULL;}
    void ShowLinklist();
    double GetValue(double x);

    Node*head;
};
Linklist::Linklist(istream &cin){
    cout<<"Input p1,e1  p2,e2  p3,e3  p4,e4 ...end with -1 -1"<<endl;
    cout<<"Example Input (1 2 3 4 -1 -1), It'll generate 1*x^2+3*x^4"<<endl;
    head=new Node();
    Node*p=head;
    double tmp_p;
    int tmp_e;
    while(cin>>tmp_p>>tmp_e){
        if(tmp_p==-1)break;
        Node*tmp_pt=new Node(tmp_p,tmp_e);
        p->next=tmp_pt;
        p=p->next;
    }
}
void Linklist::ShowLinklist(){
    if(!head||!(head->next)){
        cout<<"Empty"<<endl;
        return;
    }
    Node*q=head,*p=head->next;
    while(p){
        cout<<p->p<<"*x^"<<p->e;
        if(p->next){
            cout<<"+";
        }
        p=p->next;
    }
    cout<<endl;
}
//!因为我们要在不开辟新的内存的情况下实现A=A+B,因此此项操作后B的内存会被释放
void Adders(Linklist& a,Linklist&b){
    cout<<a.head->p<<endl;
    cout<<b.head->p<<endl;
    auto qa=a.head;
    auto pa=qa->next;
    auto pb=b.head->next;
    cout<<"pb"<<pb->p<<" "<<pb->e<<endl;
    //如果b已经遍历完成,那么就完成了,但是如果B还没有完成,A就结束了,那么需要将B添加到A的结尾上去
    while(pb){
        if(!pa)break;
        if(pb->e<pa->e){//如果pa指向的元素已经比pb指向的元素大了，那么把pb插入到pa前面
            auto tmpnextpb=pb->next;
            qa->next=pb;
            pb->next=pa;
            pb=tmpnextpb;
            qa=qa->next;
        }else if(pb->e==pa->e){
            if(pb->p+pa->p==0){//删除pa所指向的那个节点，推进pb
                auto tmpa=pa;
                auto tmpb=pb;
                pa=pa->next;
                qa->next=pa;
                pb=pb->next;
                delete tmpa;
                delete tmpb;
            }else{
                pa->p=pa->p+pb->p;
                auto tmpb=pb;
                pb=pb->next;
                delete tmpb;
            }
        }else{//如果pa指向的元素已经比pb指向的元素小,推进pa
            qa=pa;
            pa=pa->next;
        }
    }
    if(pb){
        qa->next=pb;
    }
    delete b.head;
    b.head=nullptr;
}
int main(){
    Linklist li(cin);
    Linklist li2(cin);
    Adders(li,li2);
    li.ShowLinklist();
}
