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

/** Problem: Two strings are defined to be almost equal if they are of the same length
    and their hamming distance is less than or equal to K. What this means is that they
    can have at most K mismatches.
    Given a text string S, a pattern string P, and an integer K, count how many substrings
    of S are almost equal to the pattern P with hamming distance at most K.

    Solution: Create hash table for both given string. And call BS for every substring from
    each position at most k(=4) times to count the mismatch    **/
#define sz 1200005
string str,pattern;
const int p = 37;
const int m = 1e9+7;
ll p_pow[sz];
void Power()
{
    p_pow[0] = 1;
    for(int i=1 ; i<sz ; i++)
        p_pow[i] = (p_pow[i-1] * p)%m;
}
ll hash_sum1[sz],hash_sum2[sz];
void Compute_Hash()
{
    ll i,j,k,sz1=(ll)str.size(),sz2=(ll)pattern.size();
    for(i=0 ; i<sz1 ; i++)
        hash_sum1[i+1] = (hash_sum1[i] + (str[i]-'a'+1)*p_pow[i])%m;
    for(i=0 ; i<sz2 ; i++)
        hash_sum2[i+1] = (hash_sum2[i] + (pattern[i]-'a'+1)*p_pow[i])%m;
}
ll Compute_Result(ll k)
{
    ll i,j,usedk,sz1=(ll)str.size(),sz2=(ll)pattern.size(),sum1,sum2,power1,power2,powerdif,ans=0;
    for(i=0 ; i<=sz1-sz2 ; i++){
        j=i;
        usedk = 0;
        ll lft1=i,rgt1=i+sz2-1,lft2=0,rgt2=sz2-1,mid1,mid2,res=0,rgttaken1=j,rgttaken2=0;
        do{
            res = 0;
            lft1 = rgttaken1;
            lft2 = rgttaken2;
            rgt1 = i+sz2-1;
            rgt2 = sz2-1;
            while(lft1 <= rgt1){
                mid1 = (lft1+rgt1)/2;
                mid2 = (lft2+rgt2)/2;
                power1 = lft1;
                power2 = lft2;
                powerdif = fabs(power1-power2);
                sum1 = (hash_sum1[mid1+1]-hash_sum1[rgttaken1]+m)%m;
                sum2 = (hash_sum2[mid2+1]-hash_sum2[rgttaken2]+m)%m;
                if(power1 <= power2)
                    sum1 = (sum1*p_pow[powerdif])%m;
                else
                    sum2 = (sum2*p_pow[powerdif])%m;
                if(sum1 == sum2){
                    res = mid1-rgttaken1+1;
                    lft1 = mid1+1;
                    lft2 = mid2+1;
                    rgttaken1 = mid1+1;
                    rgttaken2 = mid2+1;
                }
                else{
                    rgt1 = mid1-1;
                    rgt2 = mid2-1;
                }
            }
            if(res==sz2 || rgttaken1>i+sz2-1 || usedk>k)
                break;
            rgttaken1++;
            rgttaken2++;
            usedk++;
            j = rgttaken1;
        }while(j <= i+sz2-1);
        if(usedk <= k)
            ans++;
    }
    return ans;
}
int main()
{
    ll t,T,ans,k;
    Power();
    scln(T);
    RUN_CASE(t,T)
    {
        cin>>str>>pattern;
        scln(k);
        Compute_Hash();
        ans = Compute_Result(k);
        pf("Case %lld: %lld\n",t,ans);
    }
    return 0;
}

