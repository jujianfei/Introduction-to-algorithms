// 15117191_AC_0MS_204K.cpp
#include<stdio.h>
#include<algorithm>
using namespace std;
int a[1000000];
int main()
{
	int n,i;

	while(~scanf("%d",&n))
	{
		for(i=0;i<n;i++)
		scanf("%d",&a[i]);
		sort(a,a+n);
		printf("%d\n",a[n/2]);
	}
}