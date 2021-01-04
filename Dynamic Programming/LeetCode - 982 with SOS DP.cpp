class Solution {
public:
    ///Its an SOS DP Problem
    int fre[1<<17],dp[1<<17][17];

    int Set(int mask,int pos)
    {
        return (mask | (1<<pos));
    }

    bool Check(int mask,int pos)
    {
        return (bool)(mask & (1<<pos));
    }

    int Reset(int mask,int pos)
    {
        return (mask & (~(1<<pos)));
    }

    int FuN(int mask,int bitpos)
    {
        if(bitpos == -1)
            return fre[mask];
        if(dp[mask][bitpos] != -1)
            return dp[mask][bitpos];
        int ret1 = 0 , ret2 = 0;

        if(Check(mask , bitpos)){
            ret1 = FuN(mask , bitpos-1);
            ret2 = FuN(Reset(mask , bitpos) , bitpos-1);
        }
        else
            ret1 = FuN(mask , bitpos-1);
        return dp[mask][bitpos] = ret1 + ret2;
    }

    int countTriplets(vector<int>& A) {
        memset(fre , 0 , sizeof(fre));
        int sz = (int)A.size();
        for(int x : A)
            fre[x]++;

        ///
        memset(dp , -1 , sizeof(dp));
        int ans = 0;

        for(int i=0 ; i<sz ; i++){
            for(int j=0 ; j<sz ; j++){
                int mask = A[i] & A[j];
                int supermask = (1<<17)-1;
                mask = supermask ^ mask;

                ans += FuN(mask , 16);
            }
        }
        return ans;
    }
};
