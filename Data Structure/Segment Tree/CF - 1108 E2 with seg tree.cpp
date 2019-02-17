/**
1. Decrease the element by 1 within range i to j
2. Range Maximum & Range Minimum query
**/

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

#define sz 100002
int ara[sz];
struct data
{
    int val;
}tree[4*sz][2];         /** Two state for max & min **/
int lazy[4*sz];
void init(int node,int b,int e)
{
    if(b == e)
    {
        tree[node][0].val=ara[b];
        tree[node][1].val=ara[b];
        lazy[node]=0;
        return;
    }
    int left=node*2;
    int right=left+1;
    int mid=(b+e)/2;
    init(left,b,mid);
    init(right,mid+1,e);
    tree[node][0].val = min(tree[left][0].val,tree[right][0].val);
    tree[node][1].val = max(tree[left][1].val,tree[right][1].val);
    lazy[node]=0;
}
void update(int node,int b,int e,int i,int j,int x)
{
    if(lazy[node] != 0)        /** If I've propagation value **/
    {
        tree[node][0].val += lazy[node];
        tree[node][1].val += lazy[node];
        if(b != e)          /** If not root child **/
        {
            lazy[node*2] += lazy[node];
            lazy[node*2+1] += lazy[node];
        }
        lazy[node] = 0;    /** Reset the propagate value of node **/
    }
    if(i>e || j<b || b>e)       /** Current Segment is not within Range **/
        return;
    if(b>=i && e<=j)            /** Segment is fully in range **/
    {
        tree[node][0].val += x;
        tree[node][1].val += x;
        if(b != e)              /** Not child **/
        {
            lazy[node*2] += x;
            lazy[node*2+1] += x;
        }
        return;
    }
    int left=node*2;
    int right=left+1;
    int mid=(b+e)/2;
    update(left,b,mid,i,j,x);
    update(right,mid+1,e,i,j,x);
    tree[node][1].val = max(tree[left][1].val,tree[right][1].val);
    tree[node][0].val = min(tree[left][0].val,tree[right][0].val);
}
int query(int fg,int node,int b,int e,int i,int j)
{
    if(i>e || j<b || b>e)
        return 0LL;
    if(lazy[node] != 0)
    {
        tree[node][1].val += lazy[node];
        tree[node][0].val += lazy[node];
        if(b != e)
        {
            lazy[node*2] += lazy[node];
            lazy[node*2+1] += lazy[node];
        }
        lazy[node] = 0;
    }
    if(b>=i && e<=j)
        return tree[node][fg].val;
    int q1 = query(fg,node*2 , b , (b+e)/2, i , j);
    int q2 = query(fg,node*2+1 , 1+(b+e)/2 , e , i ,j);
    if(fg == 0)
        return min(q1,q2);  /** If state-0 ; then call range minimum query **/
    else
        return max(q1,q2);  /** If state-1 ; then call range max query **/
}
struct info
{
    int l,r;
}qry[305];
vi temp,ans,add_seg[sz],del_seg[sz];
int main()
{
    /***    Please Avoid Integer Overflow   **/
    int i,j,n,m;
    int dif=-infinity,q=0,cnt,x,y,id=0;
    scin2(n,m);
    for(i=1;i<=n;i++)
        scin(ara[i]);
    for(i=1;i<=m;i++){
        scin2(qry[i].l,qry[i].r);
        add_seg[qry[i].l].pb(i);
        del_seg[qry[i].r].pb(i);
    }
    init(1,1,n);
    dif = abs(query(1,1,1,n,1,n) - query(0,1,1,n,1,n));
    for(i=1 ; i<=n ; i++)
    {
        for(j=0 ; j<add_seg[i].size() ; j++)
        {
            update(1,1,n, qry[add_seg[i][j]].l , qry[add_seg[i][j]].r,-1);
            /** On the bits of that segment start from this node **/
        }
        x = query(1,1,1,n,1,n);
        y = query(0,1,1,n,1,n);
        if(abs(x-y) > dif)
        {
            id = i;
            dif = abs(x-y);
        }
        for(j=0 ; j<del_seg[i].size() ; j++)
        {
            update(1,1,n, qry[del_seg[i][j]].l , qry[del_seg[i][j]].r,1);
            /** Off the bits of that segment end at this node **/
        }
    }
    for(i=1 ; i<=m ; i++)
    {
        if(id>=qry[i].l && id<=qry[i].r){
            ans.pb(i);
            q++;
        }
    }
    pf("%d\n",dif);
    pf("%d\n",q);
    for(i=0 ; i<q ; i++)
        pf("%d ",ans[i]);
    return 0;
}
