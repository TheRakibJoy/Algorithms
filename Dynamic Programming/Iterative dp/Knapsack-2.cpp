#include<bits/stdc++.h>
using namespace std;

/** n<=100 , wt[i]<=1000 , cnt[i]<=1000 , profit[i]<=10000 , capacity<=10000 **/

long long wt[105],cnt[105],profit[105],dp[1005][10005];
vector<long long>fwt,fprofit;

int main()
{
    long long i,j,k,n,N,cap,ans=0;
    cin>>n>>cap;
    for(i=1 ; i<=n ; i++)   cin>>wt[i];
    for(i=1 ; i<=n ; i++)   cin>>cnt[i];
    for(i=1 ; i<=n ; i++)   cin>>profit[i];

    ///Rebuild the set of coin

    fwt.push_back(0);
    fprofit.push_back(0);
    for(i=1 ; i<=n ; i++){
        long long spend = 0LL , now = 1;
        while(spend+now <= cnt[i]){
            fwt.push_back(wt[i] * now);
            fprofit.push_back(profit[i] * now);
            spend += now;
            now *= 2;
        }
        if(cnt[i]-spend > 0){
            fwt.push_back(wt[i] * (cnt[i] - spend));
            fprofit.push_back(profit[i] * (cnt[i] - spend));
        }
    }

    ///Base case
    N = fwt.size() - 1;
    for(j=0 ; j<=cap ; j++) dp[N+1][j] = 0;

    for(int i=N ; i>=1 ; i--){
        for(int j=0 ; j<=cap ; j++){
            if(fwt[i] > j)
                dp[i][j] = dp[i+1][j];
            else
                dp[i][j] = max(dp[i+1][j] , fprofit[i] + dp[i+1][j - fwt[i]]);
        }
    }

    ///Calculate maximum profit
    for(j=0 ; j<=cap ; j++)
        ans = max(ans , dp[1][j]);
    cout<<ans<<endl;
    return 0;
}
