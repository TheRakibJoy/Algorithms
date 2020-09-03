#include<bits/stdc++.h>
using namespace std;

int n,x,coin[105],dp[1000005];
const int mod = 1000000007;

int main()
{
    int i,j,k,ans;

    cin>>n>>x;
    for(i=1 ; i<=n ; i++)   cin>>coin[i];

    for(int value=0 ; value<=1e6 ; value++){
        if(value == 0){
            dp[value] = 1;
            continue;
        }

        int ret = 0;
        for(i=1 ; i<=n ; i++){
            if(value-coin[i] >= 0)
                ret = (ret + dp[value - coin[i]])%mod;
        }
        dp[value] = ret;
    }

    cout<<dp[x]<<endl;

    return 0;
}
