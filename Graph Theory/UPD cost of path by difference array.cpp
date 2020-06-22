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

/** Advanced session - 7 (2:48:00)
Problem: You're given a tree with n(<=1e6) nodes. Initially, cost of each node is 0.
You've to perform q(<=1e6) update operation. In each update operation, you'll given
u v x(where u is the ancestor of v). You've to increase cost of all nodes in path u
to v. After all update operation, print the cost of each nodes.

Solution: We can do this like difference array. Difference array in a tree like:

DIF(u) = cost[u] - Summation(cost[v]) where v is the child of u.
According to contribution after a update opt cost will change like:
DIF[par[u]] -= x
DIF[v] += x

**/

#define sz 100005
vi graph[sz];
int cost[sz],DIF[sz],par[sz];

void DFS(int u , int parent)
{
    par[u] = parent;
    int childcost = 0;
    for(auto v : graph[u]){
        if(v != parent){
            DFS(v , u);
            childcost += cost[v];
        }
    }
    cost[u] = DIF[u] + childcost;
}

void Solve(int t)
{
    int i,j,k,n,u,v,q,x;
    scin2(n , q);
    for(i=1 ; i<=n-1 ; i++){
        scin2(u , v);
        graph[u].pb(v);
        graph[v].pb(u);
    }
    DFS(1 , -1);
    for(i=1 ; i<=q ; i++){
        cin>>u>>v>>x;
        if(DIF[par[u]] != -1)
            DIF[par[u]] -= x;
        DIF[v] += x;
    }
    DFS(1 , -1);
    for(i=1 ; i<=n ; i++)
        cout<<cost[i]<<' ';
    cout<<endl;
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
7 5
1 2
1 3
2 4
2 5
3 6
6 7
1 7 4
1 4 2
1 5 3
6 7 5
3 6 1
ANS: 9 , 5 , 5 , 2 , 3 , 10 , 9
**/

