#include<bits/stdc++.h>
using namespace std;

/** n<=100 , price[i]<=1000 , wt[i]<=1e9 , capacity<=1e12 **/

long long price[105],wt[105],dp[105][100005];

int main()
{
    long long i,p,n,cap,ans;
    cin>>n>>cap;
    for(i=1 ; i<=n ; i++)   cin>>price[i];
    for(i=1 ; i<=n ; i++)   cin>>wt[i];

    dp[n+1][0] = 0;
    for(i=1 ; i<=1e5 ; i++)
        dp[n+1][i] = 1e18;

    for(i=n ; i>=1 ; i--){
        for(p=1 ; p<=1e5 ; p++){
            dp[i][p] = min(dp[i+1][p] , wt[i]+dp[i+1][p-price[i]]);
        }
    }
    for(p=1e5 ; p>=0 ; p--){
        if(dp[1][p] <= cap){
            ans = p;
            break;
        }
    }
    cout<<ans<<endl;
    return 0;
}
