问题：有一个长度为n的数组，和一个长度为k的滑动窗口，
滑动窗口从数组的左边往右边滑动，每次滑动一个距离，输出滑动窗口内的最大值，最小值。
（或者为建立一个单调队列）


单调队列思想：
（1）元素从尾部进，尾部出，头部只出，不进。
（2）单调递增队列：进队则如果队列为空或者队尾元素比当前待进元素小，元素直接进队；
若队尾元素比待进元素大，则队尾元素从队尾出队，直至队列为空或队尾元素小于当前待进元素。然后当前待进元素
从队尾进队。
（3）出队：对头元素是最小的元素，如果队尾元素与队头元素的距离大于滑动窗口的距离，则说明队头元素不在滑动窗口内，
队头元素从队头出队，直至队头元素在滑动窗口内。
（4）队列初始化时是将滑动窗口大小的 元素尝试入队，（实际队列中的元素可能小于滑动窗口大小，因为有的在队列中，
有的可能没有入队），后来每次滑动窗口滑动一个距离，即每次尝试一个元素入队。
（5）队列中存储的是元素的下标。



```C++
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

#define rep(i,h,n) for(int i=(h);i<=(n);i++)

const int maxn=1000000+5;
int a[maxn],q1[maxn],q2[maxn];//q1、q2存储下标，元素的值可以通过访问下标间接访问到；

int head1,tail1,head2,tail2,index1,index2,k,n;

//q1为递减队列数组，对应的是头，尾分别为 head1，tail1
//q2为递增队列数组，对应的是头，尾分别为 head2，tail2
//k为滑动窗口的长度；
//n为序列总的长度；

inline void Enqueue(int cur)//维护插入操作，单调递减队列；
{
    while(head1<=tail1 && a[q1[tail1]]<=a[cur])//队列不空且待插元素大于队尾元素则让队尾元素出队直到待插元素小于队尾元素
        tail1--;
    //找到位置，插入新元素；
    q1[++tail1]=cur;
}

inline void enqueue(int cur)//单调递增队列;
{
    while(head2<=tail2&&a[q2[tail2]]>=a[cur])//开始应该是head2<tail2;
        tail2--;
    q2[++tail2]=cur;
}


inline void Dequeue(int cur)
{
    //滑动窗口的结束索引为cur，根据end-start+1=length；
    //所以开始的索引为end+1-length，即cur-k+1；
    //正常情况下，队头如果在滑动窗口内，则队头的位置在（cur-k+1）到cur之间。
    while(q1[head1]<cur-k+1)
        head1++;//队首元素不在范围之内就删除它；
    printf("%d",a[q1[head1]]);//队首元素最大；
}


inline void dequeue(int cur) {
    while(q2[head2]<cur-k+1) head2++;
    printf("%d",a[q2[head2]]);
}


int main() {
    while(scanf("%d%d",&n,&k)!=EOF) {
        //front与tail的初始化 与 enqueue对应。开始时保证队列为空。
        head1=head2=index1=index2=1;
        tail1=tail2=0;
        rep(i,1,n)  //for循环，i从1到n
            scanf("%d",&a[i]);
            //序列为长度为n的数组，此中有效的元素的下标是从1到n，而不是从0到n-1；
        rep(i,1,k-1)//维护队列2；
            enqueue(i);//先将前k-1个元素入队，下面才是继续队尾入队一个，然后队头出队，刚好获取最值。
        rep(i,k,n) {
            enqueue(i);
            dequeue(i);
            if(i!=n)
            printf(" ");
        }
        printf("\n");
        rep(i,1,k-1)//维护队列1，队首元素最大；
            Enqueue(i);
        rep(i,k,n) {
            Enqueue(i);
            Dequeue(i);
            if(i!=n)
            printf(" ");
        }
        printf("\n");
    }
    return 0;
}
```

其实滑动窗口除了使用单调队列实现之外，也可以使用STL里面的map实现。


## Pr

- UVA-11572-唯一的雪花
- UVA-1471-防线
