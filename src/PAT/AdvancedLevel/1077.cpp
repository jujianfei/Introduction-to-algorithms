//简单的模拟好吗，不知道为什么自己WA了几发
#include <iostream>  
#include <string>  
#include <vector>  
#include <algorithm>  
using namespace std;  
  
int main(){  
    //freopen("in.txt", "r", stdin);
    int n;  
    string s, ans;  
    vector<string> svec;  
    cin >> n;  
    getchar();  
    while (n--){  
        getline(cin, s);  
        reverse(s.begin(), s.end());  
        svec.push_back(s);  
    }  
    string s1 = svec[0];  
    for (int i = 0; i < s1.size(); i++){  
        bool flag = true;  
        for (int j = 1; j < svec.size(); j++){  
            if (svec[j][i] != s1[i]){  
                flag = false;  
                break;  
            }  
        }  
            if (flag)  
                ans += s1[i];  
            else  
                break;  
    }  
    if (ans.empty())  
        cout << "nai" << endl;  
    else{  
        reverse(ans.begin(), ans.end());  
        cout << ans << endl;  
    }  
    return 0;  
}  