#include<bits/stdc++.h>
using namespace std;

int dp[1000005];

int FuN(int baki)
{
    if(baki == 0)
        return 0;
    if(dp[baki] != -1)
        return dp[baki];
    int ret = 1e9 , temp = baki;
    while(temp){
        int digit = temp%10;
        if(digit > 0)
            ret = min(ret , 1+FuN(baki-digit));
        temp /= 10;
    }
    return dp[baki] = ret;
}

int main()
{
    int n,ans;
    cin>>n;
    memset(dp , -1 , sizeof(dp));
    cout<<FuN(n)<<endl;
    return 0;
}
