#include<bits/stdc++.h>
using namespace std;

#define ll                      long long
#define gcd(a,b)                __gcd(a,b)

#define sz 200009
ll ara[sz];

/**
Problem: Given an array with n elements. You've to perform q queries.
1. l r      (Find GCD of subArray a[l...r])
2. l r x    (Add x to all element of subArray a[l...r]

Approach:
GCD(a,b,c) = GCD(a , GCD(b,c))

GCD(a,b) = GCD(a , b-a) = GCD(a-b , b) = GCD(abs(a-b) , a) = GCD(abs(a-b) , b)
GCD(a,b,c) = GCD(a , GCD(b-a , c-b)

GCD(a[l],a[l+1],...,a[r]) = GCD(a[l] , a[l+1]-a[l] , a[l+2]-a[l+1] , ... , a[r]-a[r+1])
**/

///Segment Tree for maintaining main given array
ll lazy[4*sz],tree[4*sz];

void push_down(ll node,ll b,ll e)
{
    tree[node] += lazy[node];
    if(b != e){
        lazy[node<<1] += lazy[node];
        lazy[1+(node<<1)] += lazy[node];
    }
    lazy[node] = 0;
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
    tree[node] = max(tree[node<<1] , tree[1+(node<<1)]);
}

void Update(ll node,ll b,ll e,ll i,ll j,ll val)
{
    if(lazy[node] != 0)
        push_down(node , b , e);
    if(e<i || b>j)
        return;
    if(b>=i && e<=j){
        tree[node] += val;
        if(b != e){
            lazy[node<<1] += val;
            lazy[1+(node<<1)] += val;
        }
        return;
    }
    ll mid = (b+e)>>1;
    Update(node<<1 , b , mid , i , j , val);
    Update(1+(node<<1) , mid+1 , e , i , j , val);
    tree[node] = max(tree[node<<1] , tree[1+(node<<1)]);
}

ll Query(ll node,ll b,ll e,ll i,ll j)
{
    if(lazy[node] != 0)
        push_down(node , b , e);
    if(e<i || b>j)
        return 0LL;
    if(b>=i && e<=j)
        return tree[node];
    ll mid = (b+e)>>1;
    ll p1 = Query(node<<1 , b , mid , i , j);
    ll p2 = Query(1+(node<<1) , mid+1 , e , i , j);
    return max(p1 , p2);
}

///Segment tree for maintaining difference array
ll dif[sz],treegc[4*sz];

void Build2(ll node,ll b,ll e)
{
    if(b == e){
        treegc[node] = dif[b];
        return;
    }
    ll mid = (b+e)>>1;
    Build2(node<<1 , b , mid);
    Build2(1+(node<<1) , mid+1 , e);
    treegc[node] = gcd((ll)fabs(treegc[node<<1]) , (ll)fabs(treegc[1+(node<<1)]));
}

ll Query2(ll node,ll b,ll e,ll i,ll j)
{
    if(e<i || b>j)
        return 0LL;     ///Because GCD(0 , x) = x
    if(b>=i && e<=j)
        return fabs(treegc[node]);
    ll mid = (b+e)>>1;
    ll p1 = Query2(node<<1 , b , mid , i , j);
    ll p2 = Query2(1+(node<<1) , mid+1 , e , i , j);
    return gcd((ll)fabs(p1) , (ll)fabs(p2));
}

void Update2(ll node,ll b,ll e,ll pos,ll val)   ///Point Update
{
    if(e<pos || b>pos)
        return;
    if(b == pos && e == pos){
        treegc[node] += val;
        return;
    }
    ll mid = (b+e)>>1;
    Update2(node<<1 , b , mid , pos , val);
    Update2(1+(node<<1) , mid+1 , e , pos , val);
    treegc[node] = gcd((ll)fabs(treegc[node<<1]) , (ll)fabs(treegc[1+(node<<1)]));
}

void Solve()
{
    ll i,j,k,n,l,r,x,q,type;
    cin>>n>>q;
    for(i=1 ; i<=n ; i++){
        cin>>ara[i];
        dif[i] = ara[i] - ara[i-1];
    }

    Build(1 , 1 , n);
    Build2(1 , 1 , n);

    for(i=1 ; i<=q ; i++){
        cin>>type>>l>>r;
        if(type == 1){
            ll al = Query(1 , 1 , n , l , r) , gc = 0LL;
            if(l < r)
                gc = Query2(1 , 1 , n , l+1 , r);
            gc = gcd(gc , al);
            cout<<gc<<endl;
        }
        else{
            cin>>x;
            ///Update main array
            Update(1 , 1 , n , l , r , x);

            ///Update difference array
            Update2(1 , 1 , n , l , x);
            if(r+1 <= n)
                Update2(1 , 1 , n , r+1 , -x);
        }
    }
}

int main()
{
    Solve();
    return 0;
}
/**
5 10
5 10 25 15 25
**/
