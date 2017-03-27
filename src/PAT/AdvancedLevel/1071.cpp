// 忽视了一个重要的点，就是abc,abc这是两个单词
#include <bits/stdc++.h>
using namespace std;
char s[1150000];
int main()
{

    int ch, p = 0;
    map<string, int> mp;
    while ((ch = getchar()) != '\n'){
        if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9')){
            s[p++] = tolower(ch);
        }else{
            if (p > 0){
                s[p] = '\0';
                ++mp[s];
                p = 0;
            }
        }
    }
    if (p > 0){
        s[p] = '\0';
        ++mp[s];
    }
    int mx = mp.begin()->second;
    string ms = mp.begin()->first;
    for (map<string, int>::iterator it = mp.begin(); it != mp.end(); ++it){
        if (it->second > mx){
            mx = it->second;
            ms = it->first;
        }
    }
    printf("%s %d\n", ms.c_str(), mx);
    return 0;
}

