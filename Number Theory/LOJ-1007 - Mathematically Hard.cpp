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
int phi[5000009];
ull mark[5000009];
void sievephi(int n)
{
    int i,j;
    for(i=1;i<=n;i++)
        phi[i]=i;
    phi[1]=1;
    mark[1]=1;
    for(i=2;i<=n;i++)
    {
        if(mark[i]==0)
        {
            for(j=i;j<=n;j+=i)
            {
                mark[j]=1;
                phi[j]=phi[j]/i*(i-1);
            }
        }
    }
}
int main()
{
    int i,j,T,lb,ub;
    ull co;
    sievephi(5000009);
    mark[1]=1;
    for(i=2;i<=5000009;i++)
    {
        mark[i]=mark[i-1]+((ull)phi[i]*phi[i]);
    }
//    cout<<phi[5000009]<<endl;
    scin(T);
    for(i=1;i<=T;i++)
    {
        sc("%d %d",&lb,&ub);
        co=mark[ub]-mark[lb-1];
//        cout<<"Case "<<i<<": "<<co<<endl;
        pf("Case %d: %llu\n",i,co);
    }
    return 0;
}
