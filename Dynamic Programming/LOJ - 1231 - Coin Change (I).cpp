/**
Bismillahir Rahmanir Rahim
MD. Iqbal Hossain Bappy
Dept. of CSE, CoU
**/

#include<bits/stdc++.h>

#define perfect                 int main()
#define ll                      long long int
#define ull                     unsigned long long int
#define pii                     pair<int,int>
#define pll                     pair<ll,ll>
#define sc                      scanf
#define scin(x)                 sc("%d",&(x))
#define scln(x)                 sc("%lld",&(x))
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
#define intlimit                2147483647;
#define longlimit               9223372036854775808
#define infinity                (1<<28)
#define gcd(a,b)                __gcd(a,b)
#define lcm(a,b)                ((a)*(b))/gcd(a,b)
#define mxx                     123456789
#define PI                      2*acos(0.0)
#define rep(i,a,b)              for(__typeof(i) i=a;i<=b;i++)
#define rev(i,a,b)              for(__typeof(i) i=a;i>=b;i--)

using namespace std;

///------------------Graph Moves-------------------
/// const int fx[] = {+1,-1,+0,+0};
/// const int fy[] = {+0,+0,+1,-1};
/// const int fx[] = {+0,+0,+1,-1,-1,+1,-1,+1}; ///King's move
/// const int fy[] = {-1,+1,+0,+0,+1,+1,-1,-1}; ///King's move
/// const int fx[] = {-2,-2,-1,-1,+1,+1,+2,+2}; ///Knight's move
/// const int fy[] = {-1,+1,-2,+2,-2,+2,-1,+1}; ///Knight's move

int coin[51],num[51];
int dp[51][1003];
int make,n;

int CoinChange(int i,int amount)
{
    if(i>=n)
    {
        if(amount == make)
            return 1;
        else
            return 0;
    }
    if(amount>make)
        return 0;
    if(amount == make)
        return 1;
    if(dp[i][amount] != -1)
        return dp[i][amount];
    int ret=0;
    for(int take=1;take<=num[i];take++)
    {
        if(amount+(coin[i]*take) <= make)
        {
            ret += CoinChange(i+1,(amount+(coin[i]*take)))%MOD;
        }
        else
            break;
    }
    ret += CoinChange(i+1,amount)%MOD;
    return dp[i][amount]=(ret%MOD);

}
perfect
{
    int t,T,i,co;
    scin(T);
    RUN_CASE(t,T)
    {
        sc("%d %d",&n,&make);
        ms(dp,-1);
        ms(coin,0);
        ms(num,0);
        for(i=0;i<n;i++)
            scin(coin[i]);
        for(i=0;i<n;i++)
            scin(num[i]);
        co=CoinChange(0,0)%MOD;
        pf("Case %d: %d\n",t,co);
    }
    return 0;
}

