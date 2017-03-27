//直接参考1088即可，负数不用加括号
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 0x3f3f3f3f
template<typename T>
//int转化成string
std::string ToString(T x){
    std::stringstream sout;
    sout << x;
    return sout.str();
}

//string转化成int
template<typename T>
T StringTo(const std::string &s){
    std::stringstream sout;
    sout << s;
    T tmp;
    sout >> tmp;
    return tmp;
}
ll aabbss(ll a) {
    if (a < 0) return -a;
    else return a;
}

struct Node {

    ll a, b;
    Node(ll _a, ll _b) {
        ll g = __gcd(_a, _b);
        a = _a / g;
        b = _b / g;
    }
    Node() {}
    Node(string s) {
        ll sign = 1;
        if (s[0] == -1) {
            sign = -1;
            s = s.substr(1);
        }


        for (ll i=0; i<s.size(); i++) {
            if (s[i] == '/') {
                a = StringTo<ll>(string(s.begin(), s.begin() + i));
                b = StringTo<ll>(s.substr(i+1));
            }
        }

        a = a * sign;
        ll g = __gcd(a, b);
        a = a / g;
        b = b / g;
    }

    string tostring() {
        if (b == INF) {
            return "Inf";
        }
        if (a == 0) {
            return "0";
        }
        if (b == 1) {
            if (a < 0) return "(" + ToString<ll>(a) + ")";
            return ToString<ll>(a);
        }

        std::stringstream sout;

        ll flag=0;
        if (a*b<0) flag = 1;
        ll aa = aabbss(a), bb = aabbss(b);

        if (flag) sout << "-";
        if (aa/bb) sout << aa/bb << " ";
        sout << aa%bb << "/" << bb;


        return sout.str();

    }

};

Node add(Node n1, Node n2) {
    return Node(n1.a * n2.b + n2.a * n1.b, n1.b * n2.b);
}
int n;
int main() {
    //freopen("in.txt", "r", stdin);
    cin >> n;
    string tmp;
    tmp = "0/1";
    Node fir(tmp);

    while (n--) {
        cin >> tmp;
        Node adder(tmp);
        fir = add(fir, adder);
    }

    cout << fir.tostring() << endl;


}

