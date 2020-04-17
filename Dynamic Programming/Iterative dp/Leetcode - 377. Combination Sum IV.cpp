class Solution {
public:
    unsigned long long int combinationSum4(vector<int>& nums, int target) {
        int i,j,k,n = (int)nums.size();

        unsigned long long int dp[target+2];

        for(i=0 ; i<=target ; i++)
            dp[i] = 0;

        sort(nums.begin() , nums.end());
        dp[0] = 1LL;
        for(i=1 ; i<=target ; i++){
            for(j=0 ; j<n && i-nums[j]>=0 ; j++)
                dp[i] += dp[i-nums[j]];
        }
        return dp[target];
    }
};
