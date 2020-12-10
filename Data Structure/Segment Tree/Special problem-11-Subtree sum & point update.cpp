#include<bits/stdc++.h>
using namespace std;

/**
Problem: You'll given a tree with n nodes. Each node contain some value. You have to
perform q queries. There 're two types of queries.
1 u
2 u x
For the first type, you have to tell the sum of value of subtree rooted at u
For the second type, you have to update the value of u to x.

Solution: Make a linear array through DFS. In that array, for a subtree sum rooted at u
you have to find Sum(startTime[u] , startTime[u]+subtreeSize[u]-1)
**/

#define sz 200005
int tim=0,cost[sz],start[sz],finish[sz],subtreesz[sz];
vector<int>graph[sz];

void DFS(int u,int parent)
{
    subtreesz[u] = 1;
    start[u] = ++tim;
    for(int v : graph[u]){
        if(v != parent){
            DFS(v , u);
            subtreesz[u] += subtreesz[v];
        }
    }
    finish[u] = start[u] + subtreesz[u] - 1;
}

int ara[sz],tree[4*sz];

void Init(int node,int b,int e)
{
    if(b == e){
        tree[node] = ara[b];
        return;
    }
    int mid = (b+e)>>1;
    Init(node<<1 , b , mid);
    Init(1+(node<<1) , mid+1 , e);
    tree[node] = tree[node<<1] + tree[1+(node<<1)];
}

void Update(int node,int b,int e,int pos,int val)
{
    if(pos<b || pos>e)
        return;
    if(pos == b && pos == e){
        tree[node] = val;
        return;
    }
    int mid = (b+e)>>1;
    Update(node<<1 , b , mid , pos , val);
    Update(1+(node<<1) , mid+1 , e , pos , val);
    tree[node] = tree[node<<1] + tree[1+(node<<1)];
}

int Query(int node,int b,int e,int i,int j)
{
    if(e<i || b>j)
        return 0;
    if(b>=i && e<=j)
        return tree[node];
    int mid = (b+e)>>1;
    int p1 = Query(node<<1 , b , mid , i , j);
    int p2 = Query(1+(node<<1) , mid+1 , e , i , j);
    return p1+p2;
}

void Solve()
{
    cout<<"Ball\n";
    int i,j,k,u,v,x,type,n,q;
    cin>>n>>q;
    for(i=1 ; i<n ; i++){
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    for(i=1 ; i<=n ; i++)
        cin>>cost[i];

    DFS(1 , -1);
    for(i=1 ; i<=n ; i++){  ///Build linear array according to euler tour
        ara[start[i]] = cost[i];
    }
    Init(1 , 1 , n);
    for(i=1 ; i<=q ; i++){
        cin>>type>>u;
        if(type == 1){
            cout<<Query(1 , 1 , n , start[u] , finish[u]);
        }
        else{
            cin>>x;
            Update(1 , 1 , n , u , x);
        }
    }
}

int main()
{
    Solve();
    return 0;
}
