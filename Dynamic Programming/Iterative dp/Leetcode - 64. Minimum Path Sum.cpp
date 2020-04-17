class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int i,j,k,ans,row,col;
        row = (int)grid.size();
        col = (int)grid[0].size();
        int dp[row+2][col+2],mat[row+2][col+2];

        for(i=1 ; i<=row ; i++){
            for(j=1 ; j<=col ; j++){
                mat[i][j] = grid[i-1][j-1];
                dp[i][j] = 1<<28;
            }
        }

        dp[0][0] = dp[0][1] = dp[1][0] = 0;
        for(i=1 ; i<=row ; i++){
            for(j=1 ; j<=col ; j++){
                if(i == 1)
                    dp[i][j] = min(dp[i][j] , dp[i][j-1]+mat[i][j]);
                else if(i>1 && j==1)
                    dp[i][j] = min(dp[i][j] , dp[i-1][j]+mat[i][j]);
                else{
                    dp[i][j] = min(dp[i][j] , dp[i][j-1]+mat[i][j]);
                    dp[i][j] = min(dp[i][j] , dp[i-1][j]+mat[i][j]);
                }
            }
        }
        return dp[row][col];
    }
};
