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

/** Problem: You have an array of N integers and Q queries on this array. There are two types of queries:
1. L R : count the numbers divisible by K in range [L, R].
2. L R Y : add Y to all numbers in range [L, R]
Link: https://www.hackerearth.com/problem/algorithm/final-question/     **/

#define sz 200005
int totblock,blocksz,ara[sz],toadd[501],fre[501][1005];   ///fre[x][y] - how many number in xth block those r equal to y(y = a[i]%k)

void Build(int n,int k)
{
    for(int i=0 ; i<n ; i++){
        ara[i] %= k;
        fre[i / blocksz][ara[i]]++;
    }
}

int Query(int lft,int rgt,int n,int k)
{
    int ret=0,stBlock,edBlock;
    stBlock = lft/blocksz;
    edBlock = rgt/blocksz;
    if(stBlock == edBlock){
        for(int i=lft ; i<=rgt ; i++){
            ret += ((ara[i]+toadd[stBlock])%k == 0);
        }
    }
    else{
        for(int i=lft ; i<=((stBlock+1)*blocksz)-1 ; i++){
            ret += ((ara[i]+toadd[stBlock])%k == 0);
        }
        for(int i=stBlock+1 ; i<=edBlock-1 ; i++){
            int xtra = toadd[i];
            ret += fre[i][(k-xtra)%k];
        }
        for(int i=edBlock*blocksz ; i<=rgt ; i++){
            ret += ((ara[i]+toadd[edBlock])%k == 0);
        }
    }
    return ret;
}

void Update(int n,int k,int l,int r,int x)
{
    int stBlock = l/blocksz , edBlock = r/blocksz;
    if(stBlock == edBlock){
        for(int i=l ; i<=r ; i++){
            fre[i/blocksz][ara[i]]--;
            ara[i] = (ara[i]+x)%k;
            fre[i/blocksz][ara[i]]++;
        }
    }
    else{
        for(int i=l ; i<=((stBlock+1)*blocksz)-1 ; i++){
            fre[i/blocksz][ara[i]]--;
            ara[i] = (ara[i]+x)%k;
            fre[i/blocksz][ara[i]]++;
        }
        for(int i=stBlock+1 ; i<=edBlock-1 ; i++)
            toadd[i] = (toadd[i]+x)%k;
        for(int i=edBlock*blocksz ; i<=r ; i++){
            fre[i/blocksz][ara[i]]--;
            ara[i] = (ara[i]+x)%k;
            fre[i/blocksz][ara[i]]++;
        }
    }
}

void Solve(int t)
{
    int i,j,k,n,q,l,r,qid,x,ans;
    sc("%d %d %d",&n,&q,&k);
    totblock = blocksz = sqrt(n)+1;
    rep(i,0,n-1)    scln(ara[i]);
    Build(n , k);
    for(i=1 ; i<=q ; i++){
        sc("%d %d %d",&qid,&l,&r);
        if(qid == 1){
            ans = Query(l , r , n , k);
            pf("%d\n",ans);
        }
        else{
            scin(x);
            Update(n , k , l , r , x);
        }
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



