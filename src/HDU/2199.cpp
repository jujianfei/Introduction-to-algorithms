// 5072103_AC_0ms_1640kB.cpp
#include <stdio.h>
#include <math.h>
#include<iostream>
using namespace std;
double F1(double,double);
int main(int argc, int *argv[])
{

int cases;
cin>>cases;
while(cases--)
{
    double y;
    cin>>y;
    double lit = pow(10,-5);
    double min = 0, max = 100;
    double mid = (max + min) / 2;
    double result;

    while (min < max && fabs(F1(mid,y)) > lit)
    {
          if (F1(mid,y) > 0)
          {
             max = mid;
          }
          if (F1(mid,y) < 0)
          {
             min = mid;
          }
          mid = (max + min) / 2;
    }

    if (fabs(F1(mid,y)) < lit)
    {
       result = mid;
       printf("%.4f\n",result);
    }
    else
    {
        printf("No solution!\n");
    }

    }
}



double F1(double x,double y)
{
       return 8*x*x*x*x + 7*x*x*x + 2*x*x + 3*x + 6 - y;
}
