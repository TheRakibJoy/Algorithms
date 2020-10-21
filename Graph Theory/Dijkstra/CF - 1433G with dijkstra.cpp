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

using namespace std;


#define sz 1005
vector<int>graph[sz],cost[sz];
struct node
{
    int u,w;
    node(){}
    node(int _u,int _w)
    {
        u = _u;
        w = _w;
    }
    bool operator < (const node &p)const{
        return w>p.w;
    }
};

int d[sz][sz];

void Clean()
{
    for(int i=0 ; i<sz ; i++){
        for(int j=0 ; j<sz ; j++)
            d[i][j] = 1e9;
    }
}

void Dijkstra(int src,int id)
{
    priority_queue<node>pq;
    pq.push(node(src , 0));
    d[id][src] = 0;
    while(!pq.empty()){
        node top = pq.top();
        pq.pop();
        int u = top.u;
        if(top.w > d[id][u])
            continue;
        for(int i=0 ; i<(int)graph[u].size() ; i++){
            int v = graph[u][i];
            if(top.w+cost[u][i] < d[id][v]){
                d[id][v] = top.w+cost[u][i];
                pq.push(node(v , d[id][v]));
            }
        }
    }
}

vector<pii>edges,journey;

void Solve(int t)
{
    int i,j,k,n,m,u,v,ans=1e9,tot=0,w,cnt=0;
    cin>>n>>m>>k;
    for(i=1 ; i<=m ; i++){
        cin>>u>>v>>w;
        graph[u].pb(v);
        graph[v].pb(u);
        cost[u].pb(w);
        cost[v].pb(w);
        edges.pb(make_pair(u , v));
    }
    for(i=1 ; i<=k ; i++){
        cin>>u>>v;
        journey.pb(make_pair(u , v));
    }
    ///
    for(i=1 ; i<=n ; i++)
        Dijkstra(i , i);
    ///
    for(i=0 ; i<m ; i++){
        u = edges[i].first;
        v = edges[i].second;

        tot = 0;
        for(j=0 ; j<k ; j++){
            int src = journey[j].first;
            int des = journey[j].second;
            cnt = min(d[u][src]+d[v][des] , min(d[u][des]+d[v][src] , d[src][des]));
            tot += cnt;
        }
        ans = min(ans , tot);
    }
    cout<<ans<<endl;
}

int main()
{
    Clean();
    int t,T;
    T = 1;
//    cin>>T;
    RUN_CASE(t,T)
    {
        Solve(t);
    }
    return 0;
}
