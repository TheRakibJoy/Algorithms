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
///const int fx[] = {+0,+0,+1,-1,-1,+1,-1,+1}; ///King's move
///const int fy[] = {-1,+1,+0,+0,+1,+1,-1,-1}; ///King's move
///const int fx[] = {-2,-2,-1,-1,+1,+1,+2,+2}; ///Knight's move
///const int fy[] = {-1,+1,-2,+2,-2,+2,-1,+1}; ///Knight's move

/**
প্রব্লেমঃ
একটা 2D গ্রিডের কিছু কিছু সেল এ গোল্ড আছে। 2*1 সাইজের টাইলস আছে যেগুলোকে আড়াআড়ি অথবা লম্বভাবে বসানো যায়। একটা টাইলস আরেকটা টাইলস কে ওভারলেপ করতে পারে। আমার কাজ হচ্ছে মিনিমাম কয়টা টাইলস ব্যাবহার করে সবগুলো গোল্ডকে ঢেকে ফেলা যায় বের করা?
আইডিয়াঃ
প্রব্লেমটা কে একটা জানা প্রব্লেমে কনভার্ট করার চেষ্টা করি।
→	 গ্রিড টা কে গ্রাফ চিন্তা করলে এটি কি বাইপার্টাইট গ্রাফ?
হ্যাঁ,এটি বাইপারটাইট গ্রাফ। 2D গ্রিড মানেই চেসবোর্ড , আর চেসবোর্ড বাইকালারেবল। তার মানে এটি একটি বাইপার্টাইট গ্রাফ। অর্থাৎ, পাশাপাশি দুইটি সেল একই কালার এর হতে পারবে না। মানে, পাশাপাশি নোড দুইটা বাইপার্টাইট গ্রাফের ২ সেটের নোড।
একটা 2*1 টাইলস দ্বারা পাশাপাশি দুইটা নোডকে ঢাকা যায়। অর্থাৎ, একটা টাইলস বাইপার্টাইট গ্রাফের দুই সেটের দুই নোডকে যুক্ত করে তাদের মাঝে এজ এর ভূমিকা নিয়ে।
তার মানে, আমার কাজ হলো মিনিমাম সংখ্যক এজ দ্বারা নোডগুলোকে যুক্ত করা! অর্থাৎ, এটি একটি এজ কাভার প্রব্লেম!!!
এজ কাভার প্রব্লেমের ক্ষেত্রে মিনিমাম এজ = n - ম্যাক্স BPM । প্রব্লেম সলভড!
**/

const int fx[] = {+1,-1,+0,+0};
const int fy[] = {+0,+0,+1,-1};
#define sz 505
bool vis[sz];
int row,col,totnode,no[25][25],par[sz],cap[sz][sz],flow[sz][sz];
vi graph[sz];
char grid[25][25];

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
    while(BFS(src,des)){
        int mnPathFlow = infinity;
        for(v=des ; v!=src ; v=par[v]){
            u = par[v];
            mnPathFlow = min(mnPathFlow , (cap[u][v]-flow[u][v]));
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
    ms(no , 0);
    for(int i=0 ; i<=totnode+1 ; i++){
        graph[i].clear();
        for(int j=i ; j<=totnode+1 ; j++){
            cap[i][j] = 0; cap[j][i]=0;
            flow[i][j]=0; flow[j][i]=0;
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
//    Output;
    int i,j,k,t,T,mxBPM,ans,x,y,xx,yy;
    scin(T);
    RUN_CASE(t,T)
    {
        totnode = 0;
        scin2(row,col);
        getchar();
        /** Connect every gold those are in white cell(according to chess board) with global source-0 ; We know, in chessboard cell(i,j) is white if (i+j)%2==0 or black otherwise **/
        for(i=0 ; i<row ; i++){
            sc("%s",grid[i]);
            for(j=0 ; j<col ; j++){
                x = i+1 ; y = j+1;
                if(grid[i][j] == '*'){
                    no[i][j] = ++totnode;
                    if((x+y)%2 == 0){
                        cap[0][no[i][j]] = 1;
                        addEdge(0 , totnode);
                    }
                }
            }
        }
        totnode++;  /// Global sink
        for(i=0 ; i<row ; i++){
            for(j=0 ; j<col ; j++){
                x=i+1 ; y=j+1;
                if(grid[i][j]=='*' && (x+y)%2==1){  /** Connect every gold those are in black cell with global sink **/
                    cap[no[i][j]][totnode] = 1;
                    addEdge(no[i][j] , totnode);
                }
                if(grid[i][j]=='*'){
                    for(k=0 ; k<4 ; k++){
                        xx = i+fx[k];
                        yy = j+fy[k];
                        if(xx>=0 && xx<row && yy>=0 && yy<col && (x+y)%2==0 && grid[xx][yy]=='*'){    /** If present cell is white cell then connect it with its black adjacent cell with edge capacity 1 because white cell get flow 1 from global source and will supply it to global sink via black cell . **/
                            cap[no[i][j]][no[xx][yy]] = 1;
                            addEdge(no[i][j] , no[xx][yy]);
                        }
                    }
                }
            }
        }
        mxBPM = FordFulkerson(0 , totnode);
        int gold = totnode-1;
        ans = gold - mxBPM;
        pf("Case %d: %d\n",t,ans);
        Clean();
    }
    return 0;
}


