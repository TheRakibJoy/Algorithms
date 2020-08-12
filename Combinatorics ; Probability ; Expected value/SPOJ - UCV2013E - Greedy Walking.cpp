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

ll BigMod(ll a,ll b)
{
    if(b == 0)return 1%MOD;
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

ll n,start[55],ed[55],dif[55],fact[100009];

void FuN()
{
    fact[0] = 1;
    for(int i=1 ; i<=1e5 ; i++)
        fact[i] = (i * fact[i-1])%MOD;
}

ll nCr(ll x,ll r)
{
    ll nom = fact[x];
    ll denom = (fact[r] * fact[x-r])%MOD;
    return (nom * BigMod(denom , MOD-2))%MOD;
}

void Solve(int t)
{
    ll i,j,k,ans,tot=0;
    rep(i,1,n)  scln(start[i]);
    for(i=1 ; i<=n ; i++)
    {
        scln(ed[i]);
        dif[i] = ed[i]-start[i];
        tot += dif[i];
    }
    ans = 1;
    for(i=1 ; i<n ; i++){
        ans = (ans * nCr(tot , dif[i]))%MOD;
        tot -= dif[i];
    }
    cout<<ans<<endl;
}

int main()
{
    FuN();
    while(1)
    {
        scln(n);
        if(n == 0)
            break;
        else
            Solve(1);
    }
    return 0;
}



