#include<bits/stdc++.h>
using namespace std;

int dp[35];

int FuN(int baki)
{
    if(baki == 0)
        return 1;
    if(dp[baki] != -1)
        return dp[baki];
    int ret = FuN(baki - 1);
    if(baki >= 2)
        ret += FuN(baki - 2);
    if(baki >= 3)
        ret += FuN(baki - 3);
    return dp[baki] = ret;
}

int main()
{
    int n;
    cin>>n;
    memset(dp , -1 , sizeof(dp));
    cout<<FuN(n)<<endl;
    return 0;
}
