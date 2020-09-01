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

/** Problem: You're given a string s. And two types of updates. First type is sort the
substring s[l...r] in ascending order. Second type is sort the substring s[l...r] in
descending order. After all update operation print the resulting string. **/

/** Use segment tree to keep count of frequency of each letter in a specific range **/

#define sz 100005
int ara[sz],tree[27][4*sz],lazy[27][4*sz];

void push_down(int xth,int node,int b,int e)
{
    tree[xth][node] = lazy[xth][node] * (e-b+1);
    if(b != e){
        lazy[xth][node<<1] = lazy[xth][node];
        lazy[xth][1+(node<<1)] = lazy[xth][node];
    }
    lazy[xth][node] = -1;
}

void Init(int node,int b,int e)
{
    if(b == e){
        tree[ara[b]][node] = 1;
        for(int i=0 ; i<26 ; i++)
            lazy[i][node] = -1;
        return;
    }
    int mid = (b+e)>>1;
    int lft = node<<1;
    int rgt = 1+lft;
    Init(lft , b , mid);
    Init(rgt , mid+1 , e);
    for(int i=0 ; i<26 ; i++){
        tree[i][node] = tree[i][lft] + tree[i][rgt];
        lazy[i][node] = -1;
    }
}

void Update(int xth,int node,int b,int e,int i,int j,int val)
{
    if(lazy[xth][node] != -1)
        push_down(xth , node , b , e);
    if(i>e || j<b)
        return;
    if(b>=i && e<=j){
        tree[xth][node] = (e-b+1)*val;
        if(b != e){
            lazy[xth][node<<1] = val;
            lazy[xth][1+(node<<1)] = val;
        }
        lazy[xth][node] = -1;
        return;
    }
    int mid = (b+e)>>1;
    int lft = node<<1;
    int rgt = 1+lft;
    Update(xth , lft , b , mid , i , j , val);
    Update(xth , rgt , mid+1 , e , i , j , val);
    tree[xth][node] = tree[xth][lft]+tree[xth][rgt];
}

int Query(int xth,int node,int b,int e,int i,int j)
{
    if(lazy[xth][node] != -1)
        push_down(xth , node , b , e);
    if(i>e || j<b)
        return 0;
    if(b>=i && e<=j)
        return tree[xth][node];
    int lft = node<<1;
    int rgt = 1+lft;
    int mid = (b+e)>>1;
    int p1 = Query(xth , lft , b , mid , i , j);
    int p2 = Query(xth , rgt , mid+1 , e , i , j);
    return p1+p2;
}

int fre[27];

void Solve(int t)
{
    int i,j,k,n,q,l,r,type;
    string s;
    cin>>n>>q;
    cin>>s;
    for(i=0 ; i<n ; i++)
        ara[i+1] = s[i]-'a';
    Init(1 , 1 , n);
    for(i=1 ; i<=q ; i++){
        cin>>l>>r>>type;
        ms(fre , 0);
        for(j=0 ; j<26 ; j++){
            fre[j] = Query(j , 1 , 1 , n , l , r);
            Update(j , 1 , 1 , n , l , r , 0);
        }
        int pos = l;
        if(type){
            for(j=0 ; j<26 ; j++){
                if(fre[j]){
                    Update(j , 1 , 1 , n , pos , pos+fre[j]-1 , 1);
                    pos += fre[j];
                }
            }
        }
        else{
            for(j=25 ; j>=0 ; j--){
                if(fre[j]){
                    Update(j , 1 , 1 , n , pos , pos+fre[j]-1 , 1);
                    pos += fre[j];
                }
            }
        }
    }
    for(i=1 ; i<=n ; i++){
        int ans = 26;
        for(j=0 ; j<26 ; j++){
            int temp = Query(j , 1 , 1 , n , i , i);
            if(temp){
                ans = j;
                break;
            }
        }
        char ch = 'a'+ans;
        cout<<ch;
    }
    cout<<endl;
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



