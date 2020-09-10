#include<bits/stdc++.h>
using namespace std;

#define ll long long
ll ara[3005],dp[3005][3005];

/**
See session 25.1 55:00 to write tutorial

Obj-1: Here, TARO tries to maximize X-Y, JIRO tries to minimize X-Y means both of them
tries to maximize his score!

dp[i][j] = score of 1st player - score of 2nd player for the sub-array a[i...j].

Here, 1st player means who can give first move for this sub-array(not TARO). That means
after each move 1st player will become 2nd player & 2nd player will become 1st!
For this reason, dp[i][j] = max(ara[i]-dp[i+1][j] , ara[j]-dp[i][j-1])

ara[i]-dp[i+1][j] means
= ara[i] - (1st player score for a[i+1..j] - 2nd player score for a[i+1...j]
= ara[i] - 1st player score for a[i+1...j] + 2nd player score for a[i+1...j]
= (ara[i] + 2nd player score for a[i+1...j]) - 1st player score for a[i+1...j]
= 1st player score for a[i...j] - 2nd player score for a[i...j]

you can see 2nd player of previous state now become 1st player!

we'll try to build DP from small to large size sub-array
**/

int main()
{
    ll i,j,k,n,ans;
    cin>>n;
    for(i=1 ; i<=n ; i++)   cin>>ara[i];

    for(ll sz = 1 ; sz <= n ; sz++){
        for(ll start=1 ; start <= n-sz+1 ; start++){
            ll ed = start+sz-1;
            dp[start][ed] = max(ara[start]-dp[start+1][ed] , ara[ed]-dp[start][ed-1]);
        }
    }

    cout<<dp[1][n]<<endl;

    return 0;
}
