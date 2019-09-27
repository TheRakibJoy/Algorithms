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


vector<ll>Prime;
bool mark[10000009];
ll SF[10000009];
void FuN()
{
    for( int i = 2 ; i * i <= 10000000 ; i ++ ){
        if( !SF[i] ){
            for( int j = i ; j <= 10000000 ; j += i ){
                if( !SF[j] ) SF[j] = i ;
            }
        }
    }
    for( int i = 2 ; i <= 1e7 ; i ++ ) if( !SF[i] ) SF[i] = i ;
}
#define sz 100009
ll ara[sz],tree[31][sz*4],lastadd[sz];
void update(ll no,ll node,ll b,ll e,ll i,ll val)
{
    if(i>e || i<b)
        return;
    if(b>=i && e<=i){
        tree[no][node] = val;
        return;
    }
    ll lft=node*2;
    ll rgt=lft+1;
    ll mid=(b+e)/2;
    update(no , lft , b , mid , i , val);
    update(no , rgt , mid+1 , e , i , val);
    tree[no][node] = tree[no][lft]+tree[no][rgt];
}
ll query(ll no,ll node,ll b,ll e,ll i,ll j)
{
    if(i>e || j<b)
        return 0LL;
    if(b>=i && e<=j)
        return tree[no][node];
    ll lft=node*2;
    ll rgt=lft+1;
    ll mid=(b+e)/2;
    ll p1 = query(no , lft , b , mid , i , j);
    ll p2 = query(no , rgt , mid+1 , e , i , j);
    return p1+p2;
}
int main()
{
    ll i,j,k,n,x,l,r,val,q,no,ans,id;
    FuN();
    string s1,cmd;
    char ch;
    cin>>s1;
    n = (ll)s1.size();
    cin>>q;
    for(i=1 ; i<=q ; i++)
    {
        cin>>cmd;
        if(cmd == "Query"){
            cin>>l>>r;
            cin>>ch;
            no = ch-'a'+1;
            if(l > r)
                swap(l,r);
            ans = query(no , 1LL , 1LL , n , l , r);
            cout<<ans<<endl;
        }
        else{
            cin>>x;
            cin>>ch;
            x = SF[x];
            id = x;
            while(id <= n){
                no = lastadd[id];
                update(no , 1LL , 1LL , n , id , 0LL);
                no = ch-'a'+1;
                update(no , 1LL , 1LL , n , id , 1LL);
                lastadd[id] = no;
                id *= x;
            }
        }
    }
    return 0;
}
