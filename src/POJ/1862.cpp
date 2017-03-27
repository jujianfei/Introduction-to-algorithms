// 15280776_AC_16MS_728K.cc
#include<stdio.h>
#include<iostream>
#include<math.h>
using namespace std;

#include<queue>

priority_queue<double> q;
int n;
double a;

int main(){
    //freopen("D://in.txt","r",stdin);
    scanf("%d",&n);
    while(n--){
        scanf("%lf",&a);
        q.push(a);
    }
    if(q.size()==1){
        printf("%.3f\n",q.top());
        return 0;
    }

    while(q.size()!=1){
        double top=q.top();
        q.pop();
        double top2=q.top();
        q.pop();
        double res=2*sqrt(top*top2);
        q.push(res);
    }
    printf("%.3f\n",q.top());

}
