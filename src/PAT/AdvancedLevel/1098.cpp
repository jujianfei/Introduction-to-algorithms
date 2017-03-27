// 这个题目有点意思啊，实际上是不用使用直接的排序算进行模拟的，只需使用一点技巧就行，
// stl需要使用好
#include <bits/stdc++.h>
using namespace std;
#define N 107
int n;

int a[N], b[N];
int flag, pos;

void hp() {
    sort(a, a+n);
    if (b[n-1] != a[n-1]) {
        flag = 0; // 不是hp排序
        return;
    } else {
        int p = n-1;
        while (a[p] == b[p]) p--;
        if (a[p] == b[0]) {
            flag = 1;
            pos = p; // 是hp排序
        } else {
            flag = 0;
        }
        return;
    }
}

void get_pos_insert() {
    for (int i=1; i<n; i++) {
        if (b[i-1] > b[i]) {
            pos = i;
            return;
        }
    }
}


int main() {
    //freopen("in.txt", "r", stdin);
    cin >> n;
    for (int i=0; i<n; i++) cin >> a[i];
    for (int i=0; i<n; i++) cin >> b[i];
    hp();
    if (flag) {

    } else {
        get_pos_insert();
    }

    if (flag == 0) {
        cout << "Insertion Sort" << endl;
        sort(b, b+pos+1);
    } else {
        cout << "Heap Sort" << endl;
        swap(b[0], b[pos]);
        make_heap(b, b+pos);
    }

    for (int i=0; i<n-1; i++) {
            cout << b[i] << " ";
    } cout << b[n-1] << endl;

}
