class Solution {
public:
    int climbStairs(int n) {
        int dp[n+5];
        memset(dp , 0 , sizeof(dp));
        dp[0] = dp[1] = 1;
        for(int i=2 ; i<=n ; i++){
            dp[i] += dp[i-1];
            dp[i] += dp[i-2];
        }
        return dp[n];
    }
};
