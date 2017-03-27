// 15918311_AC_157MS_3084K.cc
#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#define N 50007
using namespace std;

//基础计算几何模板
//计算几何模板
const double EPS = 1e-10;
struct Point {
    double x,y;
    Point(double x, double y) :x(x), y(y) {}
    Point() {}
};
typedef Point Vec;
//向量 + 向量 = 向量
Vec operator + (Vec a, Vec b) { return Vec(a.x + b.x, a.y + b.y); }
//点 - 点 = 向量
Vec operator - (Point a, Point b) { return Vec(b.x - a.x, b.y - a.y); }
//向量 * 数 = 向量
Vec operator * (Vec a, double x) { return Vec(a.x * x, a.y * x); }
Vec operator / (Vec a, double x) { return Vec(a.x / x, a.y / x); }

bool operator < (const Point&a, const Point &b) { return a.x < b.x || (a.x == b.x && a.y < b.y); }

int dcmp(double x) {
    if (fabs(x) < EPS) return 0;
    else return x < 0 ? -1: 1;
}
bool operator == (const Point &a, const Point& b) { return dcmp(a.x-b.x)==0 && dcmp(a.y-b.y)==0; }

double Dot(Vec a, Vec b) { return a.x*b.x + a.y*b.y; }
double Lenth(Vec a) { return sqrt(Dot(a,a)); }
double Angel(Vec a, Vec b) { return acos(Dot(a,b) / Lenth(b) / Lenth(a)); } //范围在 负pi/2到pi/2之间
double Cross(Vec a, Vec b) { return a.x*b.y - a.y * b.x; }
double Area(Point a, Point b, Point c) { return Cross(b-a, c-a); }


//凸包算法模板
Point a[N];
int n;
bool cmp(const Point& n1, const Point& n2) {
    if (n1.x != n2.x) return n1.x < n2.x;
    else return n1.y < n2.y;
}

void init() {
    memset(a, 0, sizeof(a));
}

void solve() {
    sort(a, a+n, cmp);
    int k = 0;
    vector<Point> qs(n*2);
    //构造凸包的下
    for (int i=0; i<n; i++) {
        while (k > 1 && Cross((qs[k-1] - qs[k-2]),(a[i] - qs[k-1])) <= 0) k--;
        qs[k++] = a[i];
    }
    //构造凸包的上
    int t;
    for (int i=n-2, t =k; i>=0; i--) {
        while (k>t && Cross((qs[k-1] - qs[k-2]),(a[i] - qs[k-1])) <= 0) k--;
        qs[k++] = a[i];
    }

    qs.resize(k-1);
//check ...
//    for (int i=0; i< qs.size(); i++) {
//        cout << qs[i].x << " " << qs[i].y << endl;
//    }
    double res = 0;
    for (int i=0; i<qs.size(); i++) {
        for (int j=i+1; j<qs.size(); j++) {
            double tmp = Dot(qs[i]-qs[j], qs[i]-qs[j]);
            res = max(res,tmp);
        }
    }
    printf("%.0f\n", res);
}

int main() {
    //freopen("in.txt", "r", stdin);
    while (cin >> n) {
        init();
        if (n==0)break;
        for (int i=0; i<n; i++) {
            scanf("%lf%lf", &a[i].x, &a[i].y);
        }
        solve();

    }
}
