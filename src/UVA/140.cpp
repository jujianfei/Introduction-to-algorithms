// 6464602_AC_0ms_0kB.cpp
#include <cmath>
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <vector>
#include <set>
using namespace std;
void print(const vector<int> & v) {
    for (int i=0;i<v.size();i++) {
        cout << v[i] << " ";
    } cout << endl;
}

#define N 507
#include <map>
string line;
int counter=0;
vector<int> G[10];
int a[10];
int rec[10];

map<char,int> mp;
map<int,char> re;


int get(char c) {
    if (mp.find(c) == mp.end()) {
        mp[c] = counter;
        re[counter] = c;
        counter ++;
        return counter-1;

    } else {
        return mp[c];
    }
}


void init() {
    for (int i=0;i<10;i++) {
        a[i]=i;
    }
    counter = 0;
    for (int i=0; i<10; i++) {
        G[i].clear();
    }
    mp.clear(),re.clear(),counter=0;
}

int dbg=0;


int getmaxbi() {
    //calcu position
    int pos[10];
    for (int i=0;i<counter;i++) {
        pos[a[i]]=i;
    }
    int maxer = -1;
    for (int i=0; i<counter; i++) {
        for (int j=0; j<G[i].size(); j++) {
            if (maxer < abs(pos[i]-pos[G[i][j]])){
                maxer = abs(pos[i]-pos[G[i][j]]);


            }
            //cout << G[i][j] << " ";
        }//cout << endl;
    }
    return maxer;
}


bool contain(const vector<int> &v, int val) {
    for (int i=0;i<v.size();i++) {
        if(v[i]==val)return true;
    }
    return false;
}

int main() {
    //freopen("in.txt", "r", stdin);
    while (getline(cin, line)) {
        if (line == "#") break;
        init();
        int now;
        int flag = 1;

        set<int> st;
        for (int i=0;i<line.size();i++) {
            if (line[i] != ';' && line[i] != ':') {
                st.insert(line[i]);
            }
        }
        for (set<int>::iterator p=st.begin();p!=st.end();p++) {
            get(*p);
        }

        //1 stand for change ; 2 stand for add
        for (int i=0;i<line.size();i++) {
            if (line[i]==';') flag=1;
            else if (line[i]==':') flag=2;
            else if (flag == 1) {
                now = get(line[i]);

            } else {
                int ll = get(line[i]);

                if (!contain(G[now], ll))
                    G[now].push_back(ll);
                if (!contain(G[ll], now))
                    G[ll].push_back(now);
            }
        }

        int begin = INFINITY;
        do {
            if (begin > getmaxbi()) {
                begin = min(begin, getmaxbi());
                for (int i=0;i<counter;i++) {
                    rec[i]=a[i];
                }
            }
        } while (next_permutation(a, a+counter));
        for (int i=0;i<counter;i++) {
            cout << re[rec[i]] << " ";
        } cout << "-> " << begin << endl;

    }
}
