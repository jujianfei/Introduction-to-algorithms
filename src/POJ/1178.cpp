// 15186311_AC_16MS_804K.cc
#include<stdio.h>
#include<iostream>//iostream一定要放在stdio的后面
#define INF 0xfffffff
#include<vector>
#include<map>
using namespace std;
#define N 70

int dx[8]={-2,-1,1,2,2,1,-1,-2};
int dy[8]={1,2,2,1,-1,-2,-2,-1};

int dxk[4]={-1,0,1,0};
int dyk[4]={0,1,0,-1};


int D1[N+1][N+1];//knight
int G1[N+1][N+1];//knight
int D2[N+1][N+1];//king
int G2[N+1][N+1];//king

int is_legal(int i,int j){
    if(i<=8&&i>=1&&j<=8&&j>=1)return true;
    else return false;
}
pair<int,int> dec(int x){
    return pair<int,int>((x-1)/8+1, (x-1)%8+1);
}
int enc(int i,int j){
    return (i-1)*8+j;
}


void init(){
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
                G1[i][j]=G2[j][i]=INF;
            }
    }
    for(int i=1;i<=N;i++){
        G1[i][i]=G2[i][i]=0;
    }

    //骑士建立最短路
    for(int i=1;i<=64;i++){//对于每一点
        pair<int,int> kn=dec(i);
        for(int k=0;k<8;k++){//尝试8个方向
            if(is_legal(kn.first+dx[k],kn.second+dy[k])){
                G1[enc(kn.first+dx[k],kn.second+dy[k])][enc(kn.first,kn.second)]=
                G1[enc(kn.first,kn.second)][enc(kn.first+dx[k],kn.second+dy[k])]=1;
            }
        }
    }
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            D1[i][j]=G1[i][j];
        }
    }

    for(int k=1;k<=64;k++){
           for(int i=1;i<=64;i++){
               for(int j=1;j<=64;j++){
                   if(D1[i][j]>D1[i][k]+D1[k][j])
                   {
                       D1[i][j]=D1[i][k]+D1[k][j];
                   }
               }
           }
    }

    //国王建立最短路
    for(int point=1;point<=64;point++){
        pair<int,int> k1=dec(point);
        for(int k=0;k<4;k++){
            if(is_legal(k1.first+dxk[k],k1.second+dyk[k])){
                G2[enc(k1.first+dxk[k],k1.second+dyk[k])][point]=
                        G2[point][enc(k1.first+dxk[k],k1.second+dyk[k])]=1;
            }
        }
    }

    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            D2[i][j]=G2[i][j];
        }
    }
    for(int k=1;k<=64;k++){
           for(int i=1;i<=64;i++){
               for(int j=1;j<=64;j++){
                   if(D2[i][j]>D2[i][k]+D2[k][j])
                   {
                       D2[i][j]=D2[i][k]+D2[k][j];
                   }
               }
           }
    }

}


////经过测试，建立图成功
//int ModuleTest(int kind,int bx,int by,int ex,int ey){
//    if(kind==1){
//        return D1[enc(bx,by)][enc(ex,ey)];
//    }else{
//        return D2[enc(bx,by)][enc(ex,ey)];
//    }
//}
void ShowMap(){
    for(int i=1;i<=64;i++){
        for(int j=1;j<=64;j++){
            cout<<D2[i][j]<<" ";
        }cout<<endl;
    }
}

int main(){
    //freopen("D://in.txt","r",stdin);
    init();
    vector<int> v;
    int king;
    string temp;
    cin>>temp;
    //cout<<temp<<endl;
    if(temp.size()==2){
        cout<<"0"<<endl;
    }else{
        king=(temp[0]-65)*8+(temp[1]-48);
        //cout<<king<<endl;
        for(int i=3;i<=temp.size();i=i+2){
            //cout<<"now"<<i<<endl;
            v.push_back((temp[i-1]-65)*8+temp[i]-48);
        }

    //然后枚举和哪一个骑士相遇，相遇地点在哪里，集合地点在哪里
    int miner=INF;
    for(int m=1;m<=64;m++){
        for(int tar=1;tar<=64;tar++){
            int temp=0;
            for(int i=0;i<v.size();i++){
                temp+=D1[v[i]][tar];
            }
            for(int i=0;i<v.size();i++){
                int target=temp-D1[v[i]][tar];
                target+=D2[king][m];
                target+=D1[m][tar];
                target+=D1[v[i]][m];
                if(target<miner){
                    miner=target;
                }
            }
        }
    }
    cout<<miner<<endl;
    }
    return 0;
}
