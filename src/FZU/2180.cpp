// 6939091_AC_1625ms_1872kB.cpp
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <cstring>
#include <deque>
#define INF 0x3f3f3f3f
using namespace std;

const int dx[] = {-1, -1, 1, 1, 2, 2, -2, -2 };
const int dy[] = {-2, 2, 2, -2, 1, -1, 1, -1 };

string G[5] = {
    "11111",
    "01111",
    "00*11",
    "00001",
    "00000"
};
string dp[5];

map<pair<int,int>, int> mp1;
map<pair<int,int>, int> mp2;
deque<pair<int,int> > d1, d2;

bool inside(int i, int j) {
    return i<5 && i>=0 && j<5 && j>=0;
}
int BFS() {

    while (1) {
        int firstok = true;
        int secondok = true;
        if (d1.empty()==false) {
            //第一个进行bfs
            pair<int,int> top1 = d1.front();
            d1.pop_front();
            if (mp2.find(top1)!=mp2.end()) {
                return mp1[top1] + mp2[top1];
            }
            //更新第一个队列
            for (int k=0; k<8; k++) {
                int x = top1.second/5;
                int y = top1.second%5;
                int nx = top1.second/5 + dx[k];
                int ny = top1.second%5 + dy[k];
                if (inside(nx, ny)) {
                    int ans = top1.first;
                    if (top1.first & (1<<(nx * 5 + ny))) {
                        //相应的位置交换01
                        ans = ans | (1<<(x * 5 + y));
                        ans = ans & ~ (1<<(nx * 5 + ny));
                    } else {

                    }
                    int pos = nx * 5 + ny;
                    if (mp1.find(pair<int,int>(ans, pos))!=mp1.end()) continue;
                    int tmp = mp1[top1] + 1;
                    if (tmp > 8) continue;
                    mp1[pair<int,int>(ans, pos)] = mp1[top1] + 1;
                    d1.push_back(pair<int,int>(ans, pos));
                }
            }
        } else {
            firstok = false;
        }


        {
            if (d2.empty()==false) {
            //第一个进行bfs
                pair<int,int> top2 = d2.front();
                d2.pop_front();
                if (mp1.find(top2)!=mp1.end()) {
                    return mp2[top2] + mp1[top2];
                }
                //更新第一个队列
                for (int k=0; k<8; k++) {
                    int x = top2.second/5;
                    int y = top2.second%5;
                    int nx = top2.second/5 + dx[k];
                    int ny = top2.second%5 + dy[k];
                    if (inside(nx, ny)) {
                        int ans = top2.first;
                        if (top2.first & (1<<(nx * 5 + ny))) {
                            //相应的位置交换01
                            ans = ans | (1<<(x * 5 + y));
                            ans = ans & ~ (1<<(nx * 5 + ny));
                        } else {

                        }
                        int pos = nx * 5 + ny;
                        if (mp2.find(pair<int,int>(ans, pos))!=mp2.end()) continue;
                        int tmp = mp2[top2] + 1;
                        if (tmp > 8) continue;
                        mp2[pair<int,int>(ans, pos)] = mp2[top2] + 1;
                        d2.push_back(pair<int,int>(ans, pos));
                    }
                }
            } else {
                secondok = false;
            }
        }

        if (firstok == false && secondok == false) break;


    }
    return -1;

}




int main() {
    //freopen("in.txt", "r", stdin);
     int T;
     cin >> T;
     while (T--) {
        int bx, by;
        for (int i=0; i<5; i++) {
            cin >> dp[i];
            for (int j=0; j<5; j++) {
                if (dp[i][j] == '*') {
                    bx = i, by = j;
                }
            }
        }
        mp1.clear(), mp2.clear();
        d1.clear(), d2.clear();
        int ans = 0;
        for (int i=0; i<5; i++) {
            for (int j=0; j<5; j++) {
                if (G[i][j] == '1') {
                    ans = ans | (1<<(i*5+j));
                }
            }
        }
        int pos = 2*5+2;
        mp1[pair<int, int>(ans, pos)] = 0;
        d1.push_back(pair<int,int>(ans, pos));

        ans = 0;
        for (int i=0; i<5; i++) {
            for (int j=0; j<5; j++) {
                if (dp[i][j] == '1') {
                    ans = ans | (1<<(i*5+j));
                }
            }
        }
        pos = bx * 5 + by;

        mp2[pair<int,int>(ans, pos)] = 0;
        d2.push_back(pair<int,int>(ans, pos));
        int ret = BFS();
        if (ret == -1 || ret > 15) {
            cout << "Bored!" << endl;
        } else {
            cout << ret << endl;
        }


     }
}
