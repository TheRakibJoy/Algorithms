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

vector<int>prime;
int N=200;
int mark[1000];
void sieve()
{
    int i,j,sqrtN=(N*1.0)+2;
    mark[1]=1;
    prime.push_back(2);
    for(i=4;i<=N;i+=2)
    {
        mark[i]=1;
    }
    for(i=3;i<=N;i+=2)
    {
        if(mark[i] == 0)
        {
            prime.push_back(i);
            if(i<=sqrtN)
            {
                for(j=i*i;j<=N;j+=(2*i))
                    mark[j]=1;
            }
        }
    }
}
vector<int>List;
int fact[100];
void primefactorize(int n)
{
    int i,j,sqrtN=int(sqrt(n));
    for(i=0;prime[i]<=sqrtN;i++)
    {
        if(n%prime[i] == 0)
        {
            while(n%prime[i] == 0)
            {
                List.push_back(prime[i]);
                n/=prime[i];
                fact[prime[i]]++;
            }
        }
    }
    if(n>1)
    {
        List.push_back(n);
        fact[n]++;
    }
}

int main()
{
    int i,j,n;
    sieve();
//    for(i=0;i<prime.size();i++)
//        cout<<prime[i]<<" ";
    while(1)
    {
        scin(n);
        if(n == 0)
            break;
        else
        {
            j=0;
            ms(fact,0);
            List.clear();
//            cout<<prime[15]<<endl;
            for(i=2;i<=n;i++)
            {
                primefactorize(i);
            }
//            for(i=0;i<List.size();i++)
//                cout<<List[i]<<" ";
//            cout<<endl;
            pf("%3d! =",n);
            for(i=2;i<=n;i++)
            {
                if(mark[i]==0)
                {
                    if(j==0 || j%15!=0)
                    {
                        pf("%3d",fact[i]);
                        j++;
                    }
                    else
                    {
                        pf("\n");
                        pf("%9d",fact[i]);
                        j++;
                    }
                }
            }
            pf("\n");
        }
    }
    return 0;
}

