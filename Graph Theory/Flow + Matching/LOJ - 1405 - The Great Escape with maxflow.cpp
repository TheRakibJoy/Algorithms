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

/** IDEA: I'have to covert the grid into a graph. Where, there'll be a source node
and a sink node. I have to split every node with an edge of cost 1. Cost of edge between
source & each cell containing persons will be 1. And cost of edge between Xout to yin
will be 1.Cost of edge between boundary node to sink will be 1. Now, there can be
k disjoint path if I it have k flow in sink **/

const int fx[] = {+1,-1,+0,+0};
const int fy[] = {+0,+0,+1,-1};

#define sz 20005
struct Edge
{
    int u,v,cap;
    Edge(){}
    Edge(int _u,int _v,int _cap)
    {
        u = _u;
        v = _v;
        cap = _cap;
    }
};
char grid[105][105];
vector<Edge>edges;
vector<int>edgeid[sz];
bool vis[sz];
int src,sink,n,m,innode[105][105],outnode[105][105];

void Clean()
{
    for(int i=0 ; i<sz ; i++)
        edgeid[i].clear();
    edges.clear();
}

void addEdge(int u,int v,int w)
{
    edges.pb(Edge(u , v , w));
    edges.pb(Edge(v , u , 0));

    edgeid[u].pb(edges.size()-2);
    edgeid[v].pb(edges.size()-1);
}

int DFS(int u,int flow=1e9)
{
    vis[u] = 1;
    if(u == sink)
        return flow;
    int ret = 0;
    for(int i=0 ; i<(int)edgeid[u].size() ; i++){
        int id = edgeid[u][i];
        Edge &e = edges[id];
        if(!e.cap || vis[e.v])
            continue;
        ret = DFS(e.v , min(flow , e.cap));

        if(ret){
            Edge &rev = edges[id^1];
            e.cap -= ret;
            rev.cap += ret;
            return ret;
        }
    }
    return ret;
}

int FordFulkerson()
{
    int mxFlow = 0;
    while(1){
        ms(vis , 0);
        int mnPathFlow = DFS(src);
        if(mnPathFlow == 0)
            break;
        mxFlow += mnPathFlow;
    }
    return mxFlow;
}

void Solve(int t)
{
    int i,j,k,ans=0,cnt=0,person=0;
    cin>>n>>m;
    for(i=1 ; i<=n ; i++){
        for(j=1 ; j<=m ; j++){
            cin>>grid[i][j];
            if(grid[i][j] == '*')
                person++;
            innode[i][j] = ++cnt;
            outnode[i][j] = innode[i][j]+(m*n);
        }
    }
    src = 0; sink = cnt+(m*n)+1;

    for(i=1 ; i<=n ; i++){
        for(j=1 ; j<=m ; j++){
            int u = innode[i][j];

            if(grid[i][j] == '*')
                addEdge(src , u , 1);
            addEdge(u , outnode[i][j] , 1);

            if(i==1 || i==n || j==1 || j==m)
                addEdge(outnode[i][j] , sink , 1);
            else{
                for(k=0 ; k<4 ; k++){
                    int nx = i + fx[k];
                    int ny = j + fy[k];
                    if(grid[nx][ny] != '*')
                        addEdge(outnode[i][j] , innode[nx][ny] , 1);
                }
            }
        }
    }

    ans = FordFulkerson();
    if(ans == person)
        cout<<"Case "<<t<<": yes\n";
    else
        cout<<"Case "<<t<<": no\n";

    Clean();
}

int main()
{
    CIN;
    int t,T;
    cin>>T;
    RUN_CASE(t,T)
    {
        Solve(t);
    }
    return 0;
}
