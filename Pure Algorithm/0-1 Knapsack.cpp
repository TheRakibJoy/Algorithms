#include<bits/stdc++.h>
using namespace std;

int n;
int dp[50][50];
int knapsack(int i,int w,int *cost,int *weight,int CAP)
{
    int profit1,profit2;
    if(i == n+1)
        return 0;
    if(w+weight[i] <= CAP)
    {
        if(dp[i][w] != -1)
        {
            return dp[i][w];
        }
        else
        {
            profit1=cost[i]+knapsack(i+1,w+weight[i],cost,weight,CAP);
        }
    }
    else
    {
        profit1=0;
    }
    profit2=knapsack(i+1,w,cost,weight,CAP);
    return dp[i][w] = max(profit1,profit2);
}
int main()
{
    int i,j,ans=0,capacity;
    cout<<"Enter the number of product: ";
    cin>>n;
    cout<<"Enter the capacity of knapsack: ";
    cin>>capacity;
    int cost[n+1],weight[n+1];
    memset(dp,-1,sizeof(dp));
    cout<<"Enter the weight & cost of each product :";
    for(i=1;i<=n;i++)
    {
        cin>>weight[i];
        cin>>cost[i];
    }
    ans=knapsack(1,0,cost,weight,capacity);
    cout<<ans<<endl;
    return 0;
}
