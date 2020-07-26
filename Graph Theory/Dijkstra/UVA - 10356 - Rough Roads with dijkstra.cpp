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
Problem: You're given n nodes & m edges. You have to find shortest distance
for going 0 to n-1 using even number of edges.
**/

#define sz 505
int n,m,d[505][2];  ///d[x][0] - distance from source to x using even number of edges ; d[x][1] - distance from source to x using odd number of edges
vi graph[sz],cost[sz];

void Clean(int n)
{
    for(int i=0 ; i<=n ; i++){
        graph[i].clear();
        cost[i].clear();
    }
}

struct info
{
    int node,dis,oddeven;
    info(){}
    info(int a,int b,int c)
    {
        node = a;
        dis = b;
        oddeven = c;
    }
    bool operator < (const info &p)const{
        return dis > p.dis;
    }
};

void Dijkstra()
{
    for(int i=0 ; i<=n+2 ; i++){
        for(int j=0 ; j<2 ; j++)
            d[i][j] = infinity;
    }
    priority_queue<info>pq;  ///node ; distance ; number of used edges(odd or even)
    d[0][0] = 0;
    pq.push(info(0 , 0 , 0));
    while(!pq.empty()){
        info top = pq.top();
        pq.pop();
        int u = top.node;

        if(top.dis > d[u][top.oddeven])
            continue;
        for(int i=0 ; i<(int)graph[u].size() ; i++){
            int v = graph[u][i];
            if(top.dis + cost[u][i] < d[v][top.oddeven ^ 1]){
                d[v][top.oddeven ^ 1] = top.dis + cost[u][i];
                pq.push(info(v , d[v][top.oddeven ^ 1] , top.oddeven^1));
            }
        }
    }
}

void Solve(int t)
{
    int i,j,k,u,v,w,ans;
    for(i=1 ; i<=m ; i++){
        sc("%d %d %d",&u,&v,&w);
        graph[u].pb(v);
        graph[v].pb(u);
        cost[u].pb(w);
        cost[v].pb(w);
    }
    Dijkstra();
    ans = d[n-1][0];

    pf("Set #%d\n",t);
    (ans >= infinity)? pf("?\n") : pf("%d\n",ans);

    Clean(n);
}

int main()
{
    int t = 0;
    while(scin2(n , m) != EOF)
    {
        Solve(++t);
    }
    return 0;
}



