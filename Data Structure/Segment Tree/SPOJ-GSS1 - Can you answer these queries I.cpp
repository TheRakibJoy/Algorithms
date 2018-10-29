/** Maximum Sub Array Sum **/

#include<bits/stdc++.h>
#define Input                   freopen("in.txt","r",stdin)
#define Output                  freopen("out.txt","w",stdout)
#define ll                      long long int
#define ull                     unsigned long long int
#define pii                     pair<int,int>
#define pll                     pair<ll,ll>
#define sc                      scanf
#define scin(x)                 sc("%d",&(x))
#define scin2(x,y)                sc("%d %d",&(x),&(y))
#define scln(x)                 sc("%lld",&(x))
#define scln2(x,y)                sc("%lld %lld",&(x),&(y))
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
#define MOD                     100000007
#define CIN                     ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define RUN_CASE(t,T)           for(__typeof(t) t=1;t<=T;t++)
#define CASE(t)                 printf("Case %d: ",t)
#define CASEl(t)                printf("Case %d:\n",t)
#define intlimit                214748369
#define longlimit               922337203685477580
#define infinity                999999999
#define gcd(a,b)                __gcd(a,b)
#define lcm(a,b)                ((a)*(b))/gcd(a,b)
#define mxx                     123456789
#define PI                      2*acos(0.0)
#define rep(i,a,b)              for(__typeof(i) i=a;i<=b;i++)
#define rev(i,a,b)              for(__typeof(i) i=a;i>=b;i--)
using namespace std;
#define sz 50005
struct data
{
    ll sum,pref,suff,ans;
}tree[4*sz];
int ara[sz];
data combine(data left,data right)
{
    data res;
    res.sum=left.sum+right.sum;
    res.pref=max(left.pref,left.sum+right.pref);
    res.suff=max(right.suff,right.sum+left.suff);
    res.ans=max(max(left.ans,right.ans),left.suff+right.pref);
    return res;
}
data make_data(int val)
{
    data res;
    res.sum=val;
    res.pref=val;/** You must take minimum one element,thats why res.pref=val;res.suff=val;
    res.ans=val; otherwise,
    it will res.pref=max(0,val);res.suff=max(0,val);res.ans=max(0,val);**/
    res.suff=val;
    res.ans=val;
    return res;
}
void init(int node,int b,int e)
{
    if(b == e)
    {
        tree[node]=make_data(ara[b]);
        return;
    }
    int left=node*2;
    int right=left+1;
    int mid=(b+e)/2;
    init(left,b,mid);
    init(right,mid+1,e);
    tree[node]=combine(tree[left],tree[right]);
}
void update(int node,int b,int e,int idx,int val)
{
    if(idx>e || idx<b)
        return;
    if(b>=idx && e<=idx)
    {
        tree[node]=make_data(val);
        return;
    }
    int left=node*2;
    int right=left+1;
    int mid=(b+e)/2;
    update(left,b,mid,idx,val);
    update(right,mid+1,e,idx,val);
    tree[node]=combine(tree[left],tree[right]);
}
data query(int node,int b,int e,int i,int j)
{
    if(i>e || j<b)
        return make_data(-infinity);
    if(b>=i && e<=j)
    {
        return tree[node];
    }
    int left=node*2;
    int right=left+1;
    int mid=(b+e)/2;
    data p1=query(left,b,mid,i,j);
    data p2=query(right,mid+1,e,i,j);
    return combine(p1,p2);
}
int main()
{
    int i,j,x,y,n,q;
    scin(n);
    for(i=1;i<=n;i++)
        scin(ara[i]);
    init(1,1,n);
    scin(q);
//    update(1,1,n,1,5);
//    update(1,1,n,2,-3);
    for(i=1;i<=q;i++)
    {
        scin2(x,y);
        data res=query(1,1,n,x,y);
        pf("%lld\n",res.ans);
    }
    return 0;
}
