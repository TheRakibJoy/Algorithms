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
//#define mx                      123456789
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
int mark[10000009];
void sieve(int n)
{
    int i,j,limit=sqrt(n*1.0)+2;
    mark[1]=1;
    for(i=4;i<=n;i+=2)
        mark[i]=1;
    Prime.push_back(2);
    for(i=3;i<=n;i+=2)
    {
        if(!mark[i])
        {
            Prime.push_back(i);
            if(i<=limit)
            {
                for(j=i*i;j<=n;j+=(i*2))
                    mark[j]=1;
            }
        }
    }
}
vector<int>List;
int Primefactorize(int n)
{
    int div=1,temp;
    int sqrtN=int(sqrt(n));
    for(int i=0;i<=sqrtN;i++)
    {
        temp=1;
        if(n%Prime[i] == 0)
        {
            while(n%Prime[i] == 0)
            {
                List.push_back(Prime[i]);
                n/=Prime[i];
                temp++;
            }
        }
        div*=temp;
    }
    if(n>1)
    {
        List.push_back(n);
        div*=2;
    }
    return div;
}
int main()
{
    sieve(10000000);
    int i,j,k,n,lb,ub,temp,mx,value;
    scin(n);
    for(i=1;i<=n;i++)
    {
        mx=0;
        sc("%d %d",&lb,&ub);
        for(j=lb;j<=ub;j++)
        {
            List.clear();
            temp=Primefactorize(j);
            if(temp>mx)
            {
                mx=temp;
                value=j;
            }
        }
        pf("Between %d and %d, %d has a maximum of %d divisors.\n",lb,ub,value,mx);
    }
    return 0;
}
