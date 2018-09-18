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
#define MOD                     100000007
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

ll toint(string s)
{
    ll n=0,k=1;
    for(int i=s.size()-1; i>=0; i--)
    {
        n += ((s[i]-'0')*k);
        k*=10;
    }
    return n;
}
string tostring(ll n)
{
    string s="";
    ll x;
    while(n > 0)
    {
        x=n%10;
        s +=(char)(x+'0');
        n/=10;
    }
    reverse(s.begin(),s.end());
    return s;
}
int main()
{
    int i,j,t,T;
    ll a,b,rem,div;
    scin(T);
    RUN_CASE(t,T)
    {
        string s1,s2,temp;
        cin>>s1;
        s2="0";
        scln(b);
        b = fabs(b);
        if(s1[0] == '-')
            i=1;
        else
            i=0;
        a=toint(s2);
        for(;i<s1.size();)
        {
            if(b>a)
            {
                s2 += s1[i++];
                a=toint(s2);
            }
            else
            {
                if(a%b == 0)
                {
                    div=a/b;
                    a = a-(div*b);
                    s2=tostring(a);
                    s2 += s1[i++];
                }
                else
                {
                    div=a/b;
                    a = a-(div*b);
                    s2=tostring(a);
                }
            }
        }
        a=toint(s2);
        if(a%b==0)
            pf("Case %d: divisible\n",t);
        else
            pf("Case %d: not divisible\n",t);
    }
    return 0;
}
