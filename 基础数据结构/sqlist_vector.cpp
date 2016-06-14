#include <stdio.h>
#include <stdlib.h>
#define INIT_SIZE 1
#define OK 1
#define FAIL 0
#define OVERFLOW -1
#define STATUS int

int i,j,k,a,b,c,tmp;

typedef struct I_think_that_is_vector{
    int* begin;
    int size;//当前的元素个数
    int length;//在内存中占用的空间
}list;

//打印链表的元素
void Show_list(list*&li){
    for(i=0;i<li->size;i++){
        printf("%d ",li->begin[i]);
    }
    printf("%d\n");
}

//重新分配链表——前提是li.size=li.length
void Relloc_list(list*&li){
    int* newbase=(int*)malloc(li->length*2*sizeof(int));
    for(i=0;i<li->length;i++){
        newbase[i]=li->begin[i];
    }
    li->length*=2;
    free((void*)li->begin);
    li->begin=newbase;
}

//初始化链表
void Init_list(list*&li){
    li=(list*)malloc(sizeof(list));
    li->begin=(int*)malloc(INIT_SIZE*sizeof(int));
    li->size=0;
    li->length=INIT_SIZE;
}

//在线性表li的第i个元素的前面插入元素e
//满足条件的i的范围是0<=i<=li->size;
STATUS Insert_element(list*&li,int i,int e){
    if(i<0||i>li->size)return FAIL;
    if(li->size==li->length) Relloc_list(li);
    for(j=li->size;j>i;j--){
        li->begin[j]=li->begin[j-1];
    }
    li->begin[i]=e;
    li->size++;
    return OK;
}
//删除值第一个是value的元素
STATUS Delete_element(list*&li,int value){
    //TODO:unimplemented
    return OK;
}
//查找一个值为value的元素的索引,不存在返回-1
int Search(list*&li,int value){
    //TODO:unimplemented
}
int main(){
    list* pli=NULL;
    Init_list(pli);
    for(int i=0;i<100;i++){
        Insert_element(pli,pli->size,i*79%30);
    }
    Show_list(pli);

}
