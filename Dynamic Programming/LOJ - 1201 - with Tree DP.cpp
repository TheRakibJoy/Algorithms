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

/** Tree DP Template-1 **/
/** Problem: I have a list of N mosquitoes which are to be killed. But there is a small
    problem. If I kill a mosquito, all of his friends will be informed, so they will be
    prepared for my attack, thus they will be impossible to kill. But there is a surprising
    fact. That is if I denote them as a node and their friendship relations as edges, the
    graph becomes acyclic.
    Find the maximum number of mosquito I can kill. **/
int dp[2][1005][1005]; /** State-1:Can this node be taken or not? ; State-2:Node no. ; State-3: Parent of this node **/
bool vis[1005];
vi graph[1005];
void Clean(int n){
    for(int i=0 ; i<=n ; i++)
        graph[i].clear();
}
int FuN(bool canbetaken,int node,int parent)
{
    vis[node] = 1;
    if(dp[canbetaken][node][parent] != -1)
        return dp[canbetaken][node][parent];
    int ret1=0,ret2=0;
    if(canbetaken){
        ret1 = 1;   /** Take this node & traverse through the child of present node & sum up their result **/
        for(int i=0 ; i<(int)graph[node].size() ; i++){
            int v = graph[node][i];
            if(v == parent)
                continue;
            ret1 += FuN(0 , v , node);
        }
    }
    for(int i=0 ; i<(int)graph[node].size() ; i++){
        int v=graph[node][i];   /** Don't take this node & traverse through the child of this node & sum up their result **/
        if(v == parent)
            continue;
        ret2 += FuN(1 , v , node);
    }
    return dp[canbetaken][node][parent] = max(ret1 , ret2); /** Maximize the result by take or don't take **/
}
int main()
{
    int i,j,k,n,m,u,v,t,T,ans;
    scin(T);
    RUN_CASE(t,T)
    {
        ms(dp,-1);
        ms(vis,0);
        scin2(n,m);
        rep(i,1,m)
        {
            scin2(u,v);
            graph[u].pb(v);
            graph[v].pb(u);
        }
        ans = 0;
        for(i=1 ; i<=n ; i++)
        {
            if(!vis[i])
                ans += FuN(1,i,0);
        }
        pf("Case %d: %d\n",t,ans);
        Clean(n);
    }
    return 0;
}

