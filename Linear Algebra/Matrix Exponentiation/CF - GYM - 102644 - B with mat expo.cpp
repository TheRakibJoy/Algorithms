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

using namespace std;

/** There're
    19 possible ways to go from happy to happy state
    7 possible ways to go from happy to sad state
    6 possible ways to go from sad to happy state
    20 possible ways to go from sad to sad state
    We can named to function f and g where f means number of strings that make Limak
    happy and g means number of strings that make Limak sad.So,
    f(n) = 19 * f(n-1) + 6 * g(n-1)
    g(n) = 20 * g(n-1) + 7 * f(n-1)
    where f(0) = 1 , f(1) = 19 , g(0) = 0 , g(1) = 7; So, desired matrix will:

    |0  0   1   0   |   |f0 = 1  |   |f1    |
    |0  0   0   1   | * |g0 = 0  | = |g1    |
    |0  0   19  6   |   |f1 = 19 |   |f2    |
    |0  0   7   20  |   |g1 = 7  |   |g2    |   **/

struct matrix
{
    ll row,col,mat[10][10];
};

matrix Mat_Mul(const matrix &A,const matrix &B)
{
    matrix C;
    C.row = A.row;
    C.col = B.col;
    for(ll i=1 ; i<=C.row ; i++){
        for(ll j=1 ; j<=C.col ; j++){
            ll sum = 0LL;
            for(ll k=1 ; k<=A.col ; k++){
                sum = (sum + (A.mat[i][k] * B.mat[k][j])%MOD)%MOD;
            }
            C.mat[i][j] = sum;
        }
    }
    return C;
}

matrix Mat_Expo(const matrix &A,ll n)
{
    if(n == 1)
        return A;
    matrix ret = Mat_Expo(A , n/2);
    ret = Mat_Mul(ret , ret);
    if(n%2)
        ret = Mat_Mul(ret , A);
    return ret;
}

void Solve(int t)
{
    ll i,j,k,n,ans;
    cin>>n;

    matrix A,B,ret;
    A.row = A.col = B.row = 4;
    B.col = 1;
    A.mat[1][1] = 0;    A.mat[1][2] = 0;    A.mat[1][3] = 1;    A.mat[1][4] = 0;
    A.mat[2][1] = 0;    A.mat[2][2] = 0;    A.mat[2][3] = 0;    A.mat[2][4] = 1;
    A.mat[3][1] = 0;    A.mat[3][2] = 0;    A.mat[3][3] = 19;   A.mat[3][4] = 6;
    A.mat[4][1] = 0;    A.mat[4][2] = 0;    A.mat[4][3] = 7;    A.mat[4][4] = 20;

    B.mat[1][1] = 1;
    B.mat[2][1] = 0;
    B.mat[3][1] = 19;
    B.mat[4][1] = 7;

    ret = Mat_Expo(A , n);
    ret = Mat_Mul(ret , B);
    pf("%lld\n",ret.mat[1][1]);
}

int main()
{
    int t,T;
    T = 1;
//    cin>>T;
    RUN_CASE(t,T)
    {
        Solve(t);
    }
    return 0;
}
