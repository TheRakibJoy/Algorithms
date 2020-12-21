#include<bits/stdc++.h>

#define ll                      long long int
#define RUN_CASE(t,T)           for(__typeof(t) t=1;t<=T;t++)
#define gcd(a,b)                __gcd(a,b)

using namespace std;

#define sz 100005
ll ara[sz],tree[4*sz],lazy[4*sz];

void push_down(int node,int b,int e)
{
    tree[node] *= lazy[node];
    if(b != e){
        lazy[node<<1] *= lazy[node];
        lazy[1+(node<<1)] *= lazy[node];
    }
    lazy[node] = 1;
}

void Build(ll node,ll b,ll e)
{
    if(b == e){
        tree[node] = ara[b];
        return;
    }
    ll mid = (b+e)>>1;
    Build(node<<1 , b , mid);
    Build(1+(node<<1) , mid+1 , e);
    tree[node] = gcd(tree[node<<1] , tree[1+(node<<1)]);
}

ll Query(ll node,ll b,ll e,ll i,ll j)
{
    if(lazy[node] != 1)
        push_down(node , b , e);
    if(e<i || b>j)
        return 0LL;
    if(b>=i && e<=j)
        return tree[node];
    ll mid = (b+e)>>1;
    ll p1 = Query(node<<1 , b , mid , i , j);
    ll p2 = Query(1+(node<<1) , mid+1 , e , i , j);
    return gcd(p1 , p2);
}

void Update(ll node,ll b,ll e,ll i,ll j,ll val)
{
    if(lazy[node] != 1)
        push_down(node , b, e);
    if(e<i || b>j)
        return;
    if(b>=i && e<=j){
        tree[node] *= val;
        if(b != e){
            lazy[node<<1] *= val;
            lazy[1+(node<<1)] *= val;
        }
        return;
    }
    ll mid = (b+e)>>1;
    Update(node<<1 , b , mid , i , j , val);
    Update(1+(node<<1) , mid+1 , e , i , j , val);
    tree[node] = gcd(tree[node<<1] , tree[1+(node<<1)]);
}

void Solve(int t)
{
    ll i,j,k,n,q,pos,l,r,cmd,val;

    for(i=0 ; i<4*sz ; i++){
        tree[i] = 0;
        lazy[i] = 1;
    }

    cin>>n>>q;

    for(i=1 ; i<=n ; i++)
        cin>>ara[i];

    Build(1 , 1 , n);
    for(i=1 ; i<=q ; i++){
        cin>>cmd>>l>>r;
        l++;
        r++;
        if(cmd == 1){
            ll ans = Query(1 , 1 , n , l , r);
            cout<<ans<<endl;
        }
        else{
            cin>>val;
            Update(1 , 1 , n , l , r , val);
        }
    }
}

int main()
{
    int t,T;
    cin>>T;
    for(t=1 ; t<=T ; t++)
        Solve(t);
    return 0;
}
