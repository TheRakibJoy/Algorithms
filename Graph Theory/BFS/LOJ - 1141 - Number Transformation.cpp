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
#define longlimit               92233720368547758
#define infinity                (1<<28)
#define gcd(a,b)                __gcd(a,b)
#define lcm(a,b)                ((a)*(b))/gcd(a,b)
#define mxx                     123456789
#define PI                      2*acos(0.0)
#define rep(i,a,b)              for(__typeof(i) i=a;i<=b;i++)
#define rev(i,a,b)              for(__typeof(i) i=a;i>=b;i--)

using namespace std;

vector<int>Prime;
bool mark[1009];
void sieve(int n)
{
    int i,j;
    mark[1]=1;
    for(i=4; i<=n; i+=2)mark[i]=1;
    Prime.push_back(2);
    for(i=3; i<=n; i+=2){
        if(!mark[i]){
            Prime.push_back(i);
            if(i*i<=n){
                for(j=i*i; j<=n; j+=(i*2))
                    mark[j]=1;
            }
        }
    }
}
vi FactorTable[1009];
void Primefactorize(int n,int org)
{
    for(int i=0; i<(int)Prime.size() && Prime[i]*Prime[i]<=n ; i++){
        if(n%Prime[i] == 0){
            FactorTable[org].pb(Prime[i]);
            while(n%Prime[i] == 0){
                n /= Prime[i];
            }
        }
    }
    if(n>1 && n<org)
        FactorTable[org].pb(n);
}

vi graph[1009];
int dis[1009],vis[1009];

void BFS(int start,int des)
{
    for(int i=0 ; i<=1000 ; i++)
        vis[i]=0 , dis[i]=-1;
    queue<int>q;
    vis[start] = 1;
    dis[start] = 0;
    q.push(start);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int i=0 ; i<(int)graph[u].size() ; i++){
            int v = graph[u][i];
            if(!vis[v] && v<=des){
                vis[v] = 1;
                dis[v] = 1+dis[u];
                q.push(v);
            }
        }
    }
}

void Solve(int t)
{
    int i,j,k,n,m,start,des,ans;
    scin2(start , des);
    BFS(start , des);
    ans = dis[des];
    pf("Case %d: %d\n",t,ans);
}

int main()
{
    int t,T,i,j,k,u,v;
    sieve(1000);
    for(int i=1 ; i<=1000 ; i++)
        Primefactorize(i , i);
    for(i=1 ; i<=1000 ; i++){
        u = i;
        for(j=0 ; j<(int)FactorTable[u].size() ; j++){
            v = u+FactorTable[u][j];
            graph[u].pb(v);
        }
    }
    scin(T);
    RUN_CASE(t,T)
    {
        Solve(t);
    }
    return 0;
}
