#define N 1007
template <typename Key>
class IndexQ{
public:
    IndexQ(){
        n=0;
    }
    bool isempty(){return n==0;}
    void push(int id,Key e){//堆内部的id不能够相同，但是key可以是相同的
        heap[n++]=id;
        m[id]=e;
        make_heap(heap,heap+n,[this](const int i,const int j){return m[i]>m[j];});//如果想改变最大或者最小优先，可以更改这个数值
    }
    void pop(){
        pop_heap(heap,heap+n,[this](const int i,const int j){return m[i]>m[j];});
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
            make_heap(heap,heap+n,[this](const int i,const int j){return m[i]>m[j];});
            //实际上这里不用重新建立堆，应该有更好的方法
        }
    }
private:

    map<int,Key> m;
    int heap[N];
    int n;

};
