class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int i,j,k,n = (int)nums.size() , tot=0 , half;

        for(i=0 ; i<n ; i++)
            tot += nums[i];
        if(tot%2 == 1)
            return 0;
        half = tot/2;

        int dp[n+2][half+5];
        for(i=0 ; i<=half ; i++)
            dp[n][i] = 0;
        for(i=0 ; i<=n ; i++)
            dp[i][0] = 1;

        for(int pos=n-1 ; pos>=0 ; pos--){
            for(int value=1 ; value<=half ; value++){
                if(nums[pos] <= value)
                    dp[pos][value] = dp[pos+1][value] | dp[pos+1][value-nums[pos]];
                else
                    dp[pos][value] = 0;
            }
        }
        return dp[0][half];
    }
};
