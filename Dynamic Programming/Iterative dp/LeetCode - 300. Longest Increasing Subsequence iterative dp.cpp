class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int i,j,k,n = (int)nums.size() , ans = 0 , dp[n+5];
        for(i=0 ; i<n+2 ; i++)
            dp[i] = 1;

        for(i=0 ; i<n ; i++){
            for(j=0 ; j<i ; j++){
                if(nums[j]<nums[i] && 1+dp[j]>dp[i])
                    dp[i] = 1+dp[j];
            }
        }
        for(i=0 ; i<n ; i++)
            ans = max(ans , dp[i]);
        return ans;
    }
};
