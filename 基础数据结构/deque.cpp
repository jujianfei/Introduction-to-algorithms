#define MAXSIZE 10
#include<bits/stdc++.h>
using namespace std;

class Deque{
public:
    Deque();
    bool push_back(int val);
    bool pop_back();
    bool push_front(int val);
    bool pop_front();
    int size(){return sz;}
    void debug_show(){
        for(int i=head;i!=tail;i=(i+1)%MAXSIZE){
            cout<<a[i]<<" ";
        }cout<<endl;
    }
private:
    int a[MAXSIZE];//实际最多能存放9个元素
    int head;
    int tail;
    int sz;
};
Deque::Deque(){
    sz=head=tail=0;
}
bool Deque::push_back(int val){
    if((tail+1)%MAXSIZE==head){
        cout<<"full_deque"<<endl;
        return false;
    }else{
        a[tail]=val;
        tail=(tail+1)%MAXSIZE;
        sz++;
        return true;
    }
}
bool Deque::push_front(int val){
    if((tail+1)%MAXSIZE==head){
        cout<<"full_deque"<<endl;
        return false;
    }else{
        a[head]=val;
        head=(head+MAXSIZE-1)%MAXSIZE;
        sz++;
        return true;
    }
}
bool Deque::pop_back(){
    if(head==tail){
        cout<<"empty"<<endl;
        return false;
    }else{
        tail=(tail+MAXSIZE-1)%MAXSIZE;
        sz--;
        return true;
    }
}
bool Deque::pop_front(){
    if(head==tail){
        cout<<"empty"<<endl;
        return false;
    }else{
        head=(head+MAXSIZE+1)%MAXSIZE;
        sz--;
        return true;
    }
}
int main(){

}
