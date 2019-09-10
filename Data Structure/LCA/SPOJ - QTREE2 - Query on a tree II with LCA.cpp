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

/** Problem: You r given a tree with n nodes & n-1 edges with w cost
    We will ask you to perfrom some instructions of the following form:
    DIST a b : ask for the distance between node a and node b
    or
    KTH a b k : ask for the k-th node on the path from node a to node b
    Solution:
    dis(a,b) = dis(root,a)+dis(root,b) - 2*dis(root,LCA)
**/
#define sz 100005
bool vis[sz];
ll level[sz],parent[sz],sptable[sz][25],dis[sz];
vector<ll> graph[sz],cost[sz];
void BFS(ll start)  /** Pre-calculate the parent,level & distance of each node from root node **/
{
    ms(level,0);
    ms(vis,0);
    ms(parent,-1);
    queue<ll>q;
    vis[start]=1;
    level[start]=0;
    dis[start]=0;
    q.push(start);
    while(!q.empty())
    {
        ll u=q.front();
        q.pop();
        for(ll i=0 ; i<(ll)graph[u].size() ; i++)
        {
            int v=graph[u][i];
            if(!vis[v])
            {
                vis[v] = 1;
                dis[v] = cost[u][i]+dis[u];
                level[v] = 1+level[u];
                parent[v] = u;
                q.push(v);
            }
        }
    }
}
void LCA_Init(ll n)                     /** Here, n is the number of node **/
{
    ms(sptable,-1);                     /** Initially, 2^j th parent of each node is -1 **/
    for(int i=1 ; i<=n ; i++)
        sptable[i][0] = parent[i];      /** 2^0 th parent of each node is its original parent **/
    for(int j=1 ; (1<<j)<=n ; j++)
    {
        for(int i=1 ; i<=n ; i++)
        {
            if(sptable[i][j-1] != -1)
            {
                sptable[i][j] = sptable[sptable[i][j-1]][j-1];  /** kono node er 2^j th parent holo
                oi node er 2^j-1 th parent er 2^j-1 th parent. For example, 1ta node er
                2^4=16th parent holo tar 2^3=8th parent er 2^3=8th parent **/
            }
        }
    }
}
ll LCA_Query(ll n,ll p,ll q)            /** Here, n is the number of node. p & q are two nodes whose LCA we've to found out **/
{
    if(level[p] < level[q])
        swap(p,q);                      /** P will always be more deeper node than q **/
    ll Log=1;
    while(1)
    {
        ll nxt=1+Log;
        if((1<<nxt) > level[p])
            break;
        Log++;
    }
    for(ll i=Log ; i>=0 ; i--)          /** Took p & q in same level **/
    {
        if(level[p]-(1<<i) >= level[q])
            p = sptable[p][i];
    }
    if(p == q)
        return p;
    for(ll i=Log ; i>=0 ; i--)          /** Now,both nodes r in same level. Here we'll try to take both of them in a level together where parent of both of them will be equal **/
    {
        if(sptable[p][i]!=-1 && sptable[p][i]!=sptable[q][i])
        {
            p=sptable[p][i];
            q=sptable[q][i];
        }
    }
    return parent[p];
}
ll KthNodeInPath(ll n,ll u,ll v,ll k)       /** We've to found out the k-th node on the path from node u to node v **/
{
    k-=1;                                   /** u is the 1st node in the path which is already discovered,so decrease k by 1 **/
    ll Log=0,dist,lca;
    lca = LCA_Query(n,u,v);                 /** To move on the path from u to v we've to know the LCA for turning up **/
    dist = abs(level[u]-level[lca]);        /** From u to LCA how many level I can move **/
    while(1)
    {
        ll nxt=1+Log;
        if((1<<nxt) > dist)
            break;
        Log++;
    }
    for(ll i=Log ; i>=0 ; i--)
    {   /** level[sptable[u][i]]>=level[lca] means that I can't go to upper level from LCA ; I've to turn to v from LCA **/
        if((1<<i)<=k && sptable[u][i]!=-1 && level[sptable[u][i]]>=level[lca])      /** One kind of BS **/
        {   /**     move u to maximum(LCA,kth node on the path)     **/
            k -= (1<<i);
            u = sptable[u][i];
        }
    }
    if(k > 0)
    {   /** K>0 means we didn't go k th node yet ; So,we've to turn up through LCA and go deeper to node v  **/
        k = level[v]-k-level[lca];  /** We've to go upper of k level from node v for found out kth node from u **/
        Log=0;
        dist = abs(level[v]-level[lca]);    /** From v to LCA how many level I can move **/
        while(1)
        {
            ll nxt=1+Log;
            if((1<<nxt) > dist)
                break;
            Log++;
        }
        for(ll i=Log ; i>=0 ; i--)      /** One kind of BS **/
        {
            if((1<<i)<=k && sptable[v][i]!=-1 && level[sptable[v][i]]>=level[lca])
            {
                k -= (1<<i);
                v = sptable[v][i];
            }
        }
        return v;
    }
    else
        return u;
}
void Clean(ll n)
{
    for(ll i=0 ; i<=n ; i++)
    {
        graph[i].clear();
        cost[i].clear();
    }
}
int32_t main()
{
    ll i,j,k,t,T,u,v,d,n,ans,lca;
    scln(T);
    RUN_CASE(t,T)
    {
        scln(n);
        rep(i,2,n)
        {
            scln2(u,v);
            scln(d);
            graph[u].pb(v);
            graph[v].pb(u);
            cost[u].pb(d);
            cost[v].pb(d);
        }
        BFS(1);
        LCA_Init(n);
        string cmd;
        while(1)
        {
            cin>>cmd;
            if(cmd == "DONE")
                break;
            else if(cmd == "DIST")
            {
                scln2(u,v);
                lca = LCA_Query(n,u,v);
                ans = dis[u]+dis[v]-2*dis[lca];
                pf("%lld\n",ans);
            }
            else
            {
                scln2(u,v);
                scln(k);
                ans = KthNodeInPath(n,u,v,k);
                pf("%lld\n",ans);
            }
        }
        pf("\n");
        Clean(n);
    }
    return 0;
}
