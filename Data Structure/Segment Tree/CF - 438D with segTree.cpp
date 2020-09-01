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
int ara[sz];
pii mxtree[4*sz];   ///Max Value; ID of max value
ll sumtree[4*sz];

void Init(int node,int b,int e)
{
    if(b == e){
        mxtree[node] = make_pair(ara[b] , b);
        sumtree[node] = ara[b];
        return;
    }
    int mid = (b+e)>>1;
    int lft = node<<1;
    int rgt = 1+lft;
    Init(lft , b , mid);
    Init(rgt , mid+1 , e);
    sumtree[node] = sumtree[lft] + sumtree[rgt];
    if(mxtree[lft].first >= mxtree[rgt].first)
        mxtree[node] = mxtree[lft];
    else
        mxtree[node] = mxtree[rgt];
}

void pointUpdate(int node,int b,int e,int idx,int val)
{
    if(idx<b || idx>e)
        return;
    if(idx==b && idx==e){
        mxtree[node] = make_pair(val , idx);
        sumtree[node] = val;
        return;
    }
    int mid = (b+e)>>1;
    int lft = node<<1;
    int rgt = 1+lft;
    pointUpdate(lft , b , mid , idx , val);
    pointUpdate(rgt , mid+1 , e , idx , val);
    sumtree[node] = sumtree[lft] + sumtree[rgt];
    if(mxtree[lft].first >= mxtree[rgt].first)
        mxtree[node] = mxtree[lft];
    else
        mxtree[node] = mxtree[rgt];
}

pii mxIDQuery(int node,int b,int e,int i,int j)
{
    if(e<i || b>j)
        return make_pair(0 , -1);
    if(b>=i && e<=j)
        return mxtree[node];
    int mid = (b+e)>>1;
    int lft = node<<1;
    int rgt = 1+lft;
    pii ret1 = mxIDQuery(lft , b , mid , i , j);
    pii ret2 = mxIDQuery(rgt , mid+1 , e , i , j);
    if(ret1.first >= ret2.first)
        return ret1;
    else
        return ret2;
}

ll sumQuery(int node,int b,int e,int i,int j)
{
    if(e<i || b>j)
        return 0;
    if(b>=i && e<=j)
        return sumtree[node];
    int mid = (b+e)>>1;
    int lft = node<<1;
    int rgt = 1+lft;
    ll p1 = sumQuery(lft , b , mid , i , j);
    ll p2 = sumQuery(rgt , mid+1 , e , i , j);
    return p1+p2;
}

void Solve(int t)
{
    int i,j,k,n,q,l,r,val,type;
    cin>>n>>q;
    for(i=1 ; i<=n ; i++)   cin>>ara[i];
    Init(1 , 1 , n);
    for(i=1 ; i<=q ; i++){
        cin>>type;
        if(type == 1){
            cin>>l>>r;
            ll ans = sumQuery(1 , 1 , n , l , r);
            cout<<ans<<endl;
        }
        else if(type == 2){
            cin>>l>>r>>val;
            int range = r-l+1;
            while(range--){
                pii ret = mxIDQuery(1 , 1 , n , l , r);
                if(ret.first < val)
                    break;
                pointUpdate(1 , 1 , n , ret.second , ret.first%val);
            }
        }
        else{
            cin>>k>>val;
            pointUpdate(1 , 1 , n , k , val);
        }
    }
}

int main()
{
    CIN;
    int t,T;
    T = 1;
//    cin>>T;
    RUN_CASE(t,T)
    {
        Solve(t);
    }
    return 0;
}



