// 15030695_AC_4735MS_172K.cpp
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>
using namespace std;
#define eps 1e-8
struct Point{
    double x,y;
    Point(){}
    Point(double tx,double ty){x=tx;y=ty;}
}p[300];
int n;
double dist(Point p1,Point p2){
    return sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
}
Point get_circle(Point p1,Point p2){
    Point mid=Point((p1.x+p2.x)/2,(p1.y+p2.y)/2);
    double angle=atan2(p1.x-p2.x,p2.y-p1.y);
    double d=sqrt(1-dist(p1,mid)*dist(p1,mid));
    return Point(mid.x+d*cos(angle),mid.y+d*sin(angle));
}
int main(){
    while(scanf("%d",&n)!=EOF&&n){
        for(int i=0;i<n;i++)
            scanf("%lf%lf",&p[i].x,&p[i].y);
        int ans=1;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(dist(p[i],p[j])>2.0) continue;
                Point central=get_circle(p[i],p[j]);
                int cnt=0;
                for(int k=0;k<n;k++)
                    if(dist(central,p[k])<1.0+eps)
                        cnt++;
                ans=max(ans,cnt);
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}