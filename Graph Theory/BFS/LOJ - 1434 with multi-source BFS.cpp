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

const int fx[] = {+0 , +0,+0,+1,-1,-1,+1,-1,+1}; ///King's move
const int fy[] = {+0 , -1,+1,+0,+0,+1,+1,-1,-1}; ///King's move

char grid[32][32];
bool vis[32][32][25];
int row,col,dir[32][32][25];
vector<pii>letter[30];
char str[25];

void Clean()
{
    for(int i=0 ; i<=row ; i++){
        for(int j=0 ; j<=col ; j++){
            for(int k=0 ; k<20 ; k++){
                vis[i][j][k] = 0;
                dir[i][j][k] = -1;
            }
        }
    }
}

struct node
{
    int x,y,sl;
    node(){}
    node(int _x,int _y,int _sl){
        x = _x;
        y = _y;
        sl = _sl;
    }
};

int oppositeDIRECTION(int n)
{
    if(n == 1)
        return 2;
    else if(n == 2)
        return 1;
    else if(n == 3)
        return 4;
    else if(n == 4)
        return 3;
    else if(n == 5)
        return 8;
    else if(n == 6)
        return 7;
    else if(n == 7)
        return 6;
    else if(n == 8)
        return 5;
}

void BFS()
{
    Clean();
    pii last = make_pair(-1 , -1);
    vector<int>ans;
    bool fg = 0;

    queue<node>q;
    int sz = strlen(str);
    for(int i=0 ; i<(int)letter[str[0]-'A'].size() ; i++){
        int x = letter[str[0]-'A'][i].first;
        int y = letter[str[0]-'A'][i].second;
        vis[x][y][0] = 1;
        q.push(node(x , y , 0));
    }

    while(!q.empty() && !fg){
        node pr = q.front();
        q.pop();
        int sx = pr.x;
        int sy = pr.y;
        int id = pr.sl;
        for(int k=0 ; k<9 && !fg ; k++){
            int nx = sx+fx[k];
            int ny = sy+fy[k];
            if(id<sz-1 && nx>=0 && nx<row && ny>=0 && ny<col && grid[nx][ny]==str[id+1] && !vis[nx][ny][id+1]){
                vis[nx][ny][id+1] = 1;

                if(k>=1 && k<=8)
                    dir[nx][ny][id+1] = oppositeDIRECTION(k);

                if(id+1 == sz-1)    ///Full Name found
                {
                    fg = 1;
                    last = make_pair(nx , ny);
                }
                else
                    q.push(node(nx , ny , id+1));
            }
        }
    }
    if(fg){
        pii curr = last;
        int curidx = sz-1;
        while(curidx > 0){
            int x = curr.first;
            int y = curr.second;
            if(dir[x][y][curidx] == -1)
                dir[x][y][curidx] = 0;
            int nx = x + fx[dir[x][y][curidx]];
            int ny = y + fy[dir[x][y][curidx]];
            if(grid[nx][ny] == str[curidx-1]){
                curr = make_pair(nx , ny);
                ans.pb(dir[x][y][curidx]);
                curidx--;
            }
            else{
                ans.pb(0);
                curidx--;
            }
        }
        pf("%s found: (%d,%d)",str,curr.first+1,curr.second+1);
        for(int i=(int)ans.size()-1 ; i>=0 ; i--){
            if(ans[i] == 0)
                pf(", *");
            else if(ans[i] == 1)
                pf(", R");
            else if(ans[i] == 2)
                pf(", L");
            else if(ans[i] == 3)
                pf(", U");
            else if(ans[i] == 4)
                pf(", D");
            else if(ans[i] == 5)
                pf(", DL");
            else if(ans[i] == 6)
                pf(", UL");
            else if(ans[i] == 7)
                pf(", DR");
            else
                pf(", UR");
        }
        pf("\n");
    }
    else{
        pf("%s not found\n",str);
    }
}

void Solve(int t)
{
    int i,j,k,ans,q,len;
    for(int i=0 ; i<27 ; i++)
        letter[i].clear();
    scin2(row , col);
    for(i=0 ; i<row ; i++){
        sc("%s",grid[i]);
        len = strlen(grid[i]);
        for(j=0 ; j<len ; j++){
            letter[grid[i][j]-'A'].pb(make_pair(i , j));
        }
    }
    scin(q);
    pf("Case %d:\n",t);
    for(i=1 ; i<=q ; i++){
        sc("%s",str);
        BFS();
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
