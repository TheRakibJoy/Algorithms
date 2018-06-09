/**
Bismillahir Rahmanir Rahim
MD. Iqbal Hossain Bappy
Dept. of CSE, CoU
**/

#include<bits/stdc++.h>
#include<queue>
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
#define MOD                     1000000007
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

int n;
int CAP,cost[1003],weight[1003],dp[1003][32];
void mss(void)
{
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=31;j++)
            dp[i][j]=-1;
    }
}
void COST(void)
{
    for(int i=0;i<=n;i++)
        cost[i]=0;
}
void WGT(void)
{
    for(int i=0;i<=n;i++)
        weight[i]=0;
}
int knapsack(int i,int w)
{
    int profit1,profit2;
    if(i >= n+1)
        return 0;
    if(w+weight[i] <= CAP)
    {
        if(dp[i][w] > 0)
        {
            return dp[i][w];
        }
        else
        {
            profit1=cost[i]+knapsack(i+1,w+weight[i]);
        }
    }
    else
    {
        profit1=0;
    }
    profit2=knapsack(i+1,w);
    return dp[i][w] = max(profit1,profit2);
}

perfect
{
    int t,T,i,j,g,co=0;
    scin(T);
    RUN_CASE(t,T)
    {
        co=0;
        ms(dp,-1);
        COST();
        WGT();
        scin(n);
        for(i=1;i<=n;i++)
            sc("%d %d",&cost[i],&weight[i]);
        scin(g);
        for(i=1;i<=g;i++)
        {
            scin(CAP);
            co+=knapsack(1,0);
            mss();
        }
        pf("%d\n",co);
    }
    return 0;
}

