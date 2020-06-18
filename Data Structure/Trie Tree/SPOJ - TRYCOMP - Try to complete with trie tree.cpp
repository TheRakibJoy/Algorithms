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

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template<typename T> using orderset = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;


const int N = 5e6+9;
int tot_node = 1;
int to[N][26];
orderset<pii>vis[N];    /// -Frequency,id
map<string , int>inp;
map<string , int>:: iterator it;
string str[500005];

void Add(string &s,int &id,int &fre)
{
    int sz = (int)s.size() , curr = 1;
    for(int i=0 ; i<sz ; i++){
        int ch = s[i]-'a';
        if(!to[curr][ch])   to[curr][ch] = ++tot_node;
        curr = to[curr][ch];
        vis[curr].insert(make_pair(-fre , id));
    }
}

pii Search(string &s)
{
    int sz = (int)s.size() , curr=1 , mxfre=0 , id=0;
    for(int i=0 ; i<sz ; i++){
        int ch = s[i]-'a';
        if(!to[curr][ch]) return make_pair(-1 , -1);
        curr = to[curr][ch];
    }
    pii ret = *vis[curr].find_by_order(0);
    return make_pair(-ret.first , ret.second);
}

void Solve(int t)
{
    int i,j,k,n,q,id=0;
    string s;
    cin>>n;
    for(i=1 ; i<=n ; i++){
        cin>>s;
        inp[s]++;
    }
    for(it=inp.begin() ; it!=inp.end() ; it++){
        str[++id] = it->first;
        Add(str[id] , id , it->second);
//        cout<<it->first<<' '<<id<<endl;
    }
    cin>>q;
    for(i=1 ; i<=q ; i++){
        cin>>s;
        pii ret = Search(s);
        if(ret.first==-1 && ret.second==-1)
            cout<<ret.first<<endl;
        else
            cout<<str[ret.second]<<' '<<ret.first<<endl;
    }
}

int main()
{
    CIN;
    int t,T;
    T = 1;
//    scin(T);
    RUN_CASE(t,T)
    {
        Solve(t);
    }
    return 0;
}
/**
10
apple
banana
orange
applet
banana
oriental
orange
oriental
applet
bangalore
8
ban
bang
app
or
oriental
apple
hobbits
oranges
**/

