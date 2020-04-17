class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int i,j,k,n = (int)coins.size() , dp[amount+5];
        for(i=0 ; i<=amount+2 ; i++)
            dp[i] = 1<<28;
        dp[0] = 0;
        sort(coins.begin() , coins.end());
        for(i=1 ; i<=amount ; i++){
            for(int j=0 ; j<n && i-coins[j]>=0 ; j++)
                dp[i] = min(dp[i] , 1+dp[i-coins[j]]);
        }
        if(dp[amount] == 1<<28)
            return -1;
        else
            return dp[amount];
    }
};
