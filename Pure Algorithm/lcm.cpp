/**Wrong concept
#include<bits/stdc++.h>
using namespace std;

int GCD(int a,int b)
{
    if(b==0)
        return a;
    return GCD(b,a%b);
}
int LCM(int a,int b,int gcd)
{
    return (a/GCD(a,b))*b;
}
int main()
{
    int a,b,gcd,lcm;
    cin>>a>>b;
    if(b>a)
    {
        int temp=a;
        a=b;
        b=a;
    }
    gcd=GCD(a,b);
    lcm=LCM(a,b,gcd);
    cout<<"GCD = "<<gcd<<"\nLCM = "<<lcm<<endl;
    return 0;
}

