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


/** Code Start Here **/
/**
State-1: Is this number smaller than the range(2)
State-2: Positions(32)
State-3: Total number of 1's used so far(32)
State-4: Maximum bit differ from ideal number(32)
State-5: Value after mod by 3(3)
State-6: Value after mod by 7(7)
**/

bool Cheek(int N, int pos) {return  (bool)(N & (1<<pos));}

pair<ll , int> dp[2][31][31][31][3][7]; ///First - Value ; Second - Frequency

vi num,ideal;
int lb,ub,mxone,idnum,differ;

pair<ll , int> FuN(int isSmall,int pos,int ones,int diffr,int mod_3,int mod_7)
{
    if(pos >= (int)num.size()){
        if(mod_3==0 && mod_7!=0 && ones<=mxone && diffr<=differ)
            return make_pair(0 , 1);
        else
            return make_pair(0 , 0);
    }
    if(dp[isSmall][pos][ones][diffr][mod_3][mod_7] != make_pair(-1LL , -1))
        return dp[isSmall][pos][ones][diffr][mod_3][mod_7];
    ll ret = 0 , can_be_taken = 0 , fre = 0 , cnt = 0 , tempcnt = 0;
    if(isSmall)
        can_be_taken = 1;
    else
        can_be_taken = num[pos];

    for(int i=0 ; i<=can_be_taken ; i++){
        int currval = i*(1<<(30-pos));
            pll pr = FuN(isSmall|(i<num[pos]) , pos+1 , ones+(i==1) , diffr+(ideal[pos]!=i) , ((currval%3)+mod_3)%3 , ((currval%7)+mod_7)%7);
            ret += ((currval*pr.second) + pr.first);
            fre += pr.second;
    }
    return dp[isSmall][pos][ones][diffr][mod_3][mod_7] = make_pair(ret , fre);
}

ll Calculate(int x)
{
    if(x <= 2)
        return 0LL;
    num.clear();
    for(int i=30 ; i>=0 ; i--)
        num.pb(Cheek(x , i));
    ms(dp , -1);
    return FuN(0 , 0 , 0 , 0 , 0 , 0).first;
}

void Solve(int t)
{
    int i,j,k,n;
    sc("%d %d %d %d %d",&lb,&ub,&mxone,&idnum,&differ);
    ideal.clear();
    for(i=30 ; i>=0 ; i--)
        ideal.pb(Cheek(idnum , i));
    ll ans = Calculate(ub)-Calculate(lb-1);
    pf("Case %d: %lld\n",t,ans);
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

