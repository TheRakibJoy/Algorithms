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
int fact[10000];
void factorial(int n)
{
    int i,j,k=1;
    fact[0]=1;
    for(i=2;i<=n;i++)
    {
        int carry=0,mul;
        for(j=0;j<k;j++)
        {
            mul=(fact[j]*i)+carry;
            fact[j]=mul%10;
            carry=mul/10;
        }
        while(carry)
        {
            fact[k]=carry%10;
            carry/=10;
            k++;
        }
    }
    for(i=k-1;i>=0;i--)
        cout<<fact[i];
    cout<<"\n";
}
int main()
{
    int n;
    while(sc("%d",&n) != EOF)
    {
        ms(fact,0);
        if(n<0 && (n%2==0))
            pf("Underflow!\n");
        else if(n<0 && (n%2!=0))
            pf("Overflow!\n");
        else if(n<8)
            pf("Underflow!\n");
        else if(n>13)
            pf("Overflow!\n");
        else
            factorial(n);
    }
    return 0;
}
