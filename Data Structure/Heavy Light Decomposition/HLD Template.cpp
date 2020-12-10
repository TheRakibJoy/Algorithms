#include<bits/stdc++.h>
using namespace std;

/** Problem: You'll given a tree with n nodes. Each node contain some integer values.
You've to perform two types of queries.
1 u v   (Find max value in path between u to v)
2 u x   (Update value of node u to x)
**/

#define sz 100009

/** LCA Part **/
vector<int>graph[sz];
int n,level[sz],subsize[sz],parent[sz],sptable[sz][22],cost[sz];

void DFS(int u,int par=-1,int lev=0)
{
    level[u] = lev;
    parent[u] = par;
    subsize[u] = 1;
    for(int v : graph[u]){
        if(v != par){
            DFS(v , u , 1+lev);
            subsize[u] += subsize[v];
        }
    }
}

void LCA_Init(int n)
{
    memset(sptable , -1 , sizeof(sptable));
    for(int i=1 ; i<=n ; i++)
        sptable[i][0] = parent[i];
    for(int j=1 ; (1<<j) <= n ; j++){
        for(int i=1 ; i<=n ; i++){
            if(sptable[i][j-1] != -1)
                sptable[i][j] = sptable[sptable[i][j-1]] [j-1];
        }
    }
}

int LCA_Query(int n,int u,int v)
{
    if(level[u] < level[v]) swap(u , v);
    int Log = 1;
    while(1){
        int nxt = Log+1;
        if(1<<nxt > level[u])
            break;
        Log++;
    }
    for(int i=Log ; i>=0 ; i--){
        if(level[u]-(1<<i) >= level[v])
            u = sptable[u][i];
    }
    if(u == v)
        return u;
    for(int i=Log ; i>=0 ; i--){
        if(sptable[u][i] != -1 && sptable[u][i] != sptable[v][i]){
            u = sptable[u][i];
            v = sptable[v][i];
        }
    }
    return parent[u];
}

/** Segment Tree Part **/
int baseArray[sz],tree[4*sz];

void Init(int node,int b,int e)
{
    if(b == e){
        tree[node] = baseArray[b];
        return;
    }
    int mid = (b+e)>>1;
    Init(node<<1 , b , mid);
    Init(1+(node<<1) , mid+1 , e);
    tree[node] = max(tree[node<<1] , tree[1+(node<<1)]);
}

void Update(int node,int b,int e,int pos,int val)
{
    if(pos<b || pos>e)
        return;
    if(pos==b && pos==e){
        tree[node] = val;
        return;
    }
    int mid = (b+e)>>1;
    Update(node<<1 , b , mid , pos , val);
    Update(1+(node<<1) , mid+1 , e , pos , val);
    tree[node] = max(tree[node<<1] , tree[1+(node<<1)]);
}

int Query(int node,int b,int e,int i,int j)
{
    if(e<i || b>j)
        return 0;
    if(b>=i && e<=j)
        return tree[node];
    int mid = (b+e)>>1;
    int p1 = Query(node<<1 , b , mid , i , j);
    int p2 = Query(1+(node<<1) , mid+1 , e , i , j);
    return max(p1 , p2);
}

/** HLD Part **/
int now=0 , chainNo=0 , chainID[sz] , chainHead[sz] , posInBase[sz];

void HLD(int u,int par)
{
    if(chainHead[chainNo] == -1){   ///Its the first node of this chain
        chainHead[chainNo] = u;
    }
    chainID[u] = chainNo;
    posInBase[u] = ++now;     ///Position of this node in baseArray which will build segment tree
    baseArray[now] = cost[u];

    ///Find out special child
    int mxsz=0 , spchild=-1;
    for(int v : graph[u]){
        if(v != par && subsize[v] > mxsz){
            mxsz = subsize[v];
            spchild = v;
        }
    }

    if(spchild != -1)       ///Go through special child first
        HLD(spchild , u);

    for(int v : graph[u]){
        if(v != par && v != spchild){
            chainNo++;      ///Create new chain at each normal node
            HLD(v , u);
        }
    }
}

int QueryUP(int u,int v)    ///u is the ancestor of v
{
    int uchain = chainID[u] , vchain = chainID[v] , ans = -1;
    while(1){
        vchain = chainID[v];
        if(uchain == vchain){
            ans = max(ans , Query(1 , 1 , n , posInBase[u] , posInBase[v]));
            break;
        }
        ans = max(ans , Query(1 , 1 , n , posInBase[chainHead[vchain]] , posInBase[v]));
        v = chainHead[vchain];
        v = parent[v];
    }
    return ans;
}

int pathQuery(int u,int v)
{
    int lca = LCA_Query(n , u , v);
    int ans = QueryUP(lca , u);
    ans = max(ans , QueryUP(lca , v));
    return ans;
}

void hldUpdate(int u,int val)
{
    Update(1 , 1 , n , posInBase[u] , val);
}

void Clean()
{
    for(int i=0 ; i<=n+2 ; i++){
        graph[i].clear();
        now = chainNo = cost[i] = 0;
        chainHead[i] = level[i] = parent[i] = -1;
    }
}

void Solve()
{
    int i,j,k,u,v,x,type,ans,q;
    cin>>n>>q;
    Clean();

    for(i=1 ; i<n ; i++){
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for(i=1 ; i<=n ; i++)
        cin>>cost[i];

    DFS(1);
    LCA_Init(n);
    HLD(1 , -1);
    Init(1 , 1 , n);

    for(i=1 ; i<=q ; i++){
        cin>>type;
        if(type == 1){
            cin>>u>>v;
            ans = pathQuery(u , v);
            cout<<ans<<endl;
        }
        else{
            cin>>u>>x;
            hldUpdate(u , x);
        }
    }
}

int main()
{
    Solve();
    return 0;
}
/**
10 100
1 2
2 4
4 6
4 7
7 8
2 5
1 3
3 9
9 10
2 3 19 6 13 5 11 7 17 15
**/
