#include <bits/stdc++.h>
using namespace std;
#define N 1000007
#define INF 0x3f3f3f3f
int n, k;

int c[N];
struct Node {
    int l, r, id, res;
    bool operator < (const Node& n2) const { return r < n2.r; }
};
bool cmp(const Node& n1, const Node& n2) { return n1.id < n2.id; }
map<int,int> mp;

Node b[N];
int a[N];
int sum[N];

int query(int x){
    int s=0;
    while(x>0)
        s^=c[x], x-=x&-x;
    return s;
}
void update(int x, int n){
    while(x<N)
        c[x]^=n,x+=x&-x;
}

int res[N];

int main()
{

    //freopen("in.txt", "r", stdin);
    scanf("%d", &n);
    a[0] = 0;
    for (int i=1; i<=n; i++) {
        scanf("%d", &a[i]);
        sum[i] = sum[i-1] ^ a[i];
    }
    scanf("%d", &k);
    for (int i=0; i<k; i++) {
        scanf("%d%d", &b[i].l, &b[i].r);
        b[i].id = i;
    }
    sort(b, b+k);
    int cur = 1;
    for (int i=0; i<k; i++) {
        while (cur <= b[i].r) {
            if (mp.find(a[cur])==mp.end()) {
                mp[a[cur]] = cur;
            }
            else {
               update(mp[a[cur]], a[cur]);
               mp[a[cur]] = cur;
            }
            update(cur, a[cur]);
            cur ++;
        }

         res[b[i].id] = ((query(b[i].r) ^ sum[b[i].r]) ^ (query(b[i].l-1) ^ sum[b[i].l-1]));
    }

    for (int i=0; i<k; i++) printf("%d\n", res[i]);
}