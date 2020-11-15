///****In the name of ALLAH, most Gracious, most Compassionate****//
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
#define longlimit               1e17
#define infinity                (1<<28)
#define gcd(a,b)                __gcd(a,b)
#define lcm(a,b)                (a)*(b)/gcd(a,b)
#define mxx                     123456789
#define PI                      2*acos(0.0)
#define rep(i,a,b)              for(__typeof(i) i=a;i<=b;i++)
#define rev(i,a,b)              for(__typeof(i) i=a;i>=b;i--)
#define coutv(v)                for(auto it:v)cout<<it<<' ';cout<<endl;
#define cinv(v)                 for(auto &it:v)cin>>it;
#define srt(v)                  sort(v.begin(),v.end());
#define rsrt(v)                 sort(v.rbegin(),v.rend());
#define rvs(v)                  reverse(v.begin(),v.end());

using namespace std;
/**     toint, tostring, BigMod, Power , sieve, Primefactorize ,frequency in n!     **/
//ll toint(string s){ll n=0,k=1;for(int i=s.size()-1; i>=0; i--){n += ((s[i]-'0')*k);k*=10;}return n;}
//string tostring(ll x){string s="";while(x){s += (x%10)+'0';x/=10;}reverse(s.begin(),s.end());return s;}
//ll BigMod(ll a,ll b){if(b == 0)return 1%MOD;else if(b%2 == 0){ll temp=BigMod(a,b/2);return ((temp%MOD)*(temp%MOD))%MOD;}else{return ((a%MOD)*BigMod(a,b-1)%MOD)%MOD;}}
//ll Power(ll a,ll n){ll ret=1;for(ll i=1 ; i<=n ; i++)ret = ((ret%MOD)*(a%MOD))%MOD;return ret;}
//bool isPrime(ll n){for(ll i=2 ; i*i<=n ; i++){if(n%i == 0)return 0;}return 1;}
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

/** Debugging Tool **/
#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args)
{
    cerr << *it << " = " << a << endl;
    err(++it, args...);
}
///

inline int add(int a, int b) {a += b; return a >= MOD ? a - MOD : a;}
inline int sub(int a, int b) {a -= b; return a < 0 ? a + MOD : a;}
inline int mul(int a, int b) {return (ll) a * b % MOD;}
int Set(int N, int pos) {return  N = N | (1<<pos);}
int Reset(int N, int pos) {return  N = N & ~(1<<pos);}
bool Cheek(ll N, ll pos) {return  (bool)(N & (1LL<<pos));}

#define sz 100009
ll ans=longlimit,bitfre[65],ara[sz],level[sz],vis[sz],parent[sz];
vl conn[65],graph[sz];
set<pii>edges;
set<pii>cycles;
vi nodes;

void DFS(ll u,ll par,ll lev)
{
    vis[u] = 1;
    level[u] = lev;
    parent[u] = par;
    for(ll v : graph[u]){
        if(!vis[v])
            DFS(v , u , 1+lev);
        else if(v != parent[u] && level[v] < level[u]){
            cycles.insert({min(u , v) , max(u , v)});
        }
    }
}

map<pii , int>forbiddenEdge;

int BFS(int src,int dest)
{
    queue<int>q;
    q.push(src);
    vis[src] = 1;
    level[src] = 1;
    while(!q.empty()){
        int u = q.front();
        q.pop();

        for(int v : graph[u]){
            if(forbiddenEdge[{u , v}] || forbiddenEdge[{v , u}])
                continue;
            if(!vis[v]){
                q.push(v);
                vis[v] = 1;
                level[v] = 1+level[u];
            }
        }
    }
    return level[dest];
}

void Solve(int t)
{
    ll i,j,k,n,u,v;
    scln(n);
    for(i=1 ; i<=n ; i++){
        scln(ara[i]);
        if(ara[i] == 0)
            continue;
        for(j=0 ; j<=60 ; j++){
            if(Cheek(ara[i] , j)){
                bitfre[j]++;
                conn[j].pb(i);
            }

            if(bitfre[j] >= 3){
                ans = 3;
            }
        }
    }
    if(ans == longlimit){
        for(i=0 ; i<=60 ; i++){
            if(bitfre[i] >= 2){
                u = conn[i][0];
                v = conn[i][1];
                edges.insert({min(u , v) , max(u , v)});
            }
        }

        for(auto it : edges){
            u = it.first;
            v = it.second;
            graph[u].pb(v);
            graph[v].pb(u);
            nodes.pb(u);
            nodes.pb(v);
        }

        SORT_UNIQUE(nodes);

        for(i=1 ; i<=n ; i++){
            if(!vis[i])
                DFS(i , -1 , 0);
        }

        for(auto it : cycles){
            int src = it.first;
            int dest = it.second;

            forbiddenEdge[{src , dest}] = forbiddenEdge[{dest , src}] = 1;

            for(auto x : nodes)
                vis[x] = level[x] = 0;
            ans = min(ans , (ll)BFS(src , dest));

            forbiddenEdge[{src , dest}] = forbiddenEdge[{dest , src}] = 0;
        }
    }

    if(ans == longlimit)
        ans = -1;
    cout<<ans<<endl;
}

int main()
{
    int t,T;
    T = 1;
//    cin>>T;
    RUN_CASE(t,T)
    {
        Solve(t);
    }
    return 0;
}

/** Stuff u should look for
    * Avoid overflow
    * Corner(Small) case
    * Don't get stuck on one approach
    * Don't forget to clean used memory in each case
**/
/**
7
5 42 80 192 160 9 22
ANS: 4
**/

