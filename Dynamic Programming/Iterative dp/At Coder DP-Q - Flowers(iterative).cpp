#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define sz 200100
ll height[sz],beauty[sz],dp[sz],tree[4*sz];

///dp[i] means maximum possible sum of beauty for [i , n] interval if I keep this ith flower.
///Here, in segment tree at index h[i] I'll keep maximum possible sum of beauty for interval [i,n] if I keep the ith flower.

void Update(ll node,ll b,ll e,ll pos,ll val)
{
    if(pos<b || pos>e)
        return;
    if(b==pos && e==pos){
        tree[node] = val;
        return;
    }
    ll mid = (b+e)>>1;
    ll lft = node<<1;
    ll rgt = 1+lft;
    Update(lft , b , mid , pos , val);
    Update(rgt , mid+1 , e , pos , val);
    tree[node] = max(tree[lft] , tree[rgt]);
}

ll Query(ll node,ll b,ll e,ll i,ll j)
{
    if(j<b || i>e)
        return 0LL;
    if(b>=i && e<=j)
        return tree[node];
    ll mid = (b+e)>>1;
    ll lft = node<<1;
    ll rgt = 1+lft;
    ll p1 = Query(lft , b , mid , i , j);
    ll p2 = Query(rgt , mid+1 , e , i , j);
    return max(p1 , p2);
}

int main()
{
    ll i,j,k,n,ans=0;
    cin>>n;
    ll limit = n+5;
    for(i=1 ; i<=n ; i++)   cin>>height[i];
    for(i=1 ; i<=n ; i++)   cin>>beauty[i];

    for(i=n ; i>=1 ; i--){
        ll mxsofar = Query(1 , 1 , limit , height[i]+1 , limit);
        dp[i] = beauty[i] + mxsofar;
        Update(1 , 1 , limit , height[i] , dp[i]);
        ans = max(ans , dp[i]);
    }
    cout<<ans<<endl;

    return 0;
}
