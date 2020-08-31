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

#define sz 1000005
int ara[sz],lazy[4*sz];

struct info
{
    int four,seven,ftos,stof;
    info(){}
    info(int _four,int _seven,int _ftos,int _stof)
    {
        four = _four;
        seven = _seven;
        ftos = _ftos;
        stof = _stof;
    }
}tree[4*sz];

info Combine(info p1,info p2)
{
    info ret;
    ret.four = p1.four + p2.four;
    ret.seven = p1.seven + p2.seven;
    ret.ftos = max(p1.four+p2.ftos , max(p1.four+p2.seven , p1.ftos+p2.seven));
    ret.stof = max(p1.seven+p2.four , max(p1.seven+p2.stof , p1.stof+p2.four));
    return ret;
}

void push_down(int node,int b,int e)
{
    swap(tree[node].four , tree[node].seven);
    swap(tree[node].ftos , tree[node].stof);
    if(b != e){
        lazy[node<<1] ^= 1;
        lazy[1+(node<<1)] ^= 1;
    }
    lazy[node] = 0;
}

void Init(int node,int b,int e)
{
    if(b == e){
        if(ara[b] == 4)
            tree[node] = info(1 , 0 , 1 , 1);
        else
            tree[node] = info(0 , 1 , 1 , 1);
        return;
    }
    int mid = (b+e)>>1;
    Init(node<<1 , b , mid);
    Init(1+(node<<1) , mid+1 , e);
    tree[node] = Combine(tree[node<<1] , tree[1+(node<<1)]);
}

void Update(int node,int b,int e,int i,int j)
{
    if(lazy[node] != 0)
        push_down(node , b , e);
    if(e<i || b>j)
        return;
    if(b>=i && e<=j){
        swap(tree[node].four , tree[node].seven);
        swap(tree[node].ftos , tree[node].stof);
        if(b != e){
            lazy[node<<1] ^= 1;
            lazy[1+(node<<1)] ^= 1;
        }
        return;
    }
    int mid = (b+e)>>1;
    Update(node<<1 , b , mid , i , j);
    Update(1+(node<<1) , mid+1 , e , i , j);
    tree[node] = Combine(tree[node<<1] , tree[1+(node<<1)]);
}

void Solve(int t)
{
    int i,j,k,n,q,ans,l,r;
    cin>>n>>q;
    string s;
    cin>>s;
    for(i=0 ; i<n ; i++)
        ara[i+1] = s[i]-'0';
    Init(1 , 1 , n);
    for(i=1 ; i<=q ; i++){
        cin>>s;
        if(s == "count"){
            info ret = tree[1];
            cout<<max(ret.four , max(ret.seven , ret.ftos))<<endl;
        }
        else{
            cin>>l>>r;
            Update(1 , 1 , n , l , r);
        }
    }
}

int main()
{
    CIN;
    int t,T;
    T = 1;
    RUN_CASE(t,T)
    {
        Solve(t);
    }
    return 0;
}



