
#include<stdio.h>
#include<iostream>
#include<set>
#include<stdexcept>
#include<cstdlib>

using namespace std;

template<typename Key,typename Value>
class BinarySearchST{
public:
     struct Node{
         Key key;
         Value value;
         Node(){}
         Node(Key key,Value value):key(key),value(value){}
     };

     BinarySearchST<Key,Value>();
     void Put(Key key,Value value);
     Value Get(Key key);

     bool Isempty(){return last_-begin_==0;}
     int Size(){return last_-begin_;}
     Key Min(){
         if(Isempty())throw runtime_error("ST is empty!"); return begin_->key;
     }
     Key Max(){
         if(Isempty())throw runtime_error("ST is empty!"); return (last_-1)->key;
     }
     Key Floor(Key key);
     Key Ceiling(Key key);
     int Rank(Key key);
     bool Contains(Key key){return Rank(key)<last_-begin_&&begin_[Rank(key)].key==key;}
     Key Select(int k);
     void Delete(Key key);
     int Size(Key lo,Key hi);
     set<Key> Keys(Key lo,Key hi);
     set<Key> Keys(){return Keys(Min(),Max());}
     void Clear(){delete [] begin_;begin_=last_=finish_=NULL;}
     ~BinarySearchST<Key,Value>(){Clear();}

     void Test();

private:

     void _ReAllocate();
     Node* begin_,*last_,*finish_;

};
template<typename Key,typename Value>
BinarySearchST<Key,Value>::BinarySearchST(){
    begin_=last_=finish_=NULL;
}
template<typename Key,typename Value>
void BinarySearchST<Key,Value>::_ReAllocate(){
    if(finish_-begin_==0){
        begin_=new Node[4];
        last_=begin_;
        finish_=begin_+4;
    }else{
        int size=finish_-begin_,i;
        Node*new_begin_=new Node[size*2];
        Node*new_finish_=new_begin_+size*2;
        for(i=0;i<finish_-begin_;i++){
           *(new_begin_+i)=*(begin_+i);
        }
        delete [] begin_;
        begin_=new_begin_;
        finish_=new_finish_;
        last_=begin_+i;
    }
}
template<typename Key,typename Value>
void BinarySearchST<Key,Value>::Put(Key key,Value value){
    if(last_==finish_){
        _ReAllocate();
    }
    int i;
    for(i=0;i<last_-begin_;i++){
        if((begin_+i)->key==key){
            (begin_+i)->value=value;
            return;
        }else if((begin_+i)->key>key){
            int index=last_-begin_;
            for(;index>i;index--){
                *(begin_+index)=*(begin_+index-1);
            }
            (begin_+i)->key=key,(begin_+i)->value=value;
            ++last_;
            return;
        }else{}
    }
    last_->key=key,last_->value=value;
    last_++;
    return;
}
template<typename Key,typename Value>
void BinarySearchST<Key,Value>::Test(){
    cout<<"lenth"<<last_-begin_<<endl
       <<"size"<<finish_-begin_<<endl;
    cout<<"they are"<<endl;
    for(int i=0;i<last_-begin_;i++){
        cout<<(begin_+i)->key<<" "<<(begin_+i)->value<<" "<<endl;
    }cout<<endl;
}
template<typename Key,typename Value>
int BinarySearchST<Key,Value>::Rank(Key key){
    int lo=0;
    int hi=last_-begin_-1;
    while(lo<=hi){
        int mid=lo+(hi-lo)/2;
        if(begin_[mid].key==key)return mid;
        else if(begin_[mid].key<key)lo=mid+1;
        else hi=mid-1;
    }
    return lo;
}
template<typename Key,typename Value>
set<Key> BinarySearchST<Key,Value>::Keys(Key lo,Key hi){
    set<Key> res;
    if(hi<lo)return res;
    int b=Rank(lo),e=Rank(hi);
    for(int i=b;i<e;i++){
        res.insert(begin_[i].key);
    }
    if(Contains(hi)){
        res.insert(begin_[e].key);
    }
    return res;
}
template<typename Key,typename Value>
int BinarySearchST<Key,Value>::Size(Key lo,Key hi){
    if(hi<lo)return 0;
    else if(Contains(hi)){
        return Rank(hi)-Rank(lo)+1;
    }else{
        return Rank(hi)-Rank(lo);
    }
}
template<typename Key,typename Value>
Value BinarySearchST<Key,Value>::Get(Key key){
    if(Isempty()) throw runtime_error("ST is empty");
    if(!Contains(key)) return NULL;
    else return begin_[Rank(key)].value;
}
template<typename Key,typename Value>
Key BinarySearchST<Key,Value>::Select(int k){
    if(k<0||k>=finish_-begin_){
        throw runtime_error("Index is illegal");
    }else{
        return begin_[k].key;
    }
}
template<typename Key,typename Value>
void BinarySearchST<Key,Value>::Delete(Key key){
    if(Isempty()==true) throw runtime_error("ST is empty");
    if(!Contains(key)) return;
    int index=Rank(key);
    for(int i=index;i<last_-begin_-1;i++){
        begin_[i]=begin_[i+1];
    }
    last_--;

}
