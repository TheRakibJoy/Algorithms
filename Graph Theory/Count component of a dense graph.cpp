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

/** You're given a dense graph with node n. You have to count number of component in this graph.
Initially, you'll given two array l[n] & r[n] with equal size n. It means node i are
connected to all nodes from l to r with an edge. **/

#define sz 100005
set<int>nonvis;
int l[sz],r[sz];

void DFS(int u)
{
    int lft = l[u] , rgt = r[u];
    while(1){
        auto it = nonvis.lower_bound(lft);
        if(it==nonvis.end() || *it>rgt)
            break;
        else{
            int v = *it;
            nonvis.erase(v);
            DFS(v);
        }
    }
}

void Solve(int t)
{
    int i,j,k,n,comp=0;
    scin(n);
    for(i=1 ; i<=n ; i++){
        scin2(l[i] , r[i]);
        nonvis.insert(i);
    }
    for(i=1 ; i<=n ; i++){
        if(nonvis.find(i) != nonvis.end())
            DFS(i) , comp++;
    }
    cout<<comp<<endl;
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
8
2 4
1 1
1 1
1 1
6 7
5 5
5 5
8 8
**/
