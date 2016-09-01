#include<bits/stdc++.h>
#define N 1007//假设最多能够存放N个元素
using namespace std;
/*
这里我们采用数组模拟单链表，
同样我们为了能够方便的进行插入删除查找，
设置一个头指针head，这个head并没有任何意义，
只是为了操作方便，
同时为了模拟堆中的free和new
我们设定两个私有函数```free```和
```get_first_empty```进行模拟。
*/
/*
规定从1开始存放元素
并且如果一个元素的next是0的话，说明这个元素是结尾
如果一个元素的next是-1的话，说明这个位置是没有没使用的
*/
class SMlist{//要保证链表是单调递增的,而且是不重复的
public:
    struct Node{
        int val;
        int next;
    };
    SMlist();
    bool Insert(int val);
    bool Remove(int val);
    int Size();
    bool Search(int val);
    void Show();
private:
    Node a[N];
    int sz;
    int head;

    void free(int i){//将某个节点释放掉
        a[i].next=-1;
    }
    int get_first_empty(){
        for(int i=1;i<N;i++){
            if(a[i].next==-1)return i;
        }
        return 0;
    }
};
SMlist::SMlist(){
    memset(a,-1,sizeof(a));
    sz=0;
    head=1;
    a[head].next=0;
}
bool SMlist::Insert(int val){
    auto p=a[head].next;
    auto q=head;
    int location=get_first_empty();
    if(location==0)return false;
    a[location].val=val;
    while(p){
        if(a[p].val<val){
            q=p;
            p=a[p].next;
        }else{
            a[q].next=location;
            a[location].next=p;

            sz++;
            return true;
        }
    }
    a[q].next=location;
    a[location].next=0;
    sz++;
    return true;
}
void SMlist::Show(){
    auto p=a[head].next;
    while(p){
        cout<<a[p].val<<" ";
        p=a[p].next;
    }cout<<endl;
}
bool SMlist::Search(int val){
    auto p=a[head].next;
    while(p){
        if(a[p].val==val)return true;
        p=a[p].next;
    }
    return false;
}
bool SMlist::Remove(int val){
    auto q=head;
    auto p=a[head].next;
    while(p){
        if(a[p].val==val){
            a[q].next=a[p].next;
            free(p);
            sz--;
            return true;
        }else{
            q=p;
            p=a[p].next;
        }
    }
    return false;
}
int main(){
    SMlist sl;
    for(int i=0;i<10;i++){
        sl.Insert(i);
    }
    sl.Remove(3);
    sl.Insert(3);
    sl.Show();
}
