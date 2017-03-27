//WA了好久始终找不到原因，起初是怀疑不能用double，换了int
// 然后想求平均值的时候，四舍五入，还是去尾（实际上这个问题并不重要）
// 最后看别人的代码才知道求名次的时候错了
// 比如说 5 5 4 4 3 3 3 3
// 最后一个人的名次应该是5，但是我却算成了3，实际上是题意理解错了吧
#include <iostream>  
#include <cstdio>  
#include <string>  
#include <map>  
#include <algorithm>  
using namespace std;  
struct N {  
    string no;  
    int c;  
    int m;  
    int e;  
    int a;  
}buf[2000];  
  
bool cmp1(N p, N q){  
    return p.a > q.a;  
}  
bool cmp2(N p, N q){  
    return p.c > q.c;  
}  
bool cmp3(N p, N q){  
    return p.m > q.m;  
}  
bool cmp4(N p, N q){  
    return p.e > q.e;  
}  
int main(){  
    int N, M;  
    string str;  
    scanf("%d%d", &N, &M);  
    for (int i = 0; i < N; i++){  
        cin >> buf[i].no >> buf[i].c >> buf[i].m >> buf[i].e;  
        buf[i].a = (int)((buf[i].c + buf[i].m + buf[i].e) / 3.0 + 0.5);  
    }  
    while (M--){  
        cin >> str;  
        int flag = 1;  
        for (int i = 0; i < N; i++){  
            if (buf[i].no == str){  
                flag = 0;  
            }  
        }  
        if (flag){  
            cout << "N/A" << endl;  
            continue;  
        }  
        int rank1, rank2, rank3, rank4;  
        sort(buf, buf+N, cmp1);  
        for (int i = 0; i < N; i++){  
            if (buf[i].no == str){  
                rank1 = i;  
                int j = i - 1;  
                while (j >= 0){  
                    if (buf[i].a == buf[j].a)  
                        rank1 = j;  
                    j--;  
                }  
                break;  
            }  
        }  
        sort(buf, buf + N, cmp2);  
        for (int i = 0; i < N; i++){  
            if (buf[i].no == str){  
                rank2 = i;  
                int j = i - 1;  
                while (j >= 0){  
                    if (buf[i].c == buf[j].c)  
                        rank2 = j;  
                    j--;  
                }  
                break;  
            }  
        }  
        sort(buf, buf + N, cmp3);  
        for (int i = 0; i < N; i++){  
            if (buf[i].no == str){  
                rank3 = i;  
                int j = i - 1;  
                while (j >= 0){  
                    if (buf[i].m == buf[j].m)  
                        rank3 = j;  
                    j--;  
                }  
                break;  
            }  
        }  
        sort(buf, buf + N, cmp4);  
        for (int i = 0; i < N; i++){  
            if (buf[i].no == str){  
                rank4 = i;  
                int j = i - 1;  
                while (j >= 0){  
                    if (buf[i].e == buf[j].e)  
                        rank4 = j;  
                    j--;  
                }  
                break;  
            }  
        }  
        if ((rank1 <= rank2) && (rank1 <= rank3) && (rank1 <= rank4)){  
            cout << rank1+1 << " " << "A" << endl;  
        }  
        else if ((rank2 < rank1) && (rank2 <= rank3) && (rank2 <= rank4)){  
            cout << rank2+1 << " " << "C" << endl;  
        }  
        else if ((rank3 < rank1) && (rank3 < rank2) && (rank3 <= rank4)){  
            cout << rank3+1 << " " << "M" << endl;  
        }  
        else{  
            cout << rank4+1 << " " << "E" << endl;  
        }  
    }  
    return 0;  
}  


/*
#include <bits/stdc++.h>
using namespace std;
#define N 2007
#define INF 0x3f3f3f3f

map<string, int> mpa;
map<string, int> mpc;
map<string, int> mpe;
map<string, int> mpm;

int n, m;

struct Node {
    double c, m, e, a;
    string name;
};

bool cmpa(Node n1, Node n2) { return n1.a > n2.a; }
bool cmpc(Node n1, Node n2) { return n1.c > n2.c; }
bool cmpe(Node n1, Node n2) { return n1.e > n2.e; }
bool cmpm(Node n1, Node n2) { return n1.m > n2.m; }



vector<Node> v;

pair<int, char> f(string name) {
    char c;
    int ranker = INF;
    if (mpe[name] <= ranker) {
        c = 'E';
        ranker = mpe[name];
    }
    if (mpm[name] <= ranker) {
        c = 'M';
        ranker = mpm[name];
    }
    if (mpc[name] <= ranker) {
        c = 'C';
        ranker = mpc[name];
    }
    if (mpa[name] <= ranker) {
        c = 'A';
        ranker = mpa[name];
    }
    return pair<int, char> (ranker, c);
}

int main() {
    //freopen("in.txt", "r", stdin);
    cin >> n >> m;
    Node tmp;
    for (int i=0; i<n; i++) {
        cin >> tmp.name >> tmp.c >> tmp.m >> tmp.e;
        tmp.a = (tmp.c + tmp.e + tmp.m) / 3.0;
        v.push_back(tmp);
    }

    sort(v.begin(), v.end(), cmpa);
    for (int i=0; i<n; i++) {
        if (i==0) mpa[v[i].name] = 1;
        else if (v[i].a < v[i-1].a) mpa[v[i].name] = mpa[v[i-1].name] + 1;
        else mpa[v[i].name] = mpa[v[i-1].name];
    }
    sort(v.begin(), v.end(), cmpe);
    for (int i=0; i<n; i++) {
        if (i==0) mpe[v[i].name] = 1;
        else if (v[i].e < v[i-1].e) mpe[v[i].name] = mpe[v[i-1].name] + 1;
        else mpe[v[i].name] = mpe[v[i-1].name];
    }
    sort(v.begin(), v.end(), cmpc);
    for (int i=0; i<n; i++) {
        if (i==0) mpc[v[i].name] = 1;
        else if (v[i].c < v[i-1].c) mpc[v[i].name] = mpc[v[i-1].name] + 1;
        else mpc[v[i].name] = mpc[v[i-1].name];
    }
    sort(v.begin(), v.end(), cmpm);
    for (int i=0; i<n; i++) {
        if (i==0) mpm[v[i].name] = 1;
        else if (v[i].m < v[i-1].m) mpm[v[i].name] = mpm[v[i-1].name] + 1;
        else mpm[v[i].name] = mpm[v[i-1].name];
    }

    for (int i=0; i<m; i++) {
        string name;
        cin >> name;
        if (mpa.find(name) == mpa.end()) {
            cout << "N/A" << endl;
        } else {
            pair<int, char> res = f(name);
            cout << res.first << " " << res.second << endl;
        }
    }

}

*/