/** Superb LCS **/
#include<bits/stdc++.h>

#define Input                   freopen("in.txt","r",stdin)
#define Output                  freopen("out.txt","w",stdout)
#define ll                      long long int
#define ull                     unsigned long long int
#define pii                     pair<int,int>
#define pll                     pair<ll,ll>
#define sc                      scanf
#define scin(x)                 sc("%d",&(x))
#define scin2(x,y)                sc("%d %d",&(x),&(y))
#define scln(x)                 sc("%lld",&(x))
#define scln2(x,y)                sc("%lld %lld",&(x),&(y))
#define pf                      printf
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
#define MOD                     998244353
#define CIN                     ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define RUN_CASE(t,T)           for(__typeof(t) t=1;t<=T;t++)
#define CASE(t)                 printf("Case %d: ",t)
#define CASEl(t)                printf("Case %d:\n",t)
#define intlimit                214748369
#define longlimit               922337203685477580
#define infinity                (1<<28)
#define gcd(a,b)                __gcd(a,b)
#define lcm(a,b)                ((a)*(b))/gcd(a,b)
#define mxx                     123456789
#define PI                      2*acos(0.0)
#define rep(i,a,b)              for(__typeof(i) i=a;i<=b;i++)
#define rev(i,a,b)              for(__typeof(i) i=a;i>=b;i--)

using namespace std;
/** toint, tostring, BigMod, sieve, Primefactorize **/
//ll toint(string s){ll n=0,k=1;for(int i=s.size()-1;i>=0;i--){n += ((s[i]-'0')*k);k*=10;}return n;}
//string tostring(ll n){string s="";ll x;while(n > 0){x=n%10;s +=(char)(x+'0');n/=10;}reverse(s.begin(),s.end());return s;}
//ll BigMod(ll a,ll b,ll m){if(b == 0)return 1%m;else if(b%2 == 0){ll temp=BigMod(a,b/2,m);return ((temp%m)*(temp%m))%m;}else{return ((a%m)*BigMod(a,b-1,m)%m)%m;}}
//ll power(ll a,ll n){ll ans=1;if(n == 0)return 1;else if(n == 1)return a;else return a*power(a,n-1);}

/** Order Set **/
//#include <ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;
//template<typename T> using orderset = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
//orderset<int> s ; //orderset<int>::iterator it ;
//orderset<int> X; //X.insert(1); //X.insert(2); //X.insert(4); //X.insert(8); //X.insert(16);
//cout<<*X.find_by_order(1)<<endl; // 2 //cout<<*X.find_by_order(2)<<endl; // 4 //cout<<*X.find_by_order(4)<<endl; // 16 //cout<<(end(X)==X.find_by_order(6))<<endl; // true
//cout<<X.order_of_key(-5)<<endl;  // 0 //cout<<X.order_of_key(1)<<endl;   // 0 //cout<<X.order_of_key(3)<<endl;   // 2 //cout<<X.order_of_key(4)<<endl;   // 2 //cout<<X.order_of_key(400)<<endl; // 5
/** Problem LOJ - 1013 . You're given two strings. Your tasks are:
1.The length of the shortest string that contains the two names as subsequence.
2.Total number of unique shortest strings which contain the two names as subsequence.
/**/
char s[4][65];
int dp1[32][32];
int len1,len2,len;
int LCS(int pos1,int pos2)
{
    if(pos1>=len1 || pos2>=len2)
        return 0;
    if(dp1[pos1][pos2] != -1)
        return dp1[pos1][pos2];
    if(s[1][pos1] == s[2][pos2])
        return dp1[pos1][pos2]=1+LCS(pos1+1,pos2+1);
    else
    {
        int res1=LCS(pos1,pos2+1);
        int res2=LCS(pos1+1,pos2);
        return dp1[pos1][pos2] = max(res1,res2);
    }
}
ll dp2[61][61][61]; /** pos for unique string ; pos1 for string-1 ; pos2 for string-2 **/
ll Unique(int pos,int pos1,int pos2)
{
    if(pos1>=len1 || pos2>=len2)
    {
       if(pos+(len1-pos1)+(len2-pos2) == len)   /** If any of the string is finished,then
        add the remaining character in the end of unique string ; check whether the total length
        is equal to MinLen or not. If yes then it is a desired unique string ,return 1; return 0 otherwise **/
        return 1;
       else
        return 0;
    }
    if(dp2[pos][pos1][pos2] != -1)
        return dp2[pos][pos1][pos2];
    ll ret1=0,ret2=0;
    if(s[1][pos1] == s[2][pos2])
        return dp2[pos][pos1][pos2] = Unique(pos+1,pos1+1,pos2+1);
    else
    {
        if(pos1 < len1)
            ret1 = Unique(pos+1,pos1+1,pos2);
        if(pos2 < len2)
            ret2 = Unique(pos+1,pos1,pos2+1);
        return dp2[pos][pos1][pos2] = ret1+ret2;
    }
}
int main()
{
    int i,j,k,t,T,MinLen,lcs;
    ll ans=0;
    scin(T);
    RUN_CASE(t,T)
    {
        ms(dp1,-1);
        ms(dp2,-1);
        sc("%s",s[1]);
        sc("%s",s[2]);
        len1 = strlen(s[1]);
        len2 = strlen(s[2]);
        lcs = LCS(0,0);
        MinLen = (len1-lcs)+(len2-lcs)+lcs;
        len=MinLen;
        ans = Unique(0,0,0);
        pf("Case %d: %d %lld\n",t,MinLen,ans);
    }
    return 0;
}
