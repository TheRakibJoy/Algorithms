#include<bits/stdc++.h>
using namespace std;

long long wt[105],value[105],dp[105][100005];   ///dp[i][j] means maximum profit for taking exactly j kg product from i to n index

int main()
{
    long long i,j,k,cap,ans=0,n;
    cin>>n>>cap;
    for(i=1 ; i<=n ; i++)   cin>>wt[i]>>value[i];

    for(j=0 ; j<=cap ; j++) dp[n+1][j] = 0;

    for(i=n ; i>=1 ; i--){
        for(j=0 ; j<=cap ; j++){
            if(wt[i] > j)
                dp[i][j] = dp[i+1][j];
            else
                dp[i][j] = max(dp[i+1][j] , value[i]+dp[i+1][j-wt[i]]);
        }
    }

    for(j=0 ; j<=cap ; j++)
        ans = max(ans , dp[1][j]);
    cout<<ans<<endl;

    return 0;
}
