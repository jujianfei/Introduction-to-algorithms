#include <bits/stdc++.h>
using namespace std;

int a[4][5] = {

   0, 0, 0, 0,
   0, 1, 2, 3,
   0, 4, 5, 6,
   0, 7, 8, 9,
   0, -1, 0, -1

};

map<int,pair<int,int>> mp;
int n;
using P = pair<int,int>;

vector<int> dx;
vector<int> dy;
string s;

bool inside(int x, int y) {
    if (1<=x && x<=3 && 1<=y && y <=3) return true;
    if (x==4 && y==2) return true;
    else  return false;
}


bool ok_begin(int i) {

    int x = mp[i].first, y = mp[i].second;
    for (int i=0; i<dx.size(); i++) {
        x = dx[i] + x, y = dy[i] + y;
        if (inside(x, y)==false) {
            return false;
        }
    }
    return true;

}


int main() {

    //freopen("in.txt", "r", stdin);
    cin >> n;
    mp[1] = P(1,1);
    mp[2] = P(1,2);
    mp[3] = P(1,3);
    mp[4] = P(2,1);
    mp[5] = P(2,2);
    mp[6] = P(2,3);
    mp[7] = P(3,1);
    mp[8] = P(3,2);
    mp[9] = P(3,3);
    mp[0] = P(4,2);
    cin >> s;
    for (int i=1; i<s.size(); i++) {
        dx.push_back(mp[s[i]-'0'].first - mp[s[i-1]-'0'].first);
        dy.push_back(mp[s[i]-'0'].second - mp[s[i-1]-'0'].second);
    }

    int root = s[0] - '0';
    int ok = false;

    for (int i=0; i<=9; i++) {
        if (i==root) continue;
        if (ok_begin(i)) {
            ok = true;
            break;
        }
    }

    if (ok) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
    }






}