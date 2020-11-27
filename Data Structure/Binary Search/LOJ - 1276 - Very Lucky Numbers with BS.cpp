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
#define coutv(v)                for(auto it:v)cout<<it<<' ';cout<<'\n';
#define cinv(v)                 for(auto &it:v)cin>>it;
#define srt(v)                  sort(v.begin(),v.end());
#define rsrt(v)                 sort(v.rbegin(),v.rend());
#define rvs(v)                  reverse(v.begin(),v.end());

using namespace std;

vl lucky,vlucky;
set<ll>st;

void buildLucky(ll isStart,ll pos,ll num)
{
    if(pos >= 13){
        lucky.pb(num);
        return;
    }

    if(!isStart)
        buildLucky(isStart , pos+1 , num);
    buildLucky(1 , pos+1 , (num*10)+4);
    buildLucky(1 , pos+1 , (num*10)+7);
}

void buildVLucky()
{
    for(auto it : lucky)
        st.insert(it);

    for(auto x : lucky){
        for(auto y : st){
            if(x * y <= 1e12)
                st.insert(x * y);
            else
                break;
        }
    }

    for(auto it : st)
        vlucky.pb(it);
}

void Solve(int t)
{
    ll i,j,k,lft,rgt,ans,lb,ub;
    scln2(lft , rgt);

    lb = lower_bound(vlucky.begin() , vlucky.end() , lft)-vlucky.begin();
    ub = upper_bound(vlucky.begin() , vlucky.end() , rgt)-vlucky.begin();
    ans = max(0LL , ub-lb);
    pf("Case %d: %lld\n",t,ans);
}

int main()
{
    buildLucky(0 , 1 , 0);
    buildVLucky();
    int t,T;
    scin(T);
    RUN_CASE(t,T)
    {
        Solve(t);
    }
    return 0;
}

/** Stuff u should look for
    * Avoid overflow
    * Corner(Small) case
    * Don't get stuck on one approach
    * Don't forget to clean used memory in each case
**/

