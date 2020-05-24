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

int Set(int N, int pos) {return  N = N | (1<<pos);}
int Reset(int N, int pos) {return  N = N & ~(1<<pos);}
bool Cheek(int N, int pos) {return  (bool)(N & (1<<pos));}


int n,m,dp[12][1<<(12)];

string s[15];

int FuN(int pos , int mask)
{
    if(pos >= m)
        return dp[pos][mask] = 1;
    if(dp[pos][mask] != -1)
        return dp[pos][mask];
    int i,j,ret1=0,ret2=0;
    for(i=0 ; i<n ; i++)    ///Take s[i][pos]
    {
        int possbl = 1;
        for(j=0 ; j<n ; j++){
            if(Cheek(mask , j) && s[i][pos]!=s[j][pos]){
                possbl = 0;
                break;
            }
        }
        if(possbl){
            int temp = mask;
            for(j=0 ; j<n ; j++){
                if(s[i][pos] != s[j][pos])
                    temp = Set(temp , j);
            }
            ret1 |= FuN(pos+1 , temp);
        }
    }
    return dp[pos][mask] = ret1;
}

string sans = "";
void Print(int pos , int mask)
{
    if(pos >= m){
        cout<<endl;
        return;
    }
    int i,j,ret1=0,ret2=0;
    for(i=0 ; i<n ; i++)    ///Take s[i][pos]
    {
        int possbl = 1;
        for(j=0 ; j<n ; j++){
            if(Cheek(mask , j) && s[i][pos]!=s[j][pos]){
                possbl = 0;
                break;
            }
        }
        if(possbl){
            int temp = mask;
            for(j=0 ; j<n ; j++){
                if(s[i][pos] != s[j][pos])
                    temp = Set(temp , j);
            }
            if(dp[pos+1][temp] == 1){
                cout<<s[i][pos];
                Print(pos+1 , temp);
                break;
            }
        }
    }
}

void Solve(int t)
{
    int i,j,k,ans;
    ms(dp , -1);
    cin>>n>>m;
    for(i=0 ; i<n ; i++)
        cin>>s[i];
    ans = FuN(0 , 0);
    if(ans){
        Print(0 , 0);
    }
    else
        cout<<"-1\n";
}

int main()
{
    CIN;
    int t,T;
    T = 1;
    cin>>T;
    RUN_CASE(t,T)
    {
        Solve(t);
    }
    return 0;
}

