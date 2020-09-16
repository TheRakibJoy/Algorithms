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


///Use ll to avoid integer overflow

struct info
{
    ll h,p;
    info(){}
    info(ll _h,ll _p)
    {
        h = _h;
        p = _p;
    }
}ara[5005];

bool cmp(info p1,info p2)
{
    return (p2.h+p2.p) > (p1.h+p1.p);
}

ll n,dp[5005][5005];
/** dp[i][j] means minimum needed cost for making score j by attaching i as last item **/

void Solve(int t)
{
    ll i,j,k,ans=1,h,p;
    cin>>n;
    for(i=1 ; i<=n ; i++){
        cin>>h>>p;
        ara[i] = info(h , p);
    }
    sort(ara+1 , ara+n+1 , cmp);

    for(i=0 ; i<=n ; i++){
        for(j=0 ; j<=n ; j++)
            dp[i][j] = 1e18;
    }

    for(i=1 ; i<=n ; i++)   dp[i][1] = ara[i].p;

    for(j=2 ; j<=n ; j++){
        ll mn = longlimit;  ///Minimum cost for making score j-1 considering 1 to ith position
        for(i=1 ; i<j ; i++)
            mn = min(mn , dp[i][j-1]);
        for(i=j ; i<=n ; i++){
            if(mn <= ara[i].h){
                dp[i][j] = min(dp[i][j] , mn+ara[i].p);
                ans = max(ans , j);
            }
            mn = min(mn , dp[i][j-1]);
        }
    }
    cout<<ans<<endl;
}

int main()
{
    int t,T;
    T = 1;
//    cin>>T;
    RUN_CASE(t,T)
    {
        Solve(t);
    }
    return 0;
}



