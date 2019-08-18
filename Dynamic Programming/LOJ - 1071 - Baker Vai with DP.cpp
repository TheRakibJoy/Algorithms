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

int m,n,grid[105][105],dp[105][105][105][2];
/**
Approach:   এই প্রব্লেমে ধরে নেই যে দুইজন লোক গ্রিডের ১ম সেল থেকে শেষ সেলে যাবে এবং পয়েন্টগুলো কালেক্ট করবে। মনে রাখতে হবে, এই দুইজন লোকের
            রাস্তা শুধুমাত্র  গ্রিডের ১ম এবং শেষ সেলেই মিলিত হতে পারবে। আর উভয় ব্যাক্তিই হয় নিচে নাহয় ডানে মুভ করতে পারবে। মানে রো এবং কলাম এর মান শুধু বাড়তেই পারবে।
             আমাদের এপ্রোচ হচ্ছে , দুইজন লোক একইসাথে নতুন কলামে যেতে পারবে। এবং একজন একজন করে রো
            পরিবর্তন করতে পারবে। ১ম ব্যাক্তি সর্বদা ২য় ব্যাক্তির থেকে নিচের কোন রো তে থাকবে।  এক্ষেত্রে এমন হতে পারে তারা ২য় কলামের ১ম এবং ২য় রো তে তারা আছে। এখন ১ম ব্যাক্তি ২য় রো থেকে একে একে ৫ম রো তে যাওয়ার পর ২য় ব্যাক্তি ২য়,৩য় রো
            ভিজিট করতেছে। মানে ১ম ব্যাক্তির ভিজিট করা পথেই যাচ্ছে! যা অসম্ভব।
            এজন্য একটা স্টেট রাখতে হবে যে বর্তমান কলামে ১ম ব্যাক্তি ১ বারও নিচে গেছে কি না? ১ম ব্যাক্তি যদি নিচে যায়,তাহলে আমি আর জানি না সে এই কলাম এর কোন কোন
            সেল ভিজিট করছে।সো,২য় ব্যাক্তি নিচে যেতে পারবে না এই কলাম বরাবর।
            আর যদি ১ম ব্যাক্তি এখনো নিচে যায় নি এই কলাম বরারবর, তাহলে ২য় ব্যাক্তি প্রথম ব্যাক্তির রো এর আগের রো পর্যন্ত নিচে যেতে পারবে ১ রো ১ রো করে।
            সর্বশেষে, আমরা জানি যে শুরুর এবং শেষের সেলের পয়েন্ট দুইবার যোগ হয়েছে। তাই ১বার বিয়োগ করে দিতে হবে। স্টেটগুলো হবেঃ
    State-1: বর্তমান কলাম বরাবর ১ম ব্যাক্তি কি নিচের দিকে মুভ করছে?
    State-2: ১ম ব্যাক্তি বর্তমানে কোন রো তে আছে?
    State-3: ২য় ব্যাক্তি বর্তমানে কোন রো তে আছে?
    State-4: উভয়ে বর্তমানে কোন কলামে আছে?
            বেইস কেস কি হবে নিজে চিন্তা করে বের কর।
**/
int FuN(int row1,int row2,int col,int p1_not_moved_in_this_col)
{
    if(row1!=m && col==n)
        return -infinity;
    else if(row1==m && row2==m && col==n && p1_not_moved_in_this_col)
        return grid[row1][col]+grid[row2][col];
    if(dp[row1][row2][col][p1_not_moved_in_this_col] != -1)
        return dp[row1][row2][col][p1_not_moved_in_this_col];
    int ret1=0,ret2=0,ret3=0;
    if((col==n && row2<row1) || (col<n && row2+1<row1 && p1_not_moved_in_this_col && col>1))
        ret1 = grid[row2][col] + FuN(row1,row2+1,col,p1_not_moved_in_this_col);
    if(row1<m)
        ret3 = grid[row1][col] + FuN(row1+1,row2,col,0);
    if(col<n && row1!=row2)
        ret2 = grid[row1][col] + grid[row2][col] + FuN(row1,row2,col+1,1);
    return dp[row1][row2][col][p1_not_moved_in_this_col] = max(ret1, max(ret2,ret3));
}
int main()
{
    int i,j,t,T,ans;
    scin(T);
    RUN_CASE(t,T)
    {
        scin2(m,n);
        for(i=1 ; i<=m ; i++)
        {
            for(j=1 ; j<=n ; j++)
                scin(grid[i][j]);
        }
        ms(dp,-1);
        ans = FuN(1,1,1,1);
        ans -= (grid[1][1]+grid[m][n]);
        pf("Case %d: %d\n",t,ans);
    }
    return 0;
}

