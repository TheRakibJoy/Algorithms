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

int dp[2][2][15][85][85];
/** State-1: is_less_than_given_value ; State-2: is_current_position_starting_position
State-3: current_position_from_left_side ; State-4: remainder_of_value_i_have_made  ;
State-5: remainder_of_sum_of_digit  **/
vector<int>num;
int K;
int FuN(int isSmall , int isStart , int pos , int val_remainder , int sum_remainder)
{
    if(pos >= (int)num.size())
    {
        if(isStart)
            return 0;   /** If its a starting position even now! the value is zero which is invalid **/
        if(val_remainder%K==0 && sum_remainder%K==0)
            return 1;
        else
            return 0;
    }
    if(dp[isSmall][isStart][pos][val_remainder][sum_remainder] != -1)
        return dp[isSmall][isStart][pos][val_remainder][sum_remainder];
    int ret=0 , can_be_taken=0;
    if(isSmall)
        can_be_taken = 9;   /** If the number already small,then any digit can be taken **/
    else
        can_be_taken = num[pos];    /** If its prefix is equal then digit can be taken till num[pos] **/
    if(!isStart)
    {
        for(int i=0 ; i<=can_be_taken ; i++)     /** If its not a starting digit , then 0 can be taken **/
        {
            ret += FuN(isSmall|(i<num[pos]) , 0 , pos+1 , (val_remainder*10+i)%K , (sum_remainder+i)%K);
        }
    }
    else
    {
        for(int i=1 ; i<=can_be_taken ; i++)     /** we can't put zero in starting position **/
        {
            ret += FuN(isSmall|(i<num[pos]) , 0 , pos+1 , (val_remainder*10+i)%K , (sum_remainder+i)%K);
        }
        ret += FuN(1 , 1 , pos+1 , 0 , 0);  /** IF its a starting position , then we can also put nothing in that position.
        Then the position will be starting position again , and it will be smaller than max range **/
    }
    return dp[isSmall][isStart][pos][val_remainder][sum_remainder] = ret;
}
int Calculate(int x)
{
    if(x <= 0)
        return 0;
    num.clear();
    ms(dp , -1);
    while(x)
    {
        num.pb(x%10);
        x /= 10;
    }
    reverse(num.begin() , num.end());
    return FuN(0 , 1 , 0 , 0 , 0);
}
int main()
{
//    Output;
    int t,T,ans,A,B;
    scin(T);
    RUN_CASE(t,T)
    {
        sc("%d %d %d",&A,&B,&K);
        if(A>B)
            swap(A,B);
        if(K == 1)
            ans = B-A+1;    /** All number in the range will fulfill the given condition **/
        else if(K > 81)
            ans = 0;        /** None of the number will fulfill the condition digit_sum%K==0; because maximum digit sum for 9 position can be 81 **/
        else
            ans = Calculate(B)-Calculate(A-1);
        pf("Case %d: %d\n",t,ans);
    }
    return 0;
}

