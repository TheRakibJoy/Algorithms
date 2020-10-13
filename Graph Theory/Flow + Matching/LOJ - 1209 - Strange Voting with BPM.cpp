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

/** IDEA: MxFy vote is dependent on MyFx Vote. Build graph according to this. Then
find out maximum size of independent set. We know it is total node - MaxFlow(Max BPM) **/

const int sz = 509;

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

vector<Edge>edges;
vector<int>edgeid[sz];
bool vis[sz];
int src,sink;

void Clean()
{
    for(int i=0 ; i<sz ; i++){
        edgeid[i].clear();
        vis[i] = 0;
    }
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
    int mxFlow=0;
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
    int i,j,k,m,f,v,ans=0,bpm;
    string s1[sz],s2[sz];
    src = 0;
    sink = 505;
    cin>>m>>f>>v;
    for(i=1 ; i<=v ; i++){
        cin>>s1[i]>>s2[i];
        if(s1[i][0] == 'M')
            addEdge(src , i , 1);
        else
            addEdge(i , sink , 1);
        for(j=1 ; j<i ; j++){
            if(s1[i]==s2[j] || s2[i]==s1[j]){
                if(s1[i][0] == 'M')
                    addEdge(i , j , 1);
                else
                    addEdge(j , i , 1);
            }
        }
    }
    bpm = FordFulkerson();
    ans = v - bpm;
    cout<<"Case "<<t<<": "<<ans<<endl;

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
