class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int i,j,sz1 = (int)text1.size() , sz2 = (int)text2.size();
        int dp[sz1+5][sz2+5];

        for(i=0 ; i<=sz1 ; i++) dp[i][sz2] = 0;
        for(i=0 ; i<=sz2 ; i++) dp[sz1][i] = 0;

        for(i=sz1-1 ; i>=0 ; i--){
            for(j=sz2-1 ; j>=0 ; j--){
                if(text1[i] == text2[j])
                    dp[i][j] = 1+dp[i+1][j+1];
                else
                    dp[i][j] = max(dp[i+1][j] , dp[i][j+1]);
            }
        }
        return dp[0][0];
    }
};
