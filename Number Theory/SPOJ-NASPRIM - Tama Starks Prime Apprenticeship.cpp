/**
Bismillahir Rahmanir Rahim
MD. Iqbal Hossain Bappy
Dept. of CSE, CoU
**/

#include<bits/stdc++.h>

#define perfect                 int main()
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
#define intlimit                2147483647;
#define longlimit               9223372036854775808
#define infinity                (1<<28)
#define gcd(a,b)                __gcd(a,b)
#define lcm(a,b)                ((a)*(b))/gcd(a,b)
#define mxx                     123456789
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

vector<int>Prime;
int n=10000009;
int mark[10000009];
void sieve(void)
{
    int i,j,limit=sqrt(n*1.0)+2;
    mark[1]=1;
    for(i=4; i<=n; i+=2)
        mark[i]=1;
    Prime.pb(2);
    for(i=3; i<=n; i+=2)
    {
        if(!mark[i])
        {
            Prime.pb(i);
            if(i<=limit)
            {
                for(j=i*i; j<=n; j+=(i*2))
                    mark[j]=1;
            }
        }
    }
}

//int ara[5]={1,3,5,7,9};

int Bin(int lo,int hi,int item)
{
    int res=-1,mid;
    while(lo<=hi)
    {
        mid=(lo+hi)/2;
        if(Prime[mid] == item)
        {
            res=mid;
            break;
        }
        else if(item < Prime[mid])
        {
            res=mid;
            hi=mid-1;
        }
        else
        {
            lo=mid+1;
        }
    }
    return res;
}

perfect
{
    int t,T,i,j,k,l,r,lb,ub,co,last,temp,add;
    sieve();
    scin(T);
    RUN_CASE(t,T)
    {
        last=Prime.size()-1;
        co=0;
        sc("%d %d %d",&l,&r,&k);
        if(l>r)
            swap(l,r);
        for(i=0; i<=last&&Prime[i]<=r; i++)
        {
            temp=Prime[i]+k;
            if(temp > r)
                break;
            if(Prime[i]>=l&&mark[temp] == 0)
                co+=1;
        }

        pf("%d\n",co);
    }
    return 0;
}
