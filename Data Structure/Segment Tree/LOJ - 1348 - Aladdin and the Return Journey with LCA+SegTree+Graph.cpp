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
/**     toint, tostring, BigMod, Power , sieve, Primefactorize ,frequency in n!     **/
//ll toint(string s){ll n=0,k=1;for(int i=s.size()-1; i>=0; i--){n += ((s[i]-'0')*k);k*=10;}return n;}
//string tostring(ll x){string s="";while(x){s += (x%10)+'0';x/=10;}reverse(s.begin(),s.end());return s;}
//vector<ll>Prime;
//bool mark[10000003];
//void sieve(ll n){ll i,j;mark[1]=1;for(i=4; i<=n; i+=2)mark[i]=1;Prime.push_back(2);for(i=3; i<=n; i+=2){if(!mark[i]){Prime.push_back(i);if(i*i<=n){for(j=i*i; j<=n; j+=(i*2))mark[j]=1;}}}}
//map<ll,ll>Factor;
//void Primefactorize(ll n){for(ll i=0; i<Prime.size() && Prime[i]*Prime[i]<=n; i++){if(n%Prime[i] == 0){while(n%Prime[i] == 0){Factor[Prime[i]]++;n/=Prime[i];}}}if(n>1){Factor[n]++;}}
//ll frequency(ll n,ll factor)/** Frequency of a factor in n! **/{ll cnt=0;while(n){cnt += (n/factor);n /= factor;}return cnt;}
/**     Order Set       **/
//#include <ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;
//template<typename T> using orderset = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
//orderset<int> s ; //orderset<int>::iterator it ;
//orderset<int> X; //X.insert(1); //X.insert(2); //X.insert(4); //X.insert(8); //X.insert(16);
//cout<<*X.find_by_order(0)<<endl; // 2 //cout<<*X.find_by_order(2)<<endl; // 4 //cout<<*X.find_by_order(4)<<endl; // 16 //cout<<(end(X)==X.find_by_order(6))<<endl; // true
//cout<<X.order_of_key(-5)<<endl;  // 0 //cout<<X.order_of_key(1)<<endl;   // 0 //cout<<X.order_of_key(3)<<endl;   // 2 //cout<<X.order_of_key(4)<<endl;   // 2 //cout<<X.order_of_key(400)<<endl; // 5
///------------------Graph Moves-------------------
///const int fx[] = {+1,-1,+0,+0};
///const int fy[] = {+0,+0,+1,-1};
///const int fx[] = {+0,+0,+1,-1,-1,+1,-1,+1}; ///King's move
///const int fy[] = {-1,+1,+0,+0,+1,+1,-1,-1}; ///King's move
///const int fx[] = {-2,-2,-1,-1,+1,+1,+2,+2}; ///Knight's move
///const int fy[] = {-1,+1,-2,+2,-2,+2,-1,+1}; ///Knight's move

/** You're given a graph contains n node & m edges. You've to operate two different queries:
    q1. Update the cost of node x to v
    q2. Answer the total node cost between two nodes not necessary to be ancestor , decendend
    You've to perform 10^5 queries
**/
#define sz 30005
bool vis[sz];
int level[sz],parent[sz],sptable[sz][22],st[sz],ed[sz],cost[sz],ara[2*sz],tree[6*sz],curr_time;
/** level-level of each node ; parent-parent of each node ; stable-sparse table ;
    st-discovering time of each node ; ed-finishing time of each node ;
    cost-number of genies in each node ; ara-reforming cost by discovering & finishing time
    tree-build segment tree **/
