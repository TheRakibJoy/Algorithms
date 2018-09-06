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

vector<int>graph[20005];
vector<int>rgraph[20005];
bool vis[20005];
int comp[20005];
stack<int>stk;
int in[20005],out[20005];

void DFS1(int s)
{
    vis[s]=1;
    for(int i=0;i<graph[s].size();i++)
    {
        int u=graph[s][i];
        if(!vis[u])
            DFS1(u);
    }
    stk.push(s);
    return;
}
void DFS2(int s,int x)
{
    vis[s]=x;
    comp[s]=x;
    for(int i=0;i<rgraph[s].size();i++)
    {
        int u=rgraph[s][i];
        if(!vis[u])
            DFS2(u,x);
    }
    return;
}

int main()
{
    int i,j,k,t,T,n,m,u,v,x,y;
    scin(T);
    RUN_CASE(t,T)
    {
        x=0;y=0;
        scin2(n,m);
        for(i=1;i<=m;i++)
        {
            scin2(u,v);
            graph[u].pb(v);
            rgraph[v].pb(u);
        }
        for(i=1;i<=n;i++)
        {
            if(!vis[i])
                DFS1(i);
        }
        ms(vis,0);
        k=0;
        while(!stk.empty())
        {
            int top=stk.top();
            stk.pop();
            if(!vis[top])
                DFS2(top,++k);
        }
        for(i=1;i<=n;i++)
        {
            for(j=0;j<graph[i].size();j++)
            {
                u=graph[i][j];
                if(comp[i] != comp[u])
                {
                    in[comp[u]]++;
                    out[comp[i]]++;
                }
            }
        }
        for(i=1;i<=k;i++)
        {
            if(!in[i])
                x++;
            if(!out[i])
                y++;
        }
        if(k == 1)
            pf("Case %d: 0\n",t);
        else
            pf("Case %d: %d\n",t,max(x,y));

        for(i=0;i<=n;i++)
        {
            vis[i]=0;in[i]=0;out[i]=0;comp[i]=0;
            graph[i].clear();rgraph[i].clear();
        }
    }
    return 0;
}
