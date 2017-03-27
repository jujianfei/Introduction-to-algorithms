// 6633244_AC_0ms_0kB.cpp
#include <iostream>
#include <stdio.h>
#include <vector>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
#define N 50007

int k;
vector<string> v; //每一列允许的数字

vector<string> tmp,tmp2;
string stmp;
int counter = 0;

void init() {
    counter = 0;
    v.clear();
    v.resize(5);
    tmp.clear();
    tmp2.clear();
}

int dfs(string s, int cur) {
    if (cur == 5) {
        counter++;
        if (counter == k) {
            cout << s << endl;
            return true;
        } else {
            return false;
        }
    }

    for (int i=0; i<v[cur].size(); i++) {
        if (dfs(s + v[cur][i], cur+1)) return true;
    }
    return false;

}

bool inmap(char c,int j) {
    for (int i=0; i<v[j].size(); i++) {
        if (v[j][i] == c) return true;
    }
    return false;
}
int main() {
    //freopen("in.txt", "r", stdin);
    int cases;
    cin >> cases;
    while (cases--) {
        init();
        cin >> k;
        for (int i=0; i<6; i++) {
            cin >> stmp;
            tmp.push_back(stmp);
        }
        for (int i=0; i<6; i++) {
            cin >> stmp;
            tmp2.push_back(stmp);
        }
        for (int j=0; j<5; j++) {
            for (int i=0; i<6; i++) {
                //对于每列中的每个元素
                //看这个元素tmp[i][j]是否存在于 tmp2 的第j列中
                for (int x=0; x < 6; x++) {
                    if (tmp2[x][j] == tmp[i][j] && inmap(tmp[i][j], j)==false) {

                        v[j].push_back(tmp[i][j]); break;
                    }
                }
            }
        }
        for (int i=0; i<5; i++) sort(v[i].begin(), v[i].end());
        string begin = "";
        if (dfs(begin, 0)) {}
        else cout << "NO" << endl;


    }

}
