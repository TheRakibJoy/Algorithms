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
#define coutv(v)                for(auto it:v)cout<<it<<' ';cout<<endl;
#define cinv(v)                 for(auto &it:v)cin>>it;
#define srt(v)                  sort(v.begin(),v.end());
#define rsrt(v)                 sort(v.rbegin(),v.rend());
#define rvs(v)                  reverse(v.begin(),v.end());

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

#define sz 2009
ll dp[sz],fact[sz],indeg[sz],vis[sz],subtree[sz];
vl graph[sz];

void Clean()
{
    for(int i=0 ; i<sz-5 ; i++){
        vis[i] = subtree[i] = indeg[i] = 0;
        graph[i].clear();
    }
}

void Factorial()
{
    fact[0] = 1LL;
    for(ll i=1 ; i<=2000 ; i++)
        fact[i] = (i * fact[i-1])%MOD;
}

void DFS(int u)
{
    vis[u] = 1;
    subtree[u] = 1;
    for(auto v : graph[u])
    {
        if(!vis[v])
        {
            DFS(v);
            subtree[u] += subtree[v];
        }
    }
}

ll FuN(ll u)
{
    if(graph[u].size() == 0)
        return dp[u] = 1LL;

    if(dp[u] != -1)
        return dp[u];

    ll ret = 1 , totchild = subtree[u] - 1 , nom = fact[totchild] , denom = 1;
    for(auto v : graph[u]){
        denom = (denom * fact[subtree[v]])%MOD;
        nom = (nom * FuN(v))%MOD;
    }
    ret = (nom * BigMod(denom , MOD-2))%MOD;
    return dp[u] = ret;
}

void Solve(int t)
{
    ll i,j,k,n,u,v,src=1;
    scln(n);
    for(i=1 ; i<n ; i++){
        scln2(u , v);
        graph[u].pb(v);
        indeg[v]++;
    }
    for(i=1 ; i<=n ; i++){
        if(indeg[i] == 0){
            src = i;
            break;
        }
    }
    DFS(src);

    ms(dp , -1);
    ll ans = FuN(src);

    pf("Case %d: %lld\n",t,ans);
    Clean();
}

int main()
{
    Factorial();
    int t,T;
    scin(T);
    RUN_CASE(t,T)
    {
        Solve(t);
    }
    return 0;
}
