/** Problem Link: http://www.lightoj.com/volume_showproblem.php?problem=1082**/

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
ll tree[Size*3];
void init(ll node,ll b,ll e)
{
    if(b == e)
    {
        tree[node]=arr[b];
        return;
    }
    ll left=node*2;
    ll right=left+1;
    ll mid=(b+e)/2;
    init(left,b,mid);
    init(right,mid+1,e);
    tree[node]=tree[left]+tree[right];
}
ll query(ll node,ll b,ll e,ll lft,ll rgt)
{
    if(b>rgt || e<lft)
        return 0;
    if(b>=lft && e<=rgt)
    {
        return tree[node];
    }
    ll left=node*2;
    ll right=left+1;
    ll mid=(b+e)/2;
    ll q1=query(left,b,mid,lft,rgt);
    ll q2=query(right,mid+1,e,lft,rgt);
    return q1+q2;
}
void update(ll node,ll b,ll e,ll x,ll newvalue)
{
    if(x<b || x>e)
        return;
    if(b>=x && e<=x)
    {
        tree[node]=newvalue;
        return;
    }
    ll left=node*2;
    ll right=left+1;
    ll mid=(b+e)/2;
    update(left,b,mid,x,newvalue);
    update(right,mid+1,e,x,newvalue);
    tree[node]=tree[left]+tree[right];
}
int main()
{
    ll T,n,q,i,j,value,co,sack,loc,x,y;
    scln(T);
    for(i=1; i<=T; i++)
    {
        sc("%lld %lld",&n,&q);
        ms(arr,0);
        ms(tree,0);
        for(j=1; j<=n; j++)
            scln(arr[j]);
        init(1,1,n);
        printf("Case %lld:\n",i);
        for(j=1; j<=q; j++)
        {
            scln(sack);
            if(sack == 1)
            {
                scln(loc);
                loc++;
                printf("%lld\n",arr[loc]);
                update(1,1,n,loc,0);
                arr[loc] = 0;
            }
            else if(sack == 2)
            {
                sc("%lld %lld",&loc,&value);
                loc++;
                co=(arr[loc]+value);
                update(1,1,n,loc,co);
                arr[loc] = co;
            }
            else
            {
                sc("%lld %lld",&x,&y);
                x++;y++;
                co=query(1,1,n,x,y);
                printf("%lld\n",co);
            }
        }
    }
    return 0;
}
