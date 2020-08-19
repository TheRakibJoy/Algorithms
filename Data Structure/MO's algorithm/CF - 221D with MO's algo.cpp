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

#define sz 100005
int blocksz,desire=0,ans[sz],ara[sz];
int fre[sz];

struct info
{
    int id,l,r;
    bool operator < (const info &p)const{
        int blockno = l/blocksz;
        int pblockno = p.l/blocksz;
        if(blockno == pblockno)
            return r<p.r;
        else
            return blockno<pblockno;
    }
}query[sz];

void Add(int idx)
{
    if(ara[idx] > 1e5)
        return;
    if(fre[ara[idx]] == ara[idx]-1)
        desire++;
    else if(fre[ara[idx]] == ara[idx])
        desire--;
    fre[ara[idx]]++;
}

void Remove(int idx)
{
    if(ara[idx] > 1e5)
        return;
    if(fre[ara[idx]] == ara[idx])
        desire--;
    else if(fre[ara[idx]] == ara[idx]+1)
        desire++;
    fre[ara[idx]]--;
}

void Solve(int t)
{
    int i,j,k,n,q,l,r;
    scin2(n , q);
    blocksz = sqrt(n*1.0);
    for(i=0 ; i<n ; i++)
        scin(ara[i]);
    for(i=0 ; i<q ; i++){
        scin2(l , r);
        query[i].l = l-1;
        query[i].r = r-1;
        query[i].id = i;
    }
    sort(query , query+q);
    l=0; r=-1;

    ///Calculate answer for all query in offLine
    for(i=0 ; i<q ; i++){
        while(r < query[i].r)   Add(++r);
        while(l < query[i].l)   Remove(l++);
        while(r > query[i].r)   Remove(r--);
        while(l > query[i].l)   Add(--l);
        ans[query[i].id] = desire;
    }
    for(i=0 ; i<q ; i++)
        cout<<ans[i]<<endl;
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



