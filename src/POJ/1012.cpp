// 15189881_AC_344MS_388K.cc
#include<stdio.h>
int a[15];
int main()
{
	int k;
	while(scanf("%d",&k)&&k!=0)
	{
		int i,j,s,m = k;
		if(a[k])
		{
			printf("%d\n",a[k]);
			continue;
		}
		for(;;m++)//尝试第m个数
		{
			for(i=0;i<k;i++)//第i次kill
			{
				s = (m-1)%(2*k - i);
				for(j=2*k-i; j<2*k;  j++)
				{
					s = (s+m)%(j+1);
				}//如何通过这个循环确定的第i次kill的人的位置？
				if(s<k) break;
			}
			if(i==k)//如果k次kill全部能够满足题意，就可以。否则不行。
			{
				break;
			}
		}
		printf("%d\n",m);
	    a[k] = m;
	}
	return 0;
}
