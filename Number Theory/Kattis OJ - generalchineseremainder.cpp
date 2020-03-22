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

/** CRT Template(Modulo values need not to be pairwise co-prime but careful about overflow) **/
ll ext_gcd(ll A,ll B,ll *X,ll *Y)
{
    ll x2, y2, x1, y1, x, y, r2, r1, q, r;
    x2 = 1; y2 = 0;
    x1 = 0; y1 = 1;
    for(r2=A, r1=B ; r1!=0 ; r2=r1, r1=r, x2=x1, y2=y1, x1=x, y1=y)
    {
        q = r2/r1;
        r = r2%r1;
        x = x2-(q*x1);
        y = y2-(q*y1);
    }
    *X = x2;
    *Y = y2;
    return r2;
}

ll a[100005],m[100005]; ///a-remainder ; m-modulo
pll CRTStrong(ll n)
{
    ll a1 = a[1], m1 = m[1];
    for(ll i=2 ; i<=n ; i++)    ///Merge the soln with remaining equation
    {
        ll a2 = a[i], m2 = m[i];

        ll g = gcd(m1, m2);
        if(a1%g != a2%g)    return {-1,-1}; ///No solution exist

        /** Merge the two equation **/
        ll p,q;
        ext_gcd(m1/g, m2/g, &p, &q);
        ll mod = m1 / g * m2;
        ll x = ( (__int128)a1 * (m2/g) % mod *q % mod + (__int128)a2 * (m1/g) % mod * p % mod ) % mod;    ///Careful about overflow ; This line can't be compiled in GCC compiler but don't worry. It'll accepted.

        /** Merged equation **/
        a1 = (x+mod)%mod;
        m1 = mod;
    }
    return {a1,m1};
}

int main()
{
    ll i,j,k,n,t,T;
    cin>>T;
    RUN_CASE(t,T)
    {
        rep(i,1,2)cin>>a[i]>>m[i];
        pll pr = CRTStrong(2);
        if(pr.first==-1 && pr.second==-1)
            pf("no solution\n");
        else
            cout<<pr.first<<' '<<pr.second<<endl;
    }
    return 0;
}
