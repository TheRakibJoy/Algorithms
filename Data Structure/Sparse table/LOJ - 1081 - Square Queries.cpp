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

#define sz 1003
int grid[sz][sz],sptable[sz][sz][11],Log[sz];

void preLog()
{
    Log[1] = 0;
    for(int i=2 ; i < sz ; i++){
        Log[i] = Log[i/2]+1;
    }
}

void sparseTable(int n)
{
    for(int xy=0 ; (1<<xy) <= n ; xy++){
        for(int x=1 ; x <= n ; x++){
            for(int y=1 ; y <= n ; y++){
                if(xy == 0)
                    sptable[x][y][xy] = grid[x][y];
                else
                    sptable[x][y][xy] = max(sptable[x][y][xy-1] , max(sptable[x+(1<<(xy-1))][y][xy-1] , max(sptable[x][y+(1<<(xy-1))][xy-1] , sptable[x+(1<<(xy-1))][y+(1<<(xy-1))][xy-1])));
            }
        }
    }
}

int RMxQ(int x,int y,int len)
{
    int logg = Log[len];
    int ret = sptable[x][y][logg];

    int x2 = x+len-1;
    int y2 = y+len-1;

    ///
    ret = max(ret , sptable[x2 - (1<<logg) + 1][y][logg]);
    ret = max(ret , sptable[x][y2 - (1<<logg) + 1][logg]);
    ret = max(ret , sptable[x2 - (1<<logg) + 1][y2 - (1<<logg) + 1][logg]);

    return ret;
}

void Solve(int t)
{
    ms(sptable , -1);
    ms(grid , 0);
    int i,j,k,n,q,x,y,len,ans;

    scin2(n , q);
    for(i=1 ; i<=n ; i++){
        for(j=1 ; j<=n ; j++)
            scin(grid[i][j]);
    }
    sparseTable(n);

    pf("Case %d:\n",t);
    for(i=1 ; i<=q ; i++){
        sc("%d %d %d",&x,&y,&len);
        ans = RMxQ(x , y , len);
        pf("%d\n",ans);
    }
}

int main()
{
    preLog();
    int t,T;
    scin(T);
    RUN_CASE(t,T)
    {
        Solve(t);
    }
    return 0;
}
