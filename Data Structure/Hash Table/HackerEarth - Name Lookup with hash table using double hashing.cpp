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

const int p1 = 31;
const int p2 = 37;
const int mod1 = 100003;
const int mod2 = 100019;

int hashFuN1(int n)
{
    int hashsum=0,digit,primepow=p1;
    while(n > 0){
        digit = n%10;
        hashsum = (hashsum + ((digit+1) * primepow)%mod1)%mod1;
        primepow = (primepow * p1)%mod1;
        n /= 10;
    }
    return hashsum;
}

int hashFuN2(int n)
{
    int hashsum=0 , digit , primepow=p2;
    while(n > 0){
        digit = n%10;
        hashsum = (hashsum + ((digit+1) * primepow)%mod2)%mod2;
        primepow = (primepow * p2)%mod2;
        n /= 10;
    }
    return hashsum;
}

#define sz 200005
pair<int , string>hashtable[sz];

void Insert(string &s,int n)
{
    int index = hashFuN1(n);
    int indexH = hashFuN2(n);
    while(hashtable[index].first != n && hashtable[index].second != ""){
        index = (index + indexH)%sz;
    }
    hashtable[index] = make_pair(n , s);
}

string Search(int n)
{
    int index = hashFuN1(n);
    int indexH = hashFuN2(n);
    while(hashtable[index].first != n && hashtable[index].first != 0)
        index = (index + indexH)%sz;
    return hashtable[index].second;
}

void Solve(int t)
{
    int i,j,k,n,q,idx;
    string s;
    cin>>n;
    for(i=1 ; i<=n ; i++){
        cin>>idx>>s;
        Insert(s , idx);
    }
    cin>>q;
    for(i=1 ; i<=q ; i++){
        cin>>idx;
        s = Search(idx);
        cout<<s<<endl;
    }
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



