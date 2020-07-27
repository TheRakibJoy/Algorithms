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
#define longlimit               1000000000000000
#define infinity                (1<<28)
#define gcd(a,b)                __gcd(a,b)
#define lcm(a,b)                (a)*(b)/gcd(a,b)
#define mxx                     123456789
#define PI                      2*acos(0.0)
#define rep(i,a,b)              for(__typeof(i) i=a;i<=b;i++)
#define rev(i,a,b)              for(__typeof(i) i=a;i>=b;i--)

using namespace std;

struct info
{
    ll u,v,w;
    info(){}
    info(ll a,ll b,ll c)
    {
        u = a; v = b; w = c;
    }
};
vector<info>edges;
vector<info>vedge;

#define sz 1005
ll wt[sz][sz],d[sz],parent[sz];
vl graph[sz];
vl cost[sz];
int mark[sz][sz];


struct node
{
    ll u,w,prior;
    node(){}
    node(ll a,ll b,ll c)
    {
        u = a;
        w = b;
        prior = c;
    }
    bool operator < (const node &p)const{
        if(w != p.w)
            return w > p.w;
        else
            return prior < p.prior;
    }
};

ll Dijkstra(ll src , ll dest)
{
    for(ll i=0 ; i<=1000 ; i++)
        d[i] = longlimit , parent[i] = -1;
    priority_queue<node>pq;  ///u-node ; w-cost ; prior - priority
    pq.push(node(src , 0 , 0));
    d[src] = 0;
    parent[src] = -1;
    while(!pq.empty()){
        node top = pq.top();
        pq.pop();
        ll u = top.u;
        ll w = top.w;
        if(w > d[u])
            continue;
        for(ll i=0 ; i<(ll)graph[u].size() ; i++){
            ll v = graph[u][i];
            ll prior = top.prior;
            if(wt[u][v] == 0)
                prior |= 1;
            if(w + cost[u][i] < d[v]){
                d[v] = w + cost[u][i];
                pq.push(node(v , d[v] , prior));
                parent[v] = u;
            }
        }
    }
    return d[dest];
}

void Solve(int t)
{
    ms(wt , 0LL);
    ll i,j,k,n,m,u,v,src,des,dis,w,totnull=0,ans;
    cin>>n>>m>>dis>>src>>des;
    for(i=1 ; i<=m ; i++){
        cin>>u>>v>>w;
        graph[u].pb(v);
        graph[v].pb(u);
        wt[u][v] = wt[v][u] = w;
        edges.pb(info(u , v , w));
    }
    ///Try with only not erased edges
    for(i=0 ; i<m ; i++){
        u = edges[i].u;
        v = edges[i].v;
        w = edges[i].w;
        if(w == 0)
            w = longlimit;
        else
            mark[u][v] = 1;
        cost[u].pb(w);
        cost[v].pb(w);
    }
    ans = Dijkstra(src , des);
    if(ans == dis){
        pf("YES\n");
        for(i=0 ; i<m ; i++){
            u = edges[i].u;
            v = edges[i].v;
            w = edges[i].w;
            if(w == 0)
                w = longlimit;
            cout<<u<<' '<<v<<' '<<w<<endl;
        }
        return;
    }
    if(ans < dis){
        pf("NO\n");
        return;
    }
    ///Try with both erased & not erased edges
    for(i=0 ; i<=1004 ; i++){
        cost[i].clear();
        graph[i].clear();
    }
    for(i=0 ; i<m ; i++){
        u = edges[i].u;
        v = edges[i].v;
        w = edges[i].w;
        if(w == 0)
            w = 1;
        graph[u].pb(v);
        graph[v].pb(u);
        cost[u].pb(w);
        cost[v].pb(w);
    }
    ans = Dijkstra(src , des);
    if(ans > dis){
        pf("NO\n");
        return;
    }
    ///Try to give remaining cost so that path will valid
    ll node = des;
    while(node != src){
        u = node;
        v = parent[node];
        if(wt[u][v]==0 && wt[v][u]==0){
            mark[u][v] = mark[v][u] = 1;
        }
        node = parent[node];
    }
    for(i=0 ; i<m ; i++){
        u = edges[i].u;
        v = edges[i].v;
        w = edges[i].w;
        if(w==0 && !mark[u][v])
            edges[i].w = longlimit;
        else if(w==0 && mark[u][v])
            vedge.pb(edges[i]);
    }
    bool fg = 1;
    for(i=0 ; i<(int)vedge.size() && fg ; i++){
        ll remain = dis-ans;

        for(j=0 ; j<=n ; j++)
            cost[j].clear();

        for(j=0 ; j<(int)edges.size() && fg ; j++){
            u = edges[j].u;
            v = edges[j].v;
            w = edges[j].w;
            if(w == 0){
                if(vedge[i].u==u && vedge[i].v==v && vedge[i].w==w){
                    cost[u].pb(remain+1);
                    cost[v].pb(remain+1);
                    edges[j].w = remain+1;
                }
                else{
                    cost[u].pb(1);
                    cost[v].pb(1);
                }
            }
            else{
                cost[u].pb(w);
                cost[v].pb(w);
            }
        }///
        ans = Dijkstra(src , des);
        if(ans == dis){
            fg = 0;
            pf("YES\n");
            for(j=0 ; j<(int)edges.size() ; j++){
                u = edges[j].u;
                v = edges[j].v;
                w = edges[j].w;
                if(w == 0){
                    if(vedge[i].u==u && vedge[i].v==v && vedge[i].w==w)
                        cout<<u<<' '<<v<<' '<<remain+1<<endl;
                    else
                        cout<<u<<' '<<v<<' '<<"1\n";
                }
                else
                    cout<<u<<' '<<v<<' '<<w<<endl;
            }
            return;
        }
    }
    pf("NO\n");
}

int main()
{
    int t,T;
    T = 1;
    RUN_CASE(t,T)
    {
        Solve(t);
    }
    return 0;
}
/**
6 6 7 0 4
0 1 1
1 2 3
2 4 4
0 2 0
0 3 0
3 4 4
**/


