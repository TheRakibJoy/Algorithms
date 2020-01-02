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
একটি 2D গ্রিডে অনেকগুলো মানুষ এবং অনেকগুলো ভূত আছে। কিছু সেল ফাকা এবং কিছু সেল ব্লকড। শুধুমাত্র ভূত গুলো তাদের অবস্থান পরিবর্তন করতে পারে। এক সেল থেকে আরেক সেলে যেতে তাদের ১মিনিট লাগে। একটি মানুষকে খেতে লাগে ২ মিনিট। একটি ভূত একজনের বেশি মানুষ খেতে পারে না।সর্বোচ্চ ৫০ টা ভূত থাকতে পারে। প্রত্যেক ভূত মানুষ খাওয়ার পর আবার তার আগের জায়গায় ফিরে যাবে। একই সময়ে সকল ভূত বের হবে শিকারের জন্য। বলতে হবে সর্বনিম্ন কত সময়ে সকল মানুষ খাওয়া শেষ হবে?
মানে, সর্বশেষ শিকার করা ভূতটা কত সময়ে তার জায়গায় ফিরে আসবে?
আইডিয়াঃ
ভূত সকল মানুষকে খেতে পারবে কি না? এই সাবটাস্ক কিভাবে করা যায়?
ভূতগুলোকে গ্লোবাল সোর্স এর সাথে এড করবো ১ ক্যাপাসিটি দিয়ে। এরপর মানুষগুলোকে এড করবো গ্লোবাল সিংক এর সাথে ১ ক্যাপাসিটি দিয়ে । এরপর ভূত এবং মানুষ এর মধ্যে এজ দিবো যদি ওই ভূত ওই মানুষের কাছে পৌছাতে পারে। এই বাইপার্টাইট গ্রাফ থেকে যদি মানুষের সংখ্যার সমান ফ্লো পাওয়া যায় তার মানে সবগুলো মানুষ খেতে পারবে।
এখন প্রব্লেম সিম্পল।
১) প্রথমে ভূতগুলোর লোকেশন সেইভ করে রাখবো। প্রত্যেক ভূত এর জন্য BFS চালিয়ে ওই ভূত থেকে সকল মানুষের দূরত্ব বের করে সেইভ করে রাখবো।
২) এরপর একটা বাইনারী সার্চ চালাবো, যার কাজ হবে রেজাল্ট জেনারেট করে দেখা এই সময়ে সকল মানুষ কে খাওয়া পসিবল কি না।
৩) একটা Possible ফাংশন লিখবো যে যাচাই করবে বাইনারী সার্চ থেকে পাওয়া টাইমে সব মানুষ খাওয়া পসিবল কি না। এই ফাংশন প্রত্যেক ভূতের সাথে শুধুমাত্র ওই সকল মানুষের কানেকশন দিবে যাদের কাছে এজিউম করা সময়ের সমান অথবা কম সময়ে যাওয়া যায়। এরপর যদি এই বাইপার্টাইট গ্রাফের জন্য মানুষের সংখ্যার সমান ফ্লো পাওয়া যায় তাহলে True রিটার্ন করবে। নাহয় False রিটার্ণ করবে।
৪) বাইনারী সার্চ থেকে পাওয়া রেজাল্ট ই এন্সার।
**/
#define sz 105
const int fx[] = {+1,-1,+0,+0};
const int fy[] = {+0,+0,+1,-1};
char grid[27][27];
bool mark[27][27];
int totnode=101,row,col,totghost,tothuman,dis[27][27],no[27][27],par[sz],vis[sz],cap[sz][sz],flow[sz][sz],dgh[sz][sz];
vi graph[sz];

