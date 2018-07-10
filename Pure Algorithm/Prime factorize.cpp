/**
Bismillahir Rahmanir Rahim
MD. Iqbal Hossain Bappy
Dept. of CSE, CoU
**/

#include<bits/stdc++.h>
#include<queue>
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

int mark[10000009];
int n=10000000;
vector<int>prime;
void sieve()
{
    int i,j,limit=sqrt(n*1.0)+2;
    mark[1]=1;
    prime.pb(2);
    for(i=4;i<=n;i+=2)
        mark[i]=1;
    for(i=3;i<=n;i+=2)
    {
        if(!mark[i])
        {
            prime.pb(i);
            if(i <= limit)
            {
                for(j=i*i;j<=n;j+=(2*i))
                    mark[j]=1;
            }
        }
    }
}

vector<int>List;
void PrimeFactorize(int n)
{
    int i,limit=sqrt(n*1.0)+2;
    for(i=0;prime[i]<=limit;i++)
    {
        if(n%prime[i] == 0)
        {
            while(n%prime[i] == 0)
            {
                n/=prime[i];
                List.pb(prime[i]);
            }
        }
    }
    if(n>1)
        List.pb(n);
}
int main()
{
    int i,j;
    sieve();
    PrimeFactorize(114);
    for(i=0;i<List.size();i++)
        cout<<List[i]<<' ';
    return 0;
}

