#include <bits/stdc++.h>
using namespace std;

string a, b;
long long tag, base;


long long ToInt(char c) {
    if (c <= '9' && c >= '0') return c - '0';
    else return c - 'a' + 10;
}

long long ToDec(string a, long long base) {
    long long ans = 0;
    for (long long i=0; i<a.size(); i++) {
        ans = ans * base + ToInt(a[i]);
    }
    return ans;
}


long long get_min_base(string s) {
    long long maxer = -1;
    for (long long i=0; i<s.size(); i++) {
        maxer = max(maxer, ToInt(s[i]));
    }
    return maxer + 1;
}

long long bf_find(long long b, string s, long long tar) {

    if (s.size()==1) {
        if (ToInt(s[0]) == tar) return b;
        else return 0;
    }

    for (long long i=b; ;i++) {
         if (ToDec(s, i) < tar) {}
         else if (ToDec(s, i) == tar) return i;
         else return 0;
    }
    return 0;
}

int first_no_zero(string s) {
    for (int i=0; i<s.size(); i++) {
        if (s[i] != '0') return i;
    }
}

bool all_zero(string s) {
    for (int i=0; i<s.size(); i++) {
        if (s[i] != '0') return false;
    }
    return true;
}

int main() {
    //freopen("in.txt", "r", stdin);
    cin >> a >> b >> tag >> base;

    // 应该先去掉字符串开始的0
    if (all_zero(a)) a = "0";
    if (all_zero(b)) b = "0";

    a = a.substr(first_no_zero(a));
    b = b.substr(first_no_zero(b));




    if (tag == 1) {
        long long eq = ToDec(a, base);
        long long begin_base = get_min_base(b);
        long long ret = bf_find(begin_base, b, eq);
        if (!ret) {
            cout << "Impossible" << endl;
        } else {
            cout << ret << endl;
        }
    } else {

        long long eq = ToDec(b, base);

        long long begin_base = get_min_base(a);

        long long ret = bf_find(begin_base, a, eq);
        if (!ret) {
            cout << "Impossible" << endl;
        } else {
            cout << ret << endl;
        }

    }

}
