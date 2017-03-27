// 7030398_AC_2125ms_16028kB.cpp
#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int largestRectangleArea(vector<int>& v) {
        if(v.size()==0)return 0;
        int res = 0;
        vector<int> stk;
        for(int i=0;i<v.size();i++)
        {
            if(stk.empty()||stk.back()<=v[i])
                stk.push_back(v[i]);
            else
            {
                int count = 0;
                while(!stk.empty()&&stk.back() > v[i])
                {
                    count ++;
                    res = max(res, stk.back()*count);
                    stk.pop_back();
                }
                count++;
                while(count --)
                    stk.push_back(v[i]);
                //stk.push_back(v[i]);
            }
        }

        //看在vector中是否会出现比res更大的值
        for(int i=0;i<stk.size();i++){

            int tmp=(v.size()-i)*stk[i];
            res=std::max(res,tmp);
        }
        return res;
}


int maximalRectangle(vector<vector<int>>& a) {
    int n=a.size();
    if(!n)return 0;
    int m=a[0].size();

    //first row
    int ret = largestRectangleArea(a[0]);
    for(int i=1;i<n;i++){
        for(int j=0;j<m;j++){
            if(a[i][j]==0){
                a[i][j]=0;
            }else{
                a[i][j]=a[i-1][j]+1;
            }

        }
        ret = max(ret,largestRectangleArea(a[i]));
    }

    return ret;
}

vector<vector<int> > v;
int main() {
    //freopen("in.txt", "r", stdin);
    int n, m;
    while (cin >> n >> m) {
        v.clear();
        v.resize(n);
        for (int i=0; i<n; i++) {
            v[i].resize(m);
            for (int j=0; j<m; j++) {
                scanf("%d", &v[i][j]);
            }
        }
        cout << maximalRectangle(v) << endl;
    }
}
