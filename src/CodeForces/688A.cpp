#include <bits/stdc++.h>
using namespace std;

#define N 107

int n, d;

string G[N];

bool beat[N];

int counter(const string& s, char c) {
    int ret = 0;
    for (int i=0; i<s.size(); i++) {

        if (s[i] == c) ret ++;
    }
    return ret;
}


int main() {
    //freopen("in.txt", "r", stdin);
    cin >> n >> d;
    for (int i=0; i<d; i++) {
        cin >> G[i];
        if (counter(G[i],'1') == G[i].size()) beat[i] = false;
        else beat[i] = true;
    }

    int flag = 0;
    int counter = 0;
    int ans = 0;
    for (int i=0; i<d; i++) {

        if (beat[i]) {
            if (flag == 0) {
                counter = 1;
                ans = max(ans, counter);
                flag = 1;
            } else {
                counter ++;
                ans = max(ans, counter);
            }
        } else {

            if (flag==0) {
                // turn 0 to 0
            } else {
                // turn 1 to 0
                flag = 0;
            }
        }


    }

    cout << ans << endl;
}