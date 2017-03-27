// 不能再水
#include <bits/stdc++.h>
using namespace std;

string s;

string ToString(int x) {
    stringstream sout;
    sout << x;
    return sout.str();
}

string a[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven",
"eight", "nine"
};


int main() {
    cin >> s;
    int sum = 0;
    for (int i=0; i<s.size(); i++) sum += (s[i]-'0');
    string ans = ToString(sum);
    for (int i=0; i<ans.size()-1; i++) {
        cout << a[ans[i]-'0'] << " ";
    } cout << a[ans[ans.size()-1]-'0'] << endl;


}
