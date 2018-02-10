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

int main()
{
    unsigned long long int res,res1,temp1,temp2;
    int T,i,j,k,n,op,m;
    scin(T);
    for(i=1; i<=T; i++)
    {
        string s;
        cin>>s;
        int arr[91];
        vector<int>v1,v2;
        ms(arr,0);
        n=s.length();
        for(j=0; j<n ; j++)
        {
            arr[s[j]]++;
            v1.push_back(j+1);
        }
        temp2=1;
        temp1=1;
        for(j=65;j<=90;j++)
        {
            for(k=0;k<min(arr[j],n);k++)
            {
                op=gcd(v1[k],(k+1));
                if(v1[k]>=op && v1[k]%op==0)
                {
                    v1[k]=v1[k]/op;
                    temp2=temp2*((k+1)/op);
                }
                else
                    temp2*=(k+1);
            }
        }
        for(j=0;j<v1.size();j++)
            temp1=temp1*v1[j];
        res=temp1/temp2;
        cout<<"Data set "<<i<<": "<<res<<endl;
    }
    return 0;
}
