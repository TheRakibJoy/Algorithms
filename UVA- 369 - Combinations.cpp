/**Optimize with DP**/

#include<bits/stdc++.h>

using namespace std;
long long int dp[101][101];
long long int nCr(int n,int r)
{
    if(r == 1)
        return n;
    else if(n == r)
        return 1;
    else if(dp[n][r] != 0)
        return dp[n][r];
    else
        return dp[n][r] = nCr(n-1,r-1)+nCr(n-1,r);
}
int main()
{
    int n,m;
    long long int c;
    while(1)
    {
        scanf("%d %d",&n,&m);
        if(n==0 && m==0)
            break;
        else
        {
            c=nCr(n,m);
            printf("%d things taken %d at a time is %lld exactly.\n",n,m,c);
        }
    }
    return 0;
}
