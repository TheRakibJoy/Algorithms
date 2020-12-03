#include<bits/stdc++.h>
using namespace std;

int dp[2][100005],h[1005],s[1005];

int main()
{
    int i,j,k,n,x,ans = 0;
    cin>>n>>x;

    for(i=1 ; i<=n ; i++)
        cin>>h[i];
    for(i=1 ; i<=n ; i++)
        cin>>s[i];

    for(i=n ; i>=1 ; i--){
        for(j=0 ; j<=x ; j++){
            if(j-h[i] >= 0)
                dp[i & 1][j] = max(dp[(i+1) & 1][j] , s[i]+dp[(i+1) & 1][j - h[i]]);
            else
                dp[i & 1][j] = dp[(i+1) & 1][j];
        }
    }

    for(j=0 ; j<=x ; j++)
        ans = max(ans , dp[1 & 1][j]);
    cout<<ans<<endl;

    return 0;
}
