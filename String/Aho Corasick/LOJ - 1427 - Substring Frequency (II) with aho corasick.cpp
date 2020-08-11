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

/** Problem: You're given a big string T and many small strings s[n]. You have to find
number of occurrences of s[i] as a substring of T. **/

const int N = 3e5 , ALPHA = 30;
int to[N][ALPHA] , nxt[N][ALPHA];
int depth[N] , suflink[N] , par[N] , parletter[N];
vi tr[N];
int tot_node = 1;


int addString(char *s)
{
    int curr = 1 , sz = strlen(s);
    for(int i=0 ; i<sz ; i++){
        int ch = s[i]-'a';
        if(!to[curr][ch]){
            to[curr][ch] = ++tot_node;
            par[tot_node] = curr;
            depth[tot_node] = 1 + depth[curr];
            parletter[tot_node] = ch;
        }
        curr = to[curr][ch];
    }
    return curr;
}

void push_SuffixLinks()
{
    queue<int>q;
    q.push(1);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        if(depth[u] <= 1)
            suflink[u] = 1;
        else{
            int v = suflink[par[u]] , ch = parletter[u];
            while(v > 1 && !to[v][ch])
                v = suflink[v];
            if(to[v][ch])
                v = to[v][ch];
            suflink[u] = v;
        }
        if(u != 1)
            tr[suflink[u]].pb(u);
        for(int i=0 ; i<ALPHA ; i++){
            if(to[u][i])
                q.push(to[u][i]);
        }
    }
}

int jump(int u,int c)
{
    if(nxt[u][c])
        return nxt[u][c];
    int v = u;
    while(v > 1 && !to[v][c])
        v = suflink[v];
    if(to[v][c])
        v = to[v][c];
    return nxt[u][c] = v;
}

int vis[N],cnt[N];

void DFS(int u)
{
    vis[u] = 1;
    for(auto v : tr[u]){
        if(!vis[v]){
            DFS(v);
            cnt[u] += cnt[v];
        }
    }
}

void Clean()
{
    tot_node = 1;
    for(int i=0 ; i<N ; i++){
        depth[i] = suflink[i] = par[i] = parletter[i] = vis[i] = cnt[i] = 0;
        tr[i].clear();
        for(int j=0 ; j<ALPHA ; j++)
            to[i][j] = nxt[i][j] = 0;
    }
}

char txt[1000005],str[5005];
void Solve(int t)
{
    int i,j,k,n,ans,sz,curr = 1;
    scin(n);
    int endpoint[n+9];
    sc("%s",txt);
    for(i=1 ; i<=n ; i++){
        sc("%s",str);
        endpoint[i] = addString(str);
    }
    push_SuffixLinks();

    sz = strlen(txt);
    for(i=0 ; i<sz ; i++){
        int ch = txt[i] - 'a';
        curr = jump(curr , ch);
        cnt[curr]++;
    }
    DFS(1);
    pf("Case %d:\n",t);
    for(i=1 ; i<=n ; i++){
        pf("%d\n",cnt[endpoint[i]]);
    }
    Clean();
}

int main()
{
    int t,T;
    scin(T);
    RUN_CASE(t,T)
    {
        Solve(t);
    }
    return 0;
}

/**
2
5
ababacbabc
aba
ba
ac
a
abc
3
lightoj
oj
light
lit

8
ababbbab
bab
aba
bbb
aa
a
abab
abba
bba
**/
