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

int n,ara[305];
double dp[301][301][301];

/** State-1: Number of index i such that a[i] = 1;
    State-2: Number of index i such that a[i] = 2;
    State-3: Number of index i such that a[i] = 3;  **/

double FuN(int cnt1,int cnt2,int cnt3)
{
    if(cnt1+cnt2+cnt3 == 0)
        return 0.0;
    if(dp[cnt1][cnt2][cnt3] > 0.0)
        return dp[cnt1][cnt2][cnt3];

    int tot = cnt1+cnt2+cnt3;
    int zero = n - tot;
    int denom = n - zero;
    int opt = 0;

    double ret1=0.0 , ret2=0.0 , ret3=0.0;
    if(cnt1 > 0){
        ret1 = (n*1.0) + 1.0 * tot * FuN(cnt1-1 , cnt2 , cnt3);
        ret1 /= denom;
        ret1 *= cnt1;
    }
    if(cnt2 > 0){
        ret2 = (n*1.0) + 1.0 * tot * FuN(cnt1+1 , cnt2-1 , cnt3);
        ret2 /= denom;
        ret2 *= cnt2;
    }
    if(cnt3 > 0){
        ret3 = (n*1.0) + 1.0 * tot * FuN(cnt1 , cnt2+1 , cnt3-1);
        ret3 /= denom;
        ret3 *= cnt3;
    }
    return dp[cnt1][cnt2][cnt3] = (ret1 + ret2 + ret3)/tot;
}

void Solve(int t)
{
    int cnt[4] = {0 , 0 , 0 , 0};
    double ans;
    scin(n);
    for(int i=1 ; i<=n ; i++){
        scin(ara[i]);
        cnt[ara[i]]++;
    }
    ans = FuN(cnt[1] , cnt[2] , cnt[3]);
    pf("%0.10f\n",ans);
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



