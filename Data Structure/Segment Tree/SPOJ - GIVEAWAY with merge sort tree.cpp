///****In the name of ALLAH, most Gracious, most Compassionate****//
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
#define coutv(v)                for(auto it:v)cout<<it<<' ';cout<<'\n';
#define cinv(v)                 for(auto &it:v)cin>>it;
#define srt(v)                  sort(v.begin(),v.end());
#define rsrt(v)                 sort(v.rbegin(),v.rend());
#define rvs(v)                  reverse(v.begin(),v.end());

using namespace std;

/**     Order Set       **/
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template<typename T> using orderset = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
//orderset<int> s ; //orderset<int>::iterator it ;
//orderset<int> X; //X.insert(1); //X.insert(2); //X.insert(4); //X.insert(8); //X.insert(16);
//cout<<*X.find_by_order(0)<<endl; // 2 //cout<<*X.find_by_order(2)<<endl; // 4 //cout<<*X.find_by_order(4)<<endl; // 16 //cout<<(end(X)==X.find_by_order(6))<<endl; // true
//cout<<X.order_of_key(-5)<<endl;  // 0 //cout<<X.order_of_key(1)<<endl;   // 0 //cout<<X.order_of_key(3)<<endl;   // 2 //cout<<X.order_of_key(4)<<endl;   // 2 //cout<<X.order_of_key(400)<<endl; // 5

#define sz 500009
int ara[sz];
orderset<pii>ostree[4*sz];

void MergeOST(int node , int lft , int rgt)
{
    for(auto it : ostree[lft])
        ostree[node].insert(it);

    for(auto it : ostree[rgt])
        ostree[node].insert(it);
}

void Init(int node,int b,int e)
{
    if(b == e){
        ostree[node].insert(make_pair(ara[b] , b));
        return;
    }
    int mid = (b+e)>>1;
    Init(node<<1 , b , mid);
    Init(1+(node<<1) , mid+1 , e);
    MergeOST(node , node<<1 , 1+(node<<1));
}

void Update(int node,int b,int e,int pos,int val)
{
    if(pos < b || pos > e)
        return;
    if(pos == b && pos == e){
        ostree[node].erase({ara[pos] , pos});
        ostree[node].insert({val , pos});
        return;
    }
    int mid = (b+e)>>1;
    if(pos <= mid)
        Update(node<<1 , b , mid , pos , val);
    else
        Update(1+(node<<1) , mid+1 , e , pos , val);

    ///
    ostree[node].erase({ara[pos] , pos});
    ostree[node].insert({val , pos});
}

int GEQuery(int node,int b,int e,int i,int j,int val)
{
    if(e < i || b > j || b > e)
        return 0;
    if(b>=i && e<=j){
        int lb = ostree[node].order_of_key({val-1 , 1e9});
        return ((e-b+1) - lb);
    }
    int mid = (b+e)>>1;
    return (GEQuery(node<<1 , b , mid , i , j , val) + GEQuery(1+(node<<1) , mid+1 , e , i , j , val));
}

void Solve(int t)
{
    int i,j,k,n,q,l,r,val,qtype,idx;
    scin(n);
    for(i=1 ; i<=n ; i++)
        scin(ara[i]);

    Init(1 , 1 , n);
    scin(q);
    for(i=1 ; i<=q ; i++){
        scin(qtype);
        if(qtype == 0){
            sc("%d %d %d",&l,&r,&val);
            int ans = GEQuery(1 , 1 , n , l , r , val);
            pf("%d\n",ans);
        }
        else{
            scin2(idx , val);
            Update(1 , 1 , n , idx , val);
            ara[idx] = val;
        }
    }
}

int main()
{
    Solve(1);
    return 0;
}
