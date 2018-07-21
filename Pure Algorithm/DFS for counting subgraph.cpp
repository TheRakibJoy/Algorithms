#include<bits/stdc++.h>
using namespace std;

int vis[100005];
vector<int>graph[100005];
void DFS(int start,int x)
{
    if(vis[start]==0 || vis[start]!=x)
    {
        vis[start]=x;
        for(int i=0;i<graph[start].size();i++)
        {
            int u=graph[start][i];
            DFS(u,x);
        }
    }
}

int main()
{
    int i,n,e,x,u,v;
    cout<<"Enter the number of node : ";
    cin>>n;
    cout<<"Enter the number of edges: ";
    cin>>e;
    for(i=0;i<e;i++)
    {
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    x=1;
    set<int>subgraph;
    for(i=1;i<=n;i++)
    {
        if(vis[i] == 0)
            DFS(i,x++);
    }
    for(i=1;i<=n;i++)
    {
        if(vis[i] != 0)
            subgraph.insert(vis[i]);
    }
    cout<<"Number of subgraph is = "<<subgraph.size()<<endl;
    return 0;
}
