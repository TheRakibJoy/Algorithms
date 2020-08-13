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
#define longlimit               9223372036854775800
#define infinity                (1<<28)
#define gcd(a,b)                __gcd(a,b)
#define lcm(a,b)                (a)*(b)/gcd(a,b)
#define mxx                     123456789
#define PI                      2*acos(0.0)
#define rep(i,a,b)              for(__typeof(i) i=a;i<=b;i++)
#define rev(i,a,b)              for(__typeof(i) i=a;i>=b;i--)

using namespace std;

///Good problem of Hockey stick identity in pascal's triangle

ll BigMod(ll a,ll b)
{
    if(b == 0)  return 1%MOD;
    else if(b%2 == 0)
    {
        ll temp=BigMod(a,b/2);
        return ((temp%MOD)*(temp%MOD))%MOD;
    }
    else
    {
        return ((a%MOD)*BigMod(a,b-1)%MOD)%MOD;
    }
}

ll fact[10000005];

void FuN()
{
    fact[0] = 1;
    for(ll i=1 ; i<=1e7 ; i++)
        fact[i] = (i * fact[i-1])%MOD;
}

ll nCr(ll n,ll r)
{
    ll nom = fact[n];
    ll denom = (fact[r] * fact[n-r])%MOD;
    ll ans = (nom * BigMod(denom, MOD-2))%MOD;
    return ans;
}

void Solve(int t)
{
    ll i,j,k,n,ans=0;
    cin>>n>>k;
    ans = (2 * (nCr(n+k+1, k+2) - n + MOD)%MOD)%MOD;
    ans = (ans+n)%MOD;
    cout<<ans%MOD<<endl;
}

int main()
{
    FuN();
    int t,T;
    scin(T);
    RUN_CASE(t,T)
    {
        Solve(t);
    }
    return 0;
}



