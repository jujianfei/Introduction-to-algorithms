// 15125036_AC_532MS_25240K.cc
#include<iostream>
#include<fstream>
#define M  12500000
using namespace std;

char hash_[M*2+1];

int main()
{

//    ifstream fin("/home/zlq/Desktop/in");
//    streambuf *cinbackup;
//    cinbackup= cin.rdbuf(fin.rdbuf());

    int a,b,c,d,e;

    while(cin>>a>>b>>c>>d>>e)
    {
    int cnt=0;

    for(int i=0;i<M*2+5;i++){hash_[i]=0;}



    for(int x1=-50;x1<=50;x1++)
    {
        if(x1!=0)
        for(int x2=-50;x2<=50;x2++)
        {
            if(x2!=0)
              hash_[M-a*x1*x1*x1-b*x2*x2*x2]++;
        }
    }


    for(int x3=-50;x3<=50;x3++)
    {
        if(x3!=0)
        for(int x4=-50;x4<=50;x4++)
        {
            if(x4!=0)
            for(int x5=-50;x5<=50;x5++)
            {
                if(x5!=0)
                {if(M+c*x3*x3*x3+d*x4*x4*x4+e*x5*x5*x5<=2*M&&M+c*x3*x3*x3+d*x4*x4*x4+e*x5*x5*x5>=0)
                cnt+=hash_[M+c*x3*x3*x3+d*x4*x4*x4+e*x5*x5*x5];}

            }
        }
    }


    cout<<cnt<<endl;
    }

}
