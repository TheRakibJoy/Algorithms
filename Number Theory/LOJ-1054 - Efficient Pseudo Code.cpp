#include<bits/stdc++.h>

#define perfect                 int main()
#define ll                      long long int
#define ull                     unsigned long long int
#define pii                     pair<int,int>
#define pll                     pair<ll,ll>
#define sc                      scanf
#define scin(x)                 sc("%d",&(x))
#define scin2(x,y)                sc("%d %d",&(x),&(y))
#define scln(x)                 sc("%lld",&(x))
#define scln2(x,y)                sc("%lld %lld",&(x),&(y))
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
#define intlimit                214748369
#define longlimit               922337203685477580
#define infinity                (1<<28)
#define gcd(a,b)                __gcd(a,b)
#define lcm(a,b)                ((a)*(b))/gcd(a,b)
#define mxx                     123456789
#define PI                      2*acos(0.0)
#define rep(i,a,b)              for(__typeof(i) i=a;i<=b;i++)
#define rev(i,a,b)              for(__typeof(i) i=a;i>=b;i--)

using namespace std;

struct node
{
    int p,a;
};
vector<int>Prime;
bool mark[1000009];
void sieve(int n)
{
    int i,j,limit=sqrt(n*1.0)+2;
    mark[1]=mark[0]=1;
    for(i=4; i<=n; i+=2)
        mark[i]=1;
    Prime.push_back(2);
    for(i=3; i<=n; i+=2)
    {
        if(!mark[i])
        {
            Prime.push_back(i);
            if(i<=limit)
            {
                for(j=i*i; j<=n; j+=(i*2))
                    mark[j]=1;
            }
        }
    }
}
vector<node>List;
node temp;
void Primefactorize(ll n)
{
    for(int i=0; Prime[i]*Prime[i]<=n && i<Prime.size(); i++)
    {
        int cnt=0;
        if(n%Prime[i] == 0)
        {
            while(n%Prime[i] == 0)
            {
                cnt++;
                n/=Prime[i];
            }
            temp.p=Prime[i];
            temp.a=cnt;
            List.pb(temp);
        }
    }
    if(n>1)
    {
        temp.p=n;
        temp.a=1;
        List.pb(temp);
    }
}
ll BigMod(ll a,ll b)
{
    if(b == 0)
        return 1%MOD;
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
ll SOD(ll n,ll m)
{
    Primefactorize(n);
    ll ans=1,upper,lower,temp;
    for(int i=0; i<List.size(); i++)
    {
        upper=BigMod(List[i].p,(List[i].a*m)+1)-1;
        lower=List[i].p-1;
        ans *= ((upper%MOD)*BigMod(lower,MOD-2))%MOD;
        ans = (ans+MOD)%MOD;
    }
    return ans;
}

int main()
{
    int t,T,i,j;
    ll n,m,p,sod;
    sieve(1000001);
    scin(T);
    RUN_CASE(t,T)
    {
        List.clear();
        scln2(n,m);
        sod = SOD(n,m);
        pf("Case %d: %lld\n",t,sod);
    }
    return 0;
}

