// 15157967_AC_375MS_1060K.cc
#include <iostream>
#include <queue>
#include<stdio.h>
using namespace std;

#define M 30005
int array[M];

priority_queue< int,vector<int>,less<int> > maxHeap;
priority_queue< int,vector<int>,greater<int> > minHeap;

int main()
{
    //freopen("/home/zlq/acminging/in","r",stdin);
    int n, m, i;
    scanf("%d%d",&n,&m);
    for ( i = 0; i < n; ++i )
        scanf("%d",array+i );

    int oper = 0, k = 0, t1, t2;
    for ( i = 0; i < m; ++i )
    {
        scanf("%d",&oper);
        while ( k < oper )
        {
            minHeap.push ( array[k] );
            if ( ! maxHeap.empty() && minHeap.top() < maxHeap.top() )
            {

                t1 = minHeap.top(); minHeap.pop();
                t2 = maxHeap.top(); maxHeap.pop();
                maxHeap.push(t1); minHeap.push(t2);
                //cout<<"change "<<t1<<" to "<<t2<<endl;
            }
            ++k;
        }
        printf("%d\n",minHeap.top());
        maxHeap.push ( minHeap.top() );
        minHeap.pop();
    }
    return 0;
}
