#include<bits/stdc++.h>
using namespace std;
vector<int> graph[100005];
bool vis[100005];
void graphInput(int u, int v)
{
    /** Both statement if the graph is undirected, only 1st if graph is directed **/
    graph[u].push_back(v);
    graph[v].push_back(u);
}
void DFS(int u)
{
    vis[u]=1;
    for(int i=0;i<graph[u].size();i++)
    {
        if(!vis[graph[u][i]])
        {
            DFS(graph[u][i]);
        }
    }
}
int main()
{
    return 0;
}
