class Solution {
public:

    bool isOn(int pos,int mask)
    {
        return (bool)(mask & (1<<pos));
    }

    int Set(int pos,int mask)
    {
        return mask | (1<<pos);
    }

    int sz1,sz2,dp[13][1<<13],mat[13][13];

    int FuN(int pos,int mask)   ///pos track group-1 ; mask track group-2
    {
        if(pos >= sz1){
            if(mask == (1<<sz2)-1)
                return 0;
            else
                return 1e9;
        }
        if(dp[pos][mask] != -1)
            return dp[pos][mask];

        int mn = 1e9 , ret1 = 1e9 , ret2 = 1e9 , ret3 = 1e9;
        for(int j=0 ; j<sz2 ; j++){
            ret1 = ret2 = ret3 = 1e9;
            if(isOn(j , mask))
                ret1 = mat[pos][j] + FuN(pos+1 , mask);
            if(!isOn(j , mask)){
                ret2 = mat[pos][j] + FuN(pos , Set(j , mask));
                ret3 = mat[pos][j] + FuN(pos+1 , Set(j , mask));
            }
            mn = min(mn , min(ret1 , min(ret2 , ret3)));
        }
        return dp[pos][mask] = mn;
    }

    int connectTwoGroups(vector<vector<int>>& cost) {
        sz1 = (int)cost.size();
        sz2 = (int)cost[0].size();
        for(int i=0 ; i<sz1 ; i++){
            for(int j=0 ; j<sz2 ; j++)
                mat[i][j] = cost[i][j];
        }
        memset(dp , -1 , sizeof(dp));
        int ans = FuN(0 , 0);
        return ans;
    }
};
