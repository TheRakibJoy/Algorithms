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

ll BigMod(ll a,ll b,ll MOD)
{
    if(b == 0)return 1%MOD;
    else if(b%2 == 0)
    {
        ll temp=BigMod(a,b/2,MOD);
        return ((temp%MOD)*(temp%MOD))%MOD;
    }
    else
    {
        return ((a%MOD)*BigMod(a,b-1,MOD)%MOD)%MOD;
    }
}
ll a[15],m[15],M[15],y[15];

ll CRT(ll n)
{
    ll i,ans=0;

    M[0] = 1;
    rep(i,1,n)  M[0] *= m[i];

    rep(i,1,n)  M[i] = M[0]/m[i];

    rep(i,1,n)  y[i] = BigMod(M[i], m[i]-2, m[i]);

    rep(i,1,n)  ans = (ans + ((a[i] * ((M[i]*y[i])% M[0])) % M[0])) % M[0];
    return ans;
}

int main()
{
    ll i,j,k,t,T,n,ans;
    scln(T);
    RUN_CASE(t,T)
    {
        scln(n);
        rep(i,1,n)scln2(m[i] , a[i]);
        ans = CRT(n);
        pf("Case %lld: %lld\n",t,ans);
    }
    return 0;
}

