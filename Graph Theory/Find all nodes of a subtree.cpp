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

/** You're given a tree with n nodes. You've to find out the nodes of a specific subtree **/
#define sz 100005
int tim=0,vis[sz],start[sz],finish[sz],nodediscoveredinthistime[sz];
vi graph[sz];

void DFS(int u)
{
    vis[u] = 1;
    start[u] = ++tim;
    nodediscoveredinthistime[tim] = u;
    for(auto v:graph[u]){
        if(!vis[v]){
            DFS(v);
        }
    }
    finish[u] = tim;
}

void Solve(int t)
{
    int i,j,k,n,u,v;
    scin(n);
    for(i=1 ; i<=n-1 ; i++){
        scin2(u , v);
        graph[u].pb(v);
        graph[v].pb(u);
    }
    DFS(1);
    ///Find out all the node of the subtree rooted at u
    scin(u);
    for(i=start[u] ; i<=finish[u] ; i++)
        cout<<nodediscoveredinthistime[i]<<' ';
    cout<<endl;
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
7
1 2
1 3
2 4
2 5
3 6
3 7
**/
