/** Problem: Given two rooted trees. Check if they are identical or not?
    Solution: hash[u] = d * base^p + (hash[v1]+hash[v2]+---+hash[vk])
    Here, d = subtree size of u, p = level of u, k = number of child of u   **/

#include<bits/stdc++.h>
using namespace std;

const long long sz = 1e5+9 , p = 41 , mod = 1e9+7;
long long subtreesz[2][sz],hashValue[2][sz];
vector<int>graph[2][sz];
int vis[2][sz];

void DFS(int u,int treeno,int level,long long p_pow)
{
    vis[treeno][u] = subtreesz[treeno][u] = 1;
    hashValue[treeno][u] = 0LL;

    for(auto v : graph[treeno][u]){
        if(!vis[treeno][v]){
            DFS(v , treeno , 1+level , (p_pow*p)%mod);
            subtreesz[treeno][u] += subtreesz[treeno][v];
            hashValue[treeno][u] = (hashValue[treeno][u] + hashValue[treeno][v])%mod;
        }
    }
    hashValue[treeno][u] = (hashValue[treeno][u] + (subtreesz[treeno][u] * p_pow)%mod)%mod;
}

void Solve()
{
    int i,j,k,u,v,n1,n2;

    ///Input of tree-1
    cin>>n1;
    for(i=1 ; i<n1 ; i++){
        cin>>u>>v;
        graph[0][u].push_back(v);
        graph[0][v].push_back(u);
    }

    ///Input of tree-2
    cin>>n2;
    for(i=1 ; i<n2 ; i++){
        cin>>u>>v;
        graph[1][u].push_back(v);
        graph[1][v].push_back(u);
    }

    ///Here, 1 is the root for both trees
    DFS(1 , 0 , 1 , p);
    DFS(1 , 1 , 1 , p);
    if(hashValue[0][1] == hashValue[1][1])
        cout<<"Identical Trees\n";
    else
        cout<<"Not identical!\n";
}

int main()
{
    Solve();
    return 0;
}

/**
7
1 2
1 3
2 4
2 5
2 6
5 7
7
1 2
1 3
3 4
3 5
3 6
6 7
**/
