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

/** Problem: You're given a tree with n nodes and root=1. You've to answer q queries. In each
query u have to tell the kth parent of a given node x **/

const int sz = 100005;
const int k = 25;
int Log[sz],parent[sz],sptable[sz][k];
vi graph[sz];

void PreLog(int n)
{
    Log[1] = 0;
    for(int i=2 ; i<=n ; i++)
        Log[i] = Log[i/2]+1;
}

void sparseTable(int n)
{
    for(int i=1 ; i<=n ; i++)
        sptable[i][0] = parent[i];
    for(int j=1 ; (1<<j)<=n ; j++){
        for(int i=1 ; i<=n ; i++){
            if(sptable[i][j-1] == -1)
                sptable[i][j] = sptable[i][j-1];
            else
                sptable[i][j] = sptable[sptable[i][j-1]][j-1];
        }
    }
}

int kthParent(int u,int kth)
{
    for(int j=25 ; j>=0 ; j--){
        if(kth >= (1<<j)){
            u = sptable[u][j];
            kth -= (1<<j);
        }
    }
    return u;
}

void DFS(int u,int par)
{
    parent[u] = par;
    for(auto v:graph[u]){
        if(v != par)
            DFS(v , u);
    }
}

void Solve(int t)
{
    int i,j,n,kth,q,u,v;
    cin>>n>>q;
    for(i=1 ; i<n ; i++){
        cin>>u>>v;
        graph[u].pb(v);
        graph[v].pb(u);
    }
    DFS(1 , -1);
    PreLog(n);
    sparseTable(n);
    for(i=1 ; i<=q ; i++){
        cin>>u>>kth;
        cout<<kthParent(u , kth)<<endl;
    }
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
15 20
1 2
2 4
4 5
4 6
6 8
5 7
7 9
9 10
1 3
3 11
11 12
11 13
13 14
14 15
**/
