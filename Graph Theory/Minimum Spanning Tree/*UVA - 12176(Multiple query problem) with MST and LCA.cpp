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

#define sz 3009

///MST Part
struct edge
{
    int u,v,w;
    edge(){}
    edge(int _u,int _v,int _w)
    {
        u = _u;
        v = _v;
        w = _w;
    }
    bool operator < (const edge &p)const{
        return w < p.w;
    }
};

int par[sz];
vector<edge>ed;
vi msttree[sz];
map<pii , int>cost;

void makeSet(int n)
{
    for(int i=1 ; i<=n ; i++)
        par[i] = i;
}

int findSet(int u)
{
    if(u == par[u])
        return u;
    return par[u] = findSet(par[u]);
}

void MST(int n)
{
    int cnt = 0;
    sort(ed.begin() , ed.end());
    cost.clear();
    makeSet(n);
    for(int i=0 ; i<(int)ed.size() ; i++){
        int u = findSet(ed[i].u);
        int v = findSet(ed[i].v);
        if(u != v){
            par[u] = v;
            cnt++;
            msttree[ed[i].u].pb(ed[i].v);
            msttree[ed[i].v].pb(ed[i].u);
            cost[{ed[i].u , ed[i].v}] = ed[i].w;
            cost[{ed[i].v , ed[i].u}] = ed[i].w;
        }
        if(cnt == n-1)
            break;
    }
}

///LCA Part
bool vis[sz];
int level[sz],parent[sz];
pii sptable[sz][13];    ///first-2^j th parent of i ; second-max edge cost from i to its 2^j th parent

void BFS(int src)
{
    for(int i=0 ; i<sz ; i++){
        parent[i] = -1;
        level[i] = vis[i] = 0;
    }
    queue<int>q;
    q.push(src);
    vis[src] = 1;
    level[src] = 0;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int v : msttree[u]){
            if(!vis[v]){
                q.push(v);
                vis[v] = 1;
                level[v] = 1+level[u];
                parent[v] = u;
            }
        }
    }
}

void LCA_Init(int n)
{
    ms(sptable , -1);
    for(int i=1 ; i<=n ; i++){
        sptable[i][0].first = parent[i];
        if(parent[i] != -1)
            sptable[i][0].second = cost[{i , parent[i]}];
    }
    for(int j=1 ; (1<<j) <= n ; j++){
        for(int i=1 ; i<=n ; i++){
            if(sptable[i][j-1].first != -1){
                sptable[i][j].second = max(sptable[i][j].second , max(sptable[i][j-1].second , sptable[sptable[i][j-1].first][j-1].second));
                sptable[i][j].first = sptable[sptable[i][j-1].first][j-1].first;
            }
        }
    }
}

int LCA_Query(int n,int p,int q)
{
    if(p == q)
        return 0;
    int mxroad = 0;
    if(level[p] < level[q])
        swap(p , q);

    int Log = 0;
    while(1){
        int nxt = 1+Log;
        if((1<<nxt) > level[p])
            break;
        Log++;
    }

    for(int i=Log ; i>=0 ; i--){
        if(level[p]-(1<<i) >= level[q]){
            mxroad = max(mxroad , sptable[p][i].second);
            p = sptable[p][i].first;
        }
    }
    if(p == q)
        return mxroad;
    for(int i=Log ; i>=0 ; i--){
        if(sptable[p][i].first != -1 && sptable[p][i].first != sptable[q][i].first){
            mxroad = max(mxroad , max(sptable[p][i].second , sptable[q][i].second));
            p = sptable[p][i].first;
            q = sptable[q][i].first;
        }
    }
    mxroad = max(mxroad , max(cost[{p , parent[p]}] , cost[{q , parent[q]}]));
    return mxroad;
}

void Clean(int n)
{
    ed.clear();
    for(int i=1 ; i<=n ; i++){
        msttree[i].clear();
    }
}

void Solve(int t)
{
    int i,j,k,n,m,q,u,v,w,ans;
    scin2(n , m);
    for(i=1 ; i<=m ; i++){
        sc("%d %d %d",&u,&v,&w);
        ed.pb(edge(u , v , w));
    }
    scin(q);
    MST(n);
    BFS(1);
    LCA_Init(n);
    pf("Case %d\n",t);

    for(i=1 ; i<=q ; i++){
        scin2(u , v);
        ans = LCA_Query(n , u , v);
        pf("%d\n",ans);
    }
    Clean(n);
    pf("\n");
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

