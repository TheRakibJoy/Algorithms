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
একটা 2D গ্রিডে অনেকগুলো বরফের টুকরা আছে। প্রত্যেক বরফের টুকরাতে কিছু পেঙ্গুইন n[i] থাকতে পারে। একটা পেঙ্গুইন সর্বোচ্চ D দূরত্ব লাফ দিয়ে পার হতে পারে। একটা বরফের টুকরা থেকে সর্বোচ্চ m[i] সংখ্যক পেঙ্গুইন পরবর্তী বরফের টুকরার উদ্দেশ্যে লাফ দিতে পারে। কিন্তু একটা বরফের টুকরাতে অসীম সংখ্যক পেঙ্গুইন ল্যান্ড করতে পারে। তোমাকে বলতে হবে কোন কোন বরফের টুকরাতে সকল পেঙ্গুইন সাক্ষাৎ করতে পারে?
আইডিয়াঃ
এই প্রব্লেমে আমরা পেঙ্গুইন গুলোকে ফ্লো ধরবো। কমপক্ষে একটি পেঙ্গুইন আছে এমন বরফের টুকরা গুলো হবে সোর্স।
১) প্রত্যক সোর্স গ্লোবাল সোর্স এর সাথে যুক্ত হবে এবং এজ ক্যাপাসিটি হবে ওই সোর্সের পেঙ্গুইন এর সংখ্যা n[i].
২) প্রত্যেক নোড (আইস কিউব) কে দুইটা নোডে স্প্লিট করা হবে যেখানে এজ ক্যাপাসিটি হবে ওই নোড থেকে সর্বোচ্চ কতগুলো পেঙ্গুইন লাফ দিতে পারে m[i].
৩) এখন প্রত্যেকটা আইস নোড (আইস কিউব) অন্য নডগুলোর সাথে যুক্ত হবে যদি এদের মধ্যকার দূরত্ব D এর থেকে কম হয়। এবং এক্ষেত্রে এজ ক্যাপাসিটি হবে অসীম।
৪) এখন আমি একটা একটা করে আইস কিউব কে সিংক ধরে দেখবো এই আইস কিউব এ যেই ফ্লো পাই তা মোট পেঙ্গুইন এর সংখ্যার সমান কি না? যদি সমান হয় তাহলে এই আইস কিউব মিটিং এর জন্য একটি ভ্যালিড স্থান এবং তা এন্সার ভেক্টরে যোগ হবে।
→	এখন আমি যেই আইস কিউব টা কে সিংক ধরছি তার স্প্লিটিং এজ এর ক্যাপাসিটি বানিয়ে দিবো অসীম। কারণ, এই কিউবে সকল পেঙ্গুইন ল্যান্ড করবে, কেউ এখান থেকে লাফ দিবে না। আর একটা আইস কিউব এ অসীম সংখ্যক পেঙ্গুইন ল্যান্ড করতে পারে।
→	এরপর একে যুক্ত করবো গ্লোবাল সিংক এর সাথে। এবং এজ ক্যাপাসিটি হবে অসীম।
→	এরপর আমি ম্যাক্সফ্লো কল দিবো।
→	এরপর আবার এই আইস কিউব এর সাথে গ্লোবাল সিংক এর ক্যাপাসিটি ০ করে দিবো।
→	এরপর আবার এই আইস কিউব এর স্প্লিটিং এজ এর ক্যাপাশিটি m[i] করে দিবো। কারণ পরবর্তীতে এই কিউবে কোন পেঙ্গুইন আসা মানে সে এই কিউব থেকে লাফ দিয়ে অন্য কিউবে যাবে শুধু ল্যান্ড করেই ক্ষান্ত হবে না। আর একটা আইস কইবে সর্বোচ্চ m[i] সংখ্যক পেঙ্গুইন লাফ দিতে পারবে।
এর বেশি দিলে আইস কিউব ভেঙ্গে সোজা সাগরের তলায় হিম শীতল পানিতে -_-
**/

#define sz 205
bool vis[sz];
int n,e,x[sz],y[sz],peng[sz],icecap[sz],par[sz],cap[sz][sz],flow[sz][sz];
vi graph[sz];
bool BFS(int src,int des)
{
    ms(vis , 0);
    queue<int>q;
    q.push(src);
    vis[src] = 1;
    par[src] = -1;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int i=0 ; i<(int)graph[u].size() ; i++){
            int v = graph[u][i];
            if(!vis[v] && (cap[u][v]-flow[u][v])>0){
                q.push(v);
                vis[v] = 1;
                par[v] = u;
            }
        }
    }
    return vis[des];
}
int FordFulkerson(int src,int des)
{
    int u,v,mxFlow=0;
    while(BFS(src , des)){
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
    for(int i=0 ; i<=n+1 ; i++){
        for(int j=i ; j<=n+1 ; j++){
            cap[i][j] = 0;  cap[j][i]=0;
            flow[i][j] = 0; flow[j][i]=0;
        }
        graph[i].clear();
    }
}
void addEdge(int u,int v)
{
    graph[u].pb(v);
    graph[v].pb(u);
}
int main()
{
    int i,j,k,t,T,num,totpeng;
    scin(T);
    RUN_CASE(t,T)
    {
        vi ans;
        totpeng = 0;
        double dis,tempdis;
        sc("%d %lf",&num,&dis);
        n = num;
        for(i=1 ; i<=num ; i++){
            sc("%d %d %d %d",&x[i],&y[i],&peng[i],&icecap[i]);
            if(peng[i] > 0){
                cap[0][i] = peng[i];    /** IF there're penguin, then connect it with global source with edge cost peng[i] ; This edge will unidirectional **/
                graph[0].pb(i);
            }
            cap[i][num+i] = icecap[i];   /** Split the edge with icecap[i] edge cost because at most icecap[i] penguins can jump from this ice floe(Note that landing on an ice floe haven't any cost). And splitting is always unidirectional **/
            graph[i].pb(num+i);
            totpeng += peng[i];
        }

        n += num;   /** n is equal to twice num for splitting node(ice cube) **/

        for(i=1 ; i<=num ; i++){
            for(j=i+1 ; j<=num ; j++){
                    tempdis = sqrt((double)(x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j]));
                    if(tempdis <= dis){ /** If distance between node i & j is less than D , then infinite number of penguins can go from node i to node j; This edge is bidirectional **/
                        cap[i+num][j] = infinity;   /** Ending point of node i is connected with starting point of node j **/
                        cap[j+num][i] = infinity;   /** Ending point of node j is connected with starting point of node i **/
                        addEdge(i+num , j);
                        addEdge(j+num , i);
                }
            }
        }

        n += 1;     /** n increased for global sink **/

        bool fg = 0;
        pf("Case %d:",t);
        for(i=1 ; i<=num ; i++){
            ms(flow , 0);
            cap[i][num+i] = infinity;       /** Landing on destination node haven't any cost. So, infinite number of penguins can go to global sink via this node **/
            cap[i+num][n] = infinity;      /** Only this node/sink will connected to the global sink, bcoz we want to know all the penguins can meet on this node or not? **/
            graph[i+num].pb(n);

            int temp = FordFulkerson(0 , n);

            cap[i][num+i] = icecap[i];
            cap[i+num][n] = 0;

            if(temp >= totpeng){
                pf(" %d",i-1);
                fg = 1;
            }
        }
        (fg==1)? pf("\n") : pf(" -1\n");
        Clean();
    }
    return 0;
}

