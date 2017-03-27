// 4675810_AC_372ms_0kB.cpp

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int win,lose;
int chance,lefter;
void guess(string&s,char a)
{
    int bad=1;
    for(int i=0;i<s.size();i++)

        if(s[i]==a)
        {
            lefter--;
            s[i]=' ';
            bad=0;
        }
        
        if(bad)--chance;
        if(chance==0){lose=1;}
        if(lefter==0){win=1;}

}
int main()
{
    int rd;
    while(cin>>rd)
    {
        if(rd==-1)break;
        string s,s2;
        cin>>s>>s2;
        cout<<"Round "<<rd<<endl;
        win=lose=0;
        chance=7;
        lefter=s.size();
        for(int i=0;i<s2.size();i++)
        {
            guess(s,s2[i]);
            if(win||lose)break;
        }
        if(win) cout<<"You win."<<endl;
        else if(lose) cout<<"You lose."<<endl;
        else cout<<"You chickened out."<<endl;
    }
}