#include<bits/stdc++.h>
using namespace std;

#define MOD 1000000007

char grid[1005][1005];
long long dp[1005][1005];

int main()
{
    int n;
    cin>>n;
    for(int i=1 ; i<=n ; i++){
        for(int j=1 ; j<=n ; j++){
            cin>>grid[i][j];
        }
    }

    for(int i=n ; i>=1 ; i--){
        for(int j=n ; j>=1 ; j--){
            if(grid[i][j] == '*')
                continue;

            if(i==n && j==n)
                dp[i][j] = 1;
            else
                dp[i][j] = (dp[i+1][j] + dp[i][j+1])%MOD;
        }
    }

    cout<<dp[1][1]<<endl;
    return 0;
}
