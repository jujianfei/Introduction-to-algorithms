// 7030211_AC_1922ms_1348kB.cpp
#include <iostream>
#include <cstdio>
#include <cstring>
#include <stack>
typedef long long ll;
using namespace std;
int main()
{
   // freopen("in.txt", "r", stdin);
    int n;
    ll heigh,ans;
    stack<ll>s;
    while(scanf("%d",&n)!=EOF)
    {
        ans=0;
        cin>>heigh;
        s.push(heigh);//入栈
        for(int i=1;i<n;i++)
        {
            cin>>heigh;
            while(!s.empty()&&s.top()<=heigh) //比較栈顶元素和新增加元素的关系
            {
                s.pop();
            }
           // cout << "pushing " << heigh << " " << s.size() << endl;
            ans+=s.size();
            s.push(heigh);
        }
        cout<<ans<<endl;
        while(!s.empty()) s.pop();//空栈
    }
    return 0;
}

