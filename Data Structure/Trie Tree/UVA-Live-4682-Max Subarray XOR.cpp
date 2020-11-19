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

int Set(int N, int pos) {return  N = N | (1<<pos);}
int Reset(int N, int pos) {return  N = N & ~(1<<pos);}
bool Cheek(int N, int pos) {return  (bool)(N & (1<<pos));}

#define sz 1000009
int tot_node=1,ara[sz],to[sz][2],endmark[sz],cumxor[sz];

void Clean()
{
    tot_node = 1;
    ms(to , 0);
    ms(endmark , 0);
}

void Add(int num)
{
    int curr = 1;
    for(int i=31 ; i>=0 ; i--){
        int bit = Cheek(num , i);

        if(!to[curr][bit])
            to[curr][bit] = ++tot_node;
        curr = to[curr][bit];
    }
    endmark[curr] = 1;
}

int findBest(int num)
{
    int curr = 1 , ans = 0;
    for(int i=31 ; i>=0 ; i--){
        int bit = Cheek(num , i);

        if(to[curr][bit^1])
            curr = to[curr][bit^1] , ans = Set(ans , i);
        else if(to[curr][bit])
            curr = to[curr][bit];
        else
            break;
    }
    return ans;
}

void Solve(int t)
{
    int i,j,k,n,ans=0;
    scin(n);

    Add(0);
    for(i=1 ; i<=n ; i++){
        scin(ara[i]);
        cumxor[i] = (cumxor[i-1] ^ ara[i]);

        ans = max(ans , findBest(cumxor[i]));   ///Find max value for sub-array 1...i

        Add(cumxor[i]);
    }
    pf("%d\n",ans);
    Clean();
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

/** Stuff u should look for
    * Avoid overflow
    * Corner(Small) case
    * Don't get stuck on one approach
    * Don't forget to clean used memory in each case
**/
