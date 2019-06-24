/** SCC template **/
#include<bits/stdc++.h>
using namespace std;

bool vis[100005];
vector<int>graph[100005];
vector<int>rgraph[100005];
vector<int>comp[100005];
stack<int>stk;
void DFS1(int start)
{
    vis[start]=1;
    for(int i=0 ; i<graph[start].size() ; i++)
    {
        int u=graph[start][i];
        if(!vis[u])
            DFS1(u);
    }
    stk.push(start);
}
void DFS2(int start,int x)
{
    vis[start]=x;
    comp[x].push_back(start);
    for(int i=0 ; i<rgraph[start].size() ; i++)
    {
        int u=rgraph[start][i];
        if(!vis[u])
            DFS2(u,x);
    }
}
int main()
{
    int i,j,k,n,e,u,v,x=0;
    cin>>n>>e;
    for(i=1 ; i<=e ; i++)
    {
        cin>>u>>v;
        graph[u].push_back(v);
        rgraph[v].push_back(u);
    }
    for(i=1 ; i<=n ; i++)
    {
        if(!vis[i])
            DFS1(i);
    }
    memset(vis,0,sizeof(vis));
    while(!stk.empty())
    {
        int temp=stk.top();
        stk.pop();
        if(!vis[temp])
            DFS2(temp,++x);
    }
    for(i=1 ; i<=x ; i++)
    {
        printf("Component-%d : ",i);
        for(j=0 ; j<comp[i].size() ; j++)
        {
            printf("%d ",comp[i][j]);
        }
        printf("\n");
    }
    return 0;
}
