// 5939072_AC_0ms_272kB.cpp
#include<stdio.h>
#include<iostream>

using namespace std;
typedef long long ll;

int get(char f){
    if (f== '+' || f == '-') return 0;
    else return 1;
}
int solve(int a,char op,int b){
    if (op=='-') return a-b;
    if (op=='+') return a+b;
    if (op=='*') return a*b;
    if (op=='/') return a/b;
    if (op=='%') return a%b;
}
int main(){
    //freopen("D://in.txt","r",stdin);
    int cases;
    cin >> cases;
    while(cases--)
    {
        int a,b,c,ans = 0;
        char op1,op2;
        cin >> a >> op1 >> b >> op2 >> c;
        if (get(op1) >= get(op2)){//判断优先级
            ans = solve(a,op1,b);
            ans = solve(ans,op2,c);
        }
        else{
            ans = solve(b,op2,c);
            ans = solve(a,op1,ans);
        }
        cout << ans << endl;
    }

}
