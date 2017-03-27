// 好题啊
 // 刚开始的时候，TE了几发，后来使用set维护了一下就过了
 #include <bits/stdc++.h>
using namespace std;

int n;
#define N 100005

int a[N];
int pos[N];
set<int> no;

int find_first_wrong() {
    if (no.size()==0) return -1;
    else return *no.begin();
}

int main() {

    //freopen("in.txt", "r", stdin);
    scanf("%d", &n);
    for (int i=0; i<n; i++) {
            scanf("%d", &a[i]);
            pos[a[i]] = i;
            if (pos[a[i]] != a[i]) no.insert(i);
    }

    int ret = 0;


    while  (1) {

        while (pos[0] != 0) {
            int pos_0 = pos[0]; // 0的位置
            int tar_pos = pos[pos[0]]; // 应该存在的数字在哪儿？
            swap(a[pos_0], a[tar_pos]);
            pos[pos[0]] = pos_0;
            pos[0] = tar_pos;
            ret ++;
            no.erase(pos_0);
        }
        no.erase(0);

        int fir = find_first_wrong();

        if (fir == -1) break;
        int tmp = a[fir];
        swap(a[0], a[fir]);
        pos[tmp] = 0;
        pos[0] = fir;
        ret ++;
        no.insert(0);
    }
    cout << ret << endl;



}
