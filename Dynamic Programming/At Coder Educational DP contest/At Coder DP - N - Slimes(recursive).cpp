#include<bits/stdc++.h>
using namespace std;

long long n,ara[405],csum[405],dp[405][405];

long long FuN(int lft,int rgt)
{
    if(lft >= rgt)
        return 0LL;
    if(dp[lft][rgt] != -1)
        return dp[lft][rgt];

    long long ret = 1e18 , cuttingcost = csum[rgt] - csum[lft-1];
    for(int mid=lft ; mid < rgt ; mid++)
        ret = min(ret , cuttingcost + FuN(lft , mid) + FuN(mid+1 , rgt));
    return dp[lft][rgt] = ret;
}

int main()
{
    cin>>n;
    for(int i=1 ; i<=n ; i++){
        cin>>ara[i];
        csum[i] = csum[i-1] + ara[i];
    }

    memset(dp , -1 , sizeof(dp));
    cout<<FuN(1 , n)<<endl;
    return 0;
}
