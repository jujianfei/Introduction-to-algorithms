// 6463238_AC_280ms_0kB.cpp
#include <cmath>
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
#define N 507
int n;
int a[N];
//!我用这种方法生成的序列并不是按照字典序列的
vector<vector<int> > res;
bool isprime[N];
void init() {
    for (int i=0;i<20;i++) {
        a[i]=i+1;
    }

    memset(isprime, true, sizeof(isprime));
    isprime[0]=isprime[1]=false;
    for (int i=2;i<N;i++) {
        if (isprime[i]==false) {}
        else {
            for (int j=i+i;j<N;j+=i) {
                isprime[j]=false;
            }
        }
    }
}


void dfs(int cur) {
    if (cur == n) {
        if (isprime[a[0] + a[n-1]] == false){
            return;
        }
//        for (int i=0;i<n;i++) {
//            cout << a[i] << " ";
//        }cout << endl;
        res.push_back(vector<int>(a, a+n));
    }
    for (int i=cur;i<n;i++) {
        swap(a[cur], a[i]);
        if (isprime[a[cur] + a[cur-1]]==false) {
            swap(a[cur], a[i]);
        }else {
            dfs(cur+1);
            swap(a[cur], a[i]);
        }

    }
}

void show() {
    sort(res.begin(), res.end());
    for (int i=0;i<res.size();i++) {
        for (int j=0;j<res[i].size()-1;j++) {
            cout << res[i][j] << " ";
        }cout<<res[i][res[i].size()-1]<<endl;
    }
}

int main() {
    init();
    int kase=0;
    int t=0;
    
    while (~scanf("%d", &n)) {
        if(t++)cout<<endl;
        res.clear();
        cout <<  "Case "<<++kase << ":" << endl;
        dfs(1);
        show();

    }


}
