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
#define lcm(a,b)                (a)*(b)/gcd(a,b)
#define mxx                     123456789
#define PI                      2*acos(0.0)
#define rep(i,a,b)              for(__typeof(i) i=a;i<=b;i++)
#define rev(i,a,b)              for(__typeof(i) i=a;i>=b;i--)

using namespace std;

/**     Order Set       **/
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template<typename T> using orderset = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;


/**
Observation:
1. Minimum position of a friend is its SL number if he wasn'sent message or 1 otherwise.
2. Maximum position of a friend depends on those friend who are bigger than him.
**/

#define sz 1000005
int a[sz],mn[sz],mx[sz],last[sz],fre[sz];
orderset<int>st;

int blocksz,distinct=0,ans[sz];

struct info
{
    int id,l,r;
    info(){}
    info(int a,int b,int c)
    {
        l = a; r = b; id = c;
    }
    bool operator < (const info &p)const{
        int blockno = l/blocksz;
        int pblockno = p.l/blocksz;
        if(blockno == pblockno)
            return r<p.r;
        else
            return blockno<pblockno;
    }
}query[sz];

void Add(int index)
{
    if(fre[a[index]] == 0)
        distinct++;
    fre[a[index]]++;
}

void Remove(int index)
{
    fre[a[index]]--;
    if(fre[a[index]] == 0)
        distinct--;
}

void Solve(int t)
{
    int i,j,k,n,m,qno=0;
    scin2(n , m);
    blocksz = sqrt(n);
    rep(i,1,n) mn[i] = mx[i] = i;
    for(i=1 ; i<=m ; i++){
        scin(a[i]);
        mn[a[i]] = 1;

        if(last[a[i]] != 0){
            query[qno] = info(last[a[i]]+1 , i-1 , qno);
            qno++;
        }
        last[a[i]] = i;
    }
    for(i=1 ; i<=n ; i++){
        if(last[i] != 0 && last[i]<m){
            query[qno] = info(last[i]+1 , m , qno);
            qno++;
        }
    }
//    cout<<qno<<endl;
    sort(query , query+qno);
    int l=1,r=0;

    ///
//    DBG;
    for(i=0 ; i<qno ; i++){
        while(r < query[i].r)   Add(++r);
        while(l < query[i].l)   Remove(l++);
        while(r > query[i].r)   Remove(r--);
        while(l > query[i].l)   Add(--l);
        ans[query[i].id] = distinct;
    }

    int id = 0;
    ms(last , 0);
    for(i=1 ; i<=m ; i++){
        st.insert(a[i]);
        if(last[a[i]] == 0){
            int temp = (int)st.size() - st.order_of_key(a[i]) - 1;
            mx[a[i]] = a[i]+temp;
        }
        else{
            mx[a[i]] = max(mx[a[i]] , 1+ans[id++]);
        }
        last[a[i]] = i;
    }
    for(i=1 ; i<=n ; i++){
        st.insert(i);
        if(last[i] == 0){
            int temp = (int)st.size() - st.order_of_key(i) - 1;
            mx[i] = max(mx[i] , i+temp);
        }
        else if(last[i]!=0 && last[i]<m){
            mx[i] = max(mx[i] , 1+ans[id++]);
        }
    }
    for(i=1 ; i<=n ; i++)
        cout<<mn[i]<<' '<<mx[i]<<endl;
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

