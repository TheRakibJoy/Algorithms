class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int i,j,k,ans,n = (int)cost.size();
        int dp[1005];
        for(i=0 ; i<=1002 ; i++)
            dp[i] = 99999999;
        dp[0] = dp[1] = 0;
        for(i=2 ; i<=n ; i++)
            dp[i] = min(cost[i-1]+dp[i-1] , cost[i-2]+dp[i-2]);
        return dp[n];
    }
};
