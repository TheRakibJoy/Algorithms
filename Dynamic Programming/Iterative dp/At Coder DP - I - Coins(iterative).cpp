#include<bits/stdc++.h>
using namespace std;

double h_prob[3005],dp[3005];
///dp[i] means probability of having i heads so far

int main()
{
    int i,j,k,n;
    double ans = 0.0;
    cin>>n;
    for(i=1 ; i<=n ; i++)
        cin>>h_prob[i];

    dp[0] = 1.0;
    for(int pos=1 ; pos<=n ; pos++){
        for(int head=pos ; head >= 0 ; head--)
            dp[head] = (dp[head-1] * h_prob[pos]) + (dp[head] * (1.0 - h_prob[pos]));
    }

    for(int head=(n+1)/2 ; head<=n ; head++)
        ans += dp[head];

    printf("%0.10f\n",ans);

    return 0;
}
