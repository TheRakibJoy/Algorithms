#include<bits/stdc++.h>
using namespace std;

#define ll long long
int dp[505][125500];
const int mod = 1e9+7;

ll BigMOD(ll a,ll n)
{
    if(n == 0)
        return 1;
    if(n == 1)
        return a%mod;
    if(n%2){
        return (a * BigMOD(a , n-1))%mod;
    }
    else{
        ll half = BigMOD(a , n/2);
        return (half * half)%mod;
    }
}

int main()
{
    int i,j,k,n,ans,target,tot;
    cin>>n;
    tot = (n * (n+1))/2;
    if(tot%2){
        ans = 0;
    }
    else{
        target = tot/2;
        dp[n+1][0] = 1;
        for(i=n ; i>=1 ; i--){
            for(j=0 ; j<=target ; j++){
                dp[i][j] = (dp[i+1][j] + dp[i+1][j-i])%mod;
            }
        }
        ans = dp[1][target];
    }
    ans = (ans * BigMOD(2 , mod-2))%mod;
    cout<<ans<<endl;
    return 0;
}
