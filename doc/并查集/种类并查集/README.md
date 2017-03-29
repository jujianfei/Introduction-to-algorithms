## 种类并查集

POJ1182食物链
```
动物王国中有三类动物A,B,C，这三类动物的食物链构成了有趣的环形。A吃B， B吃C，C吃A。 
现有N个动物，以1－N编号。每个动物都是A,B,C中的一种，但是我们并不知道它到底是哪一种。 
有人用两种说法对这N个动物所构成的食物链关系进行描述： 
第一种说法是"1 X Y"，表示X和Y是同类。 
第二种说法是"2 X Y"，表示X吃Y。 
此人对N个动物，用上述两种说法，一句接一句地说出K句话，这K句话有的是真的，有的是假的。当一句话满足下列三条之一时，这句话就是假话，否则就是真话。 
1）  当前的话与前面的某些真的话冲突，就是假话； 
2）  当前的话中X或Y比N大，就是假话； 
3）  当前的话表示X吃X，就是假话。 
你的任务是根据给定的N（1 <= N <= 50,000）和K句话（0 <= K <= 100,000），输出假话的总数。 
```
```
struct node{  
    int parent;                    
    int relation;//p[i].relation表示节点i与其父节点(即p[i].parent)的关系  
}p[50010]; 

```
- p[x].relation=0   ……表示节点x与其父节点rootx的关系是：同类
- p[x].relation=1   ……表示节点x与其父节点rootx的关系是：吃根节点
- p[x].relation=2   ……表示节点x与其父节点rootx的关系是：被根结点吃

### 不在一个集合里面-合并操作
```
        root1 = find(a);  
        root2 = find(b);  
        if(root1 != root2) {  
            p[root2].pre = root1;  
            p[root2].relation = (3 + (ope - 1) +p[a].relation - p[b].relation) % 3;  
        }  
```
find过程中已经进行了路径压缩并更新了关系域，因此可以先不考虑。
```
rootx->rooty = rootx->x + x->y + y->rooty
```
其中 rootx->x=-(x->rootx)
其中 rooty->y=-(y->rooty)
x->y通过题目给出来
题目中
1为同类，
2为x吃y，
为了让其符合我们定义的关系
ope-1
0为同类，1表示x吃y

这样上述代码就可以明白了，这里+3然后%3是为了消除负数的情况

### 在一个集合里面-检查操作

- 检查是不是同类

因为已经进行了路径压缩，可以直接检查x->root和y->root的关系，如果是相同的就说明是同类，

- 检查是不是x吃y的关系
x->y==1
转化成
x->root+root->y==1
同样进行+3 % 3的操作
```
3 - p[a].relation + p[b].relation) % 3 == ope - 1
```
### 查找操作-带路径压缩

```
int find(int x){  
    int temp;  
    if(x == p[x].pre)  
        return x;  
    temp = p[x].pre; //路径压缩  
    p[x].pre = find(temp);  
    p[x].relation = (p[x].relation + p[temp].relation) % 3; //关系域更新  
    return p[x].pre; //根结点  
}  
```
解释：
```
p[x].relation = (p[x].relation + p[temp].relation)
```
假设是```x---tmp--root`三者构成这种关系
x首先回溯路径压缩，x指向的变成根节点
x->root = x->tmp + tmp ->root
因此可以表示成这种形式

## 这道题目的源代码如下
```C++
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define N 50010

struct node
{
    int pre;
    int relation;
};
node p[N];

int find(int x) //查找根结点
{
    int temp;
    if(x == p[x].pre)
        return x;
    temp = p[x].pre; //路径压缩
    p[x].pre = find(temp);
    p[x].relation = (p[x].relation + p[temp].relation) % 3; //关系域更新
    return p[x].pre; //根结点
}

int main()
{
    int n, k;
    int ope, a, b;
    int root1, root2;
    int sum = 0; //假话数量
    scanf("%d%d", &n, &k);
    for(int i = 1; i <= n; ++i) //初始化
    {
        p[i].pre = i;
        p[i].relation = 0;
    }
    for(int i = 1; i <= k; ++i)
    {
        scanf("%d%d%d", &ope, &a, &b);
        if(a > n || b > n) //条件2
        {
            sum++;
            continue;
        }
        if(ope == 2 && a == b) //条件3
        {
            sum++;
            continue;
        }
        root1 = find(a);
        root2 = find(b);
        if(root1 != root2) // 合并
        {
            p[root2].pre = root1;
            p[root2].relation = (3 + (ope - 1) +p[a].relation - p[b].relation) % 3;
        }
        else
        {
            if(ope == 1 && p[a].relation != p[b].relation)
            {
                sum++;
                continue;
            }
            if(ope == 2 && ((3 - p[a].relation + p[b].relation) % 3 != ope - 1))
            {
                sum++;
                continue;}
        }
    }
    printf("%d\n", sum);
    return 0;
}

```
## POJ1733

题目大意是：一个由0,1组成的数字串~~，现在你问一个人，第i位到第j位的1的个数为奇数还是偶数。一共会告诉你几组这样的数
要你判断前k组这个人回答的都是正确的，到第k+1组，这个人说的是错的，要你输出这个k，要是这个人回答的都是正确的，则输出组数
odd为奇数，even为偶数。
Input
10
5
1 2 even
3 4 odd
5 6 even
1 6 even
7 10 odd
Output：
3
###方法一：
使用向量法
```C++
#include<iostream>
#include<fstream>
#include<map>
#include<algorithm>
#include<stdio.h>
#define N 40000
using namespace std;
map<int,int> tr;
int fa[N];
int re[N];
int cnt=0;

int getroot(int x)
{
    int tmp;
    if(fa[x]==x)return x;
    else{
        tmp=fa[x];
        fa[x]=getroot(fa[x]);
        re[x]=(re[x]+re[tmp])%2;
        return fa[x];
    }
}
void merger(int x,int y,int d){
    int rx=getroot(x);
    int ry=getroot(y);
    fa[ry]=rx;
    re[ry]=(re[x]-re[y]+d+2)%2;
}

int main()
{
    for(int i=0;i<N;i++){
        fa[i]=i;
        re[i]=0;
    }
    int n,lines;
    scanf("%d%d",&n,&lines);
    int a,b,d,flag=1,pos;
    char s[11];
    for(int now=1;now<=lines;now++)
    {
       scanf("%d%d%s",&a,&b,s);
       if(s[0]=='e'){d=0;}else{d=1;}
       b++;
       if(tr.find(a)==tr.end()){tr[a]=cnt++;}
       if(tr.find(b)==tr.end()){tr[b]=cnt++;}
       int i=tr[a],j=tr[b];
       int m=getroot(i),n=getroot(j);

       if(flag==0)continue;

       if(m!=n){
           merger(i,j,d);
       }
       else{
           if(re[i]!=(re[j]+d)%2){
               pos=now-1;
               flag=0;
           }
       }
    }
    if(flag)printf("%d\n",lines);
    else printf("%d\n",pos);

}
```