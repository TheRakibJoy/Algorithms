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


#define sz 209
bool vis[sz];
int par[sz];
ll cap[sz][sz],flow[sz][sz];
vi graph[sz],v1,v2;
unordered_map<int , int>nodeno;

void Clean()
{
    for(int i=0 ; i<=205 ; i++){
        graph[i].clear();
        for(int j=0 ; j<=205 ; j++)
            cap[i][j] = flow[i][j] = 0;
    }
}

bool BFS(const int &src,const int &des)
{
    for(int i=0 ; i<sz ; i++)
        par[i] = -1 , vis[i] = 0;
    queue<int>q;
    q.push(src);
    vis[src] = 1;
    par[src] = -1;

    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(auto v : graph[u]){
            if(!vis[v] && (cap[u][v]-flow[u][v] > 0)){
                q.push(v);
                par[v] = u;
                vis[v] = 1;
            }
        }
    }
    return vis[des];
}

ll FordFulkerson(const int &src,const int &des)
{
    ll u,v,mxFlow=0;
    while(BFS(src , des)){
        ll mnPathFlow = INT_MAX;
        for(v=des ; v!=src ; v=par[v]){
            u = par[v];
            mnPathFlow = min(mnPathFlow , cap[u][v]-flow[u][v]);
        }
        for(v=des ; v!=src ; v=par[v]){
            u = par[v];
            flow[u][v] += mnPathFlow;
            flow[v][u] -= mnPathFlow;
        }
        mxFlow += mnPathFlow;
    }
    return mxFlow;
}

void addEdge(int u,int v,int w)
{
    graph[u].pb(v);
    graph[v].pb(u);
    cap[u][v] = w;
}

bool isValid(const int &nowd,const int &d,const int &src,const int &sink,const int &n)
{
    Clean();
    if(nowd == d)
        addEdge(src,sink,1e9);

    for(int i=0;i<v1.size();i++)
    {
        int u = nodeno[v1[i]];
        if(v1[i] <= nowd)
            addEdge(src,u,1e9);
        if(d-v1[i] <= nowd)
            addEdge(u+n,sink,1e9);
        addEdge(u,u+n,1e9);

        for(int j=i+1;j<v1.size();j++)
        {
            int v = nodeno[v1[j]];
            if(v1[j]-v1[i] > nowd)
                break;
            addEdge(u+n,v,1e9);
            addEdge(v+n,u,1e9);
        }
        for(int j=0;j<v2.size();j++)
        {
            int v = nodeno[v2[j]];

            if(abs(v1[i]-v2[j]) <= nowd)
            {
                addEdge(u+n,v,1e9);
                addEdge(v+n,u,1e9);
            }
        }
    }
    for(int i=0;i<v2.size();i++)
    {
        int u = nodeno[v2[i]];
        if(v2[i] <= nowd)
            addEdge(src,u,1e9);
        if(d-v2[i] <= nowd)
            addEdge(u+n,sink,1e9);
        addEdge(u,u+n,1);

        for(int j=i+1;j<v2.size();j++)
        {
            int v = nodeno[v2[j]];
            if(v2[j]-v2[i] > nowd)
                break;
            addEdge(u+n,v,1e9);
            addEdge(v+n,u,1e9);
        }
    }
    return (FordFulkerson(src , sink) > 1);
}

void Solve(int t)
{
    ll i,j,k,u,v,ans,cnt=0,n,d,src=0,des=205;
    char s[50];
    scln2(n , d);
    ans = d;
    for(i=1 ; i<=n ; i++){
        sc("%s",s);

        ll pos = 0 , digit , szz = strlen(s);
        for(j=2 ; j<szz ; j++){
            digit = s[j] - '0';
            pos = (pos*10)+digit;
        }
        if(s[0] == 'B')
            v1.pb(pos);
        else
            v2.pb(pos);
        nodeno[pos] = i;
    }

    ll lo=0,hi=d,mid;
    while(lo <= hi){
        mid = (lo+hi)/2;
        if(isValid(mid , d , src , des , n)){
            ans = mid;
            hi = mid-1;
        }
        else
            lo = mid+1;
    }

    pf("Case %d: %lld\n",t,ans);
    v1.clear();
    v2.clear();
    nodeno.clear();
}

int main()
{
//    Output;
    int t,T;
    scin(T);
    RUN_CASE(t,T)
    {
        Solve(t);
    }
    return 0;
}
