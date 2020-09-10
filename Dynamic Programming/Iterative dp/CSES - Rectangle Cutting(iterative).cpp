#include<bits/stdc++.h>
using namespace std;

int dp[505][505];
/** dp[i][j] means minimum cost to cut i*j rectangle into squares **/

int main()
{
    int i,j,k,n,m,ans;
    cin>>n>>m;

    for(i=1 ; i<=n ; i++){
        for(j=1 ; j<=m ; j++){
            if(i == j)
                continue;
            dp[i][j] = 1e9;
            ///Cut it horizontally
            for(k=1 ; k<i ; k++)
                dp[i][j] = min(dp[i][j] , 1 + dp[k][j] + dp[i-k][j]);
            ///Cut it vertically
            for(k=1 ; k<j ; k++)
                dp[i][j] = min(dp[i][j] , 1 + dp[i][k] + dp[i][j-k]);
        }
    }

    ans = dp[n][m];
    cout<<ans<<endl;

    return 0;
}
