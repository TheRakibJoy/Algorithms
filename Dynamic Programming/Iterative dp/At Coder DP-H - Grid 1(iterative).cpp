#include<bits/stdc++.h>
using namespace std;

char grid[1005][1005];
int dp[1005][1005];
/** Here,dp[i][j] means number of ways from (1,1) to (i,j) cell **/
const int mod = 1e9+7;

void addSelf(int &x,int y)
{
    x += y;
    if(x >= mod)
        x -= mod;
}

int main()
{
    int i,j,row,col,ans;
    cin>>row>>col;
    for(i=1 ; i<=row ; i++){
        for(j=1 ; j<=col ; j++)
            cin>>grid[i][j];
    }

    dp[1][1] = 1;
    for(i=1 ; i<=row ; i++){
        for(j=1 ; j<=col ; j++){
            if(grid[i][j] == '#')
                continue;
            addSelf(dp[i][j] , dp[i-1][j]);
            addSelf(dp[i][j] , dp[i][j-1]);
        }
    }

    ans = dp[row][col];
    cout<<ans<<endl;

    return 0;
}
