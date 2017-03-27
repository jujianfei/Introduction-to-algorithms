// shui!!!
#include <bits/stdc++.h>
using namespace std;


struct Node{
    string id;
    int in, out;
    Node(string _id, string i, string o) {
        id = _id;
        in = ((i[0]-'0') * 10 + i[1]) * 3600 + ((i[3]-'0') * 10 + i[4]) * 60 + ((i[6]-'0') * 10 + i[7]);
        out = ((o[0]-'0') * 10 + o[1]) * 3600 + ((o[3]-'0') * 10 + o[4]) * 60 + ((o[6]-'0') * 10 + o[7]);
    }
    Node(){}

};

bool cmp(const Node& n1, const Node& n2) {
    return n1.in < n2.in;
}

bool cmp_sec(const Node& n1, const Node& n2) {
    return n1.out > n2.out;
}


int main() {
    //freopen("in.txt", "r", stdin);
    int n;
    vector<Node> v;
    cin >> n;
    string a, b, c;
    for (int i=0; i<n; i++) {
        cin >> a >> b >> c;
        v.push_back(Node(a, b, c));
    }
    sort(v.begin(), v.end(), cmp);
    cout << v[0].id << " ";
    sort(v.begin(), v.end(), cmp_sec);
    cout << v[0].id << endl;
}
