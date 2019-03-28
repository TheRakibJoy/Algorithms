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
//string tostring(ll n){string s="";ll x;while(n > 0){x=n%10;s +=(char)(x+'0');n/=10;}reverse(s.begin(),s.end());return s;}
//ll toint(string s){ll n=0,k=1;for(int i=s.size()-1;i>=0;i--){n += ((s[i]-'0')*k);k*=10;}return n;}
//ll power(ll a,ll n){ll ans=1;if(n == 0)return 1;else if(n == 1)return a;else return a*power(a,n-1);}
//vector<ll>List;
//ll frequency(ll n,ll factor)/** Frequency of a factor in n! **/{ll cnt=0;while(n){cnt += (n/factor);n /= factor;}return cnt;}
/** Order Set **/
//#include <ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;
//template<typename T> using orderset = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
//orderset<int> s ; //orderset<int>::iterator it ;
//orderset<int> X; //X.insert(1); //X.insert(2); //X.insert(4); //X.insert(8); //X.insert(16);
//cout<<*X.find_by_order(1)<<endl; // 2 //cout<<*X.find_by_order(2)<<endl; // 4 //cout<<*X.find_by_order(4)<<endl; // 16 //cout<<(end(X)==X.find_by_order(6))<<endl; // true
//cout<<X.order_of_key(-5)<<endl;  // 0 //cout<<X.order_of_key(1)<<endl;   // 0 //cout<<X.order_of_key(3)<<endl;   // 2 //cout<<X.order_of_key(4)<<endl;   // 2 //cout<<X.order_of_key(400)<<endl; // 5
/** Bit manipulation **/
//int reset(int N,int pos){return N= N & ~(1<<pos);}

/**Problem:
You are given an array a1,a2,…,an.
You need to perform q queries of the following two types:
"MULTIPLY l r x" — for every i (l≤i≤r) multiply ai by x.
"TOTIENT l r" — print φ(∏i=lrai) taken modulo 109+7, where φ denotes Euler's totient function.
**/
bool check(ll N,ll pos){return (bool)(N & (1LL<<pos));}
ll Set(ll N,ll pos){return N=N | (1LL<<pos);}
vector<int>Prime;
map<int,int>m;
ll ModIn[305];
bool mark[310];
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
ll Primefactorize(int n)
{
    ll maskk=0;
    for(int i=0; Prime[i]*Prime[i]<=n; i++)
    {
        if(n%Prime[i] == 0)
        {
            maskk = Set(maskk,(ll)m[Prime[i]]);
            while(n%Prime[i] == 0)
            {
                n/=Prime[i];
            }
        }
    }
    if(n>1)
    {
        maskk = Set(maskk,(ll)m[n]);
    }
    return maskk;
}
ll BigMod(ll a,ll b)
{
    if(b == 0)
        return 1LL%MOD;
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
#define sz 400005
struct info
{
    ll prop,mul,mask,propmask;
}tree[sz*4];
int ara[sz];
void clean()
{
    for(int i=0; i<sz*4; i++)
    {
        tree[i].mul=1LL;
        tree[i].prop=1LL;
        tree[i].mask=0LL;
        tree[i].propmask=0LL;
    }
}
void push_down(int node,int b,int e)
{
    if(tree[node].prop > 1)
    {
        tree[node].mul = (tree[node].mul* BigMod(tree[node].prop,e-b+1))%MOD;
        tree[node].mask |= tree[node].propmask;
        if(b != e)
        {
            int left=node*2,right=left+1;
            tree[left].prop = (tree[node].prop*tree[left].prop)%MOD;
            tree[right].prop = (tree[node].prop*tree[right].prop)%MOD;
            tree[left].propmask |= tree[node].propmask;
            tree[right].propmask |= tree[node].propmask;
        }
        tree[node].prop=1;
        tree[node].propmask=0;
    }
}
void init(int node,int b,int e)
{
    if(b == e)
    {
        tree[node].mul=ara[b];
        tree[node].mask = Primefactorize(ara[b]);
        return;
    }
    int left=node*2;
    int right=left+1;
    int mid=(b+e)/2;
    init(left,b,mid);
    init(right,mid+1,e);
    tree[node].mul=(tree[left].mul*tree[right].mul)%MOD;
    tree[node].mask=tree[left].mask | tree[right].mask;
}
void update(int node,int b,int e,int i,int j,int x,ll maskk)
{
    push_down(node,b,e);
    if(b>e || i>e || j<b)
        return;
    if(b>=i && e<=j)
    {
        tree[node].prop = x;
        tree[node].propmask = maskk;
        push_down(node,b,e);
        return;
    }
    int left=node*2,right=left+1,mid=(b+e)/2;
    update(left, b, mid, i, j, x, maskk);
    update(right, mid+1, e, i, j, x , maskk);
    tree[node].mul = ((tree[left].mul%MOD)*(tree[right].mul%MOD))%MOD;
    tree[node].mask = tree[left].mask | tree[right].mask;
}
pll query(int node,int b,int e,int i,int j) /** Pair<multiplied value , mask> **/
{
    if(i>e || j<b)
        return make_pair(1LL,0LL);
    push_down(node,b,e);
    if(b>=i && e<=j)
        return make_pair(tree[node].mul%MOD,tree[node].mask);
    int left=node*2;
    int right=left+1;
    int mid=(b+e)/2;
    pll retl = query(left,b,mid,i,j);
    pll retr = query(right,mid+1,e,i,j);
    retl.first = ((retl.first%MOD) * (retr.first%MOD) )%MOD;
    retl.second = retl.second | retr.second;
    return retl;
}
void ModInverse()
{
    for(int i=0; i<Prime.size(); i++)
    {
        m[Prime[i]] = i;
        ModIn[i] = BigMod(Prime[i],MOD-2);
    }
}

int main()
{
    int i,j,k,n,q,x,y,val;
    string cmd;
    ll ans=1,mask=0,temp;
    clean();
    sieve(305);
    ModInverse();
    scin2(n,q);
    for(i=1; i<=n; i++)
        scin(ara[i]);
    init(1,1,n);
    for(j=1; j<=q; j++)
    {
        cin>>cmd;
        scin2(x,y);
        if(cmd == "MULTIPLY")
        {
            scin(val);
            mask = Primefactorize(val);
            update(1,1,n,x,y,val,mask);
        }
        else
        {
            pll ret = query(1,1,n,x,y);
            ans = ret.first;
            mask = ret.second;
            for(i=0;i<64;i++)
            {
                if(check(mask,i) == 1)
                {
                    temp = ((ll)(Prime[i]-1)*ModIn[i])%MOD;
                    ans = (ans*temp)%MOD;
                }
            }
            pf("%lld\n",ans%MOD);
        }
    }
    return 0;
}
