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

struct node
{
    int ax,ay,bx,by,cx,cy;
    node(){}
    node(int _ax,int _ay,int _bx,int _by,int _cx,int _cy){
        ax = _ax; ay = _ay;
        bx = _bx; by = _by;
        cx = _cx; cy = _cy;
    }
};

int n,dis[11][11][11][11][11][11],vis[11][11][11][11][11][11];
char grid[15][15];

void Clean()
{
    for(int i=0 ; i<=n ; i++){
        for(int j=0 ; j<=n ; j++){
            for(int k=0 ; k<=n ; k++){
                for(int x=0 ; x<=n ; x++){
                    for(int y=0 ; y<=n ; y++){
                        for(int z=0 ; z<=n ; z++){
                            dis[i][j][k][x][y][z] = infinity;
                            vis[i][j][k][x][y][z] = 0;
                        }
                    }
                }
            }
        }
    }
}

void BFS(int x1,int y1,int x2,int y2,int x3,int y3)
{
    queue<node>q;
    Clean();
    dis[x1][y1][x2][y2][x3][y3] = 0;
    q.push(node(x1 , y1 , x2 , y2 , x3 , y3));
    while(!q.empty()){
        node top = q.front();
        q.pop();
        for(int k=0 ; k<4 ; k++){
            int nx1 = top.ax + fx[k];
            int ny1 = top.ay + fy[k];
            int nx2 = top.bx + fx[k];
            int ny2 = top.by + fy[k];
            int nx3 = top.cx + fx[k];
            int ny3 = top.cy + fy[k];
            if(nx1<0 || nx1>=n || ny1<0 || ny1>=n || grid[nx1][ny1]=='#'){
                nx1 -= fx[k];
                ny1 -= fy[k];
            }
            if(nx2<0 || nx2>=n || ny2<0 || ny2>=n || grid[nx2][ny2]=='#'){
                nx2 -= fx[k];
                ny2 -= fy[k];
            }
            if(nx3<0 || nx3>=n || ny3<0 || ny3>=n || grid[nx3][ny3]=='#'){
                nx3 -= fx[k];
                ny3 -= fy[k];
            }
            if(mp(nx1,ny1) == mp(nx2,ny2)){
                nx1 = top.ax;
                ny1 = top.ay;
                nx2 = top.bx;
                ny2 = top.by;
            }
            if(mp(nx1,ny1) == mp(nx3,ny3)){
                nx1 = top.ax;
                ny1 = top.ay;
                nx3 = top.cx;
                ny3 = top.cy;
            }
            if(mp(nx2,ny2) == mp(nx3,ny3)){
                nx2 = top.bx;
                ny2 = top.by;
                nx3 = top.cx;
                ny3 = top.cy;
            }
            if(vis[nx1][ny1][nx2][ny2][nx3][ny3] || mp(nx1,ny1)==mp(nx2,ny2) || mp(nx1,ny1)==mp(nx3,ny3) || mp(nx2,ny2)==mp(nx3,ny3))
                continue;
            if(1+dis[top.ax][top.ay][top.bx][top.by][top.cx][top.cy] <= dis[nx1][ny1][nx2][ny2][nx3][ny3]){
                dis[nx1][ny1][nx2][ny2][nx3][ny3] = 1 + dis[top.ax][top.ay][top.bx][top.by][top.cx][top.cy];
                q.push(node(nx1 , ny1 , nx2 , ny2 , nx3 , ny3));
                vis[nx1][ny1][nx2][ny2][nx3][ny3] = 1;
            }
        }
    }
}

void Solve(int t)
{
    int i,j,k,ans;
    vector<pii>src,target;
    scin(n);
    for(i=0 ; i<n ; i++)
        sc("%s",grid[i]);
    for(i=0 ; i<n ; i++){
        for(j=0 ; j<n ; j++){
            if(grid[i][j]=='A' || grid[i][j]=='B' || grid[i][j]=='C'){
                src.pb(make_pair(i , j));
            }
            else if(grid[i][j] == 'X'){
                target.pb(make_pair(i , j));
            }
        }
    }
    BFS(src[0].first , src[0].second , src[1].first , src[1].second , src[2].first , src[2].second);
    ans = infinity;
    sort(target.begin() , target.end());
    do{
        ans = min(ans , dis[target[0].first][target[0].second][target[1].first][target[1].second][target[2].first][target[2].second]);
    }while(next_permutation(target.begin() , target.end()));
    if(ans == infinity)
        pf("Case %d: trapped\n",t);
    else
        pf("Case %d: %d\n",t,ans);
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
3
7
.....#.
.......
.#B....
...A.#.
.CX....
.X.X.#.
.#.....
3
ABC
...
XXX
3
ABC
###
XXX
**/
