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

/** Link: https://codeforces.com/gym/101550/attachments **/
/** TRIE + Hashing + BS **/
/** Problem statement: https://vj.z180.cn/4703efd24c7dd00c82e6081ff904cc0d?v=1591990470
    Link for submit: https://vjudge.net/contest/378643#problem/J ; Password: hash_it **/

const int p = 37;
const int m = 1e9+7;
ll p_pow[1000005];
void Power()
{
    p_pow[0] = 1;
    for(int i=1 ; i<=1000000 ; i++)
        p_pow[i] = (p_pow[i-1] * p)%m;
}

ll sthash[1000005],qryhash[1000005];
vector<int>hash_sum[100005];
int mxmatch,tot_node=1,to[1000005][26],firstvis[1000005],ssz[100005]; /// firstvis[i] - id of the string that visited this node at first

void addString(string &s , int id)
{
    int sz = (int)s.size() , curr = 1;
    hash_sum[id].pb(0);
    ssz[id] = sz;
    for(int i=0 ; i<sz ; i++){
        ///TRIE Part
        int ch = s[i]-'a';
        if(!to[curr][ch])   to[curr][ch] = ++tot_node;
        curr = to[curr][ch];
        if(!firstvis[curr]) firstvis[curr] = id;

        ///Hash Part
        sthash[i+1] = (sthash[i] + (s[i]-'a'+1)*p_pow[i])%m;
        hash_sum[id].pb(sthash[i+1]);
    }
}

int matchBS(int id,int typed,int sz,int baki,int mnnow)
{
    int lo,hi,mid,match=0,unmatch=0,sz1 = ssz[id] , sz2 = sz , mnneed;  ///sz1 - source string size ; sz2 - target string size
    lo = 1; hi = min(sz1 , sz2);
    while(lo <= hi){
        mid = (lo+hi)/2;
        if(hash_sum[id][mid] == qryhash[mid]){
            match = mid;
            lo = mid+1;
        }
        else
            hi = mid-1;
    }
    int backspace = sz1-match;  ///Those character added unnecessarily
    int enter = sz2-match;      ///Those character that have to typed
    int tab = 1;
    mnneed = tab + backspace + enter + typed;
    if(match>mxmatch){  ///IF present match > previous maximum match
        int temp = mnneed - ((mnneed-2-backspace-enter) - (mnnow-baki));
        if(temp >= 2)
            mnneed = min(mnneed , temp);
    }
    mxmatch = max(mxmatch , match);
    return mnneed;
}

int Search(string &s)
{
    int sz = (int)s.size() , curr = 1, mnkey , typed=0;
    mxmatch = 0;
    mnkey = sz;
    ///Hash Part
    for(int i=0 ; i<sz ; i++)
        qryhash[i+1] = (qryhash[i] + (s[i]-'a'+1)*p_pow[i])%m;

    ///TRIE Part
    for(int i=0 ; i<sz ; i++){
        int ch = s[i]-'a';
        if(!to[curr][ch])
            break;
        curr = to[curr][ch];
        int baki = sz - i;
        int bs = matchBS(firstvis[curr] , i+1 , sz , baki , mnkey);
        mnkey = min(mnkey , bs);
    }
    return mnkey;
}

void Solve(int t)
{
    int i,j,k,n,q,ans;
    cin>>n>>q;
    string s;
    for(i=1 ; i<=n ; i++){
        cin>>s;
        addString(s , i);
    }
    for(i=1 ; i<=q ; i++){
        cin>>s;
        cout<<Search(s)<<endl;
    }
}

int main()
{
    CIN;
    Power();
    int t,T;
    T = 1;
    RUN_CASE(t,T)
    {
        Solve(t);
    }
    return 0;
}
/**
5 5
austria
autocorrect
program
programming
computer
autocorrelation
programming
competition
zyx
austria

5 1
pr
program
programming
programmingproblem
programmingproblembengali
programmingproblembengali
ANS:10

2 1
program
programmingproblembengali
programmingproblembengali
ANS:4
**/

