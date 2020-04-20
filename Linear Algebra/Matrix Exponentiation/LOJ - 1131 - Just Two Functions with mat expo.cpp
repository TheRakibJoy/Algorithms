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

//string small = "abcdefghijklmnopqrstuvwxyz";
//string capital = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

///------------------Graph Moves-------------------
///const int fx[] = {+1,-1,+0,+0};
///const int fy[] = {+0,+0,+1,-1};
///const int fx[] = {+0,+0,+1,-1,-1,+1,-1,+1}; ///King's move
///const int fy[] = {-1,+1,+0,+0,+1,+1,-1,-1}; ///King's move
///const int fx[] = {-2,-2,-1,-1,+1,+1,+2,+2}; ///Knight's move
///const int fy[] = {-1,+1,-2,+2,-2,+2,-1,+1}; ///Knight's move

ll mod;
struct matrix
{
    ll mat[20][20];
    ll row,col;
};

matrix Mat_Mul(matrix &A , matrix &B)
{
    matrix C;
    C.row = A.row; C.col = B.col;
    for(ll i=1 ; i<=C.row ; i++){
        for(ll j=1 ; j<=C.col ; j++){
            ll sum = 0;
            for(ll k=1 ; k<=A.col ; k++)
                sum = ((sum%mod) + ( (A.mat[i][k]%mod)*(B.mat[k][j]%mod) )%mod)%mod;
            C.mat[i][j] = sum%mod;
        }
    }
    return C;
}

matrix Mat_Expo(matrix A ,int n)
{
    if(n == 1)
        return A;
    matrix ret = Mat_Expo(A , n/2);
    ret = Mat_Mul(ret , ret);
    if(n%2 == 0)
        return ret;
    else
        return Mat_Mul(A , ret);
}

void Solve(int t)
{
    ll i,j,k,a1,b1,c1,a2,b2,c2,f[3],g[3],ans,q,n;
    sc("%lld %lld %lld",&a1,&b1,&c1);
    sc("%lld %lld %lld",&a2,&b2,&c2);
    sc("%lld %lld %lld",&f[0],&f[1],&f[2]);
    sc("%lld %lld %lld",&g[0],&g[1],&g[2]);
    scln2(mod , q);

    matrix A,B,ret;
    A.row = A.col = 6;
    A.mat[1][2] = 1; A.mat[1][1] = A.mat[1][3] = A.mat[1][4] = A.mat[1][5] = A.mat[1][6] = 0;
    A.mat[2][3] = 1; A.mat[2][1] = A.mat[2][2] = A.mat[2][4] = A.mat[2][5] = A.mat[2][6] = 0;
    A.mat[3][2] = b1; A.mat[3][3] = a1; A.mat[3][4] = c1; A.mat[3][1] = A.mat[3][5] = A.mat[3][6] = 0;
    A.mat[4][5] = 1; A.mat[4][1] = A.mat[4][2] = A.mat[4][3] = A.mat[4][4] = A.mat[4][6] = 0;
    A.mat[5][6] = 1; A.mat[5][1] = A.mat[5][2] = A.mat[5][3] = A.mat[5][4] = A.mat[5][5] = 0;
    A.mat[6][1] = c2; A.mat[6][5] = b2; A.mat[6][6] = a2; A.mat[6][2] = A.mat[6][3] = A.mat[6][4] = 0;

    B.row = 6; B.col = 1;
    B.mat[1][1] = f[0]; B.mat[2][1] = f[1]; B.mat[3][1] = f[2];
    B.mat[4][1] = g[0]; B.mat[5][1] = g[1]; B.mat[6][1] = g[2];

    pf("Case %d:\n",t);
    for(i=1 ; i<=q ; i++){
        scln(n);
        if(n <= 2){
            pf("%lld %lld\n",f[n]%mod,g[n]%mod);
        }
        else{
            ret = Mat_Expo(A , n);
            ret = Mat_Mul(ret , B);
            pf("%lld %lld\n",ret.mat[1][1],ret.mat[4][1]);
        }
    }
}

int main()
{
    int t,T;
    scin(T);
    RUN_CASE(t,T)
    {
        Solve(t);
    }
    return 0;
}

