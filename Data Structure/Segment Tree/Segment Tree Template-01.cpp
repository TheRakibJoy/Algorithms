/**
Standard Segment Tree Template-01

Problem:    Circular Range Minimum Query with Lazy propagation
You are given circular array a0,a1,...,an-1. There are two types of operations with it:
1.  inc(left,right,val) — this operation increases each element on the segment [left,right] (inclusively) by val;
2.  RMQ(left,right) — this operation returns minimal value on the segment [left,right] (inclusively).
Assume segments to be circular, so if n = 5 and left=3,right=1, it means the index sequence: 3,4,0,1.
Write program to process given sequence of operations.
**/
#define sz 400005
ll ara[sz];
ll lazy[4*sz],tree[4*sz];

void push_down(ll node,ll b,ll e)
{
    tree[node] += lazy[node];
    if(b != e){
        lazy[node*2] += lazy[node];
        lazy[node*2+1] += lazy[node];
    }
    lazy[node] = 0;
}
void Build(ll node,ll b,ll e)   /** Build Tree for Range Minimum Query **/
{
    if(b == e){
        tree[node] = ara[b];
        return;
    }
    ll mid = (b+e)/2;
    ll lft = node*2;
    ll rgt = lft+1;
    Build(lft , b , mid);
    Build(rgt , mid+1 , e);
    tree[node] = min(tree[lft] , tree[rgt]);
}
void Update(ll node,ll b,ll e,ll i,ll j,ll val)     /** Increase all the element in a range **/
{
    if(lazy[node] != 0)
        push_down(node , b , e);
    if(i>e || j<b)
        return;
    if(b>=i && e<=j){
        tree[node] += val;
        if(b != e){
            lazy[node*2] += val;
            lazy[node*2+1] += val;
        }
        return;
    }
    ll lft = node*2;
    ll rgt = lft+1;
    ll mid = (b+e)/2;
    Update(lft , b , mid , i , j , val);
    Update(rgt , mid+1 , e , i , j , val);
    tree[node] = min(tree[lft] , tree[rgt]);
}
ll Query(ll node,ll b,ll e,ll i,ll j)   /** Range Minimum Query **/
{
    if(i>e || j<b)
        return longlimit;
    if(lazy[node] != 0)
        push_down(node , b , e);
    if(b>=i && e<=j)
        return tree[node];
    ll lft = node*2;
    ll rgt = lft+1;
    ll mid = (b+e)/2;
    ll p1 = Query(lft , b , mid , i , j);
    ll p2 = Query(rgt , mid+1 , e , i , j);
    return min(p1 , p2);
}

int main()
{
    ll i,j,k,n,q,lft,rgt,val,temp,ans;
    scln(n);
    for(i=1 ; i<=n ; i++)
        scln(ara[i]);
    for(i=n+1 ; i<=2*n ; i++)
        ara[i] = ara[i-n];

    Build(1 , 1 , n*2);
    scln(q);
    getchar();
    char str[50];
    for(i=1 ; i<=q ; i++){
        string s = "";
        gets(str);
        ll len = strlen(str);
        for(j=0 ; j<len ; j++)
            s += str[j];

        vl v;
        stringstream ss(s);
        while(ss >> temp){
            v.pb(temp);
        }
        lft = 1+v[0];
        rgt = 1+v[1];
        if((ll)v.size() == 3){
            val = v[2];
            if(lft <= rgt){
                Update(1 , 1 , n*2 , lft , rgt , val);
                Update(1 , 1 , n*2 , lft+n , rgt+n , val);
            }
            else{
                Update(1 , 1 , n*2 , lft , rgt+n , val);
                Update(1 , 1 , n*2 , 1 , rgt  , val);
                Update(1 , 1 , n*2 , lft+n , n*2 , val);
            }
        }
        else{
            if(lft <= rgt)
                ans = Query(1 , 1 , 2*n , lft , rgt);
            else
                ans = Query(1 , 1 , 2*n , lft , rgt+n);
            pf("%I64d\n",ans);
        }
    }
    return 0;
}


