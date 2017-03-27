#include<bits/stdc++.h>
using namespace std;
double l,v1,v2;
int k;
int n;
int main()
{
    scanf("%d%lf%lf%lf%d",&n,&l,&v1,&v2,&k);
    double t,t1,t2;
    int d = n/k+((n%k)?1:0);
    t2 = l/(v2+v1*(d-1)*(2*v2/(v1+v2)));
    t = t2+(2*v2/(v1+v2))*(d-1)*t2;
    printf("%.10lf\n",t);
}