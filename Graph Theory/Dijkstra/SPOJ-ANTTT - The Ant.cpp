/**-----------------
The function det(Two points of a line, two pints of another line) return if two points A(p1,q1) and
B(p2,q2) intersect each other
It is solution of this cf problem: http://codeforces.com/contest/994/problem/C
*/
#include<bits/stdc++.h>

#define ll              long long int
#define ull             unsigned long long int
#define pii             pair < int, int>
#define pll             pair < ll, ll>
#define sc              scanf
#define scin(x)         sc("%d",&(x))
#define scin2(x,y)                sc("%d %d",&(x),&(y))
#define scln(x)         sc("%lld",&(x))
#define pf              printf
#define ms(a,b)         memset(a,b,sizeof(a))
#define pb(a)           push_back(a)
#define mp              make_pair
#define db              double
#define EPS             10E-10
#define ff              first
#define ss              second
#define sqr(x)          (x)*(x)
#define vi              vector< int >
#define vl              vector< ll >
#define vii             vector<vector< int > >
#define vll             vector<vector< ll > >
#define DBG             pf("HI\n")
#define MOD             1000000007
#define CIN             ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define RUN_CASE(t,T)   for(__typeof(t) t=1;t<=T;t++)
#define CASE(t)         printf("Case %d: ",t)
#define CASEL(t)        printf("Case %d:\n",t)
#define intlimit        2147483648
#define longlimit       9223372036854775808
#define infinity        (1<<28)
#define gcd(a, b)       __gcd(a,b)
#define lcm(a, b)       ((a)*(b)/gcd(a,b))
#define mx              1234567899
#define PI              2*acos(0.0)
#define all(v)          v.begin(),v.end()
#define rep(i,a,b)      for(__typeof(i) i=a; i<=b; i++)
#define rev(i,a,b)      for(__typeof(i) i=a; i>=b; i--)

using namespace std;

template<typename T>inline T POW(T B,T P)
{
    if(P==0)
        return 1;
    if(P&1)
        return B*POW(B,P-1);
    else
        return sqr(POW(B,P/2));
}
ll Bigmod(ll base, ll power, ll mod)
{
    if(power==0)
        return 1%mod;
    if(power==1)
        return base%mod;
    ll x = Bigmod(base,power/2,mod);
    x = (x*x)%mod;
    if(power%2)
    {
        x = (x*(base%mod))%mod;
    }
    return x;
}
ll Mulmod(ll base, ll power, ll mod)
{
    if(power==0)
        return 0;
    if(power==1)
        return base%mod;
    ll x = Mulmod(base,power/2,mod);
    x = (x+x)%mod;
    if(power%2)
    {
        x = (x+(base%mod))%mod;
    }
    return x;
}
bool isVowel(char ch)
{
    ch=toupper(ch);
    if(ch=='A'||ch=='U'||ch=='I'||ch=='O'||ch=='E')
        return true;
    return false;
}
ll ModInverse(ll number, ll mod)
{
    return Bigmod(number, mod-2, mod);
}
bool isConso(char ch)
{
    if (isalpha(ch) && !isVowel(ch))
        return true;
    return false;
}
int toInt(string s)
{
    int sm;
    stringstream ss(s);
    ss>>sm;
    return sm;
}
bool isPrime( ll val )
{
    if( val == 2 )
        return true ;
    if( val % 2 == 0 || val == 1 )
        return false ;
    ll sqrt_N = (ll) ( ( double ) sqrt( val ) ) ;
    for( ll i = 3 ; i <= sqrt_N ; i += 2 )
    {
        if( val % i == 0 )
            return false ;
    }
    return true ;
}
template<class T> string convert(T _input)
{
    stringstream blah;
    blah << _input;
    return blah.str();
}

/**
// Ordered set
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template<typename T> using orderset = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
//orderset<int> s ; //orderset<int>::iterator it ;
//orderset<int> X; //X.insert(1); //X.insert(2); //X.insert(4); //X.insert(8); //X.insert(16);
//cout<<*X.find_by_order(1)<<endl; // 2 //cout<<*X.find_by_order(2)<<endl; // 4 //cout<<*X.find_by_order(4)<<endl; // 16 //cout<<(end(X)==X.find_by_order(6))<<endl; // true
//cout<<X.order_of_key(-5)<<endl;  // 0 //cout<<X.order_of_key(1)<<endl;   // 0 //cout<<X.order_of_key(3)<<endl;   // 2 //cout<<X.order_of_key(4)<<endl;   // 2 //cout<<X.order_of_key(400)<<endl; // 5
*/

