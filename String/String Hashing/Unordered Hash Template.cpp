#include<bits/stdc++.h>
using namespace std;

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
#define longlimit               9223372036854775800
#define infinity                (1<<28)
#define gcd(a,b)                __gcd(a,b)
#define lcm(a,b)                (a)*(b)/gcd(a,b)
#define mxx                     123456789
#define PI                      2*acos(0.0)
#define rep(i,a,b)              for(__typeof(i) i=a;i<=b;i++)
#define rev(i,a,b)              for(__typeof(i) i=a;i>=b;i--)

using namespace std;

/** Problem: You're given an array with n elements. And q queries. In each query you'll
given l1,r1,l2,r2. You have to answer is subArray a[l1..r1] = a[l2..r2] or not?.
Example, {1 , 3 , 5} = {3 , 5 , 1}
Here, 0<=a[i]<=1e5.
hash[i] = hash[i-1]+(p^a[i]) **/

ll BigMod(ll a,ll b)
{
    if(b == 0)return 1%MOD;
    else if(b%2 == 0)
    {
        ll temp=BigMod(a,b/2);
        return ((temp%MOD)*(temp%MOD))%MOD;
    }
    else
    {
        return ((a%MOD)*BigMod(a,b-1)%MOD)%MOD;
    }
}


const int p = 1e6;  ///P must be greater than maximum element of array
ll ara[100005],hash_sum[100005];

int main()
{
    ll i,j,k,n,q,l1,l2,r1,r2,hash1,hash2;
    scln2(n , q);
    for(i=1 ; i<=n ; i++){
        scln(ara[i]);
        hash_sum[i] = (hash_sum[i-1] + BigMod(p , ara[i]));
    }
    for(i=1 ; i<=q ; i++){
        scln2(l1 , r1);
        scln2(l2 , r2);
        hash1 = (hash_sum[r1] - hash_sum[l1-1] + MOD)%MOD;
        hash2 = (hash_sum[r2] - hash_sum[l2-1] + MOD)%MOD;
        if(hash1 == hash2)
            pf("Two unordered subarrays r same\n");
        else
            pf("Two unordered subarrays r not same\n");
    }
    return 0;
}
