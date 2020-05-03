class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int i,j,k,n = (int)pairs.size() , ans = 0 , dp[n+5];
        for(i=0 ; i<=n+2 ; i++)
            dp[i] = 1;

        for(i=0 ; i<n ; i++){
            for(j=0 ; j<i ; j++){
                if(pairs[i][0] > pairs[j][1] && 1+dp[j]>dp[i])
                    dp[i] = 1+dp[j];
            }
            ans = max(ans , dp[i]);
        }
        return ans;
    }
};
