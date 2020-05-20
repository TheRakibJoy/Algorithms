class Solution {
public:
    int minDistance(string word1, string word2) {
        int i,j,k,sz1 = (int)word1.size() , sz2 = (int)word2.size();
        int dp[1005][1005];

        for(i=sz2,j=0 ; i>=0 ; i--,j++)
            dp[sz1][i] = j;
        for(i=sz1,j=0 ; i>=0 ; i--,j++)
            dp[i][sz2] = j;

        for(i=sz1-1 ; i>=0 ; i--){
            for(j=sz2-1 ; j>=0 ; j--){
                if(word1[i] == word2[j])
                    dp[i][j] = dp[i+1][j+1];
                else{
                    dp[i][j] = 1+min(dp[i+1][j+1] , min(dp[i+1][j] , dp[i][j+1]));
                }
            }
        }
        return dp[0][0];
    }
};
