```C++
//用Treap实现的名次树  
  
//名次树支持两个新操作  
//1: Kth(k):找出第k小元素  
//2: Rank(x):值x的“名次”，即比x小的结点个数加1  
  
#include<cstdio>  
#include<cstdlib>  
  
struct Node{  
    Node *ch[2];                    //左右子树          ch[0]左子树   ch[1]右子树  
    int r;                      //优先级。数值越大，优先级越高  
    int v;                      //值  
    int s;                      //以该结点为根的子树的总结点数  
/*  bool operator >(const Node& rhs)const {      //  根据优先级比较结点 
        return r>rhs.r; 
    } 
*/  int cmp(int x)const{  
        if(x==v)    return -1;  
        return x<v?0:1;  
    }  
    void maintain()  
    {  
        s=1;  
        if(ch[0]!=NULL) s+=ch[0]->s;  
        if(ch[1]!=NULL) s+=ch[1]->s;  
    }  
};  
  
//d=0代表左旋,d=1代表右旋  
void rotate(Node* &o,int d){  
    Node *k=o->ch[d^1];  o->ch[d^1]=k->ch[d];  k->ch[d]=o;  
    o->maintain();   k->maintain();   o=k;        //注意必须先维护o，再维护k.因为此时o是k的子结点  
}  
  
//在以o为根的子树中插入键值x，修改o  
void insert(Node* &o,int x){  
    if(o==NULL)  
    {  
        o=new Node();   o->ch[0]=o->ch[1]=NULL;   o->v=x;  o->r=rand(); o->s=1;  
    }  
    else  
    {  
        int d=o->cmp(x);         //当可能有相同点时，不用cmp函数  d=(x<o->v?0:1);  
        insert(o->ch[d],x);  
        if(o->ch[d]->r>o->r)  
            rotate(o,d^1);  
    }  
    o->maintain();  
};  
  
void remove(Node* &o,int x){  
    int d=o->cmp(x);  
    if(d==-1){  
        Node *u=o;  
        if(o->ch[0]==NULL)   {   o=o->ch[1];   delete u;}  
        else if(o->ch[1]==NULL)  {   o=o->ch[0];  delete u;}  
        else{  
            int d2=(o->ch[0]->r>o->ch[1]->r?1:0);  
            rotate(o,d2);  
            remove(o->ch[d2],x);  
  
        }  
    }  
    else  
        remove(o->ch[d],x);  
    if(o!=NULL)  
        o->maintain();  
}  
  
//上面的代码没有处理"待插入值已经存在"和"待删除值不存在"这两种情况  
//因此在调用相应函数之前如必要可进行一次查找  
int find(Node *o,int x){  
    while(o!=NULL){  
        int d=o->cmp(x);  
        if(d==-1)  
            return 1;                       //存在  
        else o=o->ch[d];  
    }  
    return 0;                               //不存在  
}  
  
//找出第k小元素  
int Kth(Node *o,int k)  
{  
    if(o==NULL || k<=0 || k>o->s)  
        return -1;                          //出错  
    if(o->ch[0]==NULL && k==1)  
        return o->v;  
    if(o->ch[0]==NULL)  
        return Kth(o->ch[1],k-1);  
    if(o->ch[0]->s>=k)  
        return Kth(o->ch[0],k);  
    if(o->ch[0]->s+1==k)  
        return o->v;  
     return Kth(o->ch[1],k-o->ch[0]->s-1);  
}  
  
//值x的“名次”，即比x小的结点个数加1  
int Rank(Node *o,int x)  
{  
    int tmp;  
    if(o->ch[0]==NULL)  
        tmp=0;  
    else  
        tmp=o->ch[0]->s;  
    if(o->v==x)  
    {  
        return tmp+1;  
    }  
    if(o->v>x)  
        return Rank(o->ch[0],x);  
    return tmp+1+Rank(o->ch[1],x);  
}  
  
int main()  
{  
    int n,i,x;  
    Node *o=NULL;  
  
    freopen("in.txt","r",stdin);  
    while(scanf("%d",&n)==1)  
    {  
        for(i=1;i<=n;i++)  
        {  
            scanf("%d",&x);  
            if(find(o,x)==0)  
                insert(o,x);  
            else  
                printf("%d元素已存在!\n",x);  
        }  
        printf("插入完成\n");  
        for(i=1;i<=5;i++)  
            printf("Kth=%d Rank=%d\n",Kth(o,i),Rank(o,10+i));  
        remove(o,11);  
        remove(o,15);  
        for(i=1;i<=n;i++)  
        {  
            if(find(o,10+i)!=0)  
            {  
                printf("%d元素已存在!   Rank=%d\n",10+i,Rank(o,10+i));  
            }  
        }  
    }  
  
    return 0;  
}  

```
