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

const int N = 1e5+9;
int tot_node = 1;
int to[N][62] , endmark[N];

void Add(char *s)
{
    int sz = strlen(s) , curr = 1;   ///curr - Root node
    if(sz > 2)
        sort(s+1 , s+sz-1);
    for(int i=0 ; i<sz ; i++){
        int ch = s[i]-'A';
        if(!to[curr][ch])    to[curr][ch] = ++tot_node;
        curr = to[curr][ch];
    }
    endmark[curr]++;
}

int Search(string &s)
{
    int sz = s.size() , curr = 1;
    if(sz > 2)
        sort(s.begin()+1 , s.begin()+sz-1);
    for(int i=0 ; i<sz ; i++){
        int ch = s[i]-'A';
        if(!to[curr][ch])   return 0;
        curr = to[curr][ch];
    }
    return endmark[curr];
}

void Clean(int n)
{
    for(int i=0 ; i<=n ; i++){
        endmark[i] = 0;
        for(int j=0 ; j<=60 ; j++)
            to[i][j] = 0;
    }
}

void Solve(int t)
{
    int i,j,k,n,ans=1,q,sz;
    string s1,s2;
    char str[100005];
    tot_node = 1;
    scin(n);
    for(i=1 ; i<=n ; i++){
        sc("%s",str);
        Add(str);
    }
    scin(q);
    pf("Case %d:\n",t);
    getchar();
    for(i=1 ; i<=q ; i++){
        ans = 1;
        stringstream ss;
        getline(cin , s1);
        ss<<s1;
        while(ss>>s2){
            int ret = Search(s2);
//            cout<<s2<<' '<<ret<<endl;
            ans *= ret;
        }
        cout<<ans<<endl;
    }
    Clean(1e5+2);
}

int main()
{
    int t,T;
    scin(T);
    RUN_CASE(t,T)
    {
        Solve(t);
    }
    return 0;
}
/**
1
8
baggers
beggars
in
the
blowed
bowled
barn
bran
1
beggars bowled in the barn
**/
