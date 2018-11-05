#include<bits/stdc++.h>

#define Input                   freopen("in.txt","r",stdin)
#define Output                  freopen("out.txt","w",stdout)
#define ll                      long long int
#define ull                     unsigned long long int
#define pii                     pair<int,int>
#define pll                     pair<ll,ll>
#define sc                      scanf
#define scin(x)                 sc("%d",&(x))
#define scin2(x,y)                sc("%d %d",&(x),&(y))
#define scln(x)                 sc("%lld",&(x))
#define scln2(x,y)                sc("%lld %lld",&(x),&(y))
#define pf                      printf
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
#define MOD                     1000000000000037
#define CIN                     ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define RUN_CASE(t,T)           for(__typeof(t) t=1;t<=T;t++)
#define CASE(t)                 printf("Case %d: ",t)
#define CASEl(t)                printf("Case %d:\n",t)
#define intlimit                214748369
#define longlimit               922337203685477580
#define infinity                (1<<28)
#define gcd(a,b)                __gcd(a,b)
#define lcm(a,b)                ((a)*(b))/gcd(a,b)
#define mxx                     123456789
#define PI                      2*acos(0.0)
#define rep(i,a,b)              for(__typeof(i) i=a;i<=b;i++)
#define rev(i,a,b)              for(__typeof(i) i=a;i>=b;i--)

using namespace std;
/** toint, tostring, BigMod, sieve, Primefactorize **/
//ll toint(string s){ll n=0,k=1;for(int i=s.size()-1;i>=0;i--){n += ((s[i]-'0')*k);k*=10;}return n;}
//string tostring(ll n){string s="";ll x;while(n > 0){x=n%10;s +=(char)(x+'0');n/=10;}reverse(s.begin(),s.end());return s;}
//ll BigMod(ll a,ll b,ll m){if(b == 0)return 1%m;else if(b%2 == 0){ll temp=BigMod(a,b/2,m);return ((temp%m)*(temp%m))%m;}else{return ((a%m)*BigMod(a,b-1,m)%m)%m;}}
//ll power(ll a,ll n){ll ans=1;if(n == 0)return 1;else if(n == 1)return a;else return a*power(a,n-1);}
//vector<int>Prime;bool mark[1000009];
//void sieve(int n){int i,j,limit=sqrt(n*1.0)+2;mark[1]=1;for(i=4; i<=n; i+=2)mark[i]=1;Prime.push_back(2);for(i=3; i<=n; i+=2){if(!mark[i]){Prime.push_back(i);if(i<=limit){for(j=i*i; j<=n; j+=(i*2))mark[j]=1;}}}}
//vector<int>List;
//void Primefactorize(int n){for(int i=0; Prime[i]*Prime[i]<=n ; i++){if(n%Prime[i] == 0){while(n%Prime[i] == 0){List.push_back(Prime[i]);n/=Prime[i];}}}if(n>1)List.push_back(n);}

/** Order Set **/
//#include <ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;
//template<typename T> using orderset = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
//orderset<int> s ; //orderset<int>::iterator it ;
//orderset<int> X; //X.insert(1); //X.insert(2); //X.insert(4); //X.insert(8); //X.insert(16);
//cout<<*X.find_by_order(1)<<endl; // 2 //cout<<*X.find_by_order(2)<<endl; // 4 //cout<<*X.find_by_order(4)<<endl; // 16 //cout<<(end(X)==X.find_by_order(6))<<endl; // true
//cout<<X.order_of_key(-5)<<endl;  // 0 //cout<<X.order_of_key(1)<<endl;   // 0 //cout<<X.order_of_key(3)<<endl;   // 2 //cout<<X.order_of_key(4)<<endl;   // 2 //cout<<X.order_of_key(400)<<endl; // 5

/**Kth number in a sorted segment from i to j using Merge Sort Tree **
/**Complexity of build function : O(nlogn)**/
/**Complexity of O(logn)^2**/
#define sz 100005
ll ara[sz];
vector<ll> tree[4*sz];
void init(ll node,ll b,ll e)
{
    if(b == e)
    {
        tree[node].pb(ara[b]);
        return;
    }
    ll left=node*2;
    ll right=left+1;
    ll mid=(b+e)/2;
    init(left,b,mid);
    init(right,mid+1,e);
    merge(tree[left].begin(),tree[left].end(),tree[right].begin(),tree[right].end(),back_inserter(tree[node]));
    /** Merge & sort the child nodes & store them in parent node**/
}
ll query(ll node,ll b,ll e,ll i,ll j,ll val)
{
    if(i>e || j<b)
        return 0;
    if(b>=i && e<=j)
        return lower_bound(tree[node].begin(),tree[node].end(),val)-tree[node].begin();
    /** Return the number of value which are less than val **/
    ll left=node*2;
    ll right=left+1;
    ll mid=(b+e)/2;
    ll p1=query(left,b,mid,i,j,val);
    ll p2=query(right,mid+1,e,i,j,val);
    return p1+p2;
}
ll Bin(ll n,ll x,ll y,ll k)
{
    ll lo=-1000000000LL,hi=1000000000LL,mid,res;
    while(lo<=hi)
    {
        mid=(lo+hi)/2;
        if(query(1,1,n,x,y,mid) >= k)
        {
            res=mid;
            hi=mid-1;
        }
        else
        {
            lo=mid+1;
        }
    }
    return res;
}
int main()
{
    int i,j;
    ll n,q,x,y,k;
    scln2(n,q);
    for(i=1;i<=n;i++)
    {
        scln(ara[i]);
    }
    init(1,1,n);
    for(i=1;i<=q;i++)
    {
        scln2(x,y);
        scln(k);
        pf("%lld\n",Bin(n,x,y,k)-1);
    }
    return 0;
}

