#include<bits/stdc++.h>
using namespace std;

string s;
int dp[1005][1005]; ///dp[l][r] means maximum length of palindromic subsequence of string s[l..r]

int FuN(int lptr,int rptr)
{
    if(lptr > rptr)
        return 0;
    if(lptr == rptr)
        return 1;
    if(dp[lptr][rptr] != -1)
        return dp[lptr][rptr];
    int ret1=0,ret2=0;
    if(s[lptr] == s[rptr])
        ret1 = 2 + FuN(lptr+1 , rptr-1);
    else{
        ret1 = FuN(lptr+1 , rptr);
        ret2 = FuN(lptr , rptr-1);
    }
    return dp[lptr][rptr] = max(ret1 , ret2);
}

int main()
{
    int i,j,k,n,mx=0;
    cin>>s;
    n = (int)s.size();
    memset(dp , -1 , sizeof(dp));

    for(i=0 ; i<n ; i++){
        for(j=i ; j<n ; j++){
            mx = max(mx , FuN(i , j));
            cout<<i<<' '<<j<<' '<<dp[i][j]<<endl;
        }
    }
    cout<<mx<<endl;
    return 0;
}
