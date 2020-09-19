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

double p[105],dp[105][10005];
int cost[105];

void Solve(int t)
{
    int i,j,k,n,ans=0;
    double totp;
    sc("%lf %d",&totp,&n);
    for(i=1 ; i<=n ; i++)
        sc("%d %lf",&cost[i],&p[i]);
    ///dp[i][j] means minimum probability of getting caught for making j money considering ith to nth item

    /** Base Case **/
    for(i=0 ; i<=n+2 ; i++){
        for(j=0 ; j<=(n*100)+2 ; j++)
            dp[i][j] = 1.0;
    }
    dp[n+1][0] = 0.0;

    /** DP **/
    for(i=n ; i>=1 ; i--){
        for(j=0 ; j<=n*100 ; j++){
            dp[i][j] = min(dp[i][j] , dp[i+1][j]);
            double already = dp[i+1][j - cost[i]];
            dp[i][j] = min(dp[i][j] , already + (1.0 - already)*p[i]);
        }
    }

    for(j=n*100 ; j>=0 ; j--){
        if(dp[1][j] < totp){
            ans = j;
            break;
        }
    }
    pf("Case %d: %d\n",t,ans);
}

int main()
{
    int t,T;
    cin>>T;
    RUN_CASE(t,T)
    {
        Solve(t);
    }
    return 0;
}



