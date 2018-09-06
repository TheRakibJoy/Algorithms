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
/** toint, tostring, BigMod, sieve, Primefactorize **/
//ll toint(string s){ll n=0,k=1;for(int i=s.size()-1;i>=0;i--){n += ((s[i]-'0')*k);k*=10;}return n;}
//string tostring(ll n){string s="";ll x;while(n > 0){x=n%10;s +=(char)(x+'0');n/=10;}reverse(s.begin(),s.end());return s;}
//ll BigMod(ll a,ll b,ll m){if(b == 0)return 1%m;else if(b%2 == 0){ll temp=BigMod(a,b/2,m);return ((temp%m)*(temp%m))%m;}else{return ((a%m)*BigMod(a,b-1,m)%m)%m;}}
//vector<int>Prime;int mark[10000009];
//void sieve(int n){int i,j,limit=sqrt(n*1.0)+2;mark[1]=1;for(i=4; i<=n; i+=2)mark[i]=1;Prime.push_back(2);for(i=3; i<=n; i+=2){if(!mark[i]){Prime.push_back(i);if(i<=limit){for(j=i*i; j<=n; j+=(i*2))mark[j]=1;}}}}
//vector<int>List;
//void Primefactorize(int n){int sqrtN=int(sqrt(n));for(int i=0; Prime[i]<=sqrtN; i++){if(n%Prime[i] == 0){while(n%Prime[i] == 0){List.push_back(Prime[i]);n/=Prime[i];}}}if(n>1)List.push_back(n);}

///------------------Graph Moves-------------------
/// const int fx[] = {+1,-1,+0,+0};
/// const int fy[] = {+0,+0,+1,-1};
/// const int fx[] = {+0,+0,+1,-1,-1,+1,-1,+1}; ///King's move
/// const int fy[] = {-1,+1,+0,+0,+1,+1,-1,-1}; ///King's move
/// const int fx[] = {-2,-2,-1,-1,+1,+1,+2,+2}; ///Knight's move
/// const int fy[] = {-1,+1,-2,+2,-2,+2,-1,+1}; ///Knight's move

struct node
{
    int x;
    node(int a)
    {
        x=a;
    }
};
bool operator < (node A,node B)
{
    return A.x>B.x;
}

vector<int>graph[10005];
int in[10005];
vector<int>res;

void topBFS(int n)
{
    priority_queue<node>q;
    for(int i=0;i<n;i++)
    {
        if(in[i] == 0)
            q.push(node(i));
    }
    while(!q.empty())
    {
        int u=q.top().x;
        res.pb(u);
        q.pop();
        for(int i=0;i<graph[u].size();i++)
        {
            in[graph[u][i]]--;
            if(in[graph[u][i]] == 0)
                q.push(node(graph[u][i]));
        }
    }
}
int main()
{
    int i,j,k,n,u,v,sz1,sz2;
    char ch1,ch2;
    bool fg1=true;
    bool fg2=true;
    scin(n);
    string s[n];
    for(i=0; i<n; i++)
        cin>>s[i];
    for(i=0; i<n-1; i++)
    {
        sz1=s[i].size();
        sz2=s[i+1].size();
        for(j=0; j<min(sz1,sz2); j++)
        {
            if(s[i][j] != s[i+1][j])
            {
                u=s[i][j]-'a';
                v=s[i+1][j]-'a';
                graph[u].pb(v);
                in[v]++;
                fg2=true;
                break;
            }
            else
            {
                fg2=false;
            }
        }
        if(sz1>sz2 && fg2==false)
        {
            fg1=false;
        }
    }
    topBFS(26);
    for(i=0; i<26; i++)
    {
        if(in[i] != 0)
            fg1=false;
    }
    if(fg1)
    {
        for(i=0; i<res.size(); i++)
        {
            ch1=res[i]+'a';
            pf("%c",ch1);
        }
        pf("\n");
    }
    else
        pf("Impossible\n");
    return 0;
}
