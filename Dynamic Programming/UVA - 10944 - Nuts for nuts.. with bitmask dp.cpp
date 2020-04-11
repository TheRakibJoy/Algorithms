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

int Set(int N, int pos) {return  N = N | (1<<pos);}
int Reset(int N, int pos) {return  N = N & ~(1<<pos);}
bool Check(int N, int pos) {return  (bool)(N & (1<<pos));}

int n,row,col,dp[17][1<<17+2];
pii pos[20];
char grid[25][25];

int CountDistance(int p1,int p2)
{
    return max(fabs(pos[p1].first - pos[p2].first) , fabs(pos[p1].second - pos[p2].second));
}

int FuN(int lasttake,int mask)
{
    if(mask == (1<<n)-1)
        return CountDistance(lasttake , 0);
    if(dp[lasttake][mask] != -1)
        return dp[lasttake][mask];
    int mn = infinity;
    for(int i=1 ; i<n ; i++){
        if(Check(mask , i) == 0){
            int dis = CountDistance(lasttake , i) + FuN(i , Set(mask , i));
            mn = min(mn , dis);
        }
    }
    return dp[lasttake][mask] = mn;
}

void Solve(int t)
{
    int i,j,k,ans,cnt=0;
    for(i=1 ; i<=row ; i++){
        for(j=1 ; j<=col ; j++){
            cin>>grid[i][j];
            if(grid[i][j] == 'L')
                pos[0] = make_pair(i , j);
        }
    }
    for(i=1 ; i<=row ; i++){
        for(j=1 ; j<=col ; j++){
            if(grid[i][j] == '#'){
                pos[++cnt] = make_pair(i , j);
            }
        }
    }
    n = cnt+1;
    ms(dp , -1);
    ans = FuN(0 , 1);
    cout<<ans<<endl;
}

int main()
{
    CIN;
    int t,T;
    while(cin>>row>>col){
        Solve(t);
    }
    return 0;
}
/**
5 5
L....
#....
#....
.....
#....
5 5
L....
#....
#....
.....
#....
**/
