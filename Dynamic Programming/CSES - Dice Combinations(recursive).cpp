#include<bits/stdc++.h>
using namespace std;

int dp[1000005];
const int mod = 1000000007;

int FuN(int baki)
{
    if(baki == 0)
        return 1;
    if(dp[baki] != -1)
        return dp[baki];
    int ret = 0;
    for(int i=1 ; i<=6 ; i++){
        if(baki-i >= 0)
            ret = (ret + FuN(baki-i))%mod;
    }
    return dp[baki] = ret;
}

int main()
{
    int sum;
    cin>>sum;
    memset(dp , -1 , sizeof(dp));
    cout<<FuN(sum)<<endl;
    return 0;
}
