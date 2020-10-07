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

/** Problem: You're given the value of (a+b) , (a*b) and n. You've to calculate the
value of (a^n)+(b^n).
We can build a recurrence relation like the following:
(a^0)+(b^0) = 1+1 = 2
(a^1)+(b^1) = (a^0+b^0)*(a+b) - ab*(a^-1 + b^-1) = a+b
(a^2)+(b^2) = (a+b)*(a+b) - ab*(a^0+b^0)
(a^3)+(b^3) = (a^2+b^2)*(a+b) - ab*(a+b)
(a^4)+(b^4) = (a^3+b^3)*(a+b) - ab*(a^2+b^2)
f(n) = f(n-1)*p - q*f(n-2) where p = (a+b) and q = ab

|0      1|      |f(0) = 2|      |f(1)|
|-q     p| *    |f(1) = p|  =   |f(2)|
**/

struct matrix
{
    ull row,col,mat[3][3];
};

const ull mod = 1LL<<64LL;

matrix Mat_Mul(const matrix &A,const matrix &B)
{
    matrix C;
    C.row = A.row;
    C.col = B.col;
    for(ll i=1 ; i<=C.row ; i++){
        for(ll j=1 ; j<=C.col ; j++){
            ull sum = 0;
            for(ll k=1 ; k<=A.col ; k++)
                sum = (sum + (A.mat[i][k] * B.mat[k][j]));
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
    ll p,q,n;
    ull ans;
    sc("%lld %lld %lld",&p,&q,&n);

    matrix A,B,ret;
    A.row = A.col = B.row = 2;
    B.col = 1;

    A.mat[1][1] = 0;    A.mat[1][2] = 1;
    A.mat[2][1] = -q;   A.mat[2][2] = p;

    B.mat[1][1] = 2;
    B.mat[2][1] = p;

    if(n == 0)
        ans = 2;
    else if(n == 1)
        ans = p;
    else{
        ret.row = ret.col = 2;
        ret = Mat_Expo(A , n);
        ret = Mat_Mul(ret , B);
        ans = ret.mat[1][1];
    }
    pf("Case %d: %llu\n",t,ans);
}

int main()
{
    int t,T;
    T = 1;
    cin>>T;
    RUN_CASE(t,T)
    {
        Solve(t);
    }
    return 0;
}
