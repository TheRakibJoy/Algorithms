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
Problem:
এই প্রবলেমটা অনেক মজার এবং  basic DP on tree বুঝার জন্য অনেক ভাল একটা প্রবলেম । এইখানে n জন মানুষকে একটা পার্টিতে দাওয়াত দিতে  হবে , এবং প্রতিটা মানুষ এর পার্টিটা জমাইয়া রাখার কিছু রেটিং পয়েন্ট আছে । আমাদের নরমাল লাইফে এ দেখা যায় কিছু মানুষ জন আছে যারা অনেক মজা করতে পারে , তারা কোন অনুষ্ঠানে থাকলে সবাই অনেক মজা পায় আবার কেউ কেউ অনেক গম্ভীর তাদের থাকা না থাকা একই ব্যাপার , আবার কেউ কেউ অনেক রাগী তারা না থাকলেই ভাল ।  এইখানে আরো একটা শর্ত দেওয়া আছে । যেহেতু এইটা একটা প্রতিষ্ঠানের পার্টি  এইখানে কোন বস তার ইমেডিয়েট জুনিওর থাকলে ঐ পার্টিতে যায় না , জুনিওর এর ক্ষেত্রেও একই । মানে হইল হয় বস থাকবে না হয় জুনিওর থাকবে বা কেউই থাকবে না । আমাদের এমনভাবে পার্টি করার জন্য সবাইকে দাওয়াত দিতে হবে যেন পার্টিটা সব থেকে বেশী মজার হয় ।
**/
#define sz 6005
int vis[sz],par[sz],rating[sz],dp[5][sz];
vi graph[sz];
void DFS(int start)
{
    vis[start] = 1;
    for(int i=0 ; i<(int)graph[start].size() ; i++){
        int v = graph[start][i];
        if(!vis[v]){
            par[v] = start;
            DFS(v);
        }
    }
}
int FuN(int isParTaken,int node)
{
    if(dp[isParTaken][node] != -1)
        return dp[isParTaken][node];
    int ret1=0,ret2=0;
    if(isParTaken){     ///IF I have taken its parent(BOSS),then I can't take this node(employee)
        ret1 = 0;
        for(int i=0 ; i<(int)graph[node].size() ; i++){
            int v = graph[node][i];
            if(v != par[node])
                ret1 += FuN(0 , v);
        }
    }
    else{   ///IF I haven't taken its parent(BOSS),then I can take it(employee) or leave it(employee)
        ret1 = rating[node];
        for(int i=0 ; i<(int)graph[node].size() ; i++){
            int v = graph[node][i];
            if(v != par[node]){
                ret1 += FuN(1 , v);
            }
        }
        ret2 = 0;
        for(int i=0 ; i<(int)graph[node].size() ; i++){
            int v = graph[node][i];
            if(v != par[node])
                ret2 += FuN(0 , v);
        }
    }
    return dp[isParTaken][node] = max(ret1 , ret2);
}

int main()
{
    int i,j,k,n,ans,u,v;
    scin(n);
    for(i=1 ; i<=n ; i++)
        scin(rating[i]);
    while(1){
        scin2(u,v);
        if(u==0 && v==0)
            break;
        graph[u].pb(v);
        graph[v].pb(u);
    }
    par[1] = -1;
    DFS(1);
    ms(dp , -1);
    ans = FuN(0 , 1);
    cout<<ans<<endl;
    return 0;
}

