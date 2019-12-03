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
#define lcm(a,b)                ((a)*(b))/gcd(a,b)
#define mxx                     123456789
#define PI                      2*acos(0.0)
#define rep(i,a,b)              for(__typeof(i) i=a;i<=b;i++)
#define rev(i,a,b)              for(__typeof(i) i=a;i>=b;i--)

using namespace std;
/**     toint, tostring, BigMod, Power , sieve, Primefactorize ,frequency in n!     **/
//ll toint(string s){ll n=0,k=1;for(int i=s.size()-1; i>=0; i--){n += ((s[i]-'0')*k);k*=10;}return n;}
//string tostring(ll x){string s="";while(x){s += (x%10)+'0';x/=10;}reverse(s.begin(),s.end());return s;}
//ll BigMod(ll a,ll b){if(b == 0)return 1%MOD;else if(b%2 == 0){ll temp=BigMod(a,b/2);return ((temp%MOD)*(temp%MOD))%MOD;}else{return ((a%MOD)*BigMod(a,b-1)%MOD)%MOD;}}
//ll Power(ll a,ll n){ll ret=1;for(ll i=1 ; i<=n ; i++)ret = ((ret%MOD)*(a%MOD))%MOD;return ret;}
//vector<ll>Prime;
//bool mark[10000003];
//void sieve(ll n){ll i,j;mark[1]=1;for(i=4; i<=n; i+=2)mark[i]=1;Prime.push_back(2);for(i=3; i<=n; i+=2){if(!mark[i]){Prime.push_back(i);if(i*i<=n){for(j=i*i; j<=n; j+=(i*2))mark[j]=1;}}}}
//map<ll,ll>Factor;
//void Primefactorize(ll n){for(ll i=0; i<Prime.size() && Prime[i]*Prime[i]<=n; i++){if(n%Prime[i] == 0){while(n%Prime[i] == 0){Factor[Prime[i]]++;n/=Prime[i];}}}if(n>1){Factor[n]++;}}
//ll frequency(ll n,ll factor)/** Frequency of a factor in n! **/{ll cnt=0;while(n){cnt += (n/factor);n /= factor;}return cnt;}
/**     Order Set       **/
//#include <ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;
//template<typename T> using orderset = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
//orderset<int> s ; //orderset<int>::iterator it ;
//orderset<int> X; //X.insert(1); //X.insert(2); //X.insert(4); //X.insert(8); //X.insert(16);
//cout<<*X.find_by_order(0)<<endl; // 2 //cout<<*X.find_by_order(2)<<endl; // 4 //cout<<*X.find_by_order(4)<<endl; // 16 //cout<<(end(X)==X.find_by_order(6))<<endl; // true
//cout<<X.order_of_key(-5)<<endl;  // 0 //cout<<X.order_of_key(1)<<endl;   // 0 //cout<<X.order_of_key(3)<<endl;   // 2 //cout<<X.order_of_key(4)<<endl;   // 2 //cout<<X.order_of_key(400)<<endl; // 5
///------------------Graph Moves-------------------
///const int fx[] = {+1,-1,+0,+0};
///const int fy[] = {+0,+0,+1,-1};
///const int fx[] = {+0,+0,+1,-1,-1,+1,-1,+1}; ///King's move
///const int fy[] = {-1,+1,+0,+0,+1,+1,-1,-1}; ///King's move
///const int fx[] = {-2,-2,-1,-1,+1,+1,+2,+2}; ///Knight's move
///const int fy[] = {-1,+1,-2,+2,-2,+2,-1,+1}; ///Knight's move

/**
Problem: You’ll be given a, k, L and R. Find out all the values of b in the
range [L, R] for which (a & b) & (1<<k) != 0. Calculate the summation of
those b values. And print whether this summation is odd or even?
**/
vector<ll>bit,orgnum;
ll x , dp[2][2][2][2][33];
/// State-1: Is this number became already small?
/// State-2: Is this digit is starting digit?
/// State-3: Is this number match at least one bit with (a&(1<<k))? That means for non-zero b , (a&b)&(1<<k) will also be non-zero.
/// State-4: Last used bit for making the value of b
/// State-5: Position
ll FuN(ll isSmall,ll isStart,ll match,ll lastBit,ll pos)
{
    if(pos >= (ll)bit.size())
    {
        if(match)
            return lastBit; /** If match is true that means (a&b)&(1<<k)!=0. And if the statement is true then I've to return the rightmost bit of b. bcoz every time the rightmost bit defines whether the number is even or odd.
            And I've to count the number of odd b. If the number of odd b is ODD,then the summation of b will be ODD. Otherwise,it'll be even **/
        else
            return 0LL;     /** If (a&b)&(1<<k)==0 then b is not valid **/
    }
    if(dp[isSmall][isStart][match][lastBit][pos] != -1)
        return dp[isSmall][isStart][match][lastBit][pos];
    ll ret=0LL, can_be_taken = 0LL;
    if(isSmall)
        can_be_taken = 1;
    else
        can_be_taken = bit[pos];
    if(!isStart)
    {
        for(ll i=0 ; i<=can_be_taken ; i++)
            ret += FuN(isSmall | (i<bit[pos]), 0, match | (orgnum[pos] & i), i, pos+1);
    }
    else
    {
        for(ll i=1 ; i<=can_be_taken ; i++)
            ret += FuN(isSmall | (i<bit[pos]), 0, match | (orgnum[pos] & i), i, pos+1);
        ret += FuN(1, 1, match, 0, pos+1);
    }
    return dp[isSmall][isStart][match][lastBit][pos] = ret;
}
ll Calculate(ll val,ll temp)
{
    if(val == 0LL)
        return 0LL;
    bit.clear();
    ms(dp, -1);
    while(val)
    {
        bit.pb(val%2);
        val /= 2;
    }

    orgnum.clear();
    temp = x;
    while(temp)
    {
        orgnum.pb(temp%2);
        temp /= 2;
    }

    for(ll i=(ll)orgnum.size() ; i<(ll)bit.size() ; i++)
        orgnum.pb(0);   /// Make the number of bit of Range and (a&(1<<k)) equal
    for(ll i=(ll)bit.size() ; i<(ll)orgnum.size() ; i++)
        bit.pb(0);
    reverse(bit.begin(), bit.end());
    reverse(orgnum.begin(), orgnum.end());

    return FuN(0, 1, 0, 0, 0);
}
int main()
{
    ll i,j,k,n,t,T,a,l,r,ans,temp;
    scln(T);
    RUN_CASE(t,T)
    {
        sc("%lld %lld %lld %lld",&a,&k,&l,&r);
        x = a & (1<<k);

        ans = Calculate(r,x) - Calculate(l-1,x);
        if(ans%2)
            pf("Odd\n");
        else
            pf("Even\n");
    }
    return 0;
}

