///****In the name of ALLAH, most Gracious, most Compassionate****//
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
#define coutv(v)                for(auto it:v)cout<<it<<' ';cout<<'\n';
#define cinv(v)                 for(auto &it:v)cin>>it;
#define srt(v)                  sort(v.begin(),v.end());
#define rsrt(v)                 sort(v.rbegin(),v.rend());
#define rvs(v)                  reverse(v.begin(),v.end());

using namespace std;

#define sz 50009
int n , q , k , blocksz , ara[sz] , tree[100009];
int cnt = 0 , ans[sz];

///BIT Part
int segQuery(int idx)
{
    int sum = 0;
    while(idx > 0){
        sum += tree[idx];
        idx -= (idx & (-idx));
    }
    return sum;
}

int rangeQuery(int lft,int rgt)
{
    if(lft > rgt)
        return 0;
    return segQuery(rgt) - segQuery(lft-1);
}

void update(int idx,int x)
{
    while(idx <= 1e5){
        tree[idx] += x;
        idx += (idx & (-idx));
    }
}

///MO Part
struct info
{
    int id,l,r;
    bool operator < (const info &p)const{
        int blockno = l/blocksz;
        int pblockno = p.l/blocksz;
        if(blockno == pblockno)
            return r < p.r;
        else
            return blockno < pblockno;
    }
}query[sz];

void Add(int idx)
{
    int lftstart = ara[idx] - k;
    int temp = rangeQuery(1 , lftstart);
    cnt += temp;

    int rgtstart = ara[idx] + k;
    temp = rangeQuery(rgtstart , 1e5);
    cnt += temp;

    update(ara[idx] , 1);
}

void Remove(int idx)
{
    update(ara[idx] , -1);

    int lftstart = ara[idx] - k;
    int temp = rangeQuery(1 , lftstart);
    cnt -= temp;

    int rgtstart = ara[idx] + k;
    temp = rangeQuery(rgtstart , 1e5);
    cnt -= temp;
}

void Solve(int t)
{
    sc("%d %d %d",&n,&q,&k);

    blocksz = sqrt(n);

    for(int i=1 ; i<=n ; i++)
        scin(ara[i]);

    for(int i=1 ; i<=q ; i++){
        scin2(query[i].l , query[i].r);
        query[i].id = i;
    }
    sort(query+1 , query+q+1);

    int l=1 , r = 0;
    for(int i=1 ; i<=q ; i++){
        while(r < query[i].r)   Add(++r);
        while(l < query[i].l)   Remove(l++);
        while(r > query[i].r)   Remove(r--);
        while(l > query[i].l)   Add(--l);
        ans[query[i].id] = cnt;
    }

    for(int i=1 ; i<=q ; i++)
        pf("%d\n",ans[i]);
}

int main()
{
    int t,T;
    T = 1;
//    cin>>T;
    RUN_CASE(t,T)
    {
        Solve(t);
    }
    return 0;
}

/** Stuff u should look for
    * Avoid overflow
    * Corner(Small) case
    * Don't get stuck on one approach
    * Don't forget to clean used memory in each case
**/
