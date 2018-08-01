#include<bits/stdc++.h>

#define perfect                 int main()
#define ll                      long long int
#define ull                     unsigned long long int
#define pii                     pair<int,int>
#define pll                     pair<ll,ll>
#define sc                      scanf
#define scin(x)                 sc("%d",&(x))
#define scin2(x)                sc("%d %d",&(x),&(y))
#define scln(x)                 sc("%lld",&(x))
#define scln2(x)                sc("%lld %lld",&(x),&(y))
#define pf                      printf
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
#define MOD                     100000007
#define CIN                     ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define RUN_CASE(t,T)           for(__typeof(t) t=1;t<=T;t++)
#define CASE(t)                 printf("Case %d: ",t)
#define CASEl(t)                printf("Case %d:\n",t)
#define intlimit                2147483647;
#define longlimit               9223372036854775808
#define infinity                (1<<28)
#define gcd(a,b)                __gcd(a,b)
#define lcm(a,b)                ((a)*(b))/gcd(a,b)
#define mxx                     123456789
#define PI                      2*acos(0.0)
#define rep(i,a,b)              for(__typeof(i) i=a;i<=b;i++)
#define rev(i,a,b)              for(__typeof(i) i=a;i>=b;i--)

using namespace std;

///------------------Graph Moves-------------------
const int fx[] = {+1,-1,+0,+0};
const int fy[] = {+0,+0,+1,-1};
/// const int fx[] = {+0,+0,+1,-1,-1,+1,-1,+1}; ///King's move
/// const int fy[] = {-1,+1,+0,+0,+1,+1,-1,-1}; ///King's move
/// const int fx[] = {-2,-2,-1,-1,+1,+1,+2,+2}; ///Knight's move
/// const int fy[] = {-1,+1,-2,+2,-2,+2,-1,+1}; ///Knight's move
int i,j,k,row,col;
vector<int>graph[500];
string s[30];
int vis[500];
int val[25][25];
bool valid(int nx,int ny)
{
    if((nx>=1 && nx<=row) && (ny>=1 && ny<=col))
    {
        if((s[i][j]!='#' && s[i][j]!='m') && (s[nx][ny]!='#' && s[nx][ny]!='m'))
            return true;
        else
            return false;
    }
    return false;
}
void BFS(int start)
{
    queue<int>Q;
    Q.push(start);
    vis[start]=0;
    while(!Q.empty())
    {
        int u=Q.front();
        Q.pop();
        for(int i=0; i<graph[u].size(); i++)
        {
            if(vis[graph[u][i]] == 0)
            {
                int v=graph[u][i];
                vis[v]=1+vis[u]; /** Count the shortest distance **/
                Q.push(v);
            }
        }
    }
}
int main()
{
    int t,T,a,b,c,h,co,d,x,nx,ny;
    string temp;
    scin(T);
    RUN_CASE(t,T)
    {
        sc("%d %d",&row,&col);
        co=0;
        s[0]="0000000000000000000000000";
        ms(vis,0);
        ms(val,0);
        for(i=0; i<500; i++)
            graph[i].clear();
        for(i=0; i<30; i++)
            s[i].clear();
        for(i=1; i<=row; i++)
        {
            s[i]=" ";
            cin>>temp;
            s[i]+=temp;
        }
        x=1;
        for(i=1; i<=row; i++)
        {
            for(j=1; j<=col; j++)
            {
                val[i][j]=x;
                x++;
                if(s[i][j] == 'a')
                    a=val[i][j];
                else if(s[i][j] == 'b')
                    b=val[i][j];
                else if(s[i][j] == 'c')
                    c=val[i][j];
                else if(s[i][j] == 'h')
                    h=val[i][j];
            }
        }
        for(i=1; i<=row; i++)
        {
            for(j=1; j<=col; j++)
            {
                if(s[i][j]!='#' && s[i][j]!='m')
                {
                    for(k=0; k<4; k++)
                    {
                        nx=i+fx[k];
                        ny=j+fy[k];
                        if(valid(nx,ny) == true)
                        {
                            graph[val[i][j]].pb(val[nx][ny]);
                            graph[val[nx][ny]].pb(val[i][j]);
                        }
                    }
                }
            }
        }
        BFS(h);
        co=max(co,vis[a]);
        co=max(co,vis[b]);
        co=max(co,vis[c]);
        pf("Case %d: %d\n",t,co);
    }
    return 0;
}
