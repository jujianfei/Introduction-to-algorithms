// 数组模拟链表，还可以这样玩，真好玩，有意思，哈哈哈

#include <bits/stdc++.h>
using namespace std;

#define N 200007

int Next[N];
int val[N];
set<int> st;


int dev = N/2+10;
int tail = dev;


int li, n;
int main() {
    Next[dev] = -1;
    //freopen("in.txt", "r", stdin);
    cin >> li >> n;
    int pos, w, ne;
    for (int i=0; i<n; i++) {
        cin >> pos >> w >> ne;
        Next[pos] = ne;
        val[pos] = w;
    }

    int head = N/2;
    Next[head] = li;
    int p, q;


    q = head, p = Next[head];
    while (p!=-1) {
        int tmp = abs(val[p]);
        if (st.find(tmp) == st.end()) {
            st.insert(tmp);
            q=p;
            p=Next[p];
        } else {
            int del = Next[q];
            Next[q] = Next[p];
            p=Next[q];

            Next[tail] = del;
            tail = del;
            Next[tail] = -1;

        }
    }

    q = head, p = Next[head];
    while (p!=-1) {
        printf("%05d %d ", p, val[p]);
        if (Next[p] == -1) {
            printf("-1\n");
        } else {
            printf("%05d\n", Next[p]);
        }
        p = Next[p];

    }


    q = dev, p = Next[dev];
    while (p!=-1) {
        printf("%05d %d ", p, val[p]);
        if (Next[p] == -1) {
            printf("-1\n");
        } else {
            printf("%05d\n", Next[p]);
        }
        p = Next[p];
    }


}

