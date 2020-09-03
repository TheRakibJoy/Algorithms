#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9+7;
int n,m,ara[100005],lastfill[100005],dp[100005][105];

int FuN(int pos,int lastval)
{
    if(pos > n){
        if(lastval>=1 && lastval<=m)
            return 1;
        else
            return 0;
    }
    if(dp[pos][lastval] != -1)
        return dp[pos][lastval];
    int ret = 0;
    if(ara[pos] == 0){
        if(pos == 1){
            for(int i=1 ; i<=m ; i++)
                ret = (ret + FuN(pos+1 , i))%mod;
        }
        else{
            ret = (ret + FuN(pos+1 , lastval))%mod;
            if(lastval+1 <= m)
                ret = (ret + FuN(pos+1 , lastval+1))%mod;
            if(lastval-1 >= 1)
                ret = (ret + FuN(pos+1 , lastval-1))%mod;
        }
    }
    else{
        if(fabs(ara[pos]-lastval) <= 1 || pos == 1)
            ret = (ret + FuN(pos+1 , ara[pos]));
    }
    return dp[pos][lastval] = ret;
}

int main()
{
    int i,j,k,ans,last = 0;
    cin>>n>>m;
    for(i=1 ; i<=n ; i++)   cin>>ara[i];

    memset(dp , -1 , sizeof(dp));
    ans = FuN(1 , 0);
    cout<<ans<<endl;

    return 0;
}
