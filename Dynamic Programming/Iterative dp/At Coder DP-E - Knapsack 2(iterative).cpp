#include<bits/stdc++.h>
using namespace std;

long long wt[105],value[105],dp[105][100005];   ///dp[i][j] means minimum weight for making profit exactly j by considering item i to n

int main()
{
    long long i,j,k,n,cap,ans;
    cin>>n>>cap;
    for(i=1 ; i<=n ; i++)   cin>>wt[i]>>value[i];

    dp[n+1][0] = 0;
    for(i=1 ; i<=1e5 ; i++) dp[n+1][i] = 1e18;

    for(i=n ; i>=1 ; i--){
        for(j=0 ; j<=1e5 ; j++){
            if(value[i] > j)
                dp[i][j] = dp[i+1][j];
            else
                dp[i][j] = min(dp[i+1][j] , wt[i]+dp[i+1][j-value[i]]);
        }
    }

    for(i=1e5 ; i>=0 ; i--){
        if(dp[1][i] <= cap){
            cout<<i<<endl;
            break;
        }
    }

    return 0;
}
