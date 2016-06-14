#include<bits/stdc++.h>
using namespace std;
#define N 100


class MaxQ{
public:
    MaxQ(){
        memset(a,0,sizeof(a));
        sz=0;
    }
    int maxer(){
        if(isempty()){
            cout<<"empty"<<endl;
            return -1;
        }else{
            return a[0];
        }
    }
    int deleter_maxer(){
        if(isempty()){
            cout<<"empty"<<endl;
            return -1;
        }else{
            int res=a[0];
            swaper(0,sz-1);
            sz--;//应当收缩数据的大小，然后再进行下沉操作
            sink(0);

        }
    }
    bool isempty(){
        return sz==0;
    }
    int insert(int val){
        a[sz]=val;
        swim(sz);
        sz++;//这里顺顺序是无所谓的
    }
private:
    int a[N];
    int sz;

    void swim(int index){//index为索引开始上浮的函数
        while(index>0){
            if(a[(index-1)/2]<a[index]){
                swaper((index-1)/2,index);
                index=(index-1)/2;
            }else{
                break;
            }
        }
    }
    void sink(int index){
        //有左子树
        while(2*index+1<sz){
            int j=2*index+1;
            if(j+1<sz&&a[j]<a[j+1])j++;
            if(a[index]>a[j])break;
            else swaper(index,j);
            index=j;
        }//也可以使用递归的方法
    }
    void swaper(int i,int j){
        int tmp=a[i];
        a[i]=a[j];
        a[j]=tmp;
    }
};

int main(){
    MaxQ q;
    q.insert(1);
    q.insert(3);
    q.insert(4);
    q.insert(10);
    q.insert(23);
    q.insert(21);
    cout<<q.maxer()<<endl;
    q.deleter_maxer();
    cout<<q.maxer()<<endl;
}