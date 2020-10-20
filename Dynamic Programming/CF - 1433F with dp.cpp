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


///Use ll to avoid integer overflow

int row,col,k,mat[105][105],vis[75][75][40][75];
pii dp[75][75][40][75]; ///Maximum Sum ; Is possible

pii FuN(int pos1,int pos2,int taken,int mod)
{
    if(pos1 > row){
        if(mod == 0)
            return make_pair(0 , 1);
        else
            return make_pair(0 , 0);
    }
    if(vis[pos1][pos2][taken][mod])
        return dp[pos1][pos2][taken][mod];
    int ret1=0,ret2=0;
    pii pr1 = {0 , 0} , pr2 = {0 , 0};
    if(pos2 < col){
        if(taken < col/2)
            pr1 = FuN(pos1 , pos2+1 , taken+1 , (mod+mat[pos1][pos2])%k);
        pr2 = FuN(pos1 , pos2+1 , taken , mod%k);
    }
    else{
        if(taken < col/2)
            pr1 = FuN(pos1+1 , 1 , 0 , (mod+mat[pos1][pos2])%k);
        pr2 = FuN(pos1+1 , 1 , 0 , mod);
    }
    vis[pos1][pos2][taken][mod] = 1;
    if(pr1.second && pr2.second)
        return dp[pos1][pos2][taken][mod] = make_pair(max(pr1.first+mat[pos1][pos2] , pr2.first) , 1);
    else if(pr1.second)
        return dp[pos1][pos2][taken][mod] = make_pair(pr1.first+mat[pos1][pos2] , 1);
    else if(pr2.second)
        return dp[pos1][pos2][taken][mod] = pr2;
    else
        return dp[pos1][pos2][taken][mod] = make_pair(0 , 0);
}

void Solve(int t)
{
    int i,j,ans;
    cin>>row>>col>>k;
    for(i=1 ; i<=row ; i++){
        for(j=1 ; j<=col ; j++)
            cin>>mat[i][j];
    }
    pii pr = FuN(1 , 1, 0 , 0);
    cout<<pr.first<<endl;
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
