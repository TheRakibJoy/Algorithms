#include<bits/stdc++.h>
using namespace std;

#define ll long long

bool vis[2][5005][5005];
ll ara[5005] , dp[2][5005][5005];

ll FuN(int player,int lft,int rgt)
{
    if(lft > rgt)
        return 0LL;
    if(lft == rgt)
        return (player * ara[lft]);

    if(vis[player][lft][rgt])
        return dp[player][lft][rgt];
    ll ret1=0 , ret2=0;
    if(player){
        ret1 = ara[lft] + FuN(player^1 , lft+1 , rgt);
        ret2 = ara[rgt] + FuN(player^1 , lft , rgt-1);
        vis[player][lft][rgt] = 1;
        return dp[player][lft][rgt] = max(ret1 , ret2);
    }
    else{
        ret1 = FuN(player^1 , lft+1 , rgt);
        ret2 = FuN(player^1 , lft , rgt-1);
        vis[player][lft][rgt] = 1;
        return dp[player][lft][rgt] = min(ret1 , ret2);
    }
}

int main()
{
    int n;
    cin>>n;

    for(int i=1 ; i<=n ; i++)
        cin>>ara[i];

    ll ans = FuN(1 , 1 , n);
    cout<<ans<<endl;
    return 0;
}
