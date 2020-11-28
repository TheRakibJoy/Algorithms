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
#define ms(a,b)                 memset(a,b,sizeof(a))
#define pb(a)                   push_back(a)
#define RUN_CASE(t,T)           for(__typeof(t) t=1;t<=T;t++)

using namespace std;

/** Problem Summary: Find number of non-overlapping path from source to destination **/

const int fx[] = {+1,+0};
const int fy[] = {+0,+1};

int n,m;
vector<vector<int> >vis;
vector<vector<char> >grid;

bool DFS(int sx,int sy)
{
    if(sx==n-1 && sy==m-1)
        return 1;

    int ret = 0;
    vis[sx][sy] = 1;
    for(int k=0 ; k<2 ; k++){
        int nx = sx+fx[k];
        int ny = sy+fy[k];

        if(nx>=0 && nx<n && ny>=0 && ny<m && grid[nx][ny]=='.' && !vis[nx][ny]){
            ret |= DFS(nx , ny);
        }
        if(ret)
            break;
    }
    return ret;
}

void Solve(int t)
{
    int i,j,k,path=0;
    cin>>n>>m;

    for(i=1 ; i<=n ; i++){
        vector<char>temp;
        vector<int>temp2;
        char ch;
        for(j=1 ; j<=m ; j++){
            cin>>ch;
            temp.pb(ch);
            temp2.pb(0);
        }
        temp2.pb(0);
        grid.pb(temp);
        vis.pb(temp2);
    }

    path += DFS(0 , 0);
    vis[0][0] = vis[n-1][m-1] = 0;
    path += DFS(0 , 0);
    cout<<path<<endl;
}

int main()
{
    int t,T;
    T = 1;
    RUN_CASE(t,T)
    {
        Solve(t);
    }
    return 0;
}
