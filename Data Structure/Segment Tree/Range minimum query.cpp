/** This is the range minimum query with lazy prop **/

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
    ll prop,sum;
}tree[Size*3];
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
    tree[node].sum=min(tree[left].sum,tree[right].sum);
}
void update(ll node,ll b,ll e,ll x,ll y,ll value)
{
    if(x>e || y<b)
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
    tree[node].sum=min(tree[left].sum,tree[right].sum)+(e-b+1)*tree[node].prop;
}
ll query(ll node,ll b,ll e,ll x,ll y,ll carry=0)
{
    if(x>e || y<b)
        return intlimit;
    if(b>=x && e<=y)
        return tree[node].sum+carry*(e-b+1);
    ll left=node*2;
    ll right=left+1;
    ll mid=(b+e)/2;
    ll p1=query(left,b,mid,x,y,carry+tree[node].prop);
    ll p2=query(right,mid+1,e,x,y,carry+tree[node].prop);
    return min(p1,p2);
}

int main()
{
    ll n,i,j,k,x,y,co,value,cmd;
    scln(n);
    for(i=1;i<=n;i++)
        scln(arr[i]);
    init(1,1,n);
    while(1)
    {
        scln(cmd);
        if(cmd == 1)
        {
            scanf("%lld %lld",&x,&y);
            co=query(1,1,n,x,y);
            printf("Minimum value = %lld\n",co);
        }
        else if(cmd == 2)
        {
            scanf("%lld %lld",&x,&y);
            scln(value);
            update(1,1,n,x,y,value);
        }
        else
            break;
    }
    return 0;
}

