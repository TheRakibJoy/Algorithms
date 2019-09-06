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

/** Maximum sub rectangle area using segTree + BS **/
#define sz 2005
char s[sz][sz];
int n,m,ara[sz];
pii tree[3*sz];   /** 1st element-min value of range ; 2nd element-index of min value **/
void init(int node,int b,int e)
{
    if(b == e)
    {
        tree[node] = make_pair(ara[b] , b);
        return;
    }
    int lft=node*2;
    int rgt=lft+1;
    int mid=(b+e)/2;
    init(lft , b , mid);
    init(rgt , mid+1 , e);
    tree[node].first = min(tree[lft].first , tree[rgt].first);
    tree[node].second = (tree[lft].first==tree[node].first)?tree[lft].second:tree[rgt].second;
}
pii query(int node,int b,int e,int i,int j)
{
    if(b>e || b>j || e<i)
        return make_pair(infinity,infinity);
    if(b>=i && e<=j)
        return tree[node];
    int lft=node*2;
    int rgt=lft+1;
    int mid=(b+e)/2;
    pii ret1 = query(lft , b , mid , i , j);
    pii ret2 = query(rgt , mid+1 , e , i ,j);
    pii ret;
    ret.first = min(ret1.first , ret2.first);
    ret.second = (ret.first==ret1.first)?ret1.second:ret2.second;
    return ret;
}
int Calculate(int b,int e)  /** BS for calculating the area of simple histogram **/
{
    if(b > e)
        return 0;
    if(b == e)
        return ara[b];
    int ret1,ret2,ret3;
    pii p = query(1,1,n,b,e);
    ret1 = p.first*(e-b+1);
    ret2 = Calculate(b , p.second-1);
    ret3 = Calculate(p.second+1 , e);
    return max(ret1 , max(ret2 , ret3));
}
int main()
{
    int i,j,k,t,T,ans,cnt;
    scin(T);
    RUN_CASE(t,T)
    {
        ans=0;
        ms(ara,0);
        scin2(m,n);
        for(i=1 ; i<=m ; i++)
        {
            sc("%s",s[i]);
            for(j=0 ; j<n ; j++)        /** Here,0 means space 1 means block ; so, we r trying to create histogram **/
            {
                if(s[i][j] == '0')      /** Height of histogram means number of consecutive 0 from this row to upper most row **/
                    ara[j+1] += 1;
                else
                    ara[j+1] = 0;       /** Here,consecutive 0 from this row is 0 **/
            }
            init(1,1,n);    /** Building histogram from row 1 to i **/
            cnt = Calculate(1,n);   /** Maximum sub rectangle area of this histogram **/
            ans = max(ans,cnt);
        }
        pf("Case %d: %d\n",t,ans);
    }
    return 0;
}

