// 6647351_AC_40ms_0kB.cpp
#include <iostream>
#include <cstring>
#include <vector>
#include <stdio.h>
using namespace std;
#include <algorithm>
#include <cmath>
#include <map>
typedef long long ll;
#define INF 0x3f3f3f3f
#define N 107
#define M 10007

struct Node {
    int b,e,w;
    Node(int b,int e,int w):b(b),e(e),w(w){}
    Node() {}
    bool operator <(const Node& n) const { return w<n.w; }
};

Node a[M];
int m,n;
int nodecnt;
int fa[N];
int ans;

int getroot(int x) {
    int root, temp;
    root = x;
    while(root != fa[root])
        root = fa[root];
    while(x != root)
    {
        temp = fa[x];
        fa[temp] = root;
        x = temp;
    }
    return root;
}

bool q_m(int i,int j)  {
    int m=getroot(i);
    int n=getroot(j);
    if(m==n)
        return true;
    else
        return false;
}

void merger(int i,int j)  {
    fa[getroot(j)]=getroot(i);
}



bool addedge(int R) {
   int i=a[R].b;
   int j=a[R].e;
   int ri = getroot(i);
   int rj = getroot(j);
   if (ri == rj)
        return false;
   else {
        merger(i,j);
        nodecnt++;
        return nodecnt==n-1;
   }
}

void deepinit() {
    ans = INF;
    for (int i=0; i<N; i++) fa[i]=i;
    nodecnt = 0;
}


int main() {
    //freopen("in.txt", "r", stdin);

    while (cin >> n >> m) {
        //cout << "--case--" <<  endl;
        deepinit();
        if (m==0 && n==0) break;

        int b,e,w;
        for (int i=0; i<m; i++) {
            scanf("%d%d%d", &a[i].b, &a[i].e, &a[i].w);
        }
        sort(a, a+m);
        for (int L=0; L<m; L++) {
            for (int R=L; R<m; R++) {
                //cout << "now " << L << " " << R << endl;
                if (addedge(R)) {
                    ans = min(a[R].w-a[L].w, ans);
                    for (int i=0; i<N; i++) fa[i]=i;
                    nodecnt = 0;
                    break;
                }
            }
        }
        if (ans != INF) {
            cout << ans << endl;
        } else {
            cout << "-1" << endl;
        }
    }
}