void CleanGrid()
{
    for(int i=0 ; i<=row ; i++){
        for(int j=0 ; j<=col ; j++){
            mark[i][j]=0; dis[i][j]=infinity;
        }
    }
}
void BFS2D(int sx,int sy)
{
    CleanGrid();
    int nx,ny;
    queue<pii>q;
    q.push(make_pair(sx,sy));
    mark[sx][sy] = 1;
    dis[sx][sy] = 0;
    while(!q.empty()){
        pii u = q.front();
        q.pop();
        for(int i=0 ; i<4 ; i++){
            nx = u.first+fx[i];
            ny = u.second+fy[i];
            if(nx>=0 && nx<row && ny>=0 && ny<col && mark[nx][ny]==0 && grid[nx][ny]!='#'){
                mark[nx][ny] = 1;
                dis[nx][ny] = 1+dis[u.first][u.second];
                q.push(make_pair(nx,ny));
            }
        }
    }
}
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
void addEdge(int u,int v)
{
    graph[u].pb(v);
    graph[v].pb(u);
}
void Clean()
{
    for(int i=0 ; i<=totnode+1 ; i++){
        graph[i].clear();
        for(int j=i ; j<=totnode+1 ; j++){
            cap[i][j] = cap[j][i] = 0;
            flow[i][j] = flow[j][i] = 0;
            dgh[i][j] = dgh[j][i] = 0;
        }
    }
}
bool Possible(int time)
{
    int i,j,u,v,mxFlow;
    for(i=0 ; i<=101 ; i++){
        graph[i].clear();
        for(j=i ; j<=101 ; j++){
            flow[i][j] = flow[j][i] = 0;
            cap[i][j] = cap[j][i] = 0;
        }
    }
    /** Connect all ghost with super source **/
    for(i=1 ; i<=totghost ; i++){
        addEdge(0 , i);
        cap[0][i] = 1;
    }
    /** Connect all human with super sink **/
    for(j=1 ; j<=tothuman ; j++){
        addEdge(totghost+j , 101);
        cap[totghost+j][101] = 1;
    }
    /** Connect ghost with human **/
    for(i=1 ; i<=totghost ; i++){
        for(j=1 ; j<=tothuman ; j++){
            u = i; v = totghost+j;
            if(dgh[u][v] <= time){
                addEdge(u,v);
                cap[u][v] = 1;
            }
        }
    }
    mxFlow = FordFulkerson(0 , 101);
    if(mxFlow == tothuman)
        return 1;
    else
        return 0;
}
int BS()
{
    int lo=0,hi=infinity,mid,ans=-1;
    while(lo <= hi){
        mid = (lo+hi)/2;
        if(Possible(mid)){
            ans = mid;
            hi = mid-1;
        }
        else
            lo = mid+1;
    }
    return ans;
}
vector<pii>ghost;
int main()
{
    int i,j,k,t,T,ans,x,y,u,v,cnt=0,mxflow,src,sink;
    scin(T);
    RUN_CASE(t,T)
    {
        cnt = 0; src = 0; sink = 101;
        sc("\n%d",&row); col = row;
        getchar();
        ghost.clear();

        /** Indexing all ghost **/
        for(i=0 ; i<row ; i++){
            sc("%s",grid[i]);
            for(j=0 ; j<col ; j++){
                if(grid[i][j] == 'G'){
                    no[i][j] = ++cnt;
                    ghost.pb(make_pair(i,j));
                }
            }
        }

        /** Indexing all human **/
        for(i=0 ; i<row ; i++){
            for(j=0 ; j<col ; j++){
                if(grid[i][j] == 'H')
                    no[i][j] = ++cnt;
            }
        }

        /** Count the distance between human & ghost **/
        int vsz = (int)ghost.size();
        totghost = vsz ; tothuman = cnt-totghost;
        for(i=1 ; i<=totghost ; i++){
            for(j=1 ; j<=tothuman ; j++){
                dgh[i][totghost+j] = infinity;
            }
        }
        for(i=0 ; i<vsz ; i++){
            pii pr = ghost[i];
            BFS2D(pr.first , pr.second);
            for(j=0 ; j<row ; j++){
                for(k=0 ; k<col ; k++){
                    if(grid[j][k] == 'H'){
                        u = no[pr.first][pr.second];
                        v = no[j][k];
                        dgh[u][v] = dgh[v][u] = (2*dis[j][k])+2;
                    }
                }
            }
        }
        ans = BS();

        if(ans == -1)
            pf("Case %d: Vuter Dol Kupokat\n",t);
        else
            pf("Case %d: %d\n",t,ans);
        Clean();
    }
    return 0;
}


