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

#define sz 50009
vi graph[sz];
map<pii , int>cost;

///MST Part
struct edge
{
    int u,v,cost;
    edge(){}
    edge(int _u,int _v,int _cost)
    {
        u = _u;
        v = _v;
        cost = _cost;
    }
    bool operator < (const edge &p)const{
        return cost < p.cost;
    }
};
vector<edge>ed;

int par[sz];
void makeSet(int n)
{
    for(int i=1 ; i<=n ; i++)
        par[i] = i;
}

int Find(int x)
{
    if(par[x] == x)
        return x;
    return par[x] = Find(par[x]);
}

void MST(int n)
{
    sort(ed.begin() , ed.end());
    makeSet(n);
    int cnt=0 , sum=0;
    for(int i=0 ; i<(int)ed.size() ; i++){
        int u = Find(ed[i].u);
        int v = Find(ed[i].v);
        if(u != v){
            par[u] = v;
            cnt++;

            graph[ed[i].u].pb(ed[i].v);
            graph[ed[i].v].pb(ed[i].u);
            cost[{ed[i].u , ed[i].v}] = ed[i].cost;
            cost[{ed[i].v , ed[i].u}] = ed[i].cost;
        }
        if(cnt == n-1)
            break;
    }
}

///LCA Part
int level[sz],parent[sz];

void DFS(int u,int depth,int parr)
{
    level[u] = depth;
    parent[u] = parr;
    for(int v : graph[u]){
        if(v != parr)
            DFS(v , 1+depth , u);
    }
}

struct info
{
    int par,mx;
    info(){}
    info(int _par,int _mx)
    {
        par = _par;
        mx = _mx;
    }
}sptable[sz][20];

void LCA_Init(int n)
{
    for(int i=1 ; i<=n ; i++){
        sptable[i][0].par = parent[i];
        if(parent[i] != -1){
            sptable[i][0].mx = cost[{i , parent[i]}];
        }
    }

    for(int j=1 ; (1<<j) <= n ; j++){
        for(int i=1 ; i<=n ; i++){
            if(sptable[i][j-1].par != -1){
                sptable[i][j].par = sptable[sptable[i][j-1].par][j-1].par;
                sptable[i][j].mx = max(sptable[i][j].mx , max(sptable[i][j-1].mx , sptable[sptable[i][j-1].par][j-1].mx));
            }
        }
    }
}

int LCA_Query(int n,int p,int q)
{
    int ans = 0;
    if(level[p] < level[q])
        swap(p , q);

    int Log = 0;
    while(1){
        int nxt = 1 + Log;
        if((1<<nxt) > level[p])
            break;
        Log++;
    }
    for(int i=Log ; i>=0 ; i--){
        if(level[p] - (1<<i) >= level[q]){
            ans = max(ans , sptable[p][i].mx);
            p = sptable[p][i].par;
        }
    }
    if(p == q)
        return ans;

    for(int i=Log ; i>=0 ; i--){
        if(sptable[p][i].par != -1 && sptable[p][i].par != sptable[q][i].par){
            ans = max(ans , max(sptable[p][i].mx , sptable[q][i].mx));
            p = sptable[p][i].par;
            q = sptable[q][i].par;
        }
    }
    ans = max(ans , max(cost[{p , parent[p]}] , cost[{q , parent[q]}]));
    return ans;
}

void Clean()
{
    ed.clear();
    cost.clear();
    for(int i=0 ; i<sz ; i++){
        graph[i].clear();
        par[i] = i;
        level[i] = 0;
        parent[i] = -1;

        for(int j=0 ; j<20 ; j++)
            sptable[i][j] = info(-1 , 0);
    }
}

void Solve(int t)
{
    Clean();

    int i,j,k,n,m,u,v,w,q;
    scin2(n , m);
    for(i=1 ; i<=m ; i++){
        sc("%d %d %d",&u,&v,&w);
        ed.pb(edge(u , v , w));
    }
    MST(n);
    DFS(1 , 0 , -1);
    LCA_Init(n);

    ///
    scin(q);
    pf("Case %d:\n",t);
    for(i=1 ; i<=q ; i++){
        scin2(u , v);
        int ans = LCA_Query(n , u , v);
        pf("%d\n",ans);
    }
}

int main()
{
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
