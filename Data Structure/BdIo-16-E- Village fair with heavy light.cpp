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

#define sz 100005
int parent[sz],buck[sz];
vi graph[sz],cost[sz];
ll joy[sz],lazy[sz],ans[sz];
set<ll>st[sz];

void DFS(int u,int par)
{
    buck[u] = u;
    for(auto v:graph[u]){
        if(v != par)
            DFS(v , u);
    }
    st[buck[u]].insert(joy[u]);
    for(int i=0 ; i<(int)graph[u].size() ; i++){
        int v = graph[u][i];
        int wt = cost[u][i];
        if(v != par){
            if(st[buck[u]].size() < st[buck[v]].size()){
                swap(buck[u] , buck[v]);
                lazy[buck[u]] += wt;    ///Increase joy value of child bucket. And after swapping u is the child & v is the parent **/
                for(auto x:st[buck[v]])
                    st[buck[u]].insert(x + lazy[buck[v]] - lazy[buck[u]]);
            }
            else{
                lazy[buck[v]] += wt;    ///Increase joy value of child bucket.
                for(auto x:st[buck[v]])
                    st[buck[u]].insert(x + lazy[buck[v]] - lazy[buck[u]]);
            }
        }
    }
    ans[u] = st[buck[u]].size();
}

void Solve(int t)
{
    int i,j,k,n,u,v,wt,start;
    scin(n);
    for(i=1 ; i<=n ; i++)   scln(joy[i]);
    for(i=1 ; i<=n ; i++){
        v = i;
        scin(u);
        if(u == 0){
            start = v;
            parent[v] = -1;
        }
        else{
            parent[v] = u;
            graph[u].pb(v);
            graph[v].pb(u);
        }
    }
    for(i=1 ; i<=n ; i++){
        u = i;
        v = parent[i];
        scin(wt);
        if(v != -1){
            cost[u].pb(wt);
            cost[v].pb(wt);
        }
    }
    DFS(start , -1);
    for(i=1 ; i<=n ; i++)
        pf("%lld\n",ans[i]);
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
/**
13
5 7 3 2 4 3 2 3 6 1 4 3 4
0 1 2 3 3 3 1 7 7 8 8 9 9
0 2 5 13 5 2 3 7 11 7 3 2 13
**/


