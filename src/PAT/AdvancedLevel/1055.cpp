// TE了很长世间，就是找不到原因，后来分析下，知道了有个优化
// N/200=500,说明同一年龄最多可以有500个人，而M=100比较小，意味着同一年龄100以后的人都不会被搜到
// 典型的IO选手的代码
#include<iostream>
#include<cstring>
#include<cstdio>
#include <algorithm>
using namespace std;
struct node{
    char name[10];
    int age,worth;
}a[100005];
int b[20005];
int c[205];
bool cmp2(const node& p,const node& q){
    if(p.worth==q.worth)
    {
        if (p.age==q.age)
        {
            return strcmp(p.name,q.name)<=0;
        }
        return p.age<q.age;
    }
    return p.worth>q.worth;
}
int main()
{
    int n,q,i,M,ma,mb,txt=1,len;
    while(~scanf("%d %d",&n,&q))
    {
        memset(c,0,sizeof(c));
        for (i=0;i<n;++i){
            scanf("%s%d%d",a[i].name,&a[i].age,&a[i].worth);
        }
        sort(a,a+n,cmp2);
        for (len=i=0;i<n;++i){
            if (c[a[i].age]<=100)
            {
                b[len++]=i;
                c[a[i].age]++;
            }
        }

        while(q--){
            scanf("%d%d%d",&M,&ma,&mb);
            if(ma>mb){
                ma^=mb;
                mb^=ma;
                ma^=mb;
            }
            printf("Case #%d:\n",txt++);
            int cnt=0;
            for (i=0;i<len&&cnt<M;++i){
                if(a[b[i]].age>=ma&&a[b[i]].age<=mb){
                    printf("%s %d %d\n",a[b[i]].name,a[b[i]].age,a[b[i]].worth);
                    cnt++;
                }
            }
            if(cnt==0){
                printf("None\n");
            }
        }
    }
    return 0;
}
// 自己的风格
#define N  1007
#include <bits/stdc++.h>
using namespace std;

struct Node{
    string no;
    int age;
    int val;
    bool operator < (const Node& n2) const {
        if (val < n2.val) return true;
        else if (val > n2.val) return false;
        else {
            if (age > n2.age) return true;
            else if (age < n2.age) return false;
            else {
                return no > n2.no;
            }
        }
    }
};

int n, k;
vector<Node> G[N];

int main() {
    freopen("in.txt", "r", stdin);
    cin >> n >> k;
    int age;
    for (int i=0; i<n; i++) {
        Node t;
        cin >> t.no >> t.age >> t.val;
        G[t.age].push_back(t);
    }
    int M, miner, maxer;
    for (int i=0; i<k; i++) {
        
        cin >> M >> miner >> maxer;
        if (miner > maxer) swap(miner, maxer);
        priority_queue<Node> pq;
        for (int j=miner; j<=maxer; j++) {
            for (int x=0; x<G[j].size(); x++) {
                pq.push(G[j][x]);
            }
        }
        printf("Case #%d:\n", i+1);
        if (pq.size()==0) {
            cout << "None" << endl;
            continue;
        }
        while (M--) {
            if (pq.size()==0) break;
            Node fro = pq.top();
            pq.pop();
            printf("%s %d %d\n", fro.no.c_str(), fro.age, fro.val);
        }
    }

}
