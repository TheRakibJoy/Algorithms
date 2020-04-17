class Solution {
public:
    int uniquePaths(int m, int n) {
        int i,j,k,row=n,col=m;
        int dp[row+2][col+2];
        memset(dp , 0 , sizeof(dp));

        dp[0][0] = dp[0][1] = dp[1][0] = 1;
        for(i=1 ; i<=row ; i++){
            for(j=1 ; j<=col ; j++){
                if(i == 1)
                    dp[i][j] += dp[i][j-1];
                else if(i>1 && j==1)
                    dp[i][j] += dp[i-1][j];
                else{
                    dp[i][j] += dp[i][j-1];
                    dp[i][j] += dp[i-1][j];
                }
            }
        }
        return dp[row][col];
    }
};
