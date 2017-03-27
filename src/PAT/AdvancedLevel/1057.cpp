//很好的题目啊
//呵呵，但是cin cout就是不过，换了scanf，printf过了
#include <bits/stdc++.h>
using namespace std;
#define N 100005

int n;
vector<int> v;
multiset<int> fir, sec;

void banlance() {
    int n = fir.size(), m = sec.size();
    if (n-m == 2) {
        multiset<int>::iterator p = fir.end();
        --p;
        int val = *p;
        fir.erase(p);
        sec.insert(val);
    } else if (m - n == 1) {
        multiset<int>::iterator p = sec.begin();
        int val = *p;
        sec.erase(p);
        fir.insert(val);
    }
}

void Update(int tmp) {
    if (fir.empty()) fir.insert(tmp);
    else {
        multiset<int>::iterator p = fir.end();
        int mid = *(--p);
        if (tmp > mid) {
            sec.insert(tmp);
        } else {
            fir.insert(tmp);
        }
    }
    banlance();
}


int query() {
    multiset<int>::iterator p = fir.end();
    --p;
    int val = *p;
    return val;
}

void Remove(int tmp) {

    if (fir.find(tmp) != fir.end()) {
        multiset<int>::iterator p = fir.find(tmp);
        //cout << "find @ fir " << endl;
        fir.erase(p);
    } else {
        multiset<int>::iterator p = sec.find(tmp);
        //cout << "find @ sec" << endl;
        sec.erase(p);

    }
    banlance();
}


int main() {
    //freopen("in.txt", "r", stdin);
    scanf("%d", &n);
    char op[10];
    while (n--) {
        scanf("%s", op);
        if (strcmp(op, "Pop")==0) {
            if (v.empty()) {
                printf("Invalid\n");
            } else {

                printf("%d\n", v[(v.size()-1)]);
                Remove(v[v.size()-1]);
                v.pop_back();

            }

        } else if (strcmp(op, "PeekMedian")==0) {
            if (v.empty()) printf("Invalid\n");
            else {
                printf("%d\n", query());
            }

        } else {

            int tmp;
            scanf("%d", &tmp);
            v.push_back(tmp);
            Update(tmp);

        }
    }

}
