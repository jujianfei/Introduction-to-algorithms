// 15692454_AC_11422MS_9816K.cpp
#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
#define N 1000007
#include <deque>

int n, k;
int a[N];
struct Node {
    int pos,val;
    Node(){}
    Node(int p,int v):pos(p), val(v) {}
};

int main() {
    //freopen("in.txt", "r", stdin);

    while (~scanf("%d%d",&n, &k)) {

        for (int i=0; i<n; i++) {
            scanf("%d", &a[i]);
        }

        deque<Node> d;
        //max
        for (int i=0; i<k; i++) {
            //加入队尾
            while (d.empty() == false) {
                if (d.back().val >= a[i]) {
                    d.pop_back();
                } else {
                    break;
                }
            }
            d.push_back(Node(i, a[i]));
        }
        printf("%d ",d.begin()->val);

        for (int i=k; i<n; i++) {
            //加入队尾
            while (d.empty() == false) {
                if (d.back().val >= a[i]) {
                    d.pop_back();
                } else {
                    break;
                }
            }
            d.push_back(Node(i, a[i]));

            //处理队首
            while (d.empty() == false) {
                if (i - d.begin()->pos >= k) {
                    d.pop_front();
                } else {
                    break;
                }
            }
            printf("%d ",d.begin()->val);
        }

        d.clear();
        printf("\n");

        //min


        for (int i=0; i<k; i++) {
            //加入队尾
            while (d.empty() == false) {
                if (d.back().val <= a[i]) {
                    d.pop_back();
                } else {
                    break;
                }
            }
            d.push_back(Node(i, a[i]));
        }
        printf("%d ",d.begin()->val);

        for (int i=k; i<n; i++ ) {

            //加入队尾
            while (d.empty() == false) {
                if (d.back().val <= a[i]) {
                    d.pop_back();
                } else {
                    break;
                }
            }
            d.push_back(Node(i, a[i]));

            //处理队首
            while (d.empty() == false) {
                if (i - d.begin()->pos >= k) {

                    d.pop_front();
                } else {
                    break;
                }
            }
            printf("%d ",d.begin()->val);
        }
        d.clear();
    }




}
