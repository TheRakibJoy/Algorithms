#include<bits/stdc++.h>
using namespace std;

#define ll long long
ll ara[405],prefsum[405],dp[405][405];
/**
Think this problem reversely. That means assume that initially all slimes r merged.
You have to make every slime separate with minimum cost. Cost of dividing a slime into
two part is the total value of the connected slime.
dp[i][j] means minimum cost to make every (j-i+1) slimes separate
**/

int main()
{
    ll i,j,k,n,ans;
    cin>>n;
    for(i=1 ; i<=n ; i++){
        cin>>ara[i];
        prefsum[i] = prefsum[i-1] + ara[i];
    }

    for(ll sz=2 ; sz<=n ; sz++){
        for(i=1 ; i<=n-sz+1 ; i++){
            j = i+sz-1;
            dp[i][j] = 1e18;
            ll cuttingcost = prefsum[j] - prefsum[i-1];
            for(k=i ; k<j ; k++)
                dp[i][j] = min(dp[i][j] , cuttingcost + dp[i][k] + dp[k+1][j]);
        }
    }
    cout<<dp[1][n]<<endl;

    return 0;
}
