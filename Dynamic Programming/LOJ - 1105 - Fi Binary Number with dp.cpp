///****In the name of ALLAH, most Gracious, most Compassionate****//
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

/** IDEA: There're one 1-digit number, one 2-digit number, two 3-digit number, three
4-digit number, five 5-digit number. That means it's a Fibonacci series. **/

ll fib[50],fibsum[50];

void FuN()
{
    fib[1] = 1;
    fibsum[1] = fib[1];

    fib[2] = 1;
    fibsum[2] = fibsum[1]+fib[2];

    for(int i=3 ; ; i++){
        fib[i] = fib[i-1] + fib[i-2];
        fibsum[i] = fibsum[i-1] + fib[i];

        if(fibsum[i] >= 1e9){
            break;
        }
    }
}

pii findOut(ll n)
{
    pii ret;
    for(ll i=1 ; i<=50 ; i++){
        if(fibsum[i] >= n){
            int digit = i;
            int kth = n-fibsum[i-1];
            ret = {digit , kth};
            break;
        }
    }
    return ret;
}

void haveFuN(ll digit,ll kth)
{
    if(digit <= 0)
        return;
    if(kth == 1){
        pf("1");
        for(ll i=2 ; i<=digit ; i++)
            pf("0");
        pf("\n");
        return;
    }
    pf("1");
    pii pr = findOut(kth-1);
    ll faka = digit-1-pr.first;
    for(ll i=1 ; i<=faka ; i++)
        pf("0");
    haveFuN(pr.first , pr.second);
}


void Solve(int t)
{
    int i,j,k,n,kth,digit;
    scin(n);
    pii pr = findOut(n);
    digit = pr.first;
    kth = pr.second;

    pf("Case %d: ",t);
    haveFuN(digit , kth);
}

int main()
{
    FuN();
    int t,T;
    scin(T);
    RUN_CASE(t,T)
    {
        Solve(t);
    }
    return 0;
}

