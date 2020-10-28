#include<bits/stdc++.h>
using namespace std;

string s;
int n,prefsum[30][505],dp[505][505];

int FuN(int lptr,int rptr)
{
    if(lptr > rptr)
        return 0;
    if(lptr == rptr)
        return 1;
    if(dp[lptr][rptr] != -1)
        return dp[lptr][rptr];

    int ret = 1e9;
    ret = 1 + FuN(lptr+1 , rptr);

    for(int i=lptr+1 ; i<=rptr ; i++){
        if(s[lptr] == s[i])
            ret = min(ret , FuN(lptr+1 , i-1) + FuN(i , rptr));
    }
    return dp[lptr][rptr] = ret;
}

int main()
{
    cin>>n>>s;
    memset(dp , -1 , sizeof(dp));
    int ans = FuN(0 , n-1);
    cout<<ans<<endl;
    return 0;
}
