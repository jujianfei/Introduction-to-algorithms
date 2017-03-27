// 6426337_AC_100ms_0kB.cpp
#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <set>
#include <cstring>
using namespace std;
#define MAXN 100007
int N = 62;

//如何实现选择就是从

int A[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
int res[5];


int finalres[MAXN];
int finalres2[MAXN];
int rescur = 0;

int getvalue() {
    int ret = res[0];
    for (int i=1; i<5; i++) {
        ret = ret * 10 + res[i];
    }
    return ret;
}



bool good(int tmp) {
    set<int> st;
    for (int i=0;i<5;i++) {
        st.insert(res[i]);
    }
    for (int i=0; i<5; i++) {
        st.insert(tmp % 10);
        tmp = tmp / 10;
    }
    return st.size() == 10;
}


void check_out() {
    do{
        int now = getvalue();
        int tmp =  now * N;
        if (tmp > 99999) continue;
        // 检查这个元素是不是恰好构成10个数字
        if (good(tmp)) { finalres[rescur] = tmp;
                        finalres2[rescur] = now;
                        rescur ++;
                        }

    }while(next_permutation(res, res+5));

}


/*n代表原来数组中的个数，这里是10个
  depth代表当前的选择的数目
  k代表选择的最多的数目
  cur代表当前选择的节点
*/
void dfs(int cur, int depth, int n, int k){//
    if(depth==k){
        check_out();
        return;
    }
    if (cur == n) return;
    res[depth] = A[cur]; //选择当前节点
    dfs(cur+1, depth+1, n, k);
    dfs(cur+1, depth, n, k);
}

void init() {
    memset(res,0,sizeof(res));
    rescur = 0;
}

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out2.txt", "w", stdout);
    scanf("%d",&N);
    if(N==0) return 0;
    while(1){
        init();
        dfs(0,0,10,5);
        sort(finalres, finalres + rescur);
        sort(finalres2, finalres2 + rescur);
        if (rescur==0) {
            cout << "There are no solutions for "<< N <<"." <<endl;
        }
        for (int i=0; i< rescur; i++) {
            printf("%05d / %05d = %d\n", finalres[i], finalres2[i], N);
        }
        scanf("%d", &N);
        if (N)
            cout << endl;
        else
            break;
    }



}
