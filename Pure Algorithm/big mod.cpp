#include<bits/stdc++.h>
using namespace std;
long long int m=7;
long long int big_mod(long long int a,long long int b)
{
    if(b==0)
        return 1;
    if(b%2 == 0)
    {
        long long int temp=big_mod(a,b/2);
        return (((temp%m)*(temp%m))%m);
    }
    else
    {
        return (((a%m)*big_mod(a,b-1)%m)%m);
    }
}
int main()
{
    long long int a,b,mod;
    cin>>a>>b;
    mod=big_mod(a,b);
    cout<<mod<<endl;
    return 0;
}
