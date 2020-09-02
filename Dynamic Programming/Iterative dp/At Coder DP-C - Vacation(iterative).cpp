#include<bits/stdc++.h>
using namespace std;

long long a[100005],b[100005],c[100005],dp[100005][4];
/** Definition: dp[i][j] means in ith days i'll do jth activity **/

int main()
{
    long long i,j,k,n,ans;
    cin>>n;
    for(i=1 ; i<=n ; i++)   cin>>a[i]>>b[i]>>c[i];

    dp[1][1] = a[1];
    dp[1][2] = b[1];
    dp[1][3] = c[1];

    for(i=2 ; i<=n ; i++){
        dp[i][1] = a[i] + max(dp[i-1][2] , dp[i-1][3]);
        dp[i][2] = b[i] + max(dp[i-1][1] , dp[i-1][3]);
        dp[i][3] = c[i] + max(dp[i-1][1] , dp[i-1][2]);
    }
    ans = max(dp[n][1] , max(dp[n][2] , dp[n][3]));
    cout<<ans<<endl;

    return 0;
}
