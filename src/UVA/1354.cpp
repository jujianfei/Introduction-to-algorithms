// 6510139_AC_0ms_0kB.cpp
#define _CRT_SECURE_NO_WARNINGS  
#include<iostream>  
#include<algorithm>  
#include<string>  
#include<sstream>  
#include<set>  
#include<vector>  
#include<stack>  
#include<map>  
#include<queue>  
#include<cassert>  
#include<cstdlib>  
#include<cstdio>  
#include<ctime>  
#include<cmath>  
#include<cstring>  
#include<functional>  
using namespace std;  
#define INF 0x3f3f3f3f  
#define max(a,b) ((a)>(b)?(a):(b))  
#define min(a,b) ((a)<(b)?(a):(b))  
using namespace std;  
const int N = 6;  
const int MAXN = (1 << N);  
int t, n, i, j, vis[MAXN];  
double w[N], sumw[MAXN], r;  
struct Node {  
    double l, r;  
    Node() {}  
    Node(double ll, double rr) { l = ll; r = rr; }  
};  
vector<Node> node[MAXN];  
  
int bitcount(int x) {  //计算二进制中1的个数  
    if (x == 0) return 0;  
    return bitcount(x / 2) + (x & 1);  
}  
  
void dfs(int s) {  
    if (vis[s]) return;//添加了记忆数组，如果状态s已经被搜索过，直接返回  
    vis[s] = 1;  
    if (bitcount(s) == 1) {  //当只有一个1时，说明是叶子，天平的两臂都是0  
        node[s].push_back(Node(0, 0));  
        return;  
    }  
    for (int l = (s - 1)&s; l > 0; l = (l - 1)&s) { //枚举左右子集情况,（此处利用二进制枚举左右子集的方法值得学习）  
        int r = s^l; //右边的子集获取的方法，异或 其实减法也可以
        dfs(l); dfs(r);  
        for (int i = 0; i < node[l].size(); i++) {  
            for (int j = 0; j < node[r].size(); j++) {  
                //这个比较过程很容易遗漏
                double ll = min(-sumw[r] / (sumw[l] + sumw[r]) + node[l][i].l, sumw[l] / (sumw[l] + sumw[r]) + node[r][j].l);//比较 -左臂+左子天平的左臂 与 右子天平的左臂+右臂  谁更小  
                double rr = max(sumw[l] / (sumw[l] + sumw[r]) + node[r][j].r, -sumw[r] / (sumw[l] + sumw[r]) + node[l][i].r);//比较 右臂+右子天平的右臂 与 左子天平的右臂-左臂  谁更大  
                node[s].push_back(Node(ll, rr));//将得到的该根节点的左右臂长度放入数组  
            }  
        }  
    }  
}  
  
void solve() {  
    double ans = -1;  
    int s = (1 << n) - 1;  
    dfs(s);  
    for (int i = 0; i < node[s].size(); i++) {  
        if (node[s][i].r - node[s][i].l < r) {//s结点是根结点，存有所有二叉树的左右臂的长度，选出差值<r的最大值即可  
            if (node[s][i].r - node[s][i].l > ans)  
                ans = node[s][i].r - node[s][i].l;  
        }  
    }  
    if (ans == -1) printf("-1\n");  
    else printf("%.10lf\n", ans);  
}  
  

int main() {  
    scanf("%d", &t);  
    while (t--) {  
        memset(vis, 0, sizeof(vis));  
        memset(node, 0, sizeof(node));  
        scanf("%lf%d", &r, &n);  
        for (i = 0; i < n; i++)  
            scanf("%lf", &w[i]);
        //直接计算出每个子集的重量大小，预处理好
        for (i = 0; i < (1 << n); i++) {  
            sumw[i] = 0;  
            for (j = 0; j < n; j++) {  
                if (i&(1 << j))  
                    sumw[i] += w[j];  
            }  
        }  

        solve();  
    }  
    return 0;  
}  