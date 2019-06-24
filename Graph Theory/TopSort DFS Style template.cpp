/** TopSort Template - 01 **/
#include<bits/stdc++.h>
using namespace std;

vector<int>graph[1005];
bool vis[1005];
stack<int>ans;
map<string , int>toint;
map<int , string>tostring;

void topDFS(int start)
{
    vis[start]=1;
    for(int i=0 ; i<graph[start].size() ; i++)
    {
        int u=graph[start][i];
        if(!vis[u])
            topDFS(u);
    }
    ans.push(start);
}

int main()
{
    int i,j,k,u,v,e,cnt=0;
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
    }
    for(i=1 ; i<=cnt ; i++)
    {
        if(!vis[i])
            topDFS(i);
    }
    printf("Sorted task among all task : \n");
    while(!ans.empty())
    {
        int x=ans.top();
        ans.pop();
        cout<<tostring[x]<<"\t";
    }
    cout<<endl;
    return 0;
}
