#include<bits/stdc++.h>
using namespace std;

int dp[1000005];
const int mod = 1000000007;

int main()
{
    int i,j,k,n,sum,ans=0;
    cin>>sum;

    for(int val = 0 ; val <= 1e6 ; val++){
        if(val == 0){
            dp[val] = 1;
            continue;
        }

        int ret = 0;
        for(int dice=1 ; dice<=6 ; dice++){
            if(val-dice >= 0)
                ret = (ret + dp[val-dice])%mod;
        }
        dp[val] = ret;
    }

    ans = dp[sum];
    cout<<ans<<endl;
    return 0;
}
