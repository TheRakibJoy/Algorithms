#include<bits/stdc++.h>
using namespace std;

const int sz = 5e4+10;

struct Edge
{
    int u,v,cap;
    Edge(){}
    Edge(int _u,int _v,int _cap)
    {
        u = _u;
        v = _v;
        cap = _cap;
    }
};

vector<Edge>edges;
vector<int>edgeid[sz];
bool vis[sz];
int src,sink;

void addEdge(int u,int v,int w)
{
    edges.push_back(Edge(u , v , w));
    edges.push_back(Edge(v , u , 0));   ///Because it's an unidirectional edge

    edgeid[u].push_back(edges.size() - 2);  ///Even indexed
    edgeid[v].push_back(edges.size() - 1);  ///Odd indexed
}

int DFS(int u,int flow=1e9)
{
    vis[u] = 1;
    if(u == sink)
        return flow;
    int ret = 0;
    for(int i=0 ; i<(int)edgeid[u].size() ; i++){
        int id = edgeid[u][i];
        Edge &e = edges[id];

        if(!e.cap || vis[e.v])
            continue;

        ret = DFS(e.v , min(flow , e.cap));

        if(ret){
            Edge &rev = edges[id ^ 1];  ///Every forward edge stored in even index & every backward edge stored in next odd index
            e.cap -= ret;
            rev.cap += ret;
            return ret;
        }
    }
    return ret;
}

int FordFulkerson()
{
    int mxFlow=0;
    while(1){
        memset(vis , 0 , sizeof(vis));
        int mnPathFlow = DFS(src);
        if(mnPathFlow == 0)
            break;
        mxFlow += mnPathFlow;
    }
    return mxFlow;
}

int main()
{
    return 0;
}
