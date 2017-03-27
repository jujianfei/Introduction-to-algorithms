// 6503270_AC_31ms_1640kB.cpp
#include <bits/stdc++.h>
using namespace std;
#define N 200
int n;
struct Obj{
    int x,y,z;
    Obj(int x, int y, int z):x(x),y(y),z(z){}
    Obj() {}
};

struct Node {
    int x,y;
    Node(int x,int y):x(x),y(y){}
    Node(){}
    bool operator <(const Node& n2) const{
        if (x < n2.x)return true;
        else if (x > n2.x) return false;
        else return y < n2.y;
    }
};

vector<Obj> v;
map<Node,int> mp;

int dfs(int x, int y){

    if (mp.find(Node(x,y))!=mp.end()) return mp[Node(x,y)];
    if (mp.find(Node(y,x))!=mp.end()) return mp[Node(y,x)];

    int flag = 0;
    int maxer = -1;

    for (int i=0;i<v.size();i++) {
        int vx=v[i].x;
        int vy=v[i].y;
        int add_h = v[i].z;
        if ((vx < x && vy < y) || ( vx < y && vy < x )) {
           flag = 1;
           maxer = max(maxer, dfs(vx, vy) + add_h);
        }
    }

    if (flag == 0)
        return mp[Node(x,y)]=mp[Node(y,x)]=0;
    else {
        return mp[Node(x,y)]=mp[Node(y,x)]=maxer;
    }
}


int main() {
    int cases=0;
    //freopen("in.txt","r" ,stdin);
    while (cin >> n && n) {
        cases ++;
        v.clear();
        mp.clear();
        int x,y,z;
        int maxer = -1;
        for (int i=0; i<n; i++) {
            cin >> x >> y >> z;

            maxer = max(maxer, x);
            maxer = max(maxer, y);
            maxer = max(maxer, z);

            v.push_back(Obj(x,y,z));
            v.push_back(Obj(x,z,y));
            v.push_back(Obj(y,z,x));

        }

        printf("Case %d: maximum height = %d\n", cases, dfs(maxer+1, maxer+1));

    }
}
