// 6576757_AC_188ms_2368kB.cpp
#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#include <map>
#include <cstdlib>
#include <deque>
#include <algorithm>
#include <cmath>
#include <set>
#define INF 0x3f3f3f3f
using namespace std;
#define N  100007
#define ll long long
struct Node {
    int a,b;
    Node(int a, int b):a(a), b(b) {}
    Node() {}
    bool operator <(const Node& n2) const {
        return a < n2.a;
    }
};
Node a[N];
int n;
int C,F;
int lower[N],upper[N];

int main() {
    //freopen("in.txt", "r", stdin);
    while (cin >> n >> C >> F) {
        memset(lower, 0, sizeof(lower));
        memset(upper, 0, sizeof(upper));
        for (int i=1; i<=C; i++) {
            scanf("%d%d",&a[i].a, &a[i].b);
        }
        sort(a+1, a+C+1);
        int lim =  (n-1) / 2;
    {


        priority_queue<int> pq;
        int sum = 0;
        for (int i=1; i<=C; i++) {
            if (i<=lim) {
                lower[i]=INF;
                pq.push(a[i].b);
                sum += a[i].b;
            } else {
                lower[i]=sum;
                if (a[i].b < pq.top()) {
                    sum -= pq.top();
                    pq.pop();
                    pq.push(a[i].b);
                    sum += a[i].b;
                }

            }
        }
    }
    {

        //from tail
        priority_queue<int> pq2;
        int sum = 0;
        for (int i=C; i>=1; i--) {
            if (i>C-lim) {
                upper[i]=INF;
                pq2.push(a[i].b);
                sum += a[i].b;
            } else {
                upper[i]=sum;
                if (a[i].b < pq2.top()) {
                    sum -= pq2.top();
                    pq2.pop();
                    pq2.push(a[i].b);
                    sum += a[i].b;
                }

            }
        }
    }



/////////////////////////////////////////////

//    for (int i=1;i<=C;i++) {
//        cout <<lower[i] << " " << upper[i] << endl;
//    }

//////////////////////////////////////////////////
        bool flag = false;
        int ans;
        for (int i=C; i>=1; i--) {
            //cout << "now " << a[i].a << " " << a[i].b + lower[i] + upper[i] << endl;
            if (a[i].b + lower[i] + upper[i] <= F) {
                ans = a[i].a;
                flag = true;
                break;
            }
        }
        if (flag == false) {
            cout << -1 << endl;
        } else {
            cout << ans << endl;
        }


    }
}
