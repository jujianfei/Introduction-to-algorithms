// 6507530_AC_624ms_3464kB.cpp
#include <iostream>
#include <stdio.h>
#include <queue>
using namespace std;
struct Node {
    int d,p;
    Node(int d,int p):d(d),p(p){}
    Node(){}
    bool operator <(const Node& n) const {
        if (p>n.p) return true;
        else if (p<n.p)return false;
        else return d>n.d;
    }
};


int n;
priority_queue<Node> pq;


int main() {
    //freopen("in.txt", "r", stdin);
    int cases;
    scanf("%d", &cases);
    while (cases--) {
        while (pq.empty()==false) {pq.pop();}
        cin >> n;
        int d,p;
        for (int i=0;i<n;i++){
            cin >> p >> d;
            pq.push(Node(d,p));
        }
        int now = 0;
        int flag = 1;//leave it was
        while (pq.empty()==false) {
            Node fro = pq.top();
            now = fro.p;
            pq.pop();
            if (flag==0) {
                    flag = 1-flag;
                    continue;
            }
            else {

                Node tmp=Node(fro.d, fro.p + fro.d);
                pq.push(tmp);
                flag = 1-flag;
            }

        }
        cout << now << endl;
    }
}
