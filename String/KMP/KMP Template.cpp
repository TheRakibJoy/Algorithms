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

using namespace std;

/** KMP Algorithm Template **/
/** Applications:
APP-01: Given a text t & a string s. We want to find & display the positions of
all occurrences of the string s in text t.
Sol: Generate the string s+'#'+t & build pi array for the string. IF at some positions
i we have pi[i] = |s| then at positions i-2*|s| in the string t the string s appears.

APP-02: Count the number of occurrences of each prefix.
Sol:    See function FrequencyOfEachPrefix.
**/


vi prefix_FuN(string &s)
{
    int n = (int)s.size();
    vi pi(n);    ///Here, pi[i] means max length of prefix that is equal to a proper suffix ends at position i-1
    pi[0] = 0;
    for(int i=1 ; i<n ; i++){
        int j = pi[i-1];
        while(j>0 && s[i]!=s[j])
            j = pi[j-1];
        if(s[i] == s[j])
            ++j;
        pi[i] = j;
    }
    return pi;
}

vi FrequencyOfEachPrefix(string &s)
{
    int n = (int)s.size();
    vi pi(n),ans(n+1);
    pi = prefix_FuN(s);
    for(int i=0 ; i<n ; i++)
        ans[pi[i]]++;
    for(int i=n-1 ; i>0 ; i--)
        ans[pi[i-1]] += ans[i];
    for(int i=0 ; i<=n ; i++)
        ans[i]++;
    return ans;
}

void Solve(int t)
{
    string s;
    cin>>s;
    vi pi = prefix_FuN(s);
    for(int i=0 ; i<(int)pi.size() ; i++)
        cout<<pi[i]<<' ';
    cout<<endl;
}

int main()
{
    int t,T;
    T = 1;
//    scin(T);
    RUN_CASE(t,T)
    {
        Solve(t);
    }
    return 0;
}



