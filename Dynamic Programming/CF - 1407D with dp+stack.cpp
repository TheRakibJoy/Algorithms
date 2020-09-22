#include<bits/stdc++.h>
using namespace std;

#define sz 300005
int n,h[sz],dp[sz];
vector<int>graph[sz];

void add_Edge1()    ///Find nearly less or equal
{
    stack<int>stk;
    for(int i=1 ; i<=n ; i++){  ///Find rightmost less or equal in left
        while(!stk.empty() && h[stk.top()] > h[i]){
            stk.pop();
        }
        if(!stk.empty())
            graph[stk.top()].push_back(i);
        stk.push(i);
    }

    while(!stk.empty()) ///Clean stack
        stk.pop();

    for(int i=n ; i>=1 ; i--){  ///Find leftmost less or equal in right
        while(!stk.empty() && h[stk.top()] > h[i]){
            stk.pop();
        }
        if(!stk.empty())
            graph[i].push_back(stk.top());
        stk.push(i);
    }
}

void add_Edge2()    ///Find nearly greater or equal
{
    stack<int>stk;
    for(int i=1 ; i<=n ; i++){  ///Find rightmost greater or equal in left
        while(!stk.empty() && h[stk.top()] < h[i]){
            stk.pop();
        }
        if(!stk.empty())
            graph[stk.top()].push_back(i);
        stk.push(i);
    }

    while(!stk.empty()){
        stk.pop();
    } ///Clean stack

    for(int i=n ; i>=1 ; i--){   ///Find leftmost greater or equal in right
        while(!stk.empty() && h[stk.top()] < h[i])
            stk.pop();
        if(!stk.empty())
            graph[i].push_back(stk.top());
        stk.push(i);
    }
}

int main()
{
    int i,ans;
    cin>>n;
    for(i=1 ; i<=n ; i++)   cin>>h[i];
    add_Edge1();
    add_Edge2();

    dp[n] = 0;
    for(i=n-1 ; i>=1 ; i--){
        dp[i] = 1+dp[i+1];
        for(auto j : graph[i])
            dp[i] = min(dp[i] , 1+dp[j]);
    }
    cout<<dp[1]<<endl;

    return 0;
}
