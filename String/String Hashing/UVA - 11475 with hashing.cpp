///****In the name of ALLAH, most Gracious, most Compassionate****//
#include<bits/stdc++.h>

#define Input                   freopen("in.txt","r",stdin)
#define Output                  freopen("out.txt","w",stdout)
#define ll                      long long int
#define ull                     unsigned long long int
#define pii                     pair<int,int>
#define pll                     pair<ll,ll>
#define sc                      scanf
#define scin(x)                 sc("%d",&(x))
#define scin2(x,y)              sc("%d %d",&(x),&(y))
#define scln(x)                 sc("%lld",&(x))
#define scln2(x,y)              sc("%lld %lld",&(x),&(y))
#define pf                      printf
#define all(a)                  (a.begin()),(a.end())
#define UNIQUE(X)               (X).erase(unique(all(X)),(X).end())
#define SORT_UNIQUE(c)          (sort(c.begin(),c.end()), c.resize(distance(c.begin(),unique(c.begin(),c.end()))))
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
#define intlimit                2147483690
#define longlimit               9223372036854775800
#define infinity                (1<<28)
#define gcd(a,b)                __gcd(a,b)
#define lcm(a,b)                (a)*(b)/gcd(a,b)
#define mxx                     123456789
#define PI                      2*acos(0.0)
#define rep(i,a,b)              for(__typeof(i) i=a;i<=b;i++)
#define rev(i,a,b)              for(__typeof(i) i=a;i>=b;i--)
#define coutv(v)                for(auto it:v)cout<<it<<' ';cout<<endl;
#define cinv(v)                 for(auto &it:v)cin>>it;
#define srt(v)                  sort(v.begin(),v.end());
#define rsrt(v)                 sort(v.rbegin(),v.rend());
#define rvs(v)                  reverse(v.begin(),v.end());

using namespace std;


const int sz = 1e5+9 , mod = 1e9+7 , p = 109;
char s[sz];
ll len,p_pow[sz],hashSum[sz],revHashSum[sz];

void Power()
{
    p_pow[0] = 1;
    for(int i=1 ; i<sz ; i++)
        p_pow[i] = (p_pow[i-1] * p)%mod;
}

void computeHash()
{
    len = strlen(s);
    hashSum[0] = revHashSum[len+1] = 0LL;

    for(int i=0 ; i<len ; i++){
        hashSum[i+1] = (hashSum[i] + ((s[i]-'A'+1) * p_pow[i+1])%mod)%mod;
    }

    for(int i=len-1,j=0 ; i>=0 ; i--,j++){
        revHashSum[i+1] = (revHashSum[i+2] + ((s[i]-'A'+1) * p_pow[j+1])%mod)%mod;
    }
}

bool isPalindrome(int &lb1,int &ub1,int &lb2,int &ub2)
{
    ll val1 = (hashSum[ub1] - hashSum[lb1-1] + mod)%mod;
    ll val2 = (revHashSum[lb2] - revHashSum[ub2+1] + mod)%mod;
    ll basepow1 = lb1 , basepow2 = len-ub2+1;
    if(basepow1 >= basepow2)
        val2 = (val2 * p_pow[basepow1 - basepow2])%mod;
    else
        val1 = (val1 * p_pow[basepow2 - basepow1])%mod;
    return (val1 == val2);
}

void Solve()
{
    int mx = 0 , fg = 1;

    computeHash();
    for(int i = (len+1)/2 ; i<=len && fg ; i++){
        ///Compute odd length palindrome which is also a suffix of given string
        int half = len - i + 1;
        int lb1 = i - half + 1;
        int ub1 = i;
        int lb2 = i;
        int ub2 = len;
        if(isPalindrome(lb1 , ub1 , lb2 , ub2)){
            mx = max(mx , (2*half)-1);
            fg = 0;
        }

        ///Compute even length palindrome which is also a suffix of given string
        half = len-i;
        lb1 = i - half + 1;
        ub1 = i;
        lb2 = i+1;
        ub2 = len;
        if(isPalindrome(lb1 , ub1 , lb2 , ub2)){
            mx = max(mx , 2*half);
            fg = 0;
        }
    }

    pf("%s",s);
    for(int i=len-mx-1 ; i>=0 ; i--)
        pf("%c",s[i]);
    pf("\n");
}

int main()
{
    Power();

    while(scanf("%s",s) != EOF){
        Solve();
    }

    return 0;
}

