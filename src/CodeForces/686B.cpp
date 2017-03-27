#include <bits/stdc++.h>
using namespace std;
#define N 107

int n;

int a[N];

bool Update_one() {

    int b = -1, e = -1;
    int flag = 0;
    int ok = false;
    for (int i=1; i<=n-1; i+=2) {
        if (a[i] > a[i+1]) {
            swap(a[i], a[i+1]);
            ok = true;
            if (flag == 0) { // no -> yes;
                flag = 1;
                b = i, e = i+1;
            } else { // yes -> yes;
                e = i+1;
            }
        } else {
            if (flag == 0) { // no -> no
                //cout << b << " " << e << endl;
            } else { // yes -> no
                cout << b << " " << e << endl;
                flag = 0;
            }
        }
    }

    if (flag == 1) {
        cout << b << " " << e << endl;
    }
    return ok;

}

bool Update_two() {
    int b = -1, e = -1;
    int flag = 0;
    int ok = false;
    for (int i=2; i<=n-1; i+=2) {
        if (a[i] > a[i+1]) {
            swap(a[i], a[i+1]);
            ok = true;
            if (flag == 0) { // no -> yes;
                flag = 1;
                b = i, e = i+1;
            } else { // yes -> yes;
                e = i+1;
            }
        } else {
            if (flag == 0) { // no -> no
                //cout << b << " " << e << endl;
            } else { // yes -> no
                cout << b << " " << e << endl;
                flag = 0;
            }
        }
    }

    if (flag == 1) {
        cout << b << " " << e << endl;
    }
    return ok;
}


int main() {

    //freopen("in.txt", "r", stdin);

    cin >> n;
    for (int i=1; i<=n; i++) cin >> a[i];

    //cout << Update_one() << endl;
    while (1) {
        if (Update_one()==false && Update_two()==false) { break; }
    }


}