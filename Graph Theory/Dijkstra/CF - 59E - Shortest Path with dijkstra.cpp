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

/**
Problem: You're given n cities & m equal length roads. And k triples. Each triples
indicate a forbidden path. You've to find out shortest path from cities 1 to n
without visit a forbidden triples. Each triple is ordered.
**/

#define sz 3005
int parent[sz][sz],d[sz][sz]; ///d[x][y] = distance of x from 1 where y is the parent of x
///parent[x][y] = z ; means y is the parent of x & z is the parent of y
vi graph[sz],cost[sz];
set<pair<int , pair<int , int>>>forbidden;
vi path;

struct info
{
    int node,par,wt;
    info(){}
    info(int _node,int _par,int _wt)
    {
        node = _node;
        par = _par;
        wt = _wt;
    }
    bool operator < (const info &p)const{
        return wt>p.wt;
    }
};

void Init()
{
    for(int i=0 ; i<sz ; i++){
        for(int j=0 ; j<sz ; j++){
            d[i][j] = infinity;
            parent[i][j] = -1;
        }
    }
}

void BuildPath(int node,int par)
{
    path.pb(node);
    path.pb(par);
    while(parent[node][par] > 0){
        path.pb(parent[node][par]);
        node = par;
        par = path.back();
    }
}

int Dijkstra(int src,int dest)
{
    bool fg = 1;
    Init();
    priority_queue<info>pq;
    parent[src][src] = -1;
    d[src][src] = 0;
    pq.push(info(src , -1 , 0));    ///present node ; parent ; distance
    while(!pq.empty() && fg){
        int u = pq.top().node;
        int w = pq.top().wt;
        int par = pq.top().par;
        pq.pop();
        if(w > d[u][par])
            continue;
        for(int i=0 ; i<(int)graph[u].size() && fg ; i++){
            int v = graph[u][i];
            if(forbidden.find(make_pair(par , make_pair(u , v))) == forbidden.end() && w+cost[u][i]<d[v][u]){
                d[v][u] = w+cost[u][i];
                parent[v][u] = par;
                pq.push(info(v , u , d[v][u]));
                if(v == dest){
                    BuildPath(v , u);
                    fg = 0;
                    break;
                }
            }
        }
    }
    int mn = infinity;
    for(int i=1 ; i<=dest ; i++)
        mn = min(mn , d[dest][i]);
    return mn;
}

void Solve(int t)
{
    int i,j,k,n,m,u,v,ans,x,y,z;
    cin>>n>>m>>k;
    for(i=1 ; i<=m ; i++){
        cin>>u>>v;
        graph[u].pb(v);
        graph[v].pb(u);
        cost[u].pb(1);
        cost[v].pb(1);
    }
    for(i=1 ; i<=k ; i++){
        cin>>x>>y>>z;
        forbidden.insert(make_pair(x , make_pair(y , z)));
    }
    ans = Dijkstra(1 , n);
    if(ans >= infinity)
        cout<<"-1\n";
    else{
        cout<<ans<<endl;
        reverse(path.begin() , path.end());
        for(auto it:path)
            cout<<it<<' ';
        cout<<endl;
    }

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



