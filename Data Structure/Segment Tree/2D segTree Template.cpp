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

/** 2D Segment Tree template - 01 **
/** Sum query of a sub rectangle of the matrices and update an element of given matrices **/

#define sz 101
int n,m,mat[sz][sz],tree[4*sz][4*sz];
void initY(int nodeX,int bX,int eX,int nodeY,int bY,int eY)
{
    if(bY == eY)
    {
        if(bX == eX)    /** We r working on a single row ; we can directly generate segTree for row = bX **/
            tree[nodeX][nodeY] = mat[bX][bY];
        else            /** We r working on multiple row ; We r creating parent segTree from two child segTree which contains sum from row(bX to eX) **/
            tree[nodeX][nodeY] = tree[nodeX*2][nodeY] + tree[nodeX*2+1][nodeY];
        return;
    }
    int midY = (bY+eY)/2;
    initY(nodeX , bX , eX , 2*nodeY , bY , midY);
    initY(nodeX , bX , eX , 2*nodeY+1 , midY+1 , eY);
    tree[nodeX][nodeY] = tree[nodeX][nodeY*2] + tree[nodeX][nodeY*2+1];
}
void initX(int nodeX,int bX,int eX)
{
    if(bX == eX)
    {
        initY(nodeX, bX, eX, 1, 1, m);
        return;
    }
    int midX=(bX+eX)/2;
    initX(2*nodeX , bX , midX);
    initX(2*nodeX+1, midX+1 , eX);
    initY(nodeX , bX , eX , 1 , 1 ,m);  /** Merge segment trees of two rows to create parent segment tree **/
}
int sumQueryY(int nodeX,int nodeY,int bY,int eY,int ly,int ry)
{
    if(ly > ry)
        return 0;
    if(ly==bY && ry==eY)
        return tree[nodeX][nodeY];
    int midY = (bY+eY)/2;
    int ret1 = sumQueryY(nodeX , nodeY*2 , bY , midY , ly , min(ry,midY));
    int ret2 = sumQueryY(nodeX , nodeY*2+1 , midY+1 , eY , max(ly,midY+1) , ry);
    return ret1+ret2;
}
int sumQueryX(int nodeX,int bX,int eX,int lx,int rx,int ly,int ry)
{
    if(lx > rx)
        return 0;
    if(lx==bX && rx==eX)
        return sumQueryY(nodeX , 1 , 1 , m , ly , ry);
    int midX = (bX+eX)/2;
    int ret1 = sumQueryX(nodeX*2 , bX , midX , lx , min(rx,midX) , ly , ry);
    int ret2 = sumQueryX(nodeX*2+1 , midX+1 , eX , max(lx,midX+1) , rx , ly , ry);
    return ret1+ret2;
}
void updateY(int nodeX,int bX,int eX,int nodeY,int bY,int eY,int x,int y,int val)
{
    if(bY == eY)
    {
        if(bX == eX)
            tree[nodeX][nodeY] = val;
        else
            tree[nodeX][nodeY] = tree[nodeX*2][nodeY] + tree[nodeX*2+1][nodeY];
        return;
    }
    int midY = (bY+eY)/2;
    if(y <= midY)
        updateY(nodeX , bX , eX , nodeY*2 , bY , midY , x , y , val);
    else
        updateY(nodeX , bX , eX , nodeY*2+1 , midY+1 , eY , x , y , val);
    tree[nodeX][nodeY] = tree[nodeX][nodeY*2]+tree[nodeX][nodeY*2+1];   ///Merge two columns
}
void updateX(int nodeX,int bX,int eX,int x,int y,int val)
{
    if(bX == eX)
    {
        updateY(nodeX , bX , eX , 1 , 1 , m , x , y , val);
        return;
    }
    int midX = (bX+eX)/2;
    if(x <= midX)
        updateX(nodeX*2 , bX , midX , x , y , val);
    else
        updateX(nodeX*2+1 , midX+1 , eX , x , y , val);
    updateY(nodeX , bX , eX , 1 , 1, m , x , y , val);      ///Merge two rows
}
int main()
{
    int i,j,k,q,x1,y1,x2,y2,ans,val,id;
    scin2(n,m);
    for(i=1 ; i<=n ; i++)
    {
        for(j=1 ; j<=m ; j++)
            scin(mat[i][j]);
    }
    initX(1,1,n);
    scin(q);
    for(i=1 ; i<=q ; i++)
    {
        scin(id);
        if(id == 0) ///Update
        {
            scin2(x1,y1);
            scin(val);
            updateX(1 , 1 ,n , x1, y1 , val);
        }
        else        ///Sum Query
        {
            scin2(x1,y1);
            scin2(x2,y2);
            ans = sumQueryX(1 , 1 , n , x1 , x2 , y1 , y2);
            cout<<ans<<endl;
        }
    }
    return 0;
}
/**
3 4
1 2 3 4
5 6 7 8
9 10 11 12
50
1 1 1 4
2 1 2 4
3 1 3 4
**/
