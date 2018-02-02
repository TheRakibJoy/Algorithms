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
struct info
{
    int prop=0,sum=0;
};
info tree[Size*3];
void init(int node,int b,int e)
{
    if(b == e)
    {
        tree[node].sum=arr[b];
        return;
    }
    int left=node*2;
    int right=left+1;
    int mid=(b+e)/2;
    init(left,b,mid);
    init(right,mid+1,e);
    tree[node].sum=tree[left].sum+tree[right].sum;
}
void update(int node,int b,int e,int x,int y,int value)
{
    if(b>y || e<x)
        return;
    if(b>=x && e<=y)
    {
        tree[node].sum+=((e-b+1)*value);
        tree[node].prop+=value;
        return;
    }
    int left=node*2;
    int right=left+1;
    int mid=(b+e)/2;
    update(left,b,mid,x,y,value);
    update(right,mid+1,e,x,y,value);
    tree[node].sum=tree[left].sum+tree[right].sum+(e-b+1)*tree[node].prop;
}
int query(int node,int b,int e,int x,int y,int carry=0)
{
    if(b>y || e<x)
        return 0;
    if(b>=x && e<=y)
        return tree[node].sum+carry*(e-b+1);
    int left=node*2;
    int right=left+1;
    int mid=(b+e)/2;
    int p1=query(left,b,mid,x,y,carry+tree[node].prop);
    int p2=query(right,mid+1,e,x,y,carry+tree[node].prop);
    return p1+p2;
}

int main()
{
    int T,i,j,k,q,x,y,n,co,cnt;
    char ch;
    scin(T);
    for(i=1;i<=T;i++)
    {
        char s1[100005];
        ms(arr,0);
        ms(tree,0);
        getchar();
        sc("%s",s1);
        n=strlen(s1);
        for(j=0;j<n;j++)
        {
            arr[j+1]=s1[j]-'0';
        }
        init(1,1,n);
        scin(q);
        printf("Case %d:\n",i);
        for(j=0;j<q;j++)
        {
            char cmd;
            getchar();
            sc("%c",&cmd);
            scin(x);
            if(cmd == 'I')
            {
                scin(y);
                update(1,1,n,x,y,1);
            }
            else if(cmd == 'Q')
            {
                cnt=query(1,1,n,x,x)-arr[x];
                if((arr[x]==0 && (cnt%2 == 1)) || (arr[x]==1 && (cnt%2 == 0)))
                    co=1;
                else
                    co=0;
                pf("%d\n",co);
            }
        }
    }
    return 0;
}

