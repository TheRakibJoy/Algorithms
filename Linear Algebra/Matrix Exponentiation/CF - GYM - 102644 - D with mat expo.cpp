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

/** Problem Link: https://codeforces.com/gym/102644/problem/D
    Count number of path whose length is exactly k and the path not necessary to be
    a simple path. That means u can visit the same vertex or edges multiple times.
**/

struct matrix
{
    ll row,col,mat[105][105];
};

matrix Mat_Mul(const matrix &A,const matrix &B)
{
    matrix C;
    C.row = A.row;
    C.col = B.col;
    for(ll i=1 ; i<=C.row ; i++){
        for(ll j=1 ; j<=C.col ; j++){
            ll sum = 0;
            for(ll k=1 ; k<=A.col ; k++)
                sum = (sum + (A.mat[i][k] * B.mat[k][j])%MOD)%MOD;
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
    ll i,j,k,n,m,u,v,ans = 0;
    matrix A,res;
    cin>>n>>m>>k;
    A.row = A.col = res.row = res.col = n;
    for(i=1 ; i<=A.row ; i++){
        for(j=1 ; j<=A.col ; j++)
            A.mat[i][j] = 0;
    }
    for(i=1 ; i<=m ; i++){
        cin>>u>>v;
        A.mat[u][v] = 1;
    }
    res = Mat_Expo(A , k);
    for(i=1 ; i<=n ; i++){
        for(j=1 ; j<=n ; j++)
            ans = (ans + res.mat[i][j])%MOD;
    }
    cout<<ans<<endl;
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
