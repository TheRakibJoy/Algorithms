#include<bits/stdc++.h>

#define ll                      long long int
#define ull                     unsigned long long int
#define pii                     pair<int,int>
#define pll                     pair<ll,ll>
#define sc                      scanf
#define scin(x)                 sc("%d",&(x))
#define scln(x)                 sc("%lld",&(x))
#define pf                      printf
#define ms(a,b)                 memset(a,b,sizeof(a))

using namespace std;
vector<int>graph[105];
int vis[105];
void graphInput(int u,int v)
{
    graph[u].push_back(v);
    graph[v].push_back(u);
}
void DFS(int u,int x)
{
    if(vis[u] != 0)
        return;
    vis[u]=x;
    for(int i=0; i<graph[u].size(); i++)
    {
        DFS(graph[u][i],x);
    }
}
int main()
{
    int i,j,k,T,u,v,limit;
    scin(T);
    getchar();
    getchar();
    for(i=1; i<=T; i++)
    {
        memset(vis,0,sizeof(vis));
        char s1[5],s2[5];
        sc("%s",s1);
        getchar();
        while(gets(s2))
        {
            if(strlen(s2) == 0)
                break;
            u=s2[0]-'A'+1;
            v=s2[1]-'A'+1;
            graphInput(u,v);
        }
        int x=0;
        limit = s1[0]-'A'+1;
        for(j=1;j<=(limit);j++)
        {
            if(vis[j]==0){
                    x++;
                DFS(j,x);
            }
        }
        if(i>1)
            pf("\n");
        pf("%d\n",x);
        for(j=0;j<=limit;j++)
            graph[j].clear();
    }
    return 0;
}
