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

const ll mod = 1e9+7;
ll f[5];
struct matrix
{
    ll mat[11][11];
    int row,col;
};

matrix Mat_Mul(matrix &A,matrix &B)
{
    matrix C;
    C.row = A.row;
    C.col = B.col;
    for(int i=1 ; i<=C.row ; i++){
        for(int j=1 ; j<=C.col ; j++){
            ll sum = 0;
            for(int k=1 ; k<=A.col ; k++)
                sum = ( (sum%mod) + ((A.mat[i][k] * B.mat[k][j])%mod) )%mod;
            C.mat[i][j] = sum;
        }
    }
    return C;
}

matrix Mat_Expo(matrix A , ll n)
{
    if(n == 1)
        return A;
    matrix ret = Mat_Expo(A , n/2);
    ret = Mat_Mul(ret , ret);
    if(n%2 == 0)
        return ret;
    else
        return Mat_Mul(ret , A);
}

void Solve(int t)
{
    ll n;
    for(int i=0 ; i<5 ; i++)
        scln(f[i]);
    scln(n);
    if(n <= 4){
        pf("%lld\n",f[n]);
        return;
    }

    matrix A,B,ret;

    A.row = A.col = 5;
    A.mat[1][2] = 1; A.mat[1][1] = A.mat[1][3] = A.mat[1][4] = A.mat[1][5] = 0;
    A.mat[2][3] = 1; A.mat[2][1] = A.mat[2][2] = A.mat[2][4] = A.mat[2][5] = 0;
    A.mat[3][4] = 1; A.mat[3][1] = A.mat[3][2] = A.mat[3][3] = A.mat[3][5] = 0;
    A.mat[4][5] = 1; A.mat[4][1] = A.mat[4][2] = A.mat[4][3] = A.mat[4][4] = 0;
    A.mat[5][1] = A.mat[5][5] = 1; A.mat[5][2] = 5; A.mat[5][3] = 0; A.mat[5][4] = 2;

    B.row = 5; B.col = 1;
    for(int i=0 ; i<5 ; i++)
        B.mat[i+1][1] = f[i];

    ret = Mat_Expo(A , n);
    ret = Mat_Mul(ret , B);

    pf("%lld\n",ret.mat[1][1]);
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
