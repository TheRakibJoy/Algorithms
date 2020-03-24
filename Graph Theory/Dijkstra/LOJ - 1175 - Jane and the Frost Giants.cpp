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

const int fx[] = {+1,-1,+0,+0};
const int fy[] = {+0,+0,+1,-1};

int row,col,dj[205][205],df[205][205];
bool vis[205][205];
char grid[205][205];

void BFS(int sx,int sy)
{
    queue<pii>q;
    vis[sx][sy] = 1;
    dj[sx][sy] = 1;
    q.push({sx,sy});
    while(!q.empty()){
        pii top = q.front();
        q.pop();
        for(int i=0 ; i<4 ; i++){
            int nx = top.first+fx[i];
            int ny = top.second+fy[i];
            if(nx>=0 && nx<row && ny>=0 && ny<col && !vis[nx][ny] && grid[nx][ny]!='#'){
                vis[nx][ny] = 1;
                dj[nx][ny] = 1+dj[top.first][top.second];
                q.push({nx,ny});
            }
        }
    }
}
struct node
{
    int x,y,w;
    node(){}
    node(int a,int b,int c){
        x = a; y = b; w = c;
    }
    bool operator < (const node &p)const{
        if(w != p.w)
            return w>p.w;
        else{
            if(x != p.x)
                return x<p.x;
            else
                return y<p.y;
        }
    }
};
void dijkstra(int sx,int sy)
{
    priority_queue<node>pq;
    df[sx][sy] = 1;
    pq.push(node(sx , sy , 1));
    while(!pq.empty()){
        node top = pq.top();
        pq.pop();
        if(top.w > df[top.x][top.y])    ///Can be equal
            continue;
        for(int i=0 ; i<4 ; i++){
            int nx = top.x+fx[i];
            int ny = top.y+fy[i];
            if(nx>=0 && nx<row && ny>=0 && ny<col && grid[nx][ny]!='#' && grid[nx][ny]!='F'){
                if(df[nx][ny] > 1+df[top.x][top.y]){
                    df[nx][ny] = 1+df[top.x][top.y];
                    pq.push(node(nx , ny , df[nx][ny]));
                }
            }
        }
    }
}
void Clean()
{
    for(int i=0 ; i<=row ; i++){
        for(int j=0 ; j<=col ; j++){
            dj[i][j] = df[i][j] = infinity;
            vis[i][j] = 0;
        }
    }
}

void Solve(int t)
{
    int i,j,sx,sy,ans = infinity;
    getchar();
    scin2(row , col);
    Clean();
    for(i=0 ; i<row ; i++){
        getchar();
        for(j=0 ; j<col ; j++){
            sc("%c",&grid[i][j]);
            if(grid[i][j] == 'J'){
                sx = i; sy = j;
            }
        }
    }
    BFS(sx , sy);
    for(i=0 ; i<row ; i++){
        for(j=0 ; j<col ; j++){
            if(grid[i][j] == 'F')
                dijkstra(i , j);
        }
    }
    ///First & Last ROW
    for(i=0 ; i<col ; i++){
        if(df[0][i] > dj[0][i])
            ans = min(ans , dj[0][i]);
        if(df[row-1][i] > dj[row-1][i])
            ans = min(ans , dj[row-1][i]);
    }
    ///First & Last Column
    for(i=0 ; i<row ; i++){
        if(df[i][0] > dj[i][0])
            ans = min(ans , dj[i][0]);
        if(df[i][col-1] > dj[i][col-1])
            ans = min(ans , dj[i][col-1]);
    }
//    for(i=0 ; i<row ; i++){
//        for(j=0 ; j<col ; j++)
//            pf("[%d,%d] - DJ = %d\n",i,j,dj[i][j]);
//    }
    if(ans == infinity)
        pf("Case %d: IMPOSSIBLE\n",t);
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
2
4 5
##.##
#JF.#
#...#
#...#
3 3
###
#J.
#.F
**/
