//简单的进位运算，水~
#include <bits/stdc++.h>
using namespace std;

template<typename T>
T StringTo(const std::string &s){
    std::stringstream sout;
    sout << s;
    T tmp;
    sout >> tmp;
    return tmp;
}


vector<int> get(string s) {
    int last = 0;
    vector<int> ret;
    for (int i=0; i<s.size(); i++) {
        if (s[i] == '.') {
            string tmp = string(s.begin()+last, s.begin()+i);

            ret.push_back(StringTo<int>(tmp));
            last = i + 1;
        }
    }
    string tmp = string(s.begin()+last, s.end());
    ret.push_back(StringTo<int>(tmp));


    return ret;

}



int main(){
    //freopen("in.txt", "r", stdin);
    vector<int> a, b;

    string fir, sec;
    cin >> fir >> sec;

    a = get(fir), b = get(sec);


    int fir_up = (a[2] + b[2]) / 29;
    int z = (a[2] + b[2]) % 29;

    int sec_up = (a[1] + b[1] + fir_up) / 17;
    int y = (a[1] + b[1] + fir_up) % 17;

    int x = (a[0] + b[0] + sec_up);

    cout << x << "." << y << "." << z << endl;

}

