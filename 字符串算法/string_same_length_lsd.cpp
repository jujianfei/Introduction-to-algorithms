
#include<bits/stdc++.h>
using namespace std;
string a[10]={
"zh",
"ab",
"cd",
"ac",
"cc",
"ec",
"we",
"ar",
"yu",
"gh"
};
string aux[10];
int charat(char a){
    return a-'a';
}
int counter[27];


void init(){
    memset(counter,0,sizeof(counter));
}

void sort(){//从最低位开始比较
    for(int d=1;d>=0;d--){
        for(int i=0;i<26;i++){
            counter[i]=0;
        }
        for(int i=0;i<10;i++){
            counter[charat(a[i][d])+1]++;
        }
        //更新数据，从哪儿开始写入数据
        for(int i=1;i<=26;i++){
            counter[i]=counter[i]+counter[i-1];
        }
        //制作副本
        for(int i=0;i<10;i++){
            int index=charat(a[i][d]);
            aux[counter[index]++]=a[i];
        }
        //回写，复制数据
        for(int i=0;i<10;i++){
            a[i]=aux[i];
        }
    }
}

int main(){
    sort();
    for(int i=0;i<10;i++){
        cout<<a[i]<<" ";
    }cout<<endl;
}

