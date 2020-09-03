#include<bits/stdc++.h>
using namespace std;

int n,x,coin[105],dp[105][1000005];
const int mod = 1e9+7;

int main()
{
    int i,j,k,ans;
    cin>>n>>x;
    for(i=1 ; i<=n ; i++)   cin>>coin[i];

    dp[n+1][0] = 1;
    for(i=n ; i>=1 ; i--){
        for(j=0 ; j<=1e6 ; j++){
            if(j-coin[i] >= 0){
                dp[i][j] = (dp[i][j-coin[i]] + dp[i+1][j])%mod;
            }
            else
                dp[i][j] = dp[i+1][j];
        }
    }

    cout<<dp[1][x]<<endl;

    return 0;
}
