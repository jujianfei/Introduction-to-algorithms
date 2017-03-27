// 6564147_AC_0ms_0kB.cpp
#include <iostream>
#include <cstdio>
#include <sstream>
#include <vector>
#include <string.h>
#include <map>
#include <deque>
#define INF 0x3f3f3f3f
using namespace std;
#define N 57
int n;
int a[N];
template<typename T>
void StringToVec(const std::string &s){
    n = 1;
    std::stringstream sout;
    sout << s;
    T tmp;
    while(sout >> tmp) {
        a[n++] = tmp;
    }
    n--;
}

void flip(int end) {
    for (int i=1;i<=end/2;i++) {
        swap(a[i],a[end+1-i]);
    }
}

int find_big_index(int end) {
    int maxer = -1;
    int ret;
    for (int i=1;i<=end;i++) {
        if (a[i] > maxer) {
            ret = i;
            maxer = a[i];
        }
    }
    return ret;
}

int main() {
    //freopen("in.txt", "r", stdin);
    string line;
    while (getline(cin, line)) {

        //cout << "--cases--" << endl;
        StringToVec<int> (line);
        int now = n;
        for (int i=1;i<=n;i++) {
            cout << a[i] << " ";
        }cout << endl;
        while (now > 1) {

            int big = find_big_index(now);
            if (big == now) {
                    now -- ;
                    continue;
            }
            else if (big == 1) {
                flip(now);
                cout << n+1-now << " ";
            } else {
                flip(big);
                cout << n+1-big << " ";
                flip(now);
                cout << n+1-now << " ";
            }
            now --;
        }
//        for (int i=1;i<=n;i++) {
//            cout << a[i] << " ";
//        }cout << endl;
        cout << 0 << endl;
    }


}
