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
#define CIN                     ios_base::sync_with_stdio(0);cin.tie(0);
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

bool Check(int mask,int pos)
{
    return (bool)(mask & (1<<pos));
}

int Set(int mask,int pos)
{
    return mask = (mask | (1<<pos));
}

int d,len,dp[1<<11][1002],fact[12],fre[12];
string s;

int FuN(int mask,int mod)
{
    int pos = __builtin_popcount(mask);
    if(pos >= len)
        return (mod == 0);
    if(dp[mask][mod] != -1)
        return dp[mask][mod];
    int ret = 0;
    for(int i=0 ; i<len ; i++){
        if(!Check(mask , i)){
            int digit = (s[i] - '0');
            ret += FuN(Set(mask , i) , (mod*10+digit)%d);
        }
    }
    return dp[mask][mod] = ret;
}

void Solve(int t)
{
    int i,j,k,ans;
    cin>>s>>d;
    len = (int)s.size();
    ms(dp , -1);
    ms(fre , 0);
    ans = FuN(0 , 0);

    for(i=0 ; i<len ; i++){
        int digit = s[i]-'0';
        fre[digit]++;
    }

    for(i=0 ; i<=9 ; i++){
        ans /= fact[fre[i]];
    }

    cout<<"Case "<<t<<": "<<ans<<endl;
}

void Factorial()
{
    fact[0] = 1;
    for(int i=1 ; i<12 ; i++)
        fact[i] = (i * fact[i-1]);
}

int main()
{
    CIN;
    int t,T;
    cin>>T;
    Factorial();
    RUN_CASE(t,T)
    {
        Solve(t);
    }
    return 0;
}

