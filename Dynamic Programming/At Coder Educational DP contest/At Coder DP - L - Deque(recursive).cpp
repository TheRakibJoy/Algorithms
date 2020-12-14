#include<bits/stdc++.h>
using namespace std;

long long n,ara[3005],dp[3005][3005][2];
///1-First Player ; 0-Second Player

long long FuN(int lft,int rgt,int player)
{
    if(lft > rgt)
        return 0LL;
    if(dp[lft][rgt][player] != -1)
        return dp[lft][rgt][player];

    long long ret1=0 , ret2=0;

    if(player){
        ret1 = ara[lft] + FuN(lft+1 , rgt , player^1);
        ret2 = ara[rgt] + FuN(lft , rgt-1 , player^1);
        return dp[lft][rgt][player] = max(ret1 , ret2);
    }
    else{
        ret1 = FuN(lft+1 , rgt , player^1);
        ret2 = FuN(lft , rgt-1 , player^1);
        return dp[lft][rgt][player] = min(ret1 , ret2);
    }
}

int main()
{
    long long sum = 0;
    memset(dp , -1 , sizeof(dp));
    cin>>n;
    for(int i=1 ; i<=n ; i++){
        cin>>ara[i];
        sum += ara[i];
    }

    long long fscore = FuN(1 , n , 1);
    long long sscore = sum - fscore;
    cout<<fscore - sscore<<endl;
    return 0;
}
