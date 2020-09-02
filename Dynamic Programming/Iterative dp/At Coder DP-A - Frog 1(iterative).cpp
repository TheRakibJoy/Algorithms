#include<bits/stdc++.h>

using namespace std;

long long h[100005],dp[100005]; ///dp[i] means minimum cost to reach n from i

void Solve(int t)
{
    long long i,j,k,n,ans;
    cin>>n;
    for(i=1 ; i<=n ; i++)   cin>>h[i];

    dp[n] = 0;
    dp[n-1] = fabs(h[n] - h[n-1]);
    for(i=n-2 ; i>=1 ; i--)
        dp[i] = min(fabs(h[i]-h[i+1])+dp[i+1] , fabs(h[i]-h[i+2])+dp[i+2]);
    cout<<dp[1]<<endl;
}

int main()
{
    Solve(1);
    return 0;
}



