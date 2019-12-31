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
//ll BigMod(ll a,ll b){if(b == 0)return 1%MOD;else if(b%2 == 0){ll temp=BigMod(a,b/2);return ((temp%MOD)*(temp%MOD))%MOD;}else{return ((a%MOD)*BigMod(a,b-1)%MOD)%MOD;}}
//ll Power(ll a,ll n){ll ret=1;for(ll i=1 ; i<=n ; i++)ret = ((ret%MOD)*(a%MOD))%MOD;return ret;}
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

/**
প্রব্লেমঃ
তোমাকে n সংখ্যক ইন্টিজারের একটি সেট A এবং m সংখ্যক ইন্টিজারের একটি সেট B দেয়া থাকবে। A সেট থেকে k1 সংখ্যক এবং B সেট থেকে k2 সংখ্যক এলিমেন্ট ডিলিট করতে হবে যেনো B সেটের অবশিষ্ট কোন এলিমেন্ট A সেটের অবশিষ্ট কোন এলিমেন্ট এর মাল্টিফল না হয়। (k1+k2) সর্বনিম্ন হতে হবে।
আইডিয়াঃ
প্রদত্ত ইনপুট দিয়ে একটি বাইপারটাইট গ্রাফ বানানো যায়।
→	A সেটের কোন এলিমেন্ট যদি B সেটের কোন এলিমেন্ট এর ডিভিজর হয় তবে নোড দুটি কানেক্ট করবো। এজ ক্যাপাসিটি হবে ১।
→	এরপর A সেটের প্রত্যেক নোডকে একটি গ্লোবাল সোর্স এর সাথে কানেক্ট করবো এবং ক্যাপাসিটি হবে ১।
→	এরপর B সেটের প্রত্যেক নোডকে একটি গ্লোবাল সিংক এর সাথে কানেক্ট করবো এবং ক্যাপাসিট হবে ১।
এখন সোর্স থেকে সিংক এ ফ্লো এর মান হবে বাইপারটাইট গ্রাফে ম্যাক্সিমাম ম্যাচিং। আর যতগুলো ম্যাচ আছে ততোগুলো নোড যেকোন সেট থেকে ডিলিট করে দিলেই আর কোন ম্যাচ থাকবে না। অর্থাৎ , B এর কোন এলিমেন্ট আর A এর কোন এলিমেন্ট এর মাল্টিফল হবে না।
**/
/** এডজাসেন্ট লিস্ট ব্যাবহার করলে গ্রাফ ইউনিডিরেকশনাল হোক কিংবা বাইডিরেকহনাল, এজ দুইদিকেই যুক্ত করতে হবে। কারণ, ম্যাক্স ফ্লো তে ব্যাক এজ ব্যাবহার করে অপ্টিমাল সল্যুশন বের করতে হয়। ইউনিডিরেকশনাল হলে ক্যাপাসিটি এরে একমুখী হবে। তার মানে গ্রাফ একমুখী। এজন্য, লিস্টে দুইদিকে এজ যুক্ত করলেও সমস্যা হবে না। বরং দুইদিকে যুক্ত না করলে কাজ করবে না।  **/
#define sz 211
bool vis[sz];
int n,e,ara[sz],bra[sz],par[sz],cap[sz][sz],flow[sz][sz];
vi graph[sz];

bool BFS(int src,int des)
{
    ms(vis , 0);
    queue<int>q;
    q.push(src);
    par[src] = -1;
    vis[src] = 1;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int i=0 ; i<(int)graph[u].size() ; i++){
            int v = graph[u][i];
            if(!vis[v] && (cap[u][v]-flow[u][v])>0){
                q.push(v);
                par[v] = u;
                vis[v] = 1;
            }
        }
    }
    return vis[des];
}

int FordFulkerson(int src,int des)
{
    int u,v,mxFlow=0;
    while(BFS(src,des)){
        int mnPathFlow = infinity;
        for(v=des ; v!=src ; v=par[v]){
            u = par[v];
            mnPathFlow = min(mnPathFlow , cap[u][v]-flow[u][v]);
        }
        for(v=des ; v!=src ; v=par[v]){
            u = par[v];
            flow[u][v] += mnPathFlow;
            flow[v][u] -= mnPathFlow;
        }
        mxFlow += mnPathFlow;
    }
    return mxFlow;
}
void Clean()
{
    for(int i=0 ; i<=n+5 ; i++){
        graph[i].clear();
        for(int j=i ; j<=n+5 ; j++){
            cap[i][j] = 0;cap[j][i] = 0;
            flow[i][j] = 0;flow[j][i] = 0;
        }
    }
}
void addEdge(int u,int v)
{
    graph[u].pb(v);
    graph[v].pb(u);
}
int main()
{
    int i,j,k,ans,n1,n2,t,T,u,v;
    scin(T);
    RUN_CASE(t,T)
    {
        scin(n1);
        rep(i,1,n1)scin(ara[i]);
        scin(n2);
        rep(i,1,n2)scin(bra[i]);
        /** Connect all nodes of set A with global source ; Unidirectional ; node of set A is numbered from 1 to n1 **/
        for(i=1 ; i<=n1 ; i++){
            cap[0][i] = 1;
            addEdge(0 , i);
        }
        /** Connect node of set A with node of set B ; Unidirectional ; node of set B is numbered from n1+1 to n1+n2 **/
        for(i=1 ; i<=n1 ; i++){
            for(j=1 ; j<=n2 ; j++){
                if((bra[j]/ara[i])*ara[i] == bra[j]){
                    cap[i][n1+j] = 1;
                    addEdge(i , n1+j);
                }
            }
        }
        n = n1+n2+1;
        /** Connect all nodes of set B with global sink ; Unidirectional **/
        for(i=1 ; i<=n2 ; i++){
            cap[i+n1][n] = 1;
            addEdge(i+n1 , n);
        }

        ans = FordFulkerson(0 , n);
        pf("Case %d: %d\n",t,ans);
        Clean();
    }
    return 0;
}
/**
1
2 2 4
2 4 2
**/
