    /**
    Bismillahir Rahmanir Rahim
    MD. Iqbal Hossain Bappy
    Dept. of CSE, CoU
    **/

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
#define intlimit                2147483647;
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

vector<int>stall;

int check(int mid)
{
    int res=1,lo=stall[0],dif,i;
    for(i=1;i<stall.size();i++)
    {
        dif=stall[i]-lo;
        if(dif >= mid)
        {
            lo=stall[i];
            res+=1;
        }
    }
    return res;
}

int Bin(int c)
{
    int lo=0,hi=1000000000,mid,res=0;
    while(lo<=hi)
    {
        mid=lo+(hi-lo)/2;
        if(check(mid) < c)
        {
            hi=mid-1;
        }
        else if(check(mid) >= c)
        {
            res=mid;
            lo=mid+1;
        }
    }
    return res;
}
int main()
{
    int t,T,n,c,i,temp,co;
    scin(T);
    RUN_CASE(t,T)
    {
        stall.clear();
        sc("%d %d",&n,&c);
        for(i=0;i<n;i++)
        {
            scin(temp);
            stall.pb(temp);
        }
        sort(stall.begin(),stall.end());
        co=Bin(c);
        pf("%d\n",co);
    }
    return 0;
}

