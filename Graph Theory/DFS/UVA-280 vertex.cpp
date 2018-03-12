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
int vis[105];
int SeVis[105];
vector<int>graph[105];

void graphInput(int u,int v)
{
    graph[u].push_back(v);
}
void DFS(int u,bool adjacent=false)
{
    if(vis[u]==1)
        return;
    if(adjacent)
        vis[u]=1;
    for(int i=0; i<graph[u].size(); i++)
    {
        DFS(graph[u][i],true);
    }
}
int main()
{
    int n,i,j,k,q,start,temp,cnt;
    vector<int>out;
    while(1)
    {
        scin(n);
        if(n == 0)
            break;
        else
        {
            while(1)
            {
                scin(start);
                if(start == 0)
                    break;
                while(1)
                {
                    scin(temp);
                    if(temp == 0)
                        break;
                    graphInput(start,temp);
                }
            }
            scin(q);
            for(i=0;i<q;i++)
            {
                cnt=0;
                out.clear();
                scin(temp);
                DFS(temp);
                for(j=1;j<=n;j++)
                {
                    if(vis[j] == 0)
                        out.push_back(j);
                }
                pf("%d",out.size());
                for(j=0;j<out.size();j++)
                    pf(" %d",out[j]);
                pf("\n");
                memset(vis,0,sizeof(vis));
            }
            for(i=0;i<=n;i++)
                graph[i].clear();
            memset(SeVis,0,sizeof(SeVis));
        }
    }
    return 0;
}
