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
///------------------Graph Moves-------------------
///const int fx[] = {+1,-1,+0,+0};
///const int fy[] = {+0,+0,+1,-1};
///const int fx[] = {+0,+0,+1,-1,-1,+1,-1,+1}; ///King's move
///const int fy[] = {-1,+1,+0,+0,+1,+1,-1,-1}; ///King's move
///const int fx[] = {-2,-2,-1,-1,+1,+1,+2,+2}; ///Knight's move
///const int fy[] = {-1,+1,-2,+2,-2,+2,-1,+1}; ///Knight's move

#define sz 100005
vi graph[sz];
int n,vis[sz],level[sz],cost[4][sz];
pii ans;
ll tot = 0LL , optimal=longlimit;
vector<pair<int,int> >vec;
int deep1,deep2,deep3;
int BFS(int start)
{
    int mxdis=0,node=start;
    ms(vis,0);
    ms(level,0);
    queue<int>q;
    vis[start] = 1;
    level[start] = 0;
    q.push(start);
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for(int i=0 ; i<(int)graph[u].size() ; i++){
            int v = graph[u][i];
            if(!vis[v]){
                q.push(v);
                vis[v] = 1;
                level[v] = 1+level[u];
            }
        }
    }
    for(int i=1 ; i<=n ; i++){
        if(level[i] > mxdis){
            mxdis = level[i];
            node = i;
        }
    }
    return node;
}
void DFS(int last,int secondlast,int node)
{
    int fg = 1;
    if(last!=1 && secondlast!=1)
        vis[node]=1 , fg=1;
    else if(last!=2 && secondlast!=2)
        vis[node]=2 , fg=2;
    else
        vis[node]=3 , fg=3;
    tot += cost[fg][node];
    for(int i=0 ; i<(int)graph[node].size() ; i++){
        int v = graph[node][i];
        if(vis[v] == 0)
            DFS(fg , last , v);
    }
}
int main()
{
    bool fg = 1;
    int i,j,k,u,v,mn,mx;
    ll res;
    scin(n);
    rep(i,1,n)scin(cost[1][i]);
    rep(i,1,n)scin(cost[2][i]);
    rep(i,1,n)scin(cost[3][i]);
    for(i=1 ; i<n ; i++){
        scin2(u,v);
        if(u > v)
            swap(u,v);
        graph[u].pb(v);
        graph[v].pb(u);
    }
    for(i=1 ; i<=n ; i++){
        if((int)graph[i].size() >= 3){
            pf("-1\n");
            return 0;
        }
    }
    vec.pb(make_pair(1,2) );
    vec.pb(make_pair(2,1) );
    vec.pb(make_pair(1,3) );
    vec.pb(make_pair(3,1) );
    vec.pb(make_pair(2,3) );
    vec.pb(make_pair(3,2) );
    ///
    deep1 = BFS(1);
    deep2 = graph[deep1][0];
    deep3 = -1;
    for(i=0 ; i<(int)graph[deep2].size() ; i++){
        if(graph[deep2][i] != deep1){
            deep3 = graph[deep2][i];
            break;
        }
    }
    if(deep3 == -1){
        for(i=0 ; (int)i<graph[deep1].size() ; i++){
            if(graph[deep1][i] != deep2){
                deep3 = graph[deep1][i];
                break;
            }
        }
    }
    for(i=0 ; i<6 ; i++){
        ms(vis,0);
        tot = 0LL;
        ///
        pii temp = vec[i];
        vis[deep1] = temp.first;
        vis[deep2] = temp.second;
        tot += (cost[temp.first][deep1] + cost[temp.second][deep2]);
        DFS(temp.second , temp.first , deep3);
        if(tot < optimal){
            optimal = tot;
            ans = temp;
        }
    }
    cout<<optimal<<endl;
    ms(vis,0);
    pii temp = ans;
    vis[deep1] = temp.first;
    vis[deep2] = temp.second;
    DFS(temp.second , temp.first , deep3);
    for(i=1 ; i<=n ; i++)
        cout<<vis[i]<<' ';
    cout<<endl;
    return 0;
}

