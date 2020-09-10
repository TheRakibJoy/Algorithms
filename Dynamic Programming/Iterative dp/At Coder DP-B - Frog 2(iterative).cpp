#include<bits/stdc++.h>
using namespace std;

long long h[100005],dp[100005]; ///dp[i] means minimum cost to reach n from i

int main()
{
    long long i,j,k,ans,n;
    cin>>n>>k;
    for(i=1 ; i<=n ; i++)   cin>>h[i];

    dp[n] = 0;
    for(i=n-1 ; i>=1 ; i--){
        dp[i] = 1e18;
        for(j=1 ; j<=k && i+j<=n ; j++)
            dp[i] = min(dp[i] , (long long)fabs(h[i] - h[i+j])+dp[i+j]);
    }
    cout<<dp[1]<<endl;

    return 0;
}
