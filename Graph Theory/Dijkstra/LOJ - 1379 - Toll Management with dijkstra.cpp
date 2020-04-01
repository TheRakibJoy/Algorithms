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
#define longlimit               922337203685477
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
//ll BigMod(ll a,ll b){if(b == 0)return 1%MOD;else if(b%2 == 0){ll temp=BigMod(a,b/2);return ((temp%MOD)*(temp%MOD))%MOD;}else{return ((a%MOD)*BigMod(a,b-1)%MOD)%MOD;}}
//ll Power(ll a,ll n){ll ret=1;for(ll i=1 ; i<=n ; i++)ret = ((ret%MOD)*(a%MOD))%MOD;return ret;}
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

inline int add(int a, int b) {a += b; return a >= MOD ? a - MOD : a;}
inline int sub(int a, int b) {a -= b; return a < 0 ? a + MOD : a;}
inline int mul(int a, int b) {return (ll) a * b % MOD;}
int Set(int N, int pos) {return  N = N | (1<<pos);}
int Reset(int N, int pos) {return  N = N & ~(1<<pos);}
bool Cheek(int N, int pos) {return  (bool)(N & (1<<pos));}

///------------------Graph Moves-------------------
///const int fx[] = {+1,-1,+0,+0};
///const int fy[] = {+0,+0,+1,-1};
///const int fx[] = {+0,+0,+1,-1,-1,+1,-1,+1}; ///King's move
///const int fy[] = {-1,+1,+0,+0,+1,+1,-1,-1}; ///King's move
///const int fx[] = {-2,-2,-1,-1,+1,+1,+2,+2}; ///Knight's move
///const int fy[] = {-1,+1,-2,+2,-2,+2,-1,+1}; ///Knight's move

/**
Approach:
1. First make two graph. One as it given & the another one is the reverse of given one. Desired vector is graph[2][sz] ; Here-graph[0][i]..Original Graph. , graph[1][i]..Reverse graph
2. Find shortest path from source to all other node & store them in an array. Find shortest path from destination to all other node & store them in an array. Desired array is d[2][sz] ; Here d[0][i]-distance of source to node i , d[1][j]-distance of destination to node j.
3. Then, iterate over all edges (a,b). IF, d[0][source->a] + cost[a->b] + d[1][b->destination] <= Total TK then update your result for edge a-b.
**/

#define sz 10005
vl graph[2][sz],cost[2][sz];
pll edges[50005];
ll tottk,wt[50005],dis[2][sz];

struct node
{
    ll u,w;
    node(ll a,ll b){
        u = a; w = b;
    }
    bool operator < (const node &p)const{
        return w>p.w;
    }
};

void dijkstra(ll start,ll fg)
{
    for(ll i=0 ; i<sz ; i++)
        dis[fg][i] = longlimit;
    priority_queue<node>pq;
    pq.push(node(start , 0));
    dis[fg][start] = 0;
    while(!pq.empty()){
        node top = pq.top();
        pq.pop();
        ll u = top.u;
        if(top.w > dis[fg][u])
            continue;
        for(ll i=0 ; i<(ll)graph[fg][u].size() ; i++){
            ll v = graph[fg][u][i];
            if(top.w+cost[fg][u][i] < dis[fg][v]){
                dis[fg][v] = top.w+cost[fg][u][i];
                pq.push(node(v , dis[fg][v]));
            }
        }
    }
}

void Clean(ll n)
{
    for(ll i=0 ; i<=1 ; i++){
        for(ll j=0 ; j<=n+1 ; j++){
            graph[i][j].clear();
            cost[i][j].clear();
        }
    }
}

void Solve(int t)
{
    bool fg = 0;
    ll i,j,k,n,m,u,v,w,start,des,ans=0,part1,part2,part3;
    sc("%lld %lld %lld %lld %lld",&n,&m,&start,&des,&tottk);
    for(i=1 ; i<=m ; i++){
        sc("%lld %lld %lld",&u,&v,&w);
        graph[0][u].pb(v);
        cost[0][u].pb(w);
        graph[1][v].pb(u);
        cost[1][v].pb(w);
        edges[i] = {u,v};
        wt[i] = w;
    }

    dijkstra(start , 0);

    dijkstra(des , 1);

    for(i=1 ; i<=m ; i++){
        u = edges[i].first;
        v = edges[i].second;
        w = wt[i];
        part1 = dis[0][u];
        part2 = w;
        part3 = dis[1][v];
        if(part1+part2+part3 <= tottk){
            fg = 1;
            ans = max(ans , w);
        }
    }
    if(!fg)
        ans = -1;
    pf("Case %d: %lld\n",t,ans);
    Clean(n);
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
