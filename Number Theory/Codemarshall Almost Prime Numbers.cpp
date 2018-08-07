/** Problem link: https://algo.codemarshal.org/problems/556b56d1fc5f0103000a0aed **/

#include<bits/stdc++.h>

#define perfect                 int main()
#define ll                      long long int
#define ull                     unsigned long long int
#define pii                     pair<int,int>
#define pll                     pair<ll,ll>
#define sc                      scanf
#define scin(x)                 sc("%d",&(x))
#define scin2(x,y)                sc("%d %d",&(x),&(y))
#define scln(x)                 sc("%lld",&(x))
#define scln2(x,y)                sc("%lld %lld",&(x),&(y))
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
#define MOD                     100000007
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

vector<int>prime;
bool mark[10000005];
void sieve(int n)
{
    int i,j,limit=sqrt(n*1.0)+2;
    mark[1]=1;
    prime.pb(2);
    for(i=4;i<=n;i+=2)
        mark[i]=1;
    for(i=3;i<=n;i+=2)
    {
        if(!mark[i])
        {
            prime.pb(i);
            if(i<=limit)
            {
                for(j=i*i;j<=n;j+=(2*i))
                mark[j]=1;
            }
        }
    }
}
vector<ll>alp;
int BinL(ll ITEM)
{
    int BEG=0,END=alp.size()-1,MID,res=-1;
    while(BEG<=END)
    {
        MID=(BEG+END)/2;
        if(alp[MID] == ITEM)
        {
            res=MID;
            break;
        }
        else if(ITEM < alp[MID])
        {
            res=MID;
            END=MID-1;
        }
        else
            BEG=MID+1;
    }
    return res;
}
int main()
{
    sieve(10000000);
    int i,j,t,T;
    ll lb,ub,temp,x,y,sz,ans;
    for(i=0;prime[i]<=1000000;i++)
    {
        temp=(ll)prime[i]*prime[i];
        while(temp <= 1000000000000)
        {
            alp.pb(temp);
            temp*=(ll)prime[i];
        }
    }
    sort(alp.begin(),alp.end());
    scin(T);
    sz=alp.size();
    RUN_CASE(t,T)
    {
        scln2(lb,ub);
        x=BinL(lb);
        if(ub>alp[sz-1])
            y=sz-1;
        else
        {
            y=BinL(ub);
            if(alp[y] > ub)
            {
                y-=1;
            }
        }
        ans=y-x+1;
//        cout<<x<<" "<<y<<endl;
        pf("%lld\n",ans);
    }
    return 0;
}

