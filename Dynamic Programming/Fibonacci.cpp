#include<bits/stdc++.h>
using namespace std;

int dp[100];
int fib(int n)
{
    if(n == 0)
        return 0;
    if(n == 1)
        return 1;
    if(dp[n] != -1)
        return dp[n];
    else
    {
        dp[n]=fib(n-1)+fib(n-2);
        return dp[n];
    }
}

int main()
{
    memset(dp,-1,sizeof(dp));
    cout<<fib(6)<<endl;
    return 0;
}
