#include<bits/stdc++.h>
using namespace std;

string s;
int dp[1005][1005]; ///dp[l][r] means is substring s[l...r] is a palindrome or not

int FuN(int lptr,int rptr)
{
    if(lptr >= rptr)
        return 1;
    if(dp[lptr][rptr] != -1)
        return dp[lptr][rptr];
    int ret1=0;
    if(s[lptr] == s[rptr])
        ret1 = FuN(lptr+1 , rptr-1);
    return dp[lptr][rptr] = ret1;
}

int main()
{
    int i,j,k,n,mx=0;
    memset(dp , -1 , sizeof(dp));
    cin>>s;
    n = (int)s.size();

    for(i=0 ; i<n ; i++){
        for(j=i ; j<n ; j++){
            if(FuN(i , j))
                mx = max(mx , j-i+1);
        }
    }
    cout<<mx<<endl;
    return 0;
}
