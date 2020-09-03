#include<bits/stdc++.h>
using namespace std;

int coin[105],dp[105][1000005];

int main()
{
    int i,j,k,n,sum,ans;
    scanf("%d %d",&n,&sum);
    for(i=1 ; i<=n ; i++){
        scanf("%d",&coin[i]);
    }

    for(i=1 ; i<=n+1 ; i++){
        for(j=1 ; j<=sum ; j++)
            dp[i][j] = 1e8;
    }
    sort(coin+1 , coin+n+1);

    for(i=n ; i>=1 ; i--){
        for(j=1 ; j<=sum ; j++){
            if(j-coin[i] >= 0){
                dp[i][j] = min(dp[i+1][j] , 1+dp[i][j-coin[i]]);
            }
            else
                dp[i][j] = dp[i+1][j];
        }
    }

    if(dp[1][sum] >= 1e8)
        ans = -1;
    else
        ans = dp[1][sum];

    cout<<ans<<endl;

    return 0;
}
