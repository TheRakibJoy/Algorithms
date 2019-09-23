#include<bits/stdc++.h>

#define Input                   freopen("in.txt","r",stdin)
#define Output                  freopen("out.txt","w",stdout)
#define ll                      long long int
#define ull                     unsigned long long int
#define pii                     pair<int,int>
#define pll                     pair<ll,ll>
#define sc                      scanf
#define scin(x)                 sc("%d",&(x))
#define scin2(x,y)              sc("%d %d",&(x),&(y))
#define scln(x)                 sc("%lld",&(x))
#define scln2(x,y)              sc("%lld %lld",&(x),&(y))
#define pf                      printf
#define all(a)                  (a.begin()),(a.end())
#define UNIQUE(X)               (X).erase(unique(all(X)),(X).end())
#define SORT_UNIQUE(c)          (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
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
#define intlimit                2147483690
#define longlimit               92233720368547758
#define infinity                (1<<28)
#define gcd(a,b)                __gcd(a,b)
#define lcm(a,b)                ((a)*(b))/gcd(a,b)
#define mxx                     123456789
#define PI                      2*acos(0.0)
#define rep(i,a,b)              for(__typeof(i) i=a;i<=b;i++)
#define rev(i,a,b)              for(__typeof(i) i=a;i>=b;i--)

using namespace std;
/**     toint, tostring, BigMod, Power , sieve, Primefactorize ,frequency in n!     **/
//ll toint(string s){ll n=0,k=1;for(int i=s.size()-1; i>=0; i--){n += ((s[i]-'0')*k);k*=10;}return n;}
//string tostring(ll x){string s="";while(x){s += (x%10)+'0';x/=10;}reverse(s.begin(),s.end());return s;}
//vector<ll>Prime;
//bool mark[10000003];
//void sieve(ll n){ll i,j;mark[1]=1;for(i=4; i<=n; i+=2)mark[i]=1;Prime.push_back(2);for(i=3; i<=n; i+=2){if(!mark[i]){Prime.push_back(i);if(i*i<=n){for(j=i*i; j<=n; j+=(i*2))mark[j]=1;}}}}
//map<ll,ll>Factor;
//void Primefactorize(ll n){for(ll i=0; i<Prime.size() && Prime[i]*Prime[i]<=n; i++){if(n%Prime[i] == 0){while(n%Prime[i] == 0){Factor[Prime[i]]++;n/=Prime[i];}}}if(n>1){Factor[n]++;}}
//ll frequency(ll n,ll factor)/** Frequency of a factor in n! **/{ll cnt=0;while(n){cnt += (n/factor);n /= factor;}return cnt;}
/**     Order Set       **/
//#include <ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;
//template<typename T> using orderset = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
//orderset<int> s ; //orderset<int>::iterator it ;
//orderset<int> X; //X.insert(1); //X.insert(2); //X.insert(4); //X.insert(8); //X.insert(16);
//cout<<*X.find_by_order(0)<<endl; // 2 //cout<<*X.find_by_order(2)<<endl; // 4 //cout<<*X.find_by_order(4)<<endl; // 16 //cout<<(end(X)==X.find_by_order(6))<<endl; // true
//cout<<X.order_of_key(-5)<<endl;  // 0 //cout<<X.order_of_key(1)<<endl;   // 0 //cout<<X.order_of_key(3)<<endl;   // 2 //cout<<X.order_of_key(4)<<endl;   // 2 //cout<<X.order_of_key(400)<<endl; // 5
///------------------Graph Moves-------------------
///const int fx[] = {+1,-1,+0,+0};
///const int fy[] = {+0,+0,+1,-1};
///const int fx[] = {+0,+0,+1,-1,-1,+1,-1,+1}; ///King's move
///const int fy[] = {-1,+1,+0,+0,+1,+1,-1,-1}; ///King's move
///const int fx[] = {-2,-2,-1,-1,+1,+1,+2,+2}; ///Knight's move
///const int fy[] = {-1,+1,-2,+2,-2,+2,-1,+1}; ///Knight's move

/** You've to spend at least Y TK for buying some product in range L to R.
    But you've to buy all product less than the price of the maximum cost of your bought product.
    Minimize the total cost you've to spend **/
#define sz 1000005
vector<ll>tree[4*sz],cumsum[4*sz];
ll sum=0,ara[sz];
void getSum(vector<ll> &v,ll id)
{
    for(ll i=0LL ; i<(ll)v.size() ; i++)
    {
        (i==0LL)?cumsum[id].pb(v[i]):cumsum[id].pb(cumsum[id].back()+v[i]);
    }
}
void Init(ll node,ll b,ll e)
{
    if(b == e)
    {
        tree[node].pb(ara[b]);
        cumsum[node].pb(ara[b]);
        return;
    }
    ll lft=node*2;
    ll rgt=lft+1;
    ll mid=(b+e)/2;
    Init(lft,b,mid);
    Init(rgt,mid+1,e);
    merge(tree[lft].begin(),tree[lft].end(),tree[rgt].begin(),tree[rgt].end(),back_inserter(tree[node]));
    getSum(tree[node], node);
}
ll Query(ll node,ll b,ll e,ll i,ll j,ll mintaken)
{
    if(i>e || j<b)
        return 0LL;
    if(b>=i && e<=j)
    {
        ll id = upper_bound(tree[node].begin(),tree[node].end(),mintaken)-tree[node].begin();
        if(id>=1 && id<=(ll)cumsum[node].size())
            return cumsum[node][id-1];
        else
            return 0;
    }
    ll lft=node*2;
    ll rgt=lft+1;
    ll mid=(b+e)/2;
    ll p1 = Query(lft,b,mid,i,j,mintaken);
    ll p2 = Query(rgt,mid+1,e,i,j,mintaken);
    return p1+p2;
}
ll Bin(ll n,ll x,ll y,ll val)
{
    ll lo=1,hi=1e18,mid,res=longlimit,temp;
    while(lo <= hi)
    {
        mid = (lo+hi)/2;
        temp = Query(1,1,n,x,y,mid);
        if(temp < val)
            lo = mid+1;
        else{
            hi = mid-1;
            res = min(res,temp);
        }
    }
    if(res == longlimit)
        return -1;
    else
        return res;
}
int main()
{
    ll i,j,k,t,T,n,q,l,r,val,ans;
    scln(n);
    rep(i,1LL,n)
    {
        scln(ara[i]);
        sum += ara[i];
    }
    Init(1LL,1LL,n);
    scln(q);
    rep(i,1,q)
    {
        sc("%lld %lld %lld",&l,&r,&val);
        ans = Bin(n,l,r,val);
        pf("%lld\n",ans);
    }
    return 0;
}