///--------------Graph Moves--------------------------------------
///const int fx[] = {+1,-1,+0,+0};
///const int fy[] = {+0,+0,+1,-1};
///const int fx[] = {+0,+0,+1,-1,-1,+1,-1,+1}; ///King's move
///const int fy[] = {-1,+1,+0,+0,+1,+1,-1,-1}; ///king's Move
///const int fx[] = {-2,-2,-1,-1,+1,+1,+2,+2}; ///knight's move
///const int fy[] = {-1,+1,-2,+2,-2,+2,-1,+1}; ///knight's move
///---------------------------------------------------------------

bool onSegment(pii p, pii q, pii r)
{
    if (q.ff <= max(p.ff, r.ff) && q.ff >= min(p.ff, r.ff) &&
            q.ss <= max(p.ss, r.ss) && q.ss >= min(p.ss, r.ss))
        return true;

    return false;
}

int orientation(pii p, pii q, pii r)
{
    // See https://www.geeksforgeeks.org/orientation-3-ordered-points/
    // for details of below formula.
    int val = (q.ss - p.ss) * (r.ff - q.ff) - (q.ff - p.ff) * (r.ss - q.ss);

    if (val == 0)
        return 0;  // colinear

    return (val > 0)? 1: 2; // clock or counterclock wise
}

bool det(pii p1,pii q1,pii p2, pii q2)
{
    int o1 = orientation(p1, q1, p2);
    int o2 = orientation(p1, q1, q2);
    int o3 = orientation(p2, q2, p1);
    int o4 = orientation(p2, q2, q1);

    // General case
    if (o1 != o2 && o3 != o4)
        return true;
    // Special Cases
    // p1, q1 and p2 are colinear and p2 lies on segment p1q1
    if (o1 == 0 && onSegment(p1, p2, q1))
        return true;

    // p1, q1 and q2 are colinear and q2 lies on segment p1q1
    if (o2 == 0 && onSegment(p1, q2, q1))
        return true;

    // p2, q2 and p1 are colinear and p1 lies on segment p2q2
    if (o3 == 0 && onSegment(p2, p1, q2))
        return true;

    // p2, q2 and q1 are colinear and q1 lies on segment p2q2
    if (o4 == 0 && onSegment(p2, q1, q2))
        return true;
    return false;
}

struct node
{
    int ax,ay,bx,by,index;
};

int vis[1005];
vi graph[1005];

void DFS(int s,int x)
{
    vis[s]=x;
    for(int i=0;i<graph[s].size();i++)
    {
        int v=graph[s][i];
        if(!vis[v])
            DFS(v,x);
    }
}

int main()
{
    int i,j,k,t,T,x,y,n,m;
    pii p1,p2,p3,p4;
    scin(T);
    RUN_CASE(t,T)
    {
        scin2(n,m);
        /** Design Graph **/
        node ara[n];
        for(i=0; i<n; i++)
        {
            ara[i].index=i+1;
            scin2(ara[i].ax,ara[i].ay);
            scin2(ara[i].bx,ara[i].by);
        }
        for(i=0; i<n; i++)
        {
            for(j=0; j<n; j++)
            {
                p1=make_pair(ara[i].ax,ara[i].ay);
                p2=make_pair(ara[i].bx,ara[i].by);
                p3=make_pair(ara[j].ax,ara[j].ay);
                p4=make_pair(ara[j].bx,ara[j].by);
                if(det(p1,p2,p3,p4) && i!=j)
                {
                    graph[ara[i].index].pb(ara[j].index);
                    graph[ara[j].index].pb(ara[i].index);
                }
            }
        }
        /** Process **/
        x=0;
        for(i=1;i<=n;i++)
        {
            if(!vis[i])
                DFS(i,++x);
        }
        for(i=1;i<=m;i++)
        {
            scin2(x,y);
            if(vis[x] == vis[y])
                pf("YES\n");
            else
                pf("NO\n");
        }
        /** Clear **/
        for(i=0;i<1005;i++)
        {
            graph[i].clear();
            vis[i]=0;
        }
    }
}
