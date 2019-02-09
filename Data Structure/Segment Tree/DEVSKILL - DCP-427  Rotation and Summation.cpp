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
#define MOD                     998244353
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

/** Order Set **/
//#include <ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;
//template<typename T> using orderset = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
//orderset<int> s ; //orderset<int>::iterator it ;
//orderset<int> X; //X.insert(1); //X.insert(2); //X.insert(4); //X.insert(8); //X.insert(16);
//cout<<*X.find_by_order(1)<<endl; // 2 //cout<<*X.find_by_order(2)<<endl; // 4 //cout<<*X.find_by_order(4)<<endl; // 16 //cout<<(end(X)==X.find_by_order(6))<<endl; // true
//cout<<X.order_of_key(-5)<<endl;  // 0 //cout<<X.order_of_key(1)<<endl;   // 0 //cout<<X.order_of_key(3)<<endl;   // 2 //cout<<X.order_of_key(4)<<endl;   // 2 //cout<<X.order_of_key(400)<<endl; // 5

#define sz 200005
int ara[2*sz];
ll tree[4*sz];
void init(int node,int b,int e)
{
    if(b == e)
    {
        tree[node]=ara[b];
        return;
    }
    int left=node*2;
    int right=left+1;
    int mid=(b+e)/2;
    init(left,b,mid);
    init(right,mid+1,e);
    tree[node]=tree[left]+tree[right];
}
ll query(int node,int b,int e,int i,int j)
{
    if(i>e || j<b)
        return 0;
    if(b>=i && e<=j)
        return tree[node];
    int left=node*2;
    int right=left+1;
    int mid=(b+e)/2;
    ll p1=query(left,b,mid,i,j);
    ll p2=query(right,mid+1,e,i,j);
    return p1+p2;
}
void update(int node,int b,int e,int id,int val)
{
    if(id>e || id<b)
        return;
    if(b>=id && e<=id)
    {
        tree[node]=val;
        return;
    }
    int left=node*2;
    int right=left+1;
    int mid=(b+e)/2;
    update(left,b,mid,id,val);
    update(right,mid+1,e,id,val);
    tree[node]=tree[left]+tree[right];
}
int main()
{
    int i,j,k,t,T,op,x,y,n,q,m,val,id;
    ll ans,inc;
    scin(T);
    RUN_CASE(t,T)
    {
        ans=0;
        inc=0;
        ms(ara,0);
        ms(tree,0);
        scin(n);
        for(i=1;i<=n;i++)
            scin(ara[i]);
        m=2*n;
        for(i=n+1;i<=m;i++)
            ara[i]=ara[i-n];
        init(1,1,m);
        scin(q);
        for(i=1;i<=q;i++)
        {
            scin(op);
            if(op == 1)         /** Left shift **/
            {
                scin(x);
                inc += x;
            }
            else if(op == 2)    /** Right shift **/
            {
                scin(x);
                inc += (n-x);
            }
            else if(op == 3)
            {
                scin2(x,val);
                inc = inc%n;
                x += (1+inc);
                update(1,1,m,x,val);
                if(x > n)
                    update(1,1,m,x-n,val);
                else
                    update(1,1,m,x+n,val);
            }
            else
            {
                scin2(x,y);
                inc = inc%n;
                x += (1+inc);
                y += (1+inc);
                ans = query(1,1,m,x,y);
                pf("%lld\n",ans);
            }
        }
    }
    return 0;
}
