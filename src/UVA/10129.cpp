// 6456888_AC_20ms_0kB.cpp
#include<iostream>
#include<cstdio>
#include<cstring>
#include <vector>
#include <cstring>
using namespace std;
#define N 26
int n;

int G[N][N];
int outer[N];
int iner[N];
int mark[N];
string tmp;
int vis[N];

//欧拉回路关键点！；判断这个图是不是联通的


void dfs(int u) {
    vis[u] = true;
    for (int i=0;i<26;i++) {
        if(G[i][u] && vis[i] == false) {
            dfs(i);
        }
    }
}

bool isconnected() {
    int i=0;
    while (mark[i]==0) {i++;}
    if (i==26) return false;

    dfs(i);
    for (int i=0; i<26; i++) {
        if(mark[i]==true && vis[i]==false) {
            return false;
        }
    }
    return true;
}




int main() {
    //freopen("in.txt", "r", stdin);
    int cases;
    scanf("%d" ,&cases);
    while (cases--) {
        memset(outer,0,sizeof(outer));
        memset(iner,0,sizeof(iner));
        memset(G,0,sizeof(G));
        memset(vis,0,sizeof(vis));
        memset(mark,0,sizeof(mark));

        scanf("%d", &n);
        for (int i=0;i<n;i++) {
            cin>>tmp;
            outer[tmp[0]-'a']++;
            iner[tmp[tmp.size()-1]-'a']++;
            G[tmp[0]-'a'][tmp[tmp.size()-1]-'a']=1;
            G[tmp[tmp.size()-1]-'a'][tmp[0]-'a']=1;
            mark[tmp[0]-'a']=1;
            mark[tmp[tmp.size()-1]-'a']=1;
        }

        bool flag1 = 0;//入度比出度多一个
        bool flag2 = 0;//出度比入度多一个
        bool ok = true;
        for (int i=0;i<26;i++) {
            if(outer[i] == iner[i]) { continue; }
            else if (outer[i] - iner[i] == 1) { flag2 =1; }
            else if (outer[i] - iner[i] == -1) { flag1 =1; }
            else { ok = false; }
        }

        if (isconnected() == false) { ok = false; }

        if (ok && ((flag1 == 1 && flag2 == 1)  || (flag1 == 0 && flag2 == 0)) ) {
            cout << "Ordering is possible." << endl;
        } else {
            cout << "The door cannot be opened." << endl;
        }

    }
}
