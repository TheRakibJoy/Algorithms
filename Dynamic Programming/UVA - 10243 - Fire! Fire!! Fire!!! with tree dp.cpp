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

vi graph[1005];
bool vis[1005];
int n,dp[3][1005],parent[1005];

void DFS(int u)
{
    vis[u] = 1;
    for(auto v:graph[u]){
        if(!vis[v]){
            parent[v] = u;
            DFS(v);
        }
    }
}

int FuN(int musttake , int u)
{
    vis[u] = 1;
    if((int)graph[u].size() == 0)
        return dp[musttake][u] = 1;
    if((int)graph[u].size()==1 && graph[u].front()==parent[u]){
        if(musttake)
            return dp[musttake][u] = 1;
        else
            return dp[musttake][u] = 0;
    }
    if(dp[musttake][u] != -1)
        return dp[musttake][u];
    int ret1=infinity,ret2=infinity,ret=0;
    if(musttake == 1){
        ret1 = 1;
        for(auto v:graph[u]){
            if(v != parent[u])
                ret1 += FuN(0 , v);
        }
    }
    else{
        ret1 = 1; ret2 = 0;
        for(auto v:graph[u]){
            if(v != parent[u])
                ret1 += FuN(0 , v);
        }
        for(auto v:graph[u]){
            if(v != parent[u])
                ret2 += FuN(1 , v);
        }
    }
    return dp[musttake][u] = min(ret1 , ret2);
}

void Clean()
{
    for(int i=0 ; i<=n+2 ; i++){
        vis[i] = 0;
        graph[i].clear();
        for(int j=0 ; j<3 ; j++)
            dp[j][i] = -1;
    }
}

void Solve()
{
    int i,j,k,m,u,v,ans = 0;
    for(u=1 ; u<=n ; u++){
        scin(m);
        for(i=1 ; i<=m ; i++){
            scin(v);
            graph[u].pb(v);
        }
    }
    for(i=1 ; i<=n ; i++){
        if(!vis[i])
            DFS(i);
    }
    ans = FuN(0 , 1);
    cout<<ans<<endl;
    Clean();
}

int main()
{
    ms(dp , -1);
    while(1){
        scin(n);
        if(n == 0)
            break;
        Solve();
    }
    return 0;
}
/**
8
2 2 3
2 1 4
3 1 5 6
1 2
1 3
1 3
0
0
**/
