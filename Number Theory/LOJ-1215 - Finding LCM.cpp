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
ll POW(ll B,ll P)
{
    if(P==0)
        return 1;
    if(P&1)
        return B*POW(B,P-1);
    else
        return sqr(POW(B,P/2));
}
vector<int>Prime;
bool mark[1000009];
void sieve(int n)
{
    int i,j,limit=sqrt(n*1.0)+2;
    mark[1]=1;
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
map<ll,ll>m1;
map<ll,ll>m2;
set<ll>st1;
set<ll>st2;
set<ll>::iterator it;
void PrimefactorizeAB(ll n)
{
    ll cnt;
    for(int i=0; Prime[i]*Prime[i]<=n && i<Prime.size(); i++)
    {
        if(n%Prime[i] == 0)
        {
            cnt=0;
            while(n%Prime[i] == 0)
            {
                cnt+=1;
                n/=Prime[i];
            }
            st1.insert(Prime[i]);
            m1[Prime[i]]=max(m1[Prime[i]],cnt);
        }
    }
    cnt=0;
    if(n>1)
    {
        st1.insert(n);
        cnt+=1;
        m1[n]=max(m1[n],cnt);
    }
}
void PrimefactorizeL(ll n)
{
    ll cnt;
    for(int i=0; Prime[i]*Prime[i]<=n && i<Prime.size(); i++)
    {
        if(n%Prime[i] == 0)
        {
            cnt=0;
            while(n%Prime[i] == 0)
            {
                cnt+=1;
                n/=Prime[i];
            }
            st2.insert(Prime[i]);
            m2[Prime[i]]=max(m2[Prime[i]],cnt);
        }
    }
    cnt=0;
    if(n>1)
    {
        cnt+=1;
        st2.insert(n);
        m2[n]=max(m2[n],cnt);
    }
}
bool check()
{
    for(it=st1.begin() ; it!=st1.end() ; it++)
    {
        if(m2[*it] < m1[*it])
            return false;
    }
    return true;
}

int main()
{
    sieve(1000007);
    int i,j,t,T;
    ll l,c,temp,a,b;
    scin(T);
    RUN_CASE(t,T)
    {
        c=1;
        sc("%lld %lld %lld",&a,&b,&l);
        PrimefactorizeAB(a);
        PrimefactorizeAB(b);
        PrimefactorizeL(l);
        if(check()==false)
            pf("Case %d: impossible\n",t);
        else
        {
            for(it=st2.begin(); it!=st2.end(); it++)
            {
                if(m2[*it]>m1[*it])
                {
                    temp=(ll)*it;
                    c *= POW(temp,m2[temp]);
                }
            }
            pf("Case %d: %lld\n",t,c);
        }
        m1.clear();
        m2.clear();
        st1.clear();
        st2.clear();
    }
    return 0;
}
