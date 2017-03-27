// 16075910_AC_0MS_732K.cc
#include <stdio.h>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <deque>
#include <map>
#include <sstream>
using namespace std;
#define N 107



template<typename T>
T StringTo(const std::string &s){
    std::stringstream sout;
    sout << s;
    T tmp;
    sout >> tmp;
    return tmp;
}

typedef map<int, int>::iterator P;

void  merger(map<int, int>& mp, map<int, int>& oth) {

    for (P p=oth.begin(); p!=oth.end(); p++) {

        int fir = p->first;
        int sec = p->second;

        if (mp.find(fir) == mp.end()) {
            mp[fir] = sec;
        } else {
            mp[fir] += sec;
        }

    }

}


void dfs(int t, map<int,int> &mp) {
    string tmp;
    cin >> tmp;
    while (1) {
        if (tmp == "END") break;
        else if (tmp == "LOOP") {
            string c;
            cin >> c;
            if (c == "n") {
                map<int, int> a;
                dfs(-1, a);
                merger(mp, a);
            } else {
                map<int, int> a;
                dfs(StringTo<int>(c), a);
                merger(mp, a);
            }
        } else if (tmp == "OP") {
            string number;
            cin >> number;
            mp[0] += StringTo<int>(number);
        } else
            cout << "Error" << endl;
        cin >> tmp;
    }

    //对map内部的值乘以t
    if(t == -1) {
        map<int, int> ret = mp;
        mp.clear();
        for (P p=ret.begin(); p!=ret.end(); p++) {
            int fir = p->first+1;
            int sec = p->second;
            mp[fir] = sec;
        }
    } else {
        for (P p=mp.begin(); p!=mp.end(); p++) {
            p->second = p->second * t;
        }
    }
}





int main () {
    //freopen("in.txt", "r", stdin);
    int cases;
    cin  >> cases;
    int cnt = 0;
    while (cases--) {
        cnt ++;
        string tmp;
        cin >> tmp;
        map<int, int> ret;
        if (tmp == "BEGIN") {
            dfs(1, ret);
        }
        cout << "Program #" << cnt << endl;
        cout << "Runtime = ";

       vector<int> a, b;
       for (P p=ret.begin(); p!=ret.end(); p++) {
            if (p->second == 0) continue;
            a.push_back(p->first);
            b.push_back(p->second);
       }

        if (a.size()==0) {

            cout << "0" << endl << endl;
            continue;
        }

       for (int i=a.size()-1; i>=0; i--) {

        if (a[i] != 0  && a[i] != 1) {
            if (b[i] == 1) {
                cout << "n^" << a[i];
            } else{
                cout << b[i] << "*n^" << a[i];
            }

        } else if(a[i] == 0){
            cout << b[i];
        } else {

            if (b[i] == 1) {
                cout << "n";
            } else {
                cout << b[i] << "*n";
            }

        }

        if (i!=0 ) cout << "+";

       }
       cout << endl << endl;



    }
}
