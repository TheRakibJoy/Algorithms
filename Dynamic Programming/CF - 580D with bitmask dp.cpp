#include<bits/stdc++.h>

#define ll      long long
using namespace std;

ll n,m,k,bonus[20][20],sat[20],dp[1<<20][20];

int Check(int mask,int pos)
{
    return (bool) (mask & (1<<pos));
}

int Set(int mask,int pos)
{
    return mask = (mask | (1<<pos));
}

ll FuN(int mask,int lasttaken)
{
    ll taken = __builtin_popcount(mask);
    if(taken == m)
        return 0;
    if(dp[mask][lasttaken] != -1)
        return dp[mask][lasttaken];

    ll ret = 0;
    for(int i=1 ; i<=n ; i++){
        if(!Check(mask , i)){
            ll temp = sat[i] + bonus[lasttaken][i] + FuN(Set(mask , i) , i);
            ret = max(ret , temp);
        }
    }
    return dp[mask][lasttaken] = ret;
}

int main()
{
    cin>>n>>m>>k;
    for(ll i=1 ; i<=n ; i++)
        cin>>sat[i];
    for(ll i=1 ; i<=k ; i++){
        ll x,y,wt;
        cin>>x>>y>>wt;
        bonus[x][y] = wt;
    }
    memset(dp , -1 , sizeof(dp));
    ll ans = FuN(0 , 0);
    cout<<ans<<endl;
    return 0;
}
