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
#define MOD                     1000000007
#define CIN                     ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define RUN_CASE(t,T)           for(__typeof(t) t=1;t<=T;t++)
#define CASE(t)                 printf("Case %d: ",t)
#define CASEl(t)                printf("Case %d:\n",t)
#define intlimit                214748369
#define longlimit               92233720368547758
#define infinity                (1<<28)
#define gcd(a,b)                __gcd(a,b)
#define lcm(a,b)                ((a)*(b))/gcd(a,b)
#define mxx                     123456789
#define PI                      2*acos(0.0)
#define rep(i,a,b)              for(__typeof(i) i=a;i<=b;i++)
#define rev(i,a,b)              for(__typeof(i) i=a;i>=b;i--)

using namespace std;
/** toint, tostring, BigMod, Power , sieve, Primefactorize ,frequency in n!**/
//ll toint(string s){ll n=0,k=1;for(int i=s.size()-1;i>=0;i--){n += ((s[i]-'0')*k);k*=10;}return n;}
//ll BigMod(ll a,ll b,ll m){if(b == 0)return 1%m;else if(b%2 == 0){ll temp=BigMod(a,b/2,m);return ((temp%m)*(temp%m))%m;}else{return ((a%m)*BigMod(a,b-1,m)%m)%m;}}
//ll frequency(ll n,ll factor)/** Frequency of a factor in n! **/{ll cnt=0;while(n){cnt += (n/factor);n /= factor;}return cnt;}

/** Order Set **/
//#include <ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;
//template<typename T> using orderset = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
//orderset<int> s ; //orderset<int>::iterator it ;
//orderset<int> X; //X.insert(1); //X.insert(2); //X.insert(4); //X.insert(8); //X.insert(16);
//cout<<*X.find_by_order(1)<<endl; // 2 //cout<<*X.find_by_order(2)<<endl; // 4 //cout<<*X.find_by_order(4)<<endl; // 16 //cout<<(end(X)==X.find_by_order(6))<<endl; // true
//cout<<X.order_of_key(-5)<<endl;  // 0 //cout<<X.order_of_key(1)<<endl;   // 0 //cout<<X.order_of_key(3)<<endl;   // 2 //cout<<X.order_of_key(4)<<endl;   // 2 //cout<<X.order_of_key(400)<<endl; // 5

string multiply(string s,ll b)
{
    /** BigInteger Multiplication **/
    string res="";
    ll remain=0;
    for(int i=s.size()-1 ; i>=0 ; i--)
    {
        remain += ((s[i]-'0')*b);
        res += ((remain%10)+'0');
        remain /= 10;
    }
    while(remain)
    {
        res += ((remain%10)+'0');
        remain /= 10;
    }
    reverse(res.begin(),res.end());
    return res;
}
ll power(ll a,ll n)
{
    ll ans=1;
    if(n == 0)
        return 1;
    ans = power(a,n/2);
    ans = ans*ans;
    if(n%2 == 1)
        ans = ans*a;
    return ans;
}
vector<int>Prime;
bool mark[1005];
void sieve(int n)
{
    int i,j;
    mark[1]=1;
    for(i=4; i<=n; i+=2)
        mark[i]=1;
    Prime.push_back(2);
    for(i=3; i<=n; i+=2)
    {
        if(!mark[i])
        {
            Prime.push_back(i);
            if(i*i<=n)
            {
                for(j=i*i; j<=n; j+=(i*2))
                    mark[j]=1;
            }
        }
    }
}
int fre[10005];
set<int>factor;
set<int>::iterator it;
void Primefactorize(int n)
{
    for(int i=0; Prime[i]*Prime[i]<=n; i++)
    {
        if(n%Prime[i] == 0)
        {
            int pow=0;
            while(n%Prime[i] == 0)
            {
                n/=Prime[i];
                pow++;
            }
            factor.insert(Prime[i]);
            fre[Prime[i]] = max(fre[Prime[i]],pow);
        }
    }
    if(n>1)
    {
        factor.insert(n);
        fre[n] = max(fre[n],1);
    }
}
int main()
{
//    Output;
    int i,j,k,t,T,n,x,y;
    ll temp;
    sieve(1003);
    scin(T);
    RUN_CASE(t,T)
    {
        string res;
        ms(fre,0);
        factor.clear();
        scin(n);
        int ara[n];
        for(i=0; i<n; i++)
        {
            scin(ara[i]);
            Primefactorize(ara[i]);
        }
        res="1";
        for(it=factor.begin() ; it!=factor.end() ; it++)
        {
            x=*it;
            y=fre[x];
            temp = power((ll)x,(ll)y);
            res = multiply(res,temp);
        }
        pf("Case %d: ",t);
        for(i=0 ; i<res.size() ; i++)
            pf("%c",res[i]);
        pf("\n");
    }
    return 0;
}

