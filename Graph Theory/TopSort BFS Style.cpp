/** TopSort template - 02 **/
#include<bits/stdc++.h>
using namespace std;

vector<int>graph[1005];
vector<int>ans;
int in_deg[1005] , node;
map<string,int>toint;
map<int,string>tostring;
void topBFS()
{
    queue<int>q;
    for(int i=1 ; i<=node ; i++)
    {
        if(in_deg[i] == 0)
            q.push(i);
    }
    while(!q.empty())
    {
        int u=q.front();
        ans.push_back(u);
        q.pop();
        for(int i=0 ; i<graph[u].size() ; i++)
        {
            int v=graph[u][i];
            in_deg[v]--;
            if(in_deg[v] == 0)
                q.push(v);
        }
    }
}
int main()
{
    int i,j,k,n,e,u,v,cnt=0;
    string s1,s2;
    cin>>e;
    for(i=1 ; i<=e ; i++)
    {
        cin>>s1>>s2;
        if(toint[s1] == 0)
        {
            toint[s1] = ++cnt;
            tostring[cnt] = s1;
        }
        if(toint[s2] == 0)
        {
            toint[s2] = ++cnt;
            tostring[cnt] = s2;
        }
        u=toint[s1];
        v=toint[s2];
        graph[u].push_back(v);
        in_deg[v]++;
    }

    node=cnt;

    topBFS();
    printf("Sorted order of all task : \n");
    for(i=0 ; i<ans.size() ; i++)
    {
        cout<<tostring[ans[i]]<<"\t";
    }
    printf("\n");
    return 0;
}
