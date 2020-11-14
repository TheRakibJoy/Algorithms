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
ll color[sz],ans[sz],buck[sz],mxfre[sz],cnt[sz];
vi graph[sz];
map<int,int>fre[sz];

void MergE(int u,int v)
{
    if(fre[buck[u]].size() < fre[buck[v]].size())
        swap(buck[u] , buck[v]);
    for(auto it:fre[buck[v]]){
        int val = it.first;
        int freq = it.second;
        fre[buck[u]][val] += freq;

        if(fre[buck[u]][val] > mxfre[buck[u]]){
            mxfre[buck[u]] = fre[buck[u]][val];
            cnt[buck[u]] = 0;
        }
        if(fre[buck[u]][val] == mxfre[buck[u]])
            cnt[buck[u]] += val;
    }
}

void DFS(int u,int par)
{
    buck[u] = u;
    cnt[u] = color[u];
    mxfre[u] = 1;
    for(auto v:graph[u]){
        if(v != par)
            DFS(v , u);
    }
    fre[buck[u]][color[u]] = 1;
    for(auto v : graph[u]){
        if(v != par){
            MergE(u , v);
        }
    }
    ans[u] = cnt[buck[u]];
}

void Solve(int t)
{
    int i,j,k,n,u,v;
    scin(n);
    for(i=1 ; i<=n ; i++)
        scln(color[i]);
    for(i=1 ; i<=n-1 ; i++){
        scin2(u , v);
        graph[u].pb(v);
        graph[v].pb(u);
    }
    DFS(1 , -1);
    for(i=1 ; i<=n ; i++)
        cout<<ans[i]<<' ';
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


