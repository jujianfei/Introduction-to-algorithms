// 各位上都不能出现0啊，除了一种特殊情况、
// tret 拼写错误WA了几发，不应该
#include <bits/stdc++.h>
using namespace std;

string a[13] = {
    "tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"
};

set<string> sta, stb;
string b[13] = {
    "tret", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"
};
map<string, int> mp;
template<typename T>
T StringTo(const std::string &s){
    std::stringstream sout;
    sout << s;
    T tmp;
    sout >> tmp;
    return tmp;
}

template<typename T>
std::vector<T> StringToVec(const std::string &s){
    std::stringstream sout;
    sout << s;
    std::vector<T> res;
    T tmp;
    while(sout >> tmp){
        res.push_back(tmp);
    }
    return res;
}


int main() {
    //freopen("in.txt", "r", stdin);
    int n;
    cin >> n;
    string s;

    for (int i=0; i<13; i++) {
        mp[a[i]] = i;
        sta.insert(a[i]);
        mp[b[i]] = i;
        stb.insert(b[i]);
    }


    getline(cin, s);
    while (n--) {
        getline(cin, s);

        if (s[0] <= '9' && s[0] >= '0') {
            int tar = StringTo<int>(s);


            int shi = tar / 13;
            int ge = tar % 13;
            if (shi && ge) {
                cout << b[shi] << " " << a[ge] << endl;
            } else if (shi && !ge) {
                cout << b[shi] << endl;
            } else if (!shi && ge) {
                cout << a[ge] << endl;
            } else {
                cout << "tret" << endl;
            }


        } else {
            int ans = 0;
            vector<string> v = StringToVec<string>(s);

            if (v.size()==1) {

                if (sta.find(v[0]) == sta.end()) {
                    cout << 13 * mp[v[0]] << endl;
                } else {
                    cout << mp[v[0]] << endl;
                }


            } else {
                for (int i=0; i<v.size(); i++) {
                    ans = ans * 13 + mp[v[i]];
                }
                cout << ans << endl;
            }



        }
    }

}
