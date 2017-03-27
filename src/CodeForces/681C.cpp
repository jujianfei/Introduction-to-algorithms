#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;

typedef long long ll;

priority_queue<int, vector<int>, greater<int> > pq;
int n;

vector<string> rets;
vector<int> retv;


int main() {
    //freopen("in.txt", "r", stdin);
    cin >> n;
    string s;
    int t;
    while(n--) {
        cin >> s;
        if (s == "insert") {
            cin >> t;
            pq.push(t);
            rets.push_back(s);
            retv.push_back(t);
        } else if (s == "removeMin") {
            if (pq.empty()) {
                rets.push_back("insert");
                retv.push_back(0);
                rets.push_back(s);
                retv.push_back(INF);
            } else {
                pq.pop();
                rets.push_back(s);
                retv.push_back(INF);
            }
        } else {
            cin >> t;
            while (pq.empty()==false && pq.top()<t) {
                rets.push_back("removeMin");
                retv.push_back(INF);
                pq.pop();
            }

            if (pq.empty() || pq.top() > t) {
                rets.push_back("insert");
                retv.push_back(t);
                pq.push(t);
            }

            rets.push_back("getMin");
            retv.push_back(t);



        }
    }


    printf("%d\n", retv.size());
    for (int i=0; i<rets.size(); i++) {
        printf("%s", rets[i].c_str());
        if (rets[i] == "removeMin") {
            printf("\n");
        } else {
            printf(" %d\n", retv[i]);
        }
    }
}