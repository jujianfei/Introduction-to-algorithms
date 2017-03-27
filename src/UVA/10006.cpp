// 5058803_AC_179ms_0kB.cpp
#include<iostream>
#include<math.h>
using namespace std;
int d[16];
void int2two(int n)
{
    for(int i=0;i<=15;i++)
    {
        d[i]=-1;
    }
    for(int i=0;i<16;i++)
    {
        if(n&(1<<i))
        {
            d[i]=1;
        }
        else
            d[i]=0;
    }
    for(int i=0;i<16;i++)
    {
        cout<<d[i]<<" ";
    }
}

bool is_primer(int i)
{
    if(i==1||i==2)return true;

    for(int k=2;k<=sqrt(i);k++)
    {
        if(i%k==0)
        return false;
    }
    return true;

}


using ll=long long;

ll mod_pow(ll x,ll mod,ll n)
{
    ll ans = 1;
    while(n>0)
    {
        if(n & 1) ans = ans*x%mod;
        x = x*x%mod;
        n >>= 1;
    }
    return ans;
}



int main()
{


    int n;
    while(cin>>n)
    {
        if(n==0)
        break;
        int flag=0;
        if(is_primer(n)==true)
        {
            flag=1;
        }
        else
        {
            for(int i=2;i<n;i++)
            {
                if(mod_pow(i,n,n)!=i)
                {
                    flag=1;
                    break;
                }
            }
        }
        if(flag)
        {
            cout<<n<<" is normal."<<endl;

        }
            else
            {
                cout<<"The number "<<n<<" is a Carmichael number."<<endl;
            }

    }


}
