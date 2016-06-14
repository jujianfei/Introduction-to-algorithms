#include <bits/stdc++.h>
using namespace std;
#define N 1007
template <typename Key>
class IndexQ{
public:
    IndexQ(){
        n=0;
    }
    void isempty(){return n==0;}
    void push(int id,Key e){//堆内部的id不能够相同，但是key可以是相同的
        heap[n++]=id;
        m[id]=e;
        make_heap(heap,heap+n,[this](const int i,const int j){return m[i]<m[j];});
    }
    void pop(){
        pop_heap(heap,heap+n,[this](const int i,const int j){return m[i]<m[j];});
        n--;
    }
    int top(){
        if(n==0)throw;
        else return heap[0];
    }
    void change(int i,Key e){//i必须出现过了
        if(m.find(i)==m.end()){
            push(i,e);
        }else{
            m[i]=e;
            make_heap(heap,heap+n,[this](const int i,const int j){return m[i]<m[j];});
            //实际上这里不用重新建立堆，应该有更好的方法
        }
    }
private:

    map<int,Key> m;
    int heap[N];
    int n;

};
int main(){
    IndexQ<string> q;
    q.push(1,"ga");
    q.push(2,"s");
    q.push(3,"haha");
    cout<<q.top()<<endl;
    q.change(3,"za");
    cout<<q.top()<<endl;

}
