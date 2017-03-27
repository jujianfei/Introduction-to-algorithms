// 6574648_AC_157ms_304kB.cpp
/***********************************************************************************************************************
题意：某公司要买n个设备，每个设备都有不同的生产商，每个生产商的带宽b和价格p不同，要求选取的设备中的带宽最小的设备
b/买的所有设备的价格的总和p最大
思路：要使b/p最大，则b尽可能的大,p尽可能的小
首先我们选一个设备b出来，认为它的b最小 则其他设备的b小于它的全部跳过，再在这些设备中选取价格最小的即可
***********************************************************************************************************************/
#include <cstdio>
#include <cstring>
#include <cmath>
#include <queue>
#include <stack>
#include <vector>
using namespace std;
int min(int a ,int b)
{
    return a > b ? b : a;
}
double max(double a, double b)
{
    return a > b ? a : b;
}
typedef struct 
{
    int b, p;
}node;
vector <node> a[100+10];
int n , m , mina , sum;
double  ans = 0;
node temp;
void work()
{
    for(int i = 0 ; i < n ; i ++)
    {
        for(int j = 0 ; j < a[i].size() ; j ++)
        {
            temp = a[i][j];
            sum = temp.p;
            for(int k = 0 ; k < n ; k ++)
            {
                if(k == i)
                    continue;
                mina = 0x7fffffff;
                for(int q = 0 ; q < a[k].size(); q++)
                {
                    if(temp.b > a[k][q].b)
                        continue;
                    mina = min(mina , a[k][q].p);
                }
                if(mina == 0x7fffffff)
                    break;
                sum += mina;
            }
            if(mina == 0x7fffffff)
                break;
            ans = max(ans , (double)temp.b / (double)sum);
        }
    }
}
void clr()
{
    for(int i = 0 ; i < 100 + 5 ; i ++)
        a[i].clear();
}
int main()
{
    //freopen("data.in" , "r" , stdin);
    int t;
    scanf("%d", &t);
    while(t--)
    {
        ans = 0;
        clr();
        scanf("%d", &n);
        for(int i = 0 ; i < n ; i ++)
        {
            scanf("%d", &m);
            for(int j = 0 ; j < m ; j ++)
            {
                node tm;
                scanf("%d %d", &tm.b, &tm.p);
                a[i].push_back(tm);
            }
        }
        work();
        printf("%.3f\n" , ans);
    }
    return 0;
}