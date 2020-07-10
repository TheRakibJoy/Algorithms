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

const int fx[] = {+1,-1,+0,+0};
const int fy[] = {+0,+0,+1,-1};

char grid[55][55];
int row,col,vis[55][55];

void BFS(char &ch)
{
    ms(vis , 0);
    queue<pii>q;
    q.push({0 , 0});
    vis[0][0] = 1;
    while(!q.empty()){
        pii pr = q.front();
        q.pop();
        for(int k=0 ; k<4 ; k++){
            int nx = pr.first + fx[k];
            int ny = pr.second + fy[k];
            if(nx>=0 && nx<=row+1 && ny>=0 && ny<=col+1 && grid[nx][ny] != ch && !vis[nx][ny]){
                vis[nx][ny] = 1;
                q.push({nx , ny});
            }
        }
    }
    for(int i=1 ; i<=row ; i++){
        for(int j=1 ; j<=col ; j++){
            if(!vis[i][j])
                grid[i][j] = ch;
        }
    }
}

void Solve(int t)
{
    int i,j,k;
    scin2(row , col);
    for(i=0 ; i<=row+1 ; i++){
        for(j=0 ; j<=col+1 ; j++){
            if(i>=1 && i<=row && j>=1 && j<=col)
                cin>>grid[i][j];
            else
                grid[i][j] = '.';
        }
    }
    for(char ch='A' ; ch<='Z' ; ch++)
        BFS(ch);
    pf("Case %d:\n",t);
    for(i=1 ; i<=row ; i++){
        for(j=1 ; j<=col ; j++)
            cout<<grid[i][j];
        cout<<endl;
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
/**
2
5 5
AAAEE
ABAHE
A.AHF
AAAHF
.G...
20 20
....................
...B................
..BBBB..............
..B..BBB............
.BB....B............
BBB..RRBBBBBBBBBB...
BBB..RR....SS.BBB...
.BB..RR....SSBB.....
..B..RR.DD.BBB......
.BB..KMDDD.B........
..BB.KDD...B..BBB...
...B.KK....BBBBBB...
..BB.KK....BBBCBB...
...B.KK...BB.BCB....
...B.K..BBB..BCBB...
...BBBBBB....BBBB...
...BBBBBBB....BBB...
...............BB...
................BB..
.................B..
**/

