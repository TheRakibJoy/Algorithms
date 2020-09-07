#include<bits/stdc++.h>

#define ll long long

using namespace std;

const ll mod = 1e9+7;
ll ara[100005],dp[100005];

///dp[i] - number of ways such that we used i candies so far

void addSelf(ll &x,ll y)
{
    x += y;
    if(x >= mod)
        x -= mod;
}

void subSelf(ll &x,ll y)
{
    x -= y;
    if(x < 0)
        x += mod;
}

void naiveDP(ll n,ll k)
{
    dp[0] = 1;
    for(ll i=1 ; i<=n ; i++){
        for(ll used = k ; used >= 0 ; used--){
            ll lft = used + 1;
            ll rgt = used + min(ara[i] , k-used);

            for(ll j=lft ; j<=rgt ; j++)
                addSelf(dp[j] , dp[used]);
        }
    }
    cout<<dp[k]<<endl;
}

void optimizedDP(ll n,ll k)
{
    dp[0] = 1;
    for(ll i=1 ; i<=n ; i++){
        vector<ll>temp(k+1);
        for(ll used=k ; used >= 0 ; used--){
            ll lft = used + 1;
            ll rgt = used + min(ara[i] , k-used);

            if(lft <= rgt){
                addSelf(temp[lft] , dp[used]);
                if(rgt+1 <= k)
                    subSelf(temp[rgt+1] , dp[used]);
            }
        }
        ll prefSum = 0;
        for(ll x=0 ; x <= k ; x++){
            addSelf(prefSum , temp[x]);
            addSelf(dp[x] , prefSum);
        }
    }
    cout<<dp[k]<<endl;
}

int main()
{
    ll i,j,n,k,ans;
    cin>>n>>k;
    for(i=1 ; i<=n ; i++)   cin>>ara[i];

    optimizedDP(n , k);

    return 0;
}
