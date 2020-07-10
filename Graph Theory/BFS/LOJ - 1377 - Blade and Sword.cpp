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

/** এন্সার হবে p থেকে d এর স্বাভাবিক দূরত্ব এবং (p এর সবথেকে কাছে * এর দূরত্ব + d এর সব থেকে কাছের * এর দূরত্ব) এই দুইয়ের মধ্যে সর্বনিম্ন টা **/

const int fx[] = {+1,-1,+0,+0};
const int fy[] = {+0,+0,+1,-1};

char grid[205][205];
int row,col,pstardis = infinity, pstardis2 = infinity, dstardis = infinity , vis[205][205] , dis[205][205];

void BFS(int sx,int sy)
{
    queue<pii>q;
    q.push({sx , sy});
    vis[sx][sy] = 1;
    dis[sx][sy] = 0;
    while(!q.empty()){
        pii pr = q.front();
        q.pop();
        if(grid[pr.first][pr.second] == '*')
            continue;
        for(int k=0 ; k<4 ; k++){
            int nx = pr.first + fx[k];
            int ny = pr.second + fy[k];
            if(nx>=0 && nx<row && ny>=0 && ny<col && !vis[nx][ny] && grid[nx][ny]!='#'){
                vis[nx][ny] = 1;
                dis[nx][ny] = 1+dis[pr.first][pr.second];
                q.push({nx , ny});
            }
        }
    }
}

void Clean()
{
    for(int i=0 ; i<=row ; i++){
        for(int j=0 ; j<=col ; j++){
            vis[i][j] = 0;
            dis[i][j] = infinity;
        }
    }
}

void Solve(int t)
{
    int i,j,k,ans,dx,dy,sx,sy,pstarx=202,pstary=202,pstarx2=202,pstary2=202,xtra=0;
    int star = 0;
    scin2(row , col);
    for(i=0 ; i<row ; i++){
        for(j=0 ; j<col ; j++){
            cin>>grid[i][j];
            if(grid[i][j] == 'P')
                sx = i , sy = j;
            else if(grid[i][j] == 'D')
                dx = i , dy = j;
            else if(grid[i][j] == '*')
                star++;
        }
    }
    pstardis = infinity;
    pstardis2 = infinity;
    dstardis = infinity;
    ///
    Clean();
    BFS(sx , sy);
    ans = dis[dx][dy];
    for(i=0 ; i<row ; i++){
        for(j=0 ; j<col ; j++){
            if(grid[i][j]=='*' && dis[i][j]<pstardis){
                pstarx2 = pstarx;
                pstary2 = pstary;
                pstardis2 = pstardis;

                pstardis = dis[i][j];
                pstarx = i;
                pstary = j;
            }
            else if(grid[i][j]=='*' && dis[i][j]<pstardis2){
                pstarx2 = i;
                pstary2 = j;
                pstardis2 = dis[i][j];
            }
        }
    }
    xtra += dis[pstarx][pstary];
    /// Try with first closest pstar & first closest dstar **/
    Clean();
    vis[pstarx][pstary] = 1;
    BFS(dx , dy);
    for(i=0 ; i<row ; i++){
        for(j=0 ; j<col ; j++){
            if(grid[i][j]=='*' && dis[i][j]<dstardis){
                dstardis = dis[i][j];
            }
        }
    }
    ans = min(ans , pstardis+dstardis+1);
    /// Try with 2nd closest pstar & first closest dstar. Because it is possible that first closest pstar & first closest d star is same which is not acceptable **/
    Clean();
    vis[pstarx2][pstary2] = 1;
    BFS(dx , dy);
    for(i=0 ; i<row ; i++){
        for(j=0 ; j<col ; j++){
            if(grid[i][j]=='*' && dis[i][j]<dstardis)
                dstardis = dis[i][j];
        }
    }
    xtra += dis[pstarx][pstary];
    ans = min(ans , pstardis2+dstardis+1);

    ///
    if(star > 1 && pstardis<infinity){  /** IF a star can be reach from both p & d & there're more than one star in the grid. Then we can definitely reach from p to d **/
        ans = min(ans , xtra+2);
    }

    if(ans >= infinity)
        pf("Case %d: impossible\n",t);
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


