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

int value[105],cnt[105],used[100005],dp[100005];

void Solve(int t)
{
    int i,j,k,n,m,ans=0;
    ms(used , 0);
    ms(dp , 0);
    scin2(n , m);
    for(i=1 ; i<=n ; i++)   scin(value[i]);
    for(i=1 ; i<=n ; i++)   scin(cnt[i]);

    dp[0] = 1;
    for(i=1 ; i<=n ; i++){
        for(j=value[i] ; j<=m ; j++){
            if(!dp[j] && dp[j-value[i]] && used[j-value[i]]+1 <= cnt[i]){
                dp[j] = 1;
                ans++;
                used[j] = 1+used[j - value[i]];
            }
        }
        ms(used , 0);
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



