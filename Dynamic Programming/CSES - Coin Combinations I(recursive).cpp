#include<bits/stdc++.h>
using namespace std;

const int mod = 1000000007;
int n,x,coin[105],dp[1000005];

int FuN(int baki)
{
    if(baki == 0)
        return 1;
    if(dp[baki] != -1)
        return dp[baki];
    int ret = 0;
    for(int i=1 ; i<=n ; i++){
        if(baki-coin[i] >= 0)
            ret = (ret + FuN(baki - coin[i]))%mod;
    }
    return dp[baki] = ret;
}

int main()
{
    int ans;
    cin>>n>>x;
    for(int i=1 ; i<=n ; i++)   cin>>coin[i];
    memset(dp , -1 , sizeof(dp));
    ans = FuN(x);
    cout<<ans<<endl;
    return 0;
}
