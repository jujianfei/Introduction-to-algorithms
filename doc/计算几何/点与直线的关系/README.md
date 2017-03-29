```C++
#include <stdio.h>
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#define N 1007
using namespace std;

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

Vec Rotate(Vec a, double rad) { return Vec(a.x * cos(rad) - a.y * sin(rad), a.x * sin(rad) + a.y * cos(rad)); }

//两条直线的交点，使用之前确保两条直线不重合，不平行，有而且仅仅有一个交点
Point GetLineIntersection(Point p, Vec v, Point q, Vec w) {
    Vec u = p - q;
    double t = Cross(w, u) / Cross(v, w);
    return p + v * t;
}

//点到直线的距离
double DistanceToLine(Point p, Point a, Point b) {
    Vec v1 = b - a, v2 = p - a;
    return fabs(Cross(v1, v2)/Lenth(v1));
}
double DistanceToSegment(Point p, Point a, Point b) {
    if (a==b) return Lenth(p-a);
    Vec v1 = b-a, v2 = p-a, v3 = p-b;
    if (dcmp(Dot(v1, v2)) < 0) return Lenth(v2);
    else if (dcmp(Dot(v1, v3)) > 0) return Lenth(v3);
    else return fabs(Cross(v1, v2)/Lenth(v1));
}


//获得点在直线上的投影
Point GetLineProjection (Point p, Point a, Point b) {
    Vec v = b-a;
    return a + v * (Dot(v, p-a)/Dot(v,v));
}
//判断两个线段是不是规范相交
bool SegmentProperIntersection(Point a1, Point a2, Point b1, Point b2) {
    double c1=Cross(a2-a1, b1-a1), c2=Cross(a2-a1, b2-a1),
           c3=Cross(b2-b1, a1-b1), c4=Cross(b2-b1, a2-b1);
    return dcmp(c1)*dcmp(c2) < 0 && dcmp(c3)*dcmp(c4) < 0;
}
//两条线段是不是满足快速排斥实验
bool FastOut(Point a1, Point a2, Point b1, Point b2) {
    return min(a1.x, a2.x) <= max(b1.x, b2.x) &&
           min(b1.x, b2.x) <= max(a1.x, a2.x) &&
           min(a1.y, a2.y) <= max(b1.y, b2.y) &&
           min(b1.y, b2.y) <= max(a1.y, a2.y);
}
//两条线段是不是相交，这里的相交是指有公共端点
bool SegmentIntersection(Point a1, Point a2, Point b1, Point b2) {
    if (FastOut(a1, a2, b1, b2)==false) return false;
    double c1=Cross(a2-a1, b1-a1), c2=Cross(a2-a1, b2-a1),
           c3=Cross(b2-b1, a1-b1), c4=Cross(b2-b1, a2-b1);
    return dcmp(c1)*dcmp(c2) <= 0 && dcmp(c3)*dcmp(c4) <= 0;
}

struct Seg {
    Point a,b;
    Seg() {}
};
```