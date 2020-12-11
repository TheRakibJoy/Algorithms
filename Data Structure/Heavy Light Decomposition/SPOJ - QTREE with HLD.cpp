#include<bits/stdc++.h>
using namespace std;

/** Problem: You're given a tree with n nodes.
We will ask you to perform some instructions of the following form:
CHANGE i ti : change the cost of the i-th edge to ti
QUERY a b : ask for the maximum edge cost on the path from node a to node b

Sol: I think big problem of this problem is to handle edge cost!
What if, if we divide every edge by a putting a new node between two nodes of that edge.
And put edge cost in the middle new node. Save the middle node for each edge if it
necessary to update.
**/

#define sz 20099
#define infinity    1e8
#define CIN                     ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)

/** LCA Part **/
vector<int>graph[sz];
int n,level[sz],subsize[sz],parent[sz],sptable[sz][22],cost[sz],edgeSplitAt[sz];

void DFS(int u,int par=-1,int lev=0)
{
    parent[u] = par;
    level[u] = lev;
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
        int nxt = 1+Log;
        if(1<<nxt > level[u])
            break;
        Log++;
    }
    for(int i=Log ; i>=0 ; i--){
        if(level[u] - (1<<i) >= level[v])
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
        return -infinity;
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
    posInBase[u] = ++now;       ///Position of this node in baseArray which will build segment tree
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

void Solve(int t)
{
    int i,j,k,orgnode,u,v,x,ans,ith;
    char cmd[20];
    scanf("%d",&n);
    orgnode = n;
    n += (n-1);
    Clean();

    for(i=1 ; i<orgnode ; i++){
        scanf("%d %d %d",&u,&v,&x);
        int midnode = orgnode+i;
        edgeSplitAt[i] = midnode;     ///Split this edge by inserting midnode th node
        graph[u].push_back(midnode);
        graph[midnode].push_back(u);

        graph[v].push_back(midnode);
        graph[midnode].push_back(v);
        cost[u] = cost[v] = 0;
        cost[midnode] = x;
    }

    DFS(1);
    LCA_Init(n);
    HLD(1 , -1);
    Init(1 , 1 , n);

    while(1){
        scanf("%s",cmd);
        if(cmd[0] == 'D')
            break;
        else if(cmd[0] == 'Q'){
            scanf("%d %d",&u,&v);
            ans = pathQuery(u , v);
            printf("%d\n",ans);
        }
        else{
            scanf("%d %d",&ith,&x);
            hldUpdate(edgeSplitAt[ith] , x);
        }
    }
    Clean();
}

int main()
{
    int t,T;
    scanf("%d",&T);
    for(t=1 ; t<=T ; t++){
        Solve(t);
    }
    return 0;
}
