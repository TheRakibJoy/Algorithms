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

inline int add(int a, int b) {a += b; return a >= MOD ? a - MOD : a;}
inline int sub(int a, int b) {a -= b; return a < 0 ? a + MOD : a;}
inline int mul(int a, int b) {return (ll) a * b % MOD;}
///------------------Graph Moves-------------------
///const int fx[] = {+1,-1,+0,+0};
///const int fy[] = {+0,+0,+1,-1};
///const int fx[] = {+0,+0,+1,-1,-1,+1,-1,+1}; ///King's move
///const int fy[] = {-1,+1,+0,+0,+1,+1,-1,-1}; ///King's move
///const int fx[] = {-2,-2,-1,-1,+1,+1,+2,+2}; ///Knight's move
///const int fy[] = {-1,+1,-2,+2,-2,+2,-1,+1}; ///Knight's move

/**
Problem: LOJ - 1092 - Lighted Panels
এই প্রবলেম এ আমাদের একটা লাইট প্যানেল এর অবস্থা দেওয়া  হয়েছে , কোন অবস্থার '*' এর মানে হচ্ছে লাইট জ্বলে আছে , '.' মানে হচ্ছে লাইটা নিভে আছে । আমাদেরকে মিনিমাম মুভে প্যানেল এর সবগুলা লাইট জ্বালাতে হবে । এইখানে যখন কোন পয়েন্ট  toggle করা হয় ( মানে এইটা যে অবস্থায় আছে জ্বলা থাকলে নিভা , নিভা থাকলে জ্বলে উঠবে ) ঐ পয়েন্ট এর সাথে adjacent যে পয়েন্টগুলা থাকে ( diagonal সহ ) তারাও toggle করবে।
row and column of the grid <= 8
Solution:
1.      এই প্রবলেমটা যদি দেখি আমরা যখন কোন পয়েন্ট toggle করি তাহলে কি হবে আমরা যে row তে আছি তার আগের row এবং পরের row এর আমরা যে column এ আছি তার আগের column এবং পরের column নিয়ে কাজ করব ।
2.      আমি এখন যে row তে আসি তার কিঅবস্থা ( মানে কোন কোন পয়েন্ট জ্বলে আসে কি নিভে আসে ) যে row থেকে আসলাম তার কি অবস্থা ছিল এবং যে row তে যাব তার কি অবস্থা আছে আমাদের তা জানা থাকা দরকার ।
3.  State-1: number_of_row ; State-2: bit_representation_of_previous_row ; State-3: bit_representation_of_current_row
4.      আমাদের ক্যালকুলেশন এর জন্য আমাদের পরের row ও দরকার হবে এইটা আমরা কোথায় পাব । আমরা প্রথমেই ইনপুট নেওয়ার সময় একটা array তে রেখে দিতে পারি কোন কোন লাইট এখন জ্বলে আসে ।
5.      যে  row তে আসি এর প্রতিটা combination করে আমরা আমাদের store value গুলা change করে দেখব । এর জন্য আমরা subset mask use করতে পারি । যেহেতু column এর highest limit 8 .তাই ( 1 << 8 ) == 256 খুব সহজেই আমরা আমাদের dp এর ভিতর তা চালাতে পারি ।
6.      যখন আমরা নেক্সড row তে যাব আমাদের sure করতে হবে আমাদের আগের row এর সবগুলা লাইটা জ্বালানো আছে ( যদি না থাকে তাহলে আর কোন ভাবেই ঐ লাইটাকে আর জ্বালানো সম্ভব হবে না । ) ।
**/
int Set(int N, int pos) {return  N = N | (1<<pos);}
int Reset(int N, int pos) {return  N = N & ~(1<<pos);}
bool Cheek(int N, int pos) {return  (bool)(N & (1<<pos));}

bool vis[10][(1<<8)+5][(1<<8)+5];
int row,col,rowcondition[10],dp[10][(1<<8)+5][(1<<8)+5];
char grid[10][10];

int FuN(int idx,int currmask,int prevmask)
{
    if(idx >= row){
        if(prevmask == (1<<col)-1)
            return 0;
        else
            return infinity;
    }
    if(vis[idx][currmask][prevmask])
        return dp[idx][currmask][prevmask];
    int ret = infinity;
    for(int i=0 ; i <= (1<<col)-1 ; i++){
        int cnt = 0;
        int rowrep[3] = {prevmask , currmask , rowcondition[idx+1]};    /** manipulated bit representation of previous row , manipulated bit representation of current row(manipulated from previous row) , original bit representation of next row **/
        for(int j=0 ; j<col ; j++){      ///Check all possible combination by subset mask
            if(Cheek(i , j) == 0)
                continue;   ///No need to toggle
            ///Need to toggle
            cnt++;
            for(int k=0 ; k<3 ; k++){   ///Toggle the jth light of prevrow,currrow,nxtrow
                rowrep[k] ^= (1<<j);
            }
            if(j+1 < col){  ///Toggle the (j+1)th light of prevrow,currow,nxtrow
                for(int k=0 ; k<3 ; k++)
                    rowrep[k] ^= (1<<(j+1));
            }
            if(j-1 >= 0){   ///Toggle the (j-1)th light of prevrow,currow,nxtrow
                for(int k=0 ; k<3 ; k++)
                    rowrep[k] ^= (1<<(j-1));
            }
        }
        if(idx == 0){   ///IF its 1st row,then go to 2nd row. Because,if any light isn't on yet, we can on that light from next row.
            ret = min(ret , cnt+FuN(idx+1 , rowrep[2] , rowrep[1]));
        }
        else if(rowrep[0] == (1<<col)-1){   ///Only IF all the lights are on in our previous row,then we can go to next row
            ret = min(ret , cnt+FuN(idx+1 , rowrep[2] , rowrep[1]));
        }
    }
    vis[idx][currmask][prevmask] = 1;
    return dp[idx][currmask][prevmask] = ret;
}

int main()
{
    int i,j,k,t,T,ans,mask;
    scin(T);
    RUN_CASE(t,T)
    {
        scin2(row , col);
        for(i=0 ; i<row ; i++){
            sc("%s",grid[i]);
            mask = 0;
            for(j=0 ; j<col ; j++){
                if(grid[i][j] == '*')
                    mask = Set(mask , j);
            }
            rowcondition[i] = mask;
        }
        ms(vis , 0);
        ans = FuN(0 , rowcondition[0] , 0);
        if(ans < infinity)
            pf("Case %d: %d\n",t,ans);
        else
            pf("Case %d: impossible\n",t);
    }
    return 0;
}

