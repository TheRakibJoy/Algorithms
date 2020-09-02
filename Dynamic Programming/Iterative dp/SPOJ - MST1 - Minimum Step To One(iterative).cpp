#include<bits/stdc++.h>
using namespace std;

int dp[20000005];

void FuN()
{
    dp[1] = 0;
    for(int i=2 ; i<=2e7 ; i++){
        dp[i] = 1+dp[i-1];
        if(i%2 == 0)
            dp[i] = min(dp[i] , 1+dp[i/2]);
        if(i%3 == 0)
            dp[i] = min(dp[i] , 1+dp[i/3]);
    }
}

int main()
{
    int i,j,k,n,t,T;
    FuN();
    scanf("%d",&T);
    for(t=1 ; t<=T ; t++){
        scanf("%d",&n);
        printf("Case %d: %d\n",t,dp[n]);
    }
    return 0;
}
