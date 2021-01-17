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

/** MaxFlow Template(Ford Fulkerson's Algorithm)
    FAQ:
    ১) একাধিক সোর্স বা সিংক থাকলে কি করতে হবে?
    -> একটি সুপার সোর্স এবং একটি সুপার সিংক বানিয়ে নিতে হবে। সুপার সোর্স এর সাথে মূল গ্রাফের সোর্সগুলোর এজ ক্যাপাসিটি হবে ইনফিনিটি এবং সুপার সিংক এর সাথে মূল গ্রাফের সিংক গুলোর এজ ক্যাপাসিটি হবে ইনফিনিটি। ফ্লো কল দিতে হবে সুপার সোর্স থেকে সুপার সিংক এ । (উদাঃ সুপার সোর্স ০ এবং সুপার সিংক n+1)

    ২)  নোড ক্যাপাসিটি দেয়া থাকলে কি করতে হবে?
    -> নোডটা কে দুই ভাগে ভাগ করে ফেলবো। ভাগ দুইটি কে নতুন এজ দিয়ে সংযুক্ত করবো। যেই এজের ক্যাপাসিটি হবে ওই নোডের ক্যাপাসিটির সমান।
    যেমনঃ n সংখ্যক নোডের একটা গ্রাফে একটা নোড যদি I হয় এবং তার ক্যাপাসিটি যদি c হয় তবে নোডটাকে ভাঙ্গলে দুইটা নোড পাবো
    I এবং n+I । এবং এদের এজ ক্যাপাসিটি হবে c .
    আমরা A নোডটা Ain এবং Aout এই দুটি নোডে ভাগ করেছি। এখন আসল গ্রাফ যতগুলো এজ A তে প্রবেশ করেছে সেগুলো প্রবেশ করবে Ain এ এবং আসল গ্রাফে যতগুলো এজ A থেকে বাইরে গিয়েছে সেগুলো এখন বাইরে যাবে Aout থেকে। Ain থেকে Aout এ একটা এজ প্রবেশ করবে যেটার ক্যাপাসিটি হবে এজ এর ক্যাপাসিটির সমান।
    একটা নোডকে স্প্লিট করলে তাদের মধ্যকার এজ অবশ্যই ডিরেক্টেড হবে। গ্রাফ ডিরেক্টেড হোক কিংবা আনডিরেক্টেড হোক। 

    ৩) দুই বন্ধু একই নোড থেকে যাত্রা শুরু করে একই গন্তব্যে পৌছাতে চায় কিন্তু দুইজনেই চায় ভিন্ন ভিন্ন রাস্তা ব্যবহার করে যেতে, তারমানে একই এজ কখনো ২জন ব্যবহার করতে পারবে না। এধরণের পথকে এজ ডিসজয়েন্ট পাথ বলে। তোমাকে বলতে হবে কোনো একটা গ্রাফে দুটি এজ ডিসজয়েন্ট পাথ আছে নাকি?

    -> সাধারণ ম্যাক্স-ফ্লো ব্যবহার করেই এজ ডিসজয়েন্ট পাথ বের করা যায়। শুরুর নোডকে সোর্স এবং গন্তব্য নোডকে সিংক ধরবে। এবার সবগুলো এজ এর ক্যাপাসিটি বানিয়ে দাও ১ এর সমান। এখন যদি তুমি সোর্স থেকে সিংকে দুই ফ্লো পাঠাতো পারো সেটার মানে হলো দুটি ডিসজয়েন্ট পাথ আছে। প্রতিটা এজের ক্যাপাসিটি ১ হওয়াতে ২ ফ্লো যে দুটি পথে গিয়েছে তাদের মধ্যে কমন এজ থাকা সম্ভব না।
    ঠিক একই ভাবে তুমি একটা গ্রাফে সর্বোচ্চ কয়টা ডিসজয়েন্ট পাথ থাকা সম্ভব অথবা দুই বন্ধুর জায়গায় K টা বন্ধু থাকলে কি হতো বের করে ফেলতে পারবে।
    
    ৪) Min Cut = Max Flow
    মোট সর্বনিম্ন কত কস্টের এজ রিমুভ করলে একটা গ্রাফে সোর্স এবং সিংক ডিসকানেক্ট হয়ে যায় সেটিই হচ্ছে Min Cut.
    Cut Set: A set of edges which when removed, the source and sink gets disconnected.
    Cost of Cut Set: Summation of the capacities of edges in the cut set.
    Min Cut: The cut set with minimum cost.
    
    ৫)  Bipartite Graph: A bipartite graph is a graph whose vertices can be divided into two independent sets U and V such that every edge(u,v) either connects to a 
        vertex from U to V or V to U. And there is no edge that connect vertices of same set.
        Bipartite Graph is a bi-colorable graph.
        
        Bipartite Matching(BPM): A matching in a bipartite graph is a set of edges chosen in such a way that no two edges share an endpoint.
        Max BPM = Max Flow
    
    ৬)  Independent Set: Independent set is a set of nodes from a bipartite graph such that no two nodes from this set are connected.
        Maximum Size of Independent Set = Total node - Max BPM
    
    ৭)  Vertex Cover: Choose minimum number of vertex such that every edges of this graph is connected with any of those vertex.
        Vertex Cover = Max BPM
    
    ৮)  Edge Cover: Choose minimum number of edges such that every node of this graph is an endpoint of any of those edges.
        Edge Cover = n - Max BPM
**/

#define sz 105
bool vis[sz];
int n,e,cap[sz][sz],flow[sz][sz],par[sz];

bool BFS(int src,int des)   /** Return true if there is a path from source to destination.Also,fills parent[] to store the path **/
{
    ms(vis,0);
    queue<int>q;
    q.push(src);
    vis[src] = 1;
    par[src] = -1;

    while(!q.empty()){  /** Standard BFS Code using adjacency matrix **/
        int u = q.front();
        q.pop();
        for(int v=1 ; v<=n ; v++){
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
        for(v=des ; v!=src ; v=par[v]){ /** Traverse the path & find out minimum edge capacity **/
            u = par[v];
            mnPathFlow = min(mnPathFlow , cap[u][v]-flow[u][v]);
        }
        for(v=des ; v!=src ; v=par[v]){ /** Update the flow for every edge of the path **/
            u = par[v];
            flow[u][v] += mnPathFlow;
            flow[v][u] -= mnPathFlow;
        }
        mxFlow += mnPathFlow;
    }
    return mxFlow;
}

int main()
{
    int i,j,k,u,v,c,src,des,ans;
    ms(cap,0);
    ms(flow,0);
    cin>>n;
    cin>>src>>des>>e;
    for(i=1 ; i<=e ; i++){
        cin>>u>>v>>c;
        cap[u][v] += c;
        cap[v][u] += c;  /** This line means that the graph is bidirectional.If the graph is unidirectional & there're no edge v-u the cap[v][u]=0  **/
    }
    ans = FordFulkerson(src,des);
    cout<<ans<<endl;
    return 0;
}

