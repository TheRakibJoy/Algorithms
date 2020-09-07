#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pll pair<ll , ll>

bool vis[405][405];
ll ara[405];
pll dp[405][405];

/** dp[i][j].first - total sum for this interval ; dp[i][j].second - minimum total cost to build this interval **/
/** This problem is like MCM problem **/

pll FuN(ll lft,ll rgt)
{
    if(lft > rgt)
        return make_pair(0LL , 0LL);
    if(lft == rgt)
        return make_pair(ara[lft] , 0);
    if(lft+1 == rgt)
        return make_pair(ara[lft]+ara[rgt] , ara[lft]+ara[rgt]);
    if(vis[lft][rgt])
        return dp[lft][rgt];
    pll ret = {1e18 , 1e18};
    for(ll i=lft ; i<rgt ; i++){
        pll pr1 = FuN(lft , i);
        pll pr2 = FuN(i+1 , rgt);
        pll newpr = make_pair((pr1.first+pr2.first) , (pr1.first+pr2.first+pr1.second+pr2.second));
        if(ret.second > newpr.second)
            ret = newpr;
    }
    vis[lft][rgt] = 1;
    return dp[lft][rgt] = ret;
}

int main()
{
    ll i,j,k,n;
    cin>>n;
    for(i=1 ; i<=n ; i++)   cin>>ara[i];

    pll ans = FuN(1 , n);
    cout<<ans.second<<endl;

    return 0;
}
