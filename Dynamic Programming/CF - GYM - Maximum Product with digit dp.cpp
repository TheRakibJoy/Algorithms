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
#define longlimit               92233720368547758
#define infinity                (1<<28)
#define gcd(a,b)                __gcd(a,b)
#define lcm(a,b)                (a)*(b)/gcd(a,b)
#define mxx                     123456789
#define PI                      2*acos(0.0)
#define rep(i,a,b)              for(__typeof(i) i=a;i<=b;i++)
#define rev(i,a,b)              for(__typeof(i) i=a;i>=b;i--)

using namespace std;

/** Link of this problem: https://codeforces.com/gym/100886/problem/G **/

/**
State-1: is starting position?
State-2: is Bigger than LB?
State-3: is Smaller than UB?
State-4: Position
State-5: Number of skipped positions in starting
**/

pll dp[2][2][2][20][20];    ///First-Maximum Digit Product ; Second-Number for maximum digit product
vi num1,num2;
int dif,mxsz;
vl tenpow;

pll FuN(bool isStart,bool isBig,bool isSmall,int pos,int skipped)
{
    if(pos >= (int)num2.size())
        return make_pair(1LL , 0LL);
    if(dp[isStart][isBig][isSmall][pos][skipped] != make_pair(-1LL , -1LL))
        return dp[isStart][isBig][isSmall][pos][skipped];
    ll ret=0 , cnt=0 , mntake , mxtake , value = 0;

    mntake = (!isStart && isBig == 1)? 0 : num1[pos-skipped];
    mxtake = (isSmall == 1)? 9 : num2[pos];

    if(skipped<dif && isStart)
        mntake = 1;

    for(ll i=mntake ; i<=mxtake ; i++){
        pll nxt = FuN(0 , isBig|(i>num1[pos-skipped])|(skipped<dif && isStart) , isSmall|(i<num2[pos]) , pos+1 , skipped);
        cnt = i * nxt.first;
        if(cnt >= ret){
            ret = cnt;
            int id = mxsz-pos-1; ///Total digit situated in right side of this digit
            value = (i * tenpow[id]) + nxt.second;
        }
    }
    if(isStart && skipped < dif){
        pll nxt = FuN(isStart , isBig , 1 , pos+1 , skipped+1);
        if(nxt.first >= ret){
            ret = nxt.first;
            value = nxt.second;
        }
    }
    return dp[isStart][isBig][isSmall][pos][skipped] = make_pair(ret , value);
}

void Solve(int t)
{
    ll i,j,k,n,temp = 1 , a , b;
    for(i=0 ; i<=18 ; i++){
        tenpow.pb(temp);
        temp *= 10;
    }
    scln2(a , b);
    while(a > 0){
        num1.pb(a%10);
        a /= 10;
    }
    while(b > 0){
        num2.pb(b%10);
        b /= 10;
    }
    reverse(num1.begin() , num1.end());
    reverse(num2.begin() , num2.end());
    dif = (int)num2.size() - (int)num1.size();
    mxsz = (int)num2.size();
    ms(dp , -1);
    pll ans = FuN(1 , 0 , 0 , 0 , 0);
    cout<<ans.second<<endl;
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

