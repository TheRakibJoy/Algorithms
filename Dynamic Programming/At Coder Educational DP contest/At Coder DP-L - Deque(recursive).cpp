#include<bits/stdc++.h>

#define ll long long

using namespace std;

bool vis[2][3005][3005];
ll ara[3005],dp[2][3005][3005];

ll FuN(ll player,ll pos1,ll pos2)
{
    if(pos1 > pos2)
        return 0;
    if(vis[player][pos1][pos2])
        return dp[player][pos1][pos2];
    ll ret1=0,ret2=0;
    if(player){
        ret1 = ara[pos1] + FuN(player^1 , pos1+1 , pos2);
        ret2 = ara[pos2] + FuN(player^1 , pos1 , pos2-1);
        vis[player][pos1][pos2] = 1;
        return dp[player][pos1][pos2] = max(ret1 , ret2);
    }
    else{
        ret1 = -ara[pos1] + FuN(player^1 , pos1+1 , pos2);
        ret2 = -ara[pos2] + FuN(player^1 , pos1 , pos2-1);
        vis[player][pos1][pos2] = 1;
        return dp[player][pos1][pos2] = min(ret1 , ret2);
    }
}

int main()
{
    ll i,j,k,n,ans;
    cin>>n;
    for(i=1 ; i<=n ; i++)   cin>>ara[i];

    ans = FuN(1 , 1 , n);
    cout<<ans<<endl;

    return 0;
}
