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

//string small = "abcdefghijklmnopqrstuvwxyz";
//string capital = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

///------------------Graph Moves-------------------
///const int fx[] = {+1,-1,+0,+0};
///const int fy[] = {+0,+0,+1,-1};
///const int fx[] = {+0,+0,+1,-1,-1,+1,-1,+1}; ///King's move
///const int fy[] = {-1,+1,+0,+0,+1,+1,-1,-1}; ///King's move
///const int fx[] = {-2,-2,-1,-1,+1,+1,+2,+2}; ///Knight's move
///const int fy[] = {-1,+1,-2,+2,-2,+2,-1,+1}; ///Knight's move


int bicolorable=1,n,m,n1,n2,n3,color[5005],frecolor[3],res[5005];
vi graph[5005];
vi subgraph[5005];

void DFS(int u,int lastcolor,int id)
{
    subgraph[id].pb(u);
    int nowcolor = (lastcolor == 1)?2:1;
    frecolor[nowcolor]++;
    color[u] = nowcolor;
    for(auto v:graph[u]){
        if(color[v] == 0){
            DFS(v , nowcolor , id);
        }
        else{
            if(color[v] == nowcolor)
                bicolorable = 0;
        }
    }
}

vector<pii>vcolor;
int dp[5005][5005];
vi n2parallel;

int FuN(int pos,int twobaki)
{
    if(pos>=(int)vcolor.size()){
        if(twobaki == 0)
            return dp[pos][twobaki] = 1;
        else
            return 0;
    }
    if(dp[pos][twobaki] != -1)
        return dp[pos][twobaki];
    int ret1=0,ret2=0;
    if(twobaki-vcolor[pos].first >= 0)
        ret1 = FuN(pos+1 , twobaki-vcolor[pos].first);
    if(twobaki-vcolor[pos].second >= 0)
        ret2 = FuN(pos+1 , twobaki-vcolor[pos].second);
    return dp[pos][twobaki] = ret1|ret2;
}

void Print(int pos,int twobaki)
{
    if(pos>=(int)vcolor.size())
        return;
    int ret1=0,ret2=0;
    if(twobaki-vcolor[pos].first >= 0)
        ret1 = dp[pos+1][twobaki-vcolor[pos].first];
    if(twobaki-vcolor[pos].second >= 0)
        ret2 = dp[pos+1][twobaki-vcolor[pos].second];
    if(ret1 == 1){
        n2parallel.pb(1);
        Print(pos+1 , twobaki-vcolor[pos].first);
    }
    else if(ret2 == 1){
        n2parallel.pb(2);
        Print(pos+1 , twobaki-vcolor[pos].second);
    }
}

void Solve(int t)
{
    int i,j,k,u,v,subcnt=0,ans = 1;
    scin2(n , m);
    sc("%d %d %d",&n1,&n2,&n3);
    for(i=1 ; i<=m ; i++){
        scin2(u , v);
        graph[u].pb(v);
        graph[v].pb(u);
    }
    for(i=1 ; i<=n ; i++){
        if(color[i] == 0){
            ms(frecolor , 0);
            DFS(i , 1 , subcnt++);
            vcolor.pb(make_pair(frecolor[1] , frecolor[2]));
        }
    }
    ans &= bicolorable;
    ms(dp , -1);
    ans &= FuN(0 , n2);
    if(!ans){
        pf("NO\n");
        return;
    }
    else{
        Print(0 , n2);
        for(i=0 ; i<subcnt ; i++){
            for(auto node : subgraph[i]){
                if(color[node] == n2parallel[i])
                    res[node] = 2;
                else{
                    if(n1 > 0){
                        res[node] = 1;
                        n1--;
                    }
                    else
                        res[node] = 3;
                }
            }
        }
        pf("YES\n");
        for(i=1 ; i<=n ; i++)
            pf("%d",res[i]);
        pf("\n");
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
/**
5000 1
1000 0 4000
444 789

10 0
0 10 0
**/
