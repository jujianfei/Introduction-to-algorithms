
#include<bits/stdc++.h>
using namespace std;
string a[10]={
    "azhang",
    "azhangl",
    "zhanglanq",
    "zhanglan",
    "zhang",
    "",
    "d",
    "ddd",
    "ddddd",
    "dddddddddd"
};
string aux[10];
int charat(string s,int pos){//0-26
    if(pos>=s.size())return 0;
    else return s[pos]-'a'+1;//这样一来，空字符串就变得比'a'还小了
}


void sort(int lo,int hi,int pos,int lim){//同样使用前闭后开的区间
    if(pos==lim)return;//超过范围了
    if(lo+1>=hi)return;//只有一个元素不用排序,或者根本没有元素，也不用排序
    int counter[28];
    for(int i=0;i<28;i++){
        counter[i]=0;
    }

    for(int i=lo;i<hi;i++){
        int loc=charat(a[i],pos)+1;
        counter[loc]++;
    }

    //计算开始写入的位置

    for(int i=1;i<28;i++){
        counter[i]=counter[i]+counter[i-1];
    }

    //开始写入数据
    for(int i=lo;i<hi;i++){
        int loc=charat(a[i],pos);
        aux[counter[loc]++]=a[i];
    }
    ///!注意！因为aux[]数组中，下标一直是从0开始的并不是从lo开始的！
    //回写数据
    for(int i=lo;i<hi;i++){
        a[i]=aux[i-lo];
    }


    //递归的调用
    sort(lo,lo+counter[0],pos+1,lim);

    for(int i=1;i<28;i++){
        sort(lo+counter[i-1],lo+counter[i],pos+1,lim);
    }
}

void show(){
    for(int i=0;i<10;i++){
        cout<<a[i]<<endl;
    }
}


int main(){
    int maxer=-1;
    for(int i=0;i<10;i++){
        maxer=std::max(maxer,int(a[i].size()));
    }
    sort(0,10,0,maxer);
    show();
}
