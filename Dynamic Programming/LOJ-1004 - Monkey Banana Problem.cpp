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

#define inf 1<<28;
int mat[200][200];
int dp[200][200];
//int r=200,c=200;
int fun(int i,int j,int n)
{
    if(dp[i][j] != -1)
        return dp[i][j];
    int ret=-inf;
    if((i>=0 && i<(n-1) && j>=0 && j<n))
    {
        ret = max(ret,fun(i+1,j,n)+mat[i][j]);
        ret = max(ret,fun(i+1,j+1,n)+mat[i][j]);
        return dp[i][j]=ret;
    }
    else if(i>=(n-1) && i<(2*n - 1) && j>=0 && j<n)
    {
        ret = max(ret,fun(i+1,j,n)+mat[i][j]);
        ret = max(ret,fun(i+1,j-1,n)+mat[i][j]);
        return dp[i][j]=ret;
    }
    else
        return 0;
}

int main()
{
    int t,T,n,i,j,co;
    scin(T);
    RUN_CASE(t,T)
    {
        co=0;
        ms(dp,-1);
        ms(mat,0);
        scin(n);
        for(i=0; i<n; i++)
        {
            for(j=0; j<=i; j++)
                scin(mat[i][j]);
        }
        for(i=n; i<(2*n)-1; i++)
        {
            for(j=0; j<(2*n-1)-i; j++)
            {
                scin(mat[i][j]);
            }
        }
//        for(i=0;i<(2*n)-1;i++)
//        {
//            for(j=0;j<n;j++)
//                pf("%d\t",mat[i][j]);
//            pf("\n");
//        }
        co=fun(0,0,n);
        pf("Case %d: %d\n",t,co);
    }
    return 0;
}

