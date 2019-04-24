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

int n,k;
int ara[1002],sum[1002];
vi vec;
int Bin(int ITEM,int lft,int rgt)
{
    int lo=lft,hi=rgt,mid,res=lft;
    while(lo <= hi)
    {
        mid=(lo+hi)/2;
        if(sum[mid] == ITEM)
        {
            res=mid;
            break;
        }
        else if(ITEM < sum[mid])
        {
            hi=mid-1;
        }
        else
        {
            res=mid;
            lo=mid+1;
        }
    }
    return res;
}
bool Possible(int x)
{
    vec.clear();
    int pres=1,prev=1,lft=1,rgt=n+1,res,mx=0;
    for(int i=k+1 ; i>=1 ; i--)
    {
        res=Bin(x*i,lft,rgt);
        vec.pb(sum[res]);
        rgt=min(1,res-1);
    }
    vec.erase(unique(vec.begin(),vec.end()),vec.end());
    sort(vec.begin(),vec.end());
    mx = max(mx,vec[0]);
    for(int i=1;i<vec.size();i++)
    {
        mx = max(mx,vec[i]-vec[i-1]);
    }
    if(vec.size()==k+1 && mx<=x)
        return true;
    else
        return false;
}
int BiSec()
{
    int lo=0,hi=10000001,mid,res=0;
    while(lo <= hi)
    {
        mid=(lo+hi)/2;
        if(Possible(mid))
        {
            res=mid;
            hi=mid;
        }
        else
            lo=mid;
    }
    return res;
}
int main()
{
    int i,j,t,T,ans;
    scin(T);
    RUN_CASE(t,T)
    {
        ms(ara,0);
        ms(sum,0);
        scin2(n,k);
        for(i=1;i<=n+1;i++)
            scin(ara[i]);
        for(i=1;i<=n+1;i++)
            sum[i] += sum[i-1];
        ans = BiSec();
        Possible(ans);
        pf("Case %d: %d\n",t,ans);
        pf("%d\n",vec[0]);
        for(i=1;i<vec.size();i++)
        {
            pf("%d\n",vec[i]-vec[i-1]);
        }
    }
    return 0;
}

