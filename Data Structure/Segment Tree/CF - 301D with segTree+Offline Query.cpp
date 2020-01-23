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
Problem: CF-301D - Yaroslav and Divisors with segTree + Offline Query
You're given an array with n distinct elements & q queries. In each query you'll given l[i],r[i]. You have to print the number of pairs of integers q,w(l[i]<=q,w<=r[i]) such that ara[q] is the divisor of ara[w].
Solution:
Suppose, we have a pair of index(i,j) where ara[i] is the divisor of ara[j]. We say it a segment on a 2D plane. Now we have to count the number of segment those are completely lies in range [x,y] on that 2D plane.
1.  For each number between [1,n] we have to store its multiples between [1,n]. Actually here in divisor's id, we stored all its multiple's id.
2.  Store the query according to l[i] of each query. (see the solution for details)
3.  Now, iterate from n to 1. For each i, increase the value of endpoint of the segment starting from i. Calculate the sum of total segment lies in range i to qry[i].first
**/
#define sz 200005
int ara[sz],id[sz],tree[4*sz],ans[sz];
void Update(int node,int b,int e,int pos,int val)    /// Point Update
{
    if(pos>e || pos<b)
        return;
    if(b>=pos && e<=pos){
        tree[node] += val;
        return;
    }
    int mid = (b+e)>>1;
    if(pos <= mid)
        Update(node<<1 , b , mid , pos , val);
    else
        Update(1+(node<<1) , mid+1 , e , pos , val);
    tree[node] = tree[node<<1]+tree[1+(node<<1)];
}
int Query(int node,int b,int e,int i,int j)   /** Range Query **/
{
    if(i>e || j<b)
        return 0;
    if(b>=i && e<=j)
        return tree[node];
    int mid = (b+e)>>1;
    return (Query(node<<1 , b , mid , i , j) + Query(1+(node<<1) , mid+1 , e , i , j));
}
vi segment[sz];     /** segment[i][j] means i is the divisor's id & j is the multiple's id **/
vector<pii>qry[sz]; /** qry[i][j] means l=i && qry[i][j]={r , query's SL} **/
int main()
{
    int i,j,k,n,q,l,r,lft,rgt,x,y,totseg,cnt=0,badsz=0;
    scin2(n,q);
    for(i=1 ; i<=n ; i++){
        scin(ara[i]);
        id[ara[i]] = i;     ///ID of each distinct element
    }
    for(i=1 ; i<=q ; i++){
        scin2(lft,rgt);
        qry[lft].pb(make_pair(rgt , i));
    }
    for(i=1 ; i<=n ; i++){
        for(j=i ; j<=n ; j+=i){
            x = id[i];      ///Divisor's ID
            y = id[j];      ///Multiple's ID
            segment[min(x,y)].pb(max(x,y));
        }
    }
    /// How OFFline Query works
    for(i=n ; i>=1 ; i--){
        for(auto it : segment[i])
            Update(1 , 1 , n , it , 1);     ///Increase the value of ending point of the segment starting from this node. Here, i is the divisor's address , it is the multiple's address.
        for(auto it : qry[i])
            ans[it.second] = Query(1 , 1 , n , i , it.first);   ///Calculate the sum of total segment completely lies in range i to it.first
    }
    for(i=1 ; i<=q ; i++)
        pf("%d\n",ans[i]);
    return 0;
}


