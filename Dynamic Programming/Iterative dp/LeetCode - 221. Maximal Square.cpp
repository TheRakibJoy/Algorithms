class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int row = (int)matrix.size();
        if(row == 0)
            return 0;
        int col = (int)matrix[0].size();
        int ans=0,dp[row+5][col+5];
        memset(dp , 0 , sizeof(dp));
        
        for(int i=0 ; i<row ; i++){
            for(int j=0 ; j<col ; j++){
                if(matrix[i][j] == '1'){
                    dp[i][j] = 1;
                    if(i>0 && j>0)
                        dp[i][j] += min(dp[i-1][j] , min(dp[i][j-1] , dp[i-1][j-1]));
                    ans = max(ans , dp[i][j]);
                }
            }
        }
        return ans*ans;
    }
};
