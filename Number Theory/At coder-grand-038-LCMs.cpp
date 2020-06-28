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
#define MOD                     998244353
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

ll BigMod(ll a,ll b)
{
    if(b == 0)return 1%MOD;
    else if(b%2 == 0)
    {
        ll temp=BigMod(a,b/2);
        return ((temp%MOD)*(temp%MOD))%MOD;
    }
    else
    {
        return ((a%MOD)*BigMod(a,b-1)%MOD)%MOD;
    }
}

#define sz 1000005
ll ara[sz],fre[sz],divbyi[sz],gcdgreater[sz],exact[sz],pairsum[sz];

void Solve(int t)
{
    ll i,j,k,n,ans=0;
    scln(n);
    for(i=1 ; i<=n ; i++)
    {
        scln(ara[i]);
        fre[ara[i]]++;
    }
    /** Count number of elements those r divisible by i & calculate sum of pair whose GCD is i or multiple of i **/
    for(i=1 ; i<=1e6 ; i++)
    {
        ll sum = 0, sqsum = 0;
        for(j=i ; j<=1e6 ; j+=i)
        {
            divbyi[i] += fre[j];
            sum = (sum + (fre[j] * j)%MOD)%MOD;
            sqsum = (sqsum + (fre[j] * ((j*j)%MOD))%MOD)%MOD;
        }
        sum = (sum * sum)%MOD;
        ll temp = (sum - sqsum + MOD)%MOD;
        pairsum[i] = (temp * BigMod(2 , MOD-2))%MOD;
    }
    /** Count number of pairs those GCD is i or multiple of i **/
    for(i=1 ; i<=1e6 ; i++){
        if(divbyi[i] >= 1)
            gcdgreater[i] = (divbyi[i] * (divbyi[i]-1))/2;
    }
    /** Count exact number of pairs those GCD is equal to i & sum of pair whose GCD is exactly i **/
    for(i=1e6 ; i>=1 ; i--){
        exact[i] = gcdgreater[i];
        for(j=i+i ; j<=1e6 ; j+=i){
            exact[i] -= exact[j];
            pairsum[i] = (pairsum[i] - pairsum[j] + MOD)%MOD;
        }
        if(exact[i] == 0)
            continue;
        ll temp = (pairsum[i] * BigMod(i , MOD-2))%MOD;
        ans = (ans + temp + MOD)%MOD;
    }
    cout<<ans<<endl;
}

int main()
{
    int t,T;
    T = 1;
//    scin(T);
    RUN_CASE(t,T)
    {
        Solve(t);
    }
    return 0;
}


