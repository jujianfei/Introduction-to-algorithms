// 15150950_AC_0MS_740K.cc
#include <iostream>
#include<stdio.h>
using namespace std;

int main()
{
    int s, d;
    int sNum, dNum;
    while (scanf("%d%d", &s, &d) != EOF)
    {
     if (d > 4*s)
     {
         sNum = 10;
         dNum = 2;
     }
     else if (2*d > 3*s)
     {
         sNum = 8;
         dNum = 4;
     }
     else if (3*d > 2*s)
     {
         sNum = 6;
         dNum = 6;
     }
     else if (4*d > s)
     {
         sNum = 3;
         dNum = 9;
     }
     else
     {
         sNum = 0;
         dNum = 12;
     }
     int sum = sNum*s - dNum*d;
     (sum>0)? cout << sum << endl : cout << "Deficit"<<endl;
    }
}
