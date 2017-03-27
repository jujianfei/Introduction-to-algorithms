// 略微恶心的模拟题，使用类的思想实现，输出格式比较麻烦

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define N 100005
#define INF 0x3f3f3f3f

ll aabbss(ll a) {
    if (a < 0) return -a;
    else return a;
}

template<typename T>
T StringTo(const std::string &s){
    std::stringstream sout;
    sout << s;
    T tmp;
    sout >> tmp;
    return tmp;
}

template<typename T>
std::string ToString(T x){
    std::stringstream sout;
    sout << x;
    return sout.str();
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

        if (flag) sout << "(-";
        if (aa/bb) sout << aa/bb << " ";
        sout << aa%bb << "/" << bb;
        if (flag) sout << ")";

        return sout.str();

    }

};

Node add(Node n1, Node n2) {
    return Node(n1.a * n2.b + n2.a * n1.b, n1.b * n2.b);
}

Node sub(Node n1, Node n2) {
    return Node(n1.a * n2.b - n2.a * n1.b, n1.b * n2.b);
}

Node mul(Node n1, Node n2) {
    return Node(n1.a * n2.a, n1.b * n2.b);
}

Node div(Node n1, Node n2) {
    if (n2.a == 0) {
        return Node(1, INF);
    } else {
        return Node(n1.a * n2.b, n1.b * n2.a);
    }
}


int main() {
    //freopen("in.txt", "r", stdin);

    string a, b;
    cin >> a >> b;
    Node fir(a);
    Node sec(b);


    Node thi = add(fir, sec);
    cout << fir.tostring() << " + " << sec.tostring() << " = " << thi.tostring() << endl;
    thi = sub(fir, sec);
    cout << fir.tostring() << " - " << sec.tostring() << " = " << thi.tostring() << endl;
    thi = mul(fir, sec);
    cout << fir.tostring() << " * " << sec.tostring() << " = " << thi.tostring() << endl;
    thi = div(fir, sec);
    cout << fir.tostring() << " / " << sec.tostring() << " = " << thi.tostring() << endl;

}

