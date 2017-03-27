// 15166002_AC_16MS_792K.cc
#include <string>
#include <sstream>
#include <iostream>
#include <stdio.h>
using namespace std;
const int inf = 1<<20;
const int NV = 106;
int dis[NV];
int m[NV][NV];
bool mark[NV];
int n;
//图的index从0开始
void dijstra(int src)
{
    int i,index,j,minf;
    for( i=0;i<n;i++){
        mark[i]=false;
        dis[i]=m[src][i];
    }
    dis[src]=0;
    mark[src]=true;
    for(i=1;i<n;++i){
        minf=inf;
        index=src;
        for(j=0;j<n;++j){
            if(dis[j]<minf&&(!mark[j])){
                minf=dis[j];
                index=j;
                }
            }

            mark[index]=true;
            for(j=0;j<n;j++)
            {
                int temp=dis[index]+m[index][j];
                if(!mark[j]&&temp<dis[j])
                    dis[j]=temp;
                //cout<<"change"<<dis[j]<<" "<<endl;
            }
        }
        return;
}

int string_to_int(string & s)
{
    int thevalue;
    std::istringstream ss(s);
    ss >> thevalue;
    return thevalue;
}
int main()
{
    //freopen("/home/zlq/QTACMING/in","r",stdin);
    cin>>n;
    string c;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            m[i][j]=inf;
        }
    }
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
           cin>>c;
           if(c!="x"){
               m[i][j]=m[j][i]=string_to_int(c);
           }
        }
    }
    dijstra(0);
    int res=-1;
    for(int i=1;i<n;i++){
        if(dis[i]>res)res=dis[i];
    }
    cout<<res<<endl;

}


