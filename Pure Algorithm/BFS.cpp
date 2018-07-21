/** BFS for counting level of graph **/

#include<bits/stdc++.h>
using namespace std;

vector<int>graph[1000];
int vis[1000];

void BFS(int start,int n)       ///start->source and n->node
{
    int x=1;
    memset(vis,0,sizeof(vis));
    queue<int>Q;
    Q.push(start);
    vis[start]=1;
    while(! Q.empty())
    {
        int u=Q.front();
        Q.pop();
        for(int i=0;i<graph[u].size();i++)
        {
            if(vis[graph[u][i]] == 0)
            {
                int v=graph[u][i];
                vis[v]=vis[u]+1;
                Q.push(v);
            }
        }
    }
}

int main()
{
    int i,n,u,v,e,mx=0;
    cout<<"Enter the number of node: ";
    cin>>n;
    cout<<"Enter the number of edges: ";
    cin>>e;
    cout<<"Connect the edges: \n";
    for(i=0;i<e;i++)
    {
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    BFS(1,n);
    for(i=1;i<=n;i++)
        cout<<vis[i]<<"\t";
    cout<<endl;
    for(i=0;i<=n;i++)
    {
        mx=max(mx,vis[i]);
    }
    cout<<mx<<endl;
    return 0;
}
