// 6547106_AC_500ms_780kB.cpp
#include <cstdio>
#include <iostream>
#include <cstring>
#include <queue>
#include <map>
#include <cstdlib>
#include <deque>
#include <algorithm>
#include <cmath>
#include <set>
using namespace std;
#define N   10007
#define INF 0x3f3f3f3f

int a[N];
int f[N];
int n;
int sum;
int usesum;
int getsum(int index, int K) { //index max is n-k+1
    if (index <= K) {
        sum += f[index-1];
    } else {
        sum += f[index-1];
        sum -= f[index-K];
    }
    return sum;
}


bool ok(int K) { //every K cows is ok?
    memset(f, 0, sizeof(f));
    sum = 0;
    usesum=0;
    for (int i=1; i<=n-K+1;i++) {
        int sum = getsum(i, K);
        //cout << "sum at " << i << " " << sum << endl;
        if (a[i]==1) {
            if (sum%2==1) {//牛的位置本身是正确的，但是被前面的翻过了，需要翻回来
                f[i]=1;
                usesum+=1;
            }
        } else {
            if (sum%2==0) { //牛的位置是错误的，但是没有被前面翻过，需要翻到正确的位置
                f[i]=1;
                usesum+=1;
            }
        }
    }
//    for (int i=1;i<=n;i++) {
//        cout << f[i] << " ";
//    }cout<<endl;
    //检查剩下的是不是都符合题意
    for (int i=n-K+2;i<=n;i++) {
        int sum = getsum(i, K);
        if (a[i]==1 && sum%2==0) {continue;}
        else if (a[i]==0 && sum%2==1) {continue;}
        else return false;
    }

    return true;
}


int main() {

    //freopen("in.txt", "r", stdin);
    while (cin >> n) {
        memset(a, 0, sizeof(a));
        memset(f, 0, sizeof(f));
        char c;
        for (int i=1;i<=n;i++) {
            cin>>c;
            if (c == 'F') a[i]=1;
            else a[i]=0;
            //cout << "-" << a[i] <<"-" ;
        }//cout<<endl;
        int miner = INF;
        int resk = -1;
        for (int K=n;K>=1;K--) {
            if (ok(K)) {
                //cout << K << "_is_ok" << endl;
//                int tmp=0;
//                for (int i=1;i<=n;i++) {
//                    //cout << f[i] << " ";
//                    tmp += f[i];
//                }//cout<<endl;
                //cout << " and times " << tmp << endl;
                if (usesum <= miner) {
                    miner = usesum;
                    resk = K;
                }
            }
        }
        cout  << resk <<" "<< miner << endl;


    }

}
