// 6495624_AC_10ms_0kB.cpp
#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#include <map>
#include <cstdlib>
using namespace std;
int A,B,C,tar;
#define N 207

struct Node {
    int a,b,c,val;//改变量
    Node(int a,int b,int c,int val):a(a),b(b),c(c),val(val){}
    Node(){a=b=c=val=-1;}
    bool operator < (Node n) const {
        if (val > n.val) return true;
        else if (val < n.val) return false;
        else {
            if(a > n.a) return true;
            else if (a < n.a) return false;
            else {
                if(b > n.b) return true;
                else if (b < n.b) return false;
                else {
                    return c > n.c;
                }
            }
        }
    }
};

struct comp{
    bool operator()(const Node&n1, const Node&n2) const {
    if (n1.a < n2.a) return true;
    else if (n1.a > n2.a) return false;
    else {
        if (n1.b < n2.b) return true;
        else if (n1.b > n2.b) return false;
        else return n1.c < n2.c;
        }
    }

};


Node perform(const Node& n,int type) {

    const int &a = n.a;
    const int &b = n.b;
    const int &c = n.c;
    const int &val = n.val;

    if (type == 1) { //A->B
        if (a+b < B) { return Node(0,a+b ,c, a + val); }
        else return Node(a+b-B, B, c, B-b+val);
    }
    if (type == 2) {//B->A
        if (a+b < A) { return Node(a+b,0,c,b+val); }
        else return Node(A, a+b-A, c, A-a+val);
    }
    if (type == 3) { //A->C
        if (a+c < C) { return Node(0,b,a+c,a+val); }
        else return Node(a+c-C,b,C,C-c+val);
    }
    if (type == 4) { // C->A
        if (a+c < A) return Node(a+c, b, 0, c+val);
        else return Node(A, b, a+c-A, A-a+val);
    }
    if (type == 5) { //B->C
        if (b+c < C) return Node(a, 0, b+c, b+val);
        else return Node(a, b+c-C, C, C-c+val);
    }
    if (type == 6) { //C->B
        if (c+b < B) return Node(a, b+c, 0, c+val);
        else return Node(a, B, c+b-B, B-b+val);
    }
}

priority_queue<Node> pq;
map<Node,int,comp> mp;

int main() {
    //freopen("in.txt", "r", stdin);
    int cases;
    cin >> cases;
    while (cases--) {
        cin >> A >> B >> C >> tar;
        while (!pq.empty()) { pq.pop(); }
        mp.clear();
        Node root(0,0,C,0);
        pq.push(root);
        mp[root]=0;
        bool flag = false;
        while (pq.empty()==false) {
            Node fro = pq.top();
            pq.pop();
            if (fro.a == tar|| fro.b == tar || fro.c == tar) {
                cout << mp[fro] << " " << tar << endl;
                flag = true;
                break;
            }
            for (int  i=1; i<=6; i++) {
                Node tmp = perform(fro, i);
                if (mp.find(tmp) == mp.end()) {
                    mp[tmp] = tmp.val;
                    pq.push(tmp);
                }
            }
        }

        if (flag == false) {
            int closer = -1;
            int res = 0;
            for (map<Node,int,comp>::iterator p=mp.begin();p!=mp.end();p++){
                if (p->first.a >= closer && p->first.a < tar) {
                    if (closer == p->first.a) {
                        res = min(res, p->second);
                    } else {
                        closer = p->first.a;
                        res = p->second;
                    }

                }
                if (p->first.b >= closer && p->first.b < tar) {
                    if (closer == p->first.b) {
                        res = min(res, p->second);
                    } else {
                        closer = p->first.b;
                        res = p->second;
                    }
                }
                if (p->first.c >= closer && p->first.c < tar) {
                    if (closer == p->first.c) {
                        res = min(res, p->second);
                    } else {
                        closer = p->first.c;
                        res = p->second;
                    }
                }
            }
            cout << res << " " << closer << endl;
        }

    }
}
