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

/** Problem: You're given a 2D grid. You have to answer q queries. In each query u will
given upper left & lower right point of a sub-rectangle. You have to answer maximum
element of that sub-rectangle.(advance session-11,52minutes) **/

const int sz = 505;
const int k = 11;
int Log[sz],grid[sz][sz],sptable[sz][sz][k][k]; ///sptable[x][y][kx][ky] - Store the maximum of sub-rectangle from (x,y) point whose length is kx & width is ky

void PreLog(int row,int col)
{
    Log[1] = 0;
    for(int i=2 ; i<=max(row , col) ; i++)
        Log[i] = Log[i/2]+1;
}

void sparseTable(int row,int col)
{
    for(int kx=0 ; (1<<kx) <= col ; kx++){      ///kx is the length from upper left
        for(int ky=0 ; (1<<ky) <= row ; ky++){  ///ky is the width from upper left
            for(int x=1 ; x<=row ; x++){
                for(int y=1 ; y<=col ; y++){
                    if(kx==0 && ky==0)  ///IF its a 1*1 grid
                        sptable[x][y][kx][ky] = grid[x][y];
                    else if(kx == 0)    ///IF its length is 1
                        sptable[x][y][kx][ky] = max(sptable[x][y][kx][ky-1] , sptable[x][y+(1<<(ky-1))][kx][ky-1]);
                    else if(ky == 0)    ///IF its width is 1
                        sptable[x][y][kx][ky] = max(sptable[x][y][kx-1][ky] , sptable[x+(1<<(kx-1))][y][kx-1][ky]);
                    else
                        sptable[x][y][kx][ky] = max(sptable[x][y][kx-1][ky] , max(sptable[x+(1<<(kx-1))][y][kx-1][ky] , max(sptable[x][y][kx][ky-1] , sptable[x][y+(1<<(ky-1))][kx][ky-1])));
                }
            }
        }
    }
}

int RmxQ(int x1,int y1,int x2,int y2)
{
    int xlog = Log[x2-x1+1];
    int ylog = Log[y2-y1+1];
    int ret = max(sptable[x1][y1][xlog][ylog] , max(sptable[x2-(1<<xlog)+1][y1][xlog][ylog] , max(sptable[x1][y2-(1<<ylog)+1][xlog][ylog] , sptable[x2-(1<<xlog)+1][y2-(1<<ylog)+1][xlog][ylog])));
    return ret;
}

void Solve(int t)
{
    int i,j,row,col,q,x1,y1,x2,y2;
    cin>>row>>col;
    for(i=1 ; i<=row ; i++){
        for(j=1 ; j<=col ; j++){
            cin>>grid[i][j];
        }
    }
    PreLog(row , col);
    sparseTable(row , col);
    cin>>q;
    for(i=1 ; i<=q ; i++){
        cin>>x1>>y1>>x2>>y2;
        cout<<i<<" -> "<<RmxQ(x1 , y1 , x2 , y2)<<endl;
    }
}

int main()
{
    int t,T;
    T = 1;
//    scin(T);
    RUN_CASE(t,T)
    {
        Solve(t);
    }
    return 0;
}
/**
5 5
3 1 2 5 7
4 6 8 10 2
6 9 11 13 5
17 18 3 4 1
4 8 6 9 11
12
1 1 2 2
1 1 3 3
1 1 4 4
1 1 5 5
3 4 3 4
3 4 5 5
1 4 5 5
1 3 3 5
2 3 3 4
4 2 5 5
5 4 5 5
5 3 5 5
Output:
**/
