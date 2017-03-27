// 裸的质因数分解，发现了自己以前的模板的一个bug，并且1的时候需要特判
#include <bits/stdc++.h>
using namespace std;

map<long long,long long> prime_factor(long long n){
    map<long long,long long> res;
    for(long long i=2;i*i<=n;i++){
        while(n%i==0){
            res[i]++;
            n/=i;
        }
    }
    if (n!=1) {
        res[n] ++;
    }
    return res;
}
int main(){
    //freopen("in.txt", "r", stdin);
    long long n;
    cin >> n;
    if (n==1) {
        cout << "1=1" << endl;
        return 0;
    }
    map<long long,long long> res = prime_factor(n);

    cout << n << "=";
    map<long long,long long>::iterator mark = res.end();
    mark --;
    for (map<long long,long long>::iterator p=res.begin(); p!=res.end(); p++) {
        long long fir = p->first;
        long long sec = p->second;

        if (sec == 1) {
            cout << fir;
        } else {
            cout << fir << "^" << sec;
        }
        if (p!=mark) cout << "*";
        else cout << endl;

    }

}
