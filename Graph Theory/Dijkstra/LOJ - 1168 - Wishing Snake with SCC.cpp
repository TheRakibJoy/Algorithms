#include<bits/stdc++.h>

#define ll                      long long int
#define pii                     pair<int,int>
#define sc                      scanf
#define scin(x)                 sc("%d",&(x))
#define scin2(x,y)              sc("%d %d",&(x),&(y))
#define pf                      printf
#define ms(a,b)                 memset(a,b,sizeof(a))
#define pb(a)                   push_back(a)
#define vi                      vector<int>
#define RUN_CASE(t,T)           for(__typeof(t) t=1;t<=T;t++)

using namespace std;


#define sz 1009
set<int>nodes;
map<int , int>compress;
vector<pii>edges;
vi graph[sz],rgraph[sz],comp[sz],dag[sz];
stack<int>stk;
int ans=1,vis[sz];

void Clean()
{
    ans = 1;
    nodes.clear();
    edges.clear();
    compress.clear();
    while(!stk.empty())
        stk.pop();
    for(int i=0 ; i<sz ; i++){
        vis[i] = 0;
        graph[i].clear();
        rgraph[i].clear();
        comp[i].clear();
        dag[i].clear();
    }
}

void DFS1(int u)
{
    vis[u] = 1;
    for(auto v : graph[u]){
        if(!vis[v])
            DFS1(v);
    }
    stk.push(u);
}

void DFS2(int u,int compno)
{
    vis[u] = compno;
    comp[compno].pb(u);
    for(auto v : rgraph[u]){
        if(!vis[v])
            DFS2(v , compno);
    }
}

void DFS(int u)
{
    vis[u] = 1;
    if((int)dag[u].size() > 1){
        ans = 0;
        return;
    }
    for(auto v : dag[u]){
        if(!vis[v])
            DFS(v);
    }
}

void Solve(int t)
{
    int i,j,k,n,u,v,wish,src=-1,cnt=0;
    scin(n);

    nodes.insert(0);
    for(i=1 ; i<=n ; i++){
        scin(wish);
        for(j=1 ; j<=wish ; j++){
            scin2(u , v);
            edges.pb(make_pair(u , v));
            nodes.insert(u);
            nodes.insert(v);
        }
    }
    ///
    for(auto x : nodes){
        compress[x] = ++cnt;
    }
    for(auto pr : edges){
        u = compress[pr.first];
        v = compress[pr.second];
        graph[u].pb(v);
        rgraph[v].pb(u);
    }

    ///SCC Call
    for(i=1 ; i<=cnt ; i++){
        if(!vis[i])
            DFS1(i);
    }

    int compno = 0;
    ms(vis , 0);
    while(!stk.empty()){
        int top = stk.top();
        stk.pop();
        if(!vis[top])
            DFS2(top , ++compno);
    }

    ///Make DAG according to SCC
    for(u=1 ; u<=cnt ; u++){
        int nu = vis[u];
        for(auto adj : graph[u]){
            int nv = vis[adj];
            if(nu == nv)
                continue;
            dag[nu].pb(nv);
        }
    }

    src = vis[1];   ///Initially, the snake is at checkpoint 0 which is compressed to node 1. And node 1 is at node vis[1] in DAG
    ms(vis , 0);
    DFS(src);
    for(i=1 ; i<=compno ; i++)
        ans &= vis[i];

    if(ans)
        pf("Case %d: YES\n",t);
    else
        pf("Case %d: NO\n",t);
    Clean();
}

int main()
{
    int t,T;
    scin(T);
    RUN_CASE(t,T)
    {
        Solve(t);
    }
    return 0;
}

/** Stuff u should look for
    * Avoid overflow
    * Corner(Small) case
    * Don't get stuck on one approach
    * Don't forget to clean used memory in each case
**/

