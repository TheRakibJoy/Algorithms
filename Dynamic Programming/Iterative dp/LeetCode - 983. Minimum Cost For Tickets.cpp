class Solution {
public:
    int dp[505];
    int Evaluate(int pos,int n)
    {
        if(pos >= n)
            return 0;
        else
            return dp[pos];
    }

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int i,j,k,n = (int)days.size(),ans;
        for(int i=0 ; i<=500 ; i++)
            dp[i] = 1<<30;

        for(i=n-1 ; i>=0 ; i--){
            dp[i] = min(dp[i] , costs[0] + Evaluate(i+1 , n));

            int ub = upper_bound(days.begin() , days.end() , days[i]+7-1)-days.begin();
            dp[i] = min(dp[i] , costs[1] + Evaluate(ub , n));

            ub = upper_bound(days.begin() , days.end() , days[i]+30-1)-days.begin();
            dp[i] = min(dp[i] , costs[2] + Evaluate(ub , n));
        }
        return dp[0];
    }
};
