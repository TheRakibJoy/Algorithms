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

/** This is the most optimized solution for querying maximum frequency of value in a
given sub-array **/

#define sz 200009

int n , mxfre=0 , blocksz , ara[sz] , ans[sz] , freoffre[sz] , freofval[sz];
map<int , int>compress;

struct info
{
    int l,r,k,id;
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
    freofval[ara[idx]]++;
    freoffre[ freofval[ara[idx]] ]++;
    mxfre = max(mxfre , freofval[ara[idx]]);
}

void Remove(int idx)
{
    freoffre[ freofval[ara[idx]] ]--;
    freofval[ara[idx]]--;

    if(freoffre[mxfre] == 0)
        mxfre--;
}

void Solve(int t)
{
    int i,j,l,r,q,cnt=0;
    scin2(n , q);
    blocksz = sqrt(n);
    for(i=1 ; i<=n ; i++){
        scin(ara[i]);
        if(compress[ara[i]] == 0)
            ara[i] = compress[ara[i]] = ++cnt;
        else
            ara[i] = compress[ara[i]];
    }

    for(i=1 ; i<=q ; i++){
        sc("%d %d %d",&query[i].l , &query[i].r , &query[i].k);
        query[i].id = i;
    }
    sort(query+1 , query+q+1);

    l = 1; r = 0;
    for(i=1 ; i<=q ; i++){
        while(r < query[i].r)   Add(++r);
        while(l < query[i].l)   Remove(l++);
        while(r > query[i].r)   Remove(r--);
        while(l > query[i].l)   Add(--l);

        if((ll)mxfre*(ll)query[i].k >= r-l+1)
            ans[query[i].id] = 1;
        else
            ans[query[i].id] = 0;
    }

    for(i=1 ; i<=q ; i++){
        if(ans[i])
            pf("YES\n");
        else
            pf("NO\n");
    }
}

int main()
{
    Solve(1);
    return 0;
}

/** Stuff u should look for
    * Avoid overflow
    * Corner(Small) case
    * Don't get stuck on one approach
    * Don't forget to clean used memory in each case
**/

