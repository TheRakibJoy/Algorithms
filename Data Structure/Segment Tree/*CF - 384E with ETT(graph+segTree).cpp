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
bool Cheek(int N, int pos) {return  (bool)(N & (1<<pos));}

//string small = "abcdefghijklmnopqrstuvwxyz";
//string capital = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

///------------------Graph Moves-------------------
///const int fx[] = {+1,-1,+0,+0};
///const int fy[] = {+0,+0,+1,-1};
///const int fx[] = {+0,+0,+1,-1,-1,+1,-1,+1}; ///King's move
///const int fy[] = {-1,+1,+0,+0,+1,+1,-1,-1}; ///King's move
///const int fx[] = {-2,-2,-1,-1,+1,+1,+2,+2}; ///Knight's move
///const int fy[] = {-1,+1,-2,+2,-2,+2,-1,+1}; ///Knight's move

#define sz 400009
int tree[2][4*sz],lazy[2][4*sz];  ///tree[0]-for even level ; tree[1]-for odd level

void pushdown(int id,int node,int b,int e)
{
    tree[id][node] += lazy[id][node];
    if(b != e){
        lazy[id][node<<1] += lazy[id][node];
        lazy[id][1+(node<<1)] += lazy[id][node];
    }
    lazy[id][node] = 0;
}

void Update(int id,int node,int b,int e,int i,int j,int val)
{
    if(lazy[id][node] != 0)
        pushdown(id , node , b , e);
    if(b>j || e<i)
        return;
    if(b>=i && e<=j){
        tree[id][node] += val;
        if(b != e){
            lazy[id][node<<1] += val;
            lazy[id][1+(node<<1)] += val;
        }
        return;
    }
    int lft = node<<1;
    int rgt = 1+lft;
    int mid = (b+e)>>1;
    Update(id , lft , b , mid , i , j , val);
    Update(id , rgt , mid+1 , e , i , j , val);
    tree[id][node] = tree[id][lft]+tree[id][rgt];
}

int Query(int id,int node,int b,int e,int i,int j)
{
    if(b>j || e<i)
        return 0;
    if(lazy[id][node] != 0)
        pushdown(id , node , b , e);
    if(b>=i && e<=j)
        return tree[id][node];
    int lft = node<<1;
    int rgt = lft+1;
    int mid = (b+e)>>1;
    int p1 = Query(id , lft , b , mid , i , j);
    int p2 = Query(id , rgt , mid+1 , e , i , j);
    return p1+p2;
}

///graph part
int tim=0,stime[sz/2],edtime[sz/2],level[sz/2],vis[sz/2],ara[sz/2];
vi graph[sz/2];

void DFS(int u,int lv)
{
    vis[u] = 1;
    stime[u] = ++tim;
    level[u] = lv;
    for(auto v:graph[u]){
        if(!vis[v]){
            DFS(v , 1+lv);
        }
    }
    edtime[u] = ++tim;
}

void Solve(int t)
{
    int i,j,k,n,q,type,u,v,x,ans;
    scin2(n , q);
    rep(i,1,n)scin(ara[i]);
    for(i=1 ; i<n ; i++){
        scin2(u , v);
        graph[u].pb(v);
        graph[v].pb(u);
    }
    DFS(1 , 1);
    for(i=1 ; i<=q ; i++){
        scin(type);
        if(type == 1){
            scin2(u , x);
            if(level[u]%2 == 0){
                Update(0 , 1 , 1 , 2*n , stime[u] , edtime[u] , x);
                Update(1 , 1 , 1 , 2*n , stime[u] , edtime[u] , -x);
            }
            else{
                Update(0 , 1 , 1 , 2*n , stime[u] , edtime[u] , -x);
                Update(1 , 1 , 1 , 2*n , stime[u] , edtime[u] , x);
            }
        }
        else{
            scin(u);
            if(level[u]%2 == 0)
                cout<<Query(0 , 1 , 1 , 2*n , stime[u] , stime[u])+ara[u]<<endl;
            else
                cout<<Query(1 , 1 , 1 , 2*n , stime[u] , stime[u])+ara[u]<<endl;
        }
    }
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


