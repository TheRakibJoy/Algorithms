#include<bits/stdc++.h>

#define ll                      long long int
#define ull                     unsigned long long int
#define pii                     pair<int,int>
#define pll                     pair<ll,ll>
#define sc                      scanf
#define scin(x)                 sc("%d",&(x))
#define scln(x)                 sc("%lld",&(x))
#define pf                      printf
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
#define intlimit                2147483648
#define longlimit               9223372036854775808
#define infinity                (1<<28)
#define gcd(a,b)                __gcd(a,b)
#define lcm(a,b)                ((a)*(b))/gcd(a,b)
#define mx                      123456789
#define PI                      2*acos(0.0)
#define rep(i,a,b)              for(__typeof(i) i=a;i<=b;i++)
#define rev(i,a,b)              for(__typeof(i) i=a;i>=b;i--)

using namespace std;

///------------------Graph Moves-------------------
/// const int fx[] = {+1,-1,+0,+0};
/// const int fy[] = {+0,+0,+1,-1};
/// const int fx[] = {+0,+0,+1,-1,-1,+1,-1,+1}; ///King's move
/// const int fy[] = {-1,+1,+0,+0,+1,+1,-1,-1}; ///King's move
/// const int fx[] = {-2,-2,-1,-1,+1,+1,+2,+2}; ///Knight's move
/// const int fy[] = {-1,+1,-2,+2,-2,+2,-1,+1}; ///Knight's move
#define Size 100005
int arr[Size];
int tree[Size*3];
void init(int node,int b,int e)
{
    if(b == e)
    {
        tree[node]=arr[b];
        return;
    }
    int left=node*2;
    int right=left+1;
    int mid=(b+e)/2;
    init(left,b,mid);
    init(right,mid+1,e);
    tree[node]=min(tree[left],tree[right]);
}
int query(int node,int b,int e,int lft,int rgt)
{
    if(b>rgt || e<lft)
        return intlimit-1;
    if(b>=lft && e<=rgt)
        return tree[node];
    int left=node*2;
    int right=left+1;
    int mid=(b+e)/2;
    int q1=query(left,b,mid,lft,rgt);
    int q2=query(right,mid+1,e,lft,rgt);
    return min(q1,q2);
}
int main()
{
    int T,n,q,b,e,co,i,j;
    scin(T);
    for(i=1;i<=T;i++)
    {
        sc("%d %d",&n,&q);
        ms(arr,0);
        ms(tree,0);
        for(j=1;j<=n;j++)
        {
            scin(arr[j]);
        }
        printf("Case %d:\n",i);
        init(1,1,n);
        for(j=1;j<=q;j++)
        {
            scanf("%d %d",&b,&e);
            co=query(1,1,n,b,e);
            printf("%d\n",co);
        }
    }
    return 0;
}
