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
#define MOD                     1000000000000037
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
//vector<int>Prime;bool mark[1000009];
//void sieve(int n){int i,j,limit=sqrt(n*1.0)+2;mark[1]=1;for(i=4; i<=n; i+=2)mark[i]=1;Prime.push_back(2);for(i=3; i<=n; i+=2){if(!mark[i]){Prime.push_back(i);if(i<=limit){for(j=i*i; j<=n; j+=(i*2))mark[j]=1;}}}}
//vector<int>List;
//void Primefactorize(int n){for(int i=0; Prime[i]*Prime[i]<=n ; i++){if(n%Prime[i] == 0){while(n%Prime[i] == 0){List.push_back(Prime[i]);n/=Prime[i];}}}if(n>1)List.push_back(n);}

/** Order Set **/
//#include <ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;
//template<typename T> using orderset = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
//orderset<int> s ; //orderset<int>::iterator it ;
//orderset<int> X; //X.insert(1); //X.insert(2); //X.insert(4); //X.insert(8); //X.insert(16);
//cout<<*X.find_by_order(1)<<endl; // 2 //cout<<*X.find_by_order(2)<<endl; // 4 //cout<<*X.find_by_order(4)<<endl; // 16 //cout<<(end(X)==X.find_by_order(6))<<endl; // true
//cout<<X.order_of_key(-5)<<endl;  // 0 //cout<<X.order_of_key(1)<<endl;   // 0 //cout<<X.order_of_key(3)<<endl;   // 2 //cout<<X.order_of_key(4)<<endl;   // 2 //cout<<X.order_of_key(400)<<endl; // 5

set<ll>difx,dify;
set<ll>xx,yy;
vector<ll>xox,yoy;
set<ll>::iterator it;
map<ll,ll>frex,frey;
map<ll,ll>leftx,rightx,lefty,righty;
ll id[100005],pos[100005],ans[100005];
void Clean()
{
    difx.clear();
    dify.clear();
    xx.clear();
    yy.clear();
    xox.clear();
    yoy.clear();
    frex.clear();
    frey.clear();
    leftx.clear();
    rightx.clear();
    lefty.clear();
    righty.clear();
    ms(id,0);
    ms(pos,0);
    ms(ans,0);
}
ll n,m;
void Take_Query(int q)
{
    xx.insert(0);
    xx.insert(n);
    yy.insert(0);
    yy.insert(m);
    for(int i=1; i<=q; i++)
    {
        scln2(id[i],pos[i]);
        if(id[i] == 0)
        {
            xx.insert(pos[i]);
            frex[pos[i]]++;
        }
        else
        {
            yy.insert(pos[i]);
            frey[pos[i]]++;
        }
    }
}
void Process_X()
{
    for(int i=0; i<xox.size(); i++)
    {
        if(i>=1)
        {
            difx.insert(abs(xox[i]-xox[i-1]));
        }
        if(i==0)
            leftx[0]=0;
        else
            leftx[xox[i]]=xox[i-1];
        if(i == xox.size()-1)
            rightx[xox[i]]=xox[i];
        else
            rightx[xox[i]]=xox[i+1];
    }
}
void Process_Y()
{
    for(int i=0; i<yoy.size(); i++)
    {
        if(i>=1)
        {
            dify.insert(abs(yoy[i]-yoy[i-1]));
        }
        if(i==0)
            lefty[0]=0;
        else
            lefty[yoy[i]]=yoy[i-1];
        if(i == yoy.size()-1)
            righty[yoy[i]]=yoy[i];
        else
            righty[yoy[i]]=yoy[i+1];
    }
}
int main()
{
    int i,j,k,t,T,q;
    scin(T);
    ll x,y,temp;
    RUN_CASE(t,T)
    {
        Clean();
        scln2(n,m);
        scin(q);
        Take_Query(q);
        copy(xx.begin(),xx.end(),inserter(xox,xox.end()));
        copy(yy.begin(),yy.end(),inserter(yoy,yoy.end()));
        Process_X();
        Process_Y();
        it=difx.end();
        it--;
        x=*it;
        it=dify.end();
        it--;
        y=*it;
        for(i=q; i>=1; i--)
        {
            ans[i]=x*y;
            /** Erase the line **/
            if(id[i] == 0)
            {
                frex[pos[i]]--;
                if(frex[pos[i]] == 0)
                {
                    if(abs(rightx[pos[i]]- leftx[pos[i]]) > x)
                        x = abs(rightx[pos[i]]- leftx[pos[i]]);
                    temp=leftx[pos[i]];
                    rightx[temp]=rightx[pos[i]];
                    temp=rightx[pos[i]];
                    leftx[temp]=leftx[pos[i]];
                    leftx[pos[i]]=-1;
                    rightx[pos[i]]=-1;
                }
            }
            else
            {
                frey[pos[i]]--;
                if(frey[pos[i]] == 0)
                {
                    if(abs(righty[pos[i]]- lefty[pos[i]]) > y)
                        y = abs(righty[pos[i]]- lefty[pos[i]]);
                    temp=lefty[pos[i]];
                    righty[temp]=righty[pos[i]];
                    temp=righty[pos[i]];
                    lefty[temp]=lefty[pos[i]];
                    lefty[pos[i]]=-1;
                    righty[pos[i]]=-1;
                }
            }
        }
        for(i=1; i<=q; i++)
            pf("%lld\n",ans[i]);
    }
    return 0;
}
