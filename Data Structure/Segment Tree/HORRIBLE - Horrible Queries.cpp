/** This problem is from SPOJ
LINK: http://www.spoj.com/problems/HORRIBLE/   **/

#include<bits/stdc++.h>

#define ll                      long long int
#define ull                     unsigned long long int
#define pii                     pair<int,int>
#define pll                     pair<ll,ll>
#define sc                      scanf
#define scin(x)                 sc("%d",&(x))
#define scln(x)                 sc("%lld",&(x))
#define pf                      printf
#define ms(a,b)                 memset(a,b,sizeof(a))
#define pb(a)                   push_back(a)
#define mp                      make_pair
#define db                      double
#define EPS                     10E-10
#define ff                      first
#define ss                      second
#define sqr(x)                  (x)*(x)
#define vi                      vector<int>
#define vl                      vector<ll>
#define vii                     vector<vector<int> >
#define vll                     vector<vector<ll> >
#define DBG                     pf("HI\n")
#define MOD                     1000000007
#define CIN                     ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define RUN_CASE(t,T)           for(__typeof(t) t=1;t<=T;t++)
#define CASE(t)                 printf("Case %d: ",t)
#define CASEl(t)                printf("Case %d:\n",t)
#define intlimit                2147483648
#define longlimit               9223372036854775808
#define infinity                (1<<28)
#define gcd(a,b)                __gcd(a,b)
#define lcm(a,b)                ((a)*(b))/gcd(a,b)
#define mx                      123456789
#define PI                      2*acos(0.0)
#define rep(i,a,b)              for(__typeof(i) i=a;i<=b;i++)
#define rev(i,a,b)              for(__typeof(i) i=a;i>=b;i--)

using namespace std;

///------------------Graph Moves-------------------
/// const int fx[] = {+1,-1,+0,+0};
/// const int fy[] = {+0,+0,+1,-1};
/// const int fx[] = {+0,+0,+1,-1,-1,+1,-1,+1}; ///King's move
/// const int fy[] = {-1,+1,+0,+0,+1,+1,-1,-1}; ///King's move
/// const int fx[] = {-2,-2,-1,-1,+1,+1,+2,+2}; ///Knight's move
/// const int fy[] = {-1,+1,-2,+2,-2,+2,-1,+1}; ///Knight's move

#define Size 100005
ll arr[Size];
struct info
{
    ll prop=0,sum=0;
};
info tree[Size*3];
void init(ll node,ll b,ll e)
{
    if(b == e)
    {
        tree[node].sum=arr[b];
        return;
    }
    ll left=node*2;
    ll right=left+1;
    ll mid=(b+e)/2;
    init(left,b,mid);
    init(right,mid+1,e);
    tree[node].sum=tree[left].sum+tree[right].sum;
}
void update(ll node,ll b,ll e,ll x,ll y,ll value)
{
    if(b>y || e<x)
        return;
    if(b>=x && e<=y)
    {
        tree[node].sum+=((e-b+1)*value);
        tree[node].prop+=value;
        return;
    }
    ll left=node*2;
    ll right=left+1;
    ll mid=(b+e)/2;
    update(left,b,mid,x,y,value);
    update(right,mid+1,e,x,y,value);
    tree[node].sum=tree[left].sum+tree[right].sum+(e-b+1)*tree[node].prop;
}
ll query(ll node,ll b,ll e,ll x,ll y,ll carry=0)
{
    if(b>y || e<x)
        return 0;
    if(b>=x && e<=y)
        return tree[node].sum+carry*(e-b+1);
    ll left=node*2;
    ll right=left+1;
    ll mid=(b+e)/2;
    ll p1=query(left,b,mid,x,y,carry+tree[node].prop);
    ll p2=query(right,mid+1,e,x,y,carry+tree[node].prop);
    return p1+p2;
}
int main()
{
    ll i,j,k,T,p,q,v,n,c,cmd,co;
    scln(T);
    for(i=1;i<=T;i++)
    {
        scanf("%lld %lld",&n,&c);
        ms(arr,0);
        ms(tree,0);
        init(1,1,n);
        for(j=1;j<=c;j++)
        {
            scln(cmd);
            if(cmd == 0)
            {
                scanf("%lld %lld %lld",&p,&q,&v);
                update(1,1,n,p,q,v);
            }
            else
            {
                scanf("%lld %lld",&p,&q);
                co=query(1,1,n,p,q);
                printf("%lld\n",co);
            }
        }
    }
    return 0;
}
