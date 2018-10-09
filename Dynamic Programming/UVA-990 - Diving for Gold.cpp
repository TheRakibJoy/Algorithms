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
#define MOD                     100000007
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
/** Order Set **/
//#include <ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;
//template<typename T> using orderset = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
//orderset<int> s ; //orderset<int>::iterator it ;
//orderset<int> X; //X.insert(1); //X.insert(2); //X.insert(4); //X.insert(8); //X.insert(16);
//cout<<*X.find_by_order(1)<<endl; // 2 //cout<<*X.find_by_order(2)<<endl; // 4 //cout<<*X.find_by_order(4)<<endl; // 16 //cout<<(end(X)==X.find_by_order(6))<<endl; // true
//cout<<X.order_of_key(-5)<<endl;  // 0 //cout<<X.order_of_key(1)<<endl;   // 0 //cout<<X.order_of_key(3)<<endl;   // 2 //cout<<X.order_of_key(4)<<endl;   // 2 //cout<<X.order_of_key(400)<<endl; // 5

int weight[32],cost[32];
int dir[32][3005];
ll dp[32][3005];
vector<int>ans;
int n,cap,cons;
ll knapsack(int i,int w)
{
    ll profit1,profit2;
    if(i == n)
        return 0;
    if(dp[i][w] != -1)
        return dp[i][w];
    if(w+(3*weight[i]*cons) <= cap)
        profit1=cost[i]+knapsack(i+1,w+(3*weight[i]*cons));
    else
        profit1=0;
    profit2=knapsack(i+1,w);
    if(profit1 >= profit2)
        dir[i][w]=1;
    else
        dir[i][w]=-1;
    return dp[i][w]=max(profit1,profit2);
}
void Print()
{
    int w=0;
    for(int i=0;i<n;i++)
    {
        if(dir[i][w] == 1)
        {
            ans.pb(i);
            w += (3*weight[i]*cons);
        }
    }
}
int main()
{
//    Output;
    int i,j,k;
    ll profit;
    while(scin2(cap,cons) != EOF)
    {
        ans.clear();
        ms(dp,-1);
        ms(dir,-1);
        ms(weight,0);
        ms(cost,0);
        scin(n);
        for(i=0; i<n; i++)
        {
            scin2(weight[i],cost[i]);
        }
        profit=knapsack(0,0);
        Print();
        pf("%lld\n",profit);
        int sz=ans.size();
        pf("%d\n",sz);
        for(i=0; i<sz; i++)
            pf("%d %d\n",weight[ans[i]],cost[ans[i]]);
        pf("\n");
    }
    return 0;
}