vi graph[sz];
/** LCA part **/
void BFS(int start)         /** Pre-calculate the parent & level of each node **/
{
    ms(parent,-1);
    ms(vis,0);
    ms(level,0);
    queue<int>q;
    vis[start]=1;
    level[start]=0;
    q.push(start);
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(int i=0 ; i<graph[u].size() ; i++)
        {
            int v=graph[u][i];
            if(!vis[v])
            {
                vis[v] = 1;
                parent[v] = u;
                level[v] = 1+level[u];
                q.push(v);
            }
        }
    }
}
void LCA_Init(int n)            /** Here, n is the number of node **/
{
    ms(sptable,-1);                  /** Initially, 2^j th parent of each node is -1 **/
    for(int i=1 ; i<=n ; i++)
        sptable[i][0] = parent[i];   /** 2^0 th parent of each node is its original parent **/
    for(int j=1 ; (1<<j)<=n ; j++){
        for(int i=1 ; i<=n ; i++){
            if(sptable[i][j-1] != -1)
            {
                sptable[i][j] = sptable[sptable[i][j-1]][j-1];     /** kono node er 2^j th parent holo
                oi node er 2^j-1 th parent er 2^j-1 th parent. For example, 1ta node er
                2^4=16th parent holo tar 2^3=8th parent er 2^3=8th parent **/
            }
        }
    }
}
int LCA_Query(int n,int p,int q)    /** Here, n is the number of node. p & q are two nodes whose LCA we've to found out **/
{
    if(level[p] < level[q])
        swap(p,q);                  /** P will always be more deeper node than q **/
    int Log=1;
    while(1){
        int nxt = Log+1;
        if((1<<nxt) > level[p])
            break;
        Log++;
    }
    for(int i=Log ; i>=0 ; i--){    /** Took p & q in same level **/
        if(level[p]-(1<<i) >= level[q])
            p = sptable[p][i];
    }
    if(p == q)
        return p;   /** Here,q is the ancestor of p **/
    for(int i=Log ; i>=0 ; i--)     /** Now,both nodes r in same level. Here we'll try to take both of them in a level together where parent of both of them will be equal **/
    {
        if(sptable[p][i]!=-1 && sptable[p][i]!=sptable[q][i])
        {
            p=sptable[p][i];
            q=sptable[q][i];
        }
    }
    return parent[p];
}
/** Segment Tree Part **/
void DFS(int start)
{
    vis[start]=1;
    st[start] = ++curr_time;
    for(int i=0 ; i<graph[start].size() ; i++)
    {
        int v=graph[start][i];
        if(!vis[v])
            DFS(v);
    }
    ed[start] = ++curr_time;
}
void init(int node,int b,int e)
{
    if(b == e)
    {
        tree[node] = ara[b];
        return;
    }
    int lft=node*2;
    int rgt=lft+1;
    int mid=(b+e)/2;
    init(lft,b,mid);
    init(rgt,mid+1,e);
    tree[node] = tree[lft]+tree[rgt];
}
void update(int node,int b,int e,int i,int val)
{
    if(i>e || i<b)
        return;
    if(i==b && i==e)
    {
        tree[node]=val;
        return;
    }
    int lft=node*2;
    int rgt=lft+1;
    int mid=(b+e)/2;
    update(lft,b,mid,i,val);
    update(rgt,mid+1,e,i,val);
    tree[node] = tree[lft]+tree[rgt];
}
int query(int node,int b,int e,int i,int j)
{
    if(i>e || j<b)
        return 0;
    if(b>=i && e<=j)
        return tree[node];
    int lft=node*2;
    int rgt=lft+1;
    int mid=(b+e)/2;
    int p1 = query(lft,b,mid,i,j);
    int p2 = query(rgt,mid+1,e,i,j);
    return p1+p2;
}
void Clean(int n)
{
    curr_time=0;
    for(int i=0 ; i<=n ; i++)
    {
        graph[i].clear();
        vis[i]=0;
        parent[i]=-1;
    }
}
int main()
{
//    Output;
    int i,j,k,t,T,n,u,v,q,id,lca,tot,start,finish,p1,p2;
    scin(T);
    RUN_CASE(t,T)
    {
        scin(n);
        rep(i,1,n)scin(cost[i]);
        rep(i,2,n)
        {
            scin2(u,v);
            graph[u+1].pb(v+1);
            graph[v+1].pb(u+1);
        }
        DFS(1);
        for(i=1 ; i<=n ; i++)
        {
            start = st[i];
            finish = ed[i];
            ara[start] = cost[i];
            ara[finish] = -cost[i];
        }
        init(1,1,2*n);
        BFS(1);
        LCA_Init(n);
        scin(q);
        pf("Case %d:\n",t);
        rep(i,1,q)
        {
            sc("%d %d %d",&id,&u,&v);
            if(id)
            {
                u+=1;
                cost[u] = v;
                update(1,1,2*n,st[u],v);
                update(1,1,2*n,ed[u],-v);
            }
            else
            {
                u+=1;v+=1;
                if(u > v)swap(u,v);
                lca = LCA_Query(n,u,v);
                start = min(st[u] , st[lca]);
                finish = max(st[u] , st[lca]);
                p1 = query(1,1,2*n,start,finish);
                start = min(st[v] , st[lca]);
                finish = max(st[v] , st[lca]);
                p2 = query(1,1,2*n,start,finish);
                tot = p1+p2-cost[lca];
                pf("%d\n",tot);
            }
        }
        Clean(n);
    }
    return 0;
}

