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
#define intlimit                214748369
#define longlimit               92233720368547758
#define infinity                (1<<28)
#define gcd(a,b)                __gcd(a,b)
#define lcm(a,b)                ((a)*(b))/gcd(a,b)
#define mxx                     123456789
#define PI                      2*acos(0.0)
#define rep(i,a,b)              for(__typeof(i) i=a;i<=b;i++)
#define rev(i,a,b)              for(__typeof(i) i=a;i>=b;i--)

using namespace std;

bool mark[1000005];
int SP[1000005];        /** Here we store smallest factor for each number **/
vector<int> Prime;
void Sieve(int n)
{
    long long int i,j;
    mark[1]=1;
    for(i=4 ; i<=n ; i+=2){
        mark[i]=1;
        SP[i]=2;
    }
    Prime.push_back(2);
    SP[1]=1;
    SP[2]=2;
    for(i=3 ; i<=n ; i+=2)
    {
        if(!mark[i])
        {
            Prime.push_back(i);
            SP[i]=i;
            if(i*i <= n)    /** Can be overflow **/
            {
                for(j=i*i ; j<=n ; j+=(i*2)){
                    mark[j]=1;
                    if(!SP[j])SP[j]=i;
                }
            }
        }
    }
}
set<int>Factor;
int getFactor(int n)       /** It will works when prime till n is generated **/
{
    Factor.clear();
    while(n != 1)
    {
        Factor.insert(SP[n]);
        n/=SP[n];
    }
    return Factor.size();
}
int main()
{
    int i,j,n;
    Sieve(1000002);
    while(1)
    {
        scin(n);
        if(n == 0)
            break;
        pf("%d : %d\n",n,getFactor(n));
    }
    return 0;
}

