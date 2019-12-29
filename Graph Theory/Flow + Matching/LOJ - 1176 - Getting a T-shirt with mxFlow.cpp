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

/**
Problem:
In programming contests, a common problem for the contestants is to get a suited T-shirt. Sometimes people gets too long or too short T-shirts. So, this time I have planned to ask the authority to manage the T-shirts such that everyone gets a suitable one. From my past experience, it's known that there are 6 available sizes of T-shirts and they are XXL, XL, L, M, S, and XS. And exactly two sizes of the T-shirts suit a person.
Now, for a contest there are T-shirts of N colors and M contestants. And for each color, all the 6 sizes are available. So, there are 6*N T-shirts. And you are given the suitable sizes for each contestant. You have to distribute the T-shirts to the contestants such that everyone gets a suitable size. Only size matters, color is not an issue. Now you have to decide whether it's possible or not.
Solution:
1.  There're n different colors t-shirt. For each color,all 6 sizes are available.
    That means If we define sizes as XXL-1 ; XL-2 ; L-3 ; M-4 ; S-5 ; XS-6. Then,
    all this 6 nodes have capacity n.
    So, we've to split this 6 nodes as XXLin-1 ; XXLout-7 ; XLin-2 ; XLout-8 ;
    Lin-3 ; Lout-9 ; Min-4 ; Mout-10 ; Sin-5 ; Sout-11 ; XSin-6 ; XSout-12.
    So, edge capacity of all splitting nodes will be n.
2.  Now, we've to take a global source 0. And all the sizes will be connected
    to the global source with edge capacity infinity.
3.  Then, we'll connect every contestant(12+1 to 12+m) with their desired size's t-shirt.
4.  Then, we will connect every contestant(12+1 to 12+m) with the global sink
    12+m+1 with edge capacity 1 because each contestant can get exactly one t-shirt.
5.  Finally, every contestant will get a suitable t-shirt if sink get at least
    M flow.
**/

#define sz 121
bool vis[sz];
int n,m,par[sz],cap[sz][sz],flow[sz][sz];
bool BFS(int src,int des)
{
    ms(vis,0);
    queue<int>q;
    q.push(src);
    vis[src] = 1;
    par[src] = -1;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int v=1 ; v<=n ; v++){
            if(!vis[v] && (cap[u][v]-flow[u][v])>0){
                q.push(v);
                par[v] = u;
                vis[v] = 1;
            }
        }
    }
    return vis[des];
}
int FordFulkerson(int src,int des)
{
    int u,v,mxFlow=0;
    while(BFS(src,des)){
        int mnPathFlow = infinity;
        for(v=des ; v!=src ; v=par[v]){ /** Traverse the path & find out minimum edge capacity **/
            u = par[v];
            mnPathFlow = min(mnPathFlow , cap[u][v]-flow[u][v]);
        }
        for(v=des ; v!=src ; v=par[v]){ /** Update the flow for every edge of the path **/
            u = par[v];
            flow[u][v] += mnPathFlow;
            flow[v][u] -= mnPathFlow;
        }
        mxFlow += mnPathFlow;
    }
    return mxFlow;
}
void Clean()
{
    for(int i=0 ; i<=n ; i++){
        for(int j=0 ; j<=n ; j++){
            cap[i][j] = 0;
            flow[i][j] = 0;
        }
    }
}
string ToString(char *str,int len)
{
    string s="";
    for(int i=0 ; i<len ; i++){
        s += str[i];
    }
    return s;
}
map<string , int>sizeid;
int main()
{
    sizeid["XXL"] = 1;sizeid["XL"] = 2;sizeid["L"] = 3;
    sizeid["M"] = 4;sizeid["S"] = 5;sizeid["XS"] = 6;
    int i,j,k,t,T,color,contestant,ans,u,v;
    scin(T);
    RUN_CASE(t,T){
        scin2(color,contestant);
        m = contestant;
        /** Connect each size t-shirt with super source ; n=6 **/
        for(i=1 ; i<=6 ; i++){
            cap[0][i] = infinity;
        }
        /** Split each size t-shirt in two nodes ; n=12 **/
        for(i=1 ; i<=6 ; i++){
            cap[i][i+6] = color;
        }
        char s1[5],s2[5];
        string s3,s4;
        /** Connect each contestant with their desired size's t-shirt ; n=12+m **/
        for(i=1 ; i<=contestant ; i++){
            sc("%s %s",s1,s2);
            s3 = ToString(s1 , strlen(s1));
            s4 = ToString(s2 , strlen(s2));

            u = sizeid[s3]+6;  /** sizeOut will connect with contestant with edge capacity 1 **/
            v = 12+i;
            cap[u][v] = 1;

            u = sizeid[s4]+6;
            cap[u][v] = 1;
        }
        /** Connect each contestant with super sink with edge capacity 1. Because , each of them can get exactly one t-shirt , n=12+m+1 **/
        for(i=1 ; i<=contestant ; i++){
            u = 12+i;
            v = 12+m+1;
            cap[u][v] = 1;
        }
        n = 12+m+1;
        ans = FordFulkerson(0 , n);
        if(ans >= contestant)
            pf("Case %d: YES\n",t);
        else
            pf("Case %d: NO\n",t);
        Clean();
    }
    return 0;
}


