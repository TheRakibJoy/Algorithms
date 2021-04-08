#include<bits/stdc++.h>
using namespace std;

#define sz 100005
#define ll long long
map<int , int>compress;
int n,ara[sz],dp[sz],tree[4*sz];
const int mod = 1e9+7;

///Here, dp[i] means number of sequence we can make by taking a[i] must

void Update(int node,int b,int e,int pos,int val)
{
    if(pos<b || pos>e)
        return;
    if(b == pos && e == pos){
        tree[node] = (tree[node] + val)%mod;
        return;
    }
    int mid = (b+e)>>1;
    Update(node<<1 , b , mid , pos , val);
    Update(1+(node<<1) , mid+1 , e , pos , val);
    tree[node] = (tree[node<<1] + tree[1+(node<<1)])%mod;
}

int Query(int node,int b,int e,int i,int j)
{
    if(e<i || b>j)
        return 0;
    if(b>=i && e<=j)
        return tree[node];
    int mid = (b+e)>>1;
    int p1 = Query(node<<1 , b , mid , i , j);
    int p2 = Query(1+(node<<1) , mid+1 , e , i , j);
    return (p1+p2)%mod;
}

void Clean()
{
    compress.clear();
    for(int i=0 ; i<4*sz ; i++){
        tree[i] = 0;
        if(i < sz)
            dp[i] = 0;
    }
}

void FuN(int t)
{
    set<int>st;
    int ans = 0 , cnt = 0 , mxbound;
    scanf("%d",&n);
    for(int i=1 ; i<=n ; i++){
        scanf("%d",&ara[i]);
        st.insert(ara[i]);
    }

    for(auto it:st)
        compress[it] = ++cnt;

    mxbound = cnt+1;

    for(int i=n ; i>=1 ; i--){
        int val = compress[ara[i]];
        dp[i] = (1 + Query(1 , 1 , mxbound , val+1 , mxbound))%mod;
        ans = (ans + dp[i])%mod;
        Update(1 , 1 , mxbound , val , dp[i]);
    }
    printf("Case %d: %d\n",t,ans);
    Clean();
}

int main()
{
    int t,T;
    scanf("%d",&T);
    for(t=1 ; t<=T ; t++)
        FuN(t);
    return 0;
}
