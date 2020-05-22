class Solution {
public:
    int Set(int N, int pos) {return  N = N | (1<<pos);}
    int Reset(int N, int pos) {return  N = N & ~(1<<pos);}
    bool Cheek(int N, int pos) {return  (bool)(N & (1<<pos));}

    int totst,n,part,dp[18][1<<17];
    vector<int>vec;

    int FuN(int setno,int mask,int val)
    {
        if(mask==((1<<n)-1)){
            if(setno == totst)
                return 1;
            else
                return 0;
        }
        if(dp[setno][mask] != -1)
            return dp[setno][mask];
        int ret = 0;
        for(int i=0 ; i<n ; i++){
            if(val+vec[i]<part && Cheek(mask , i)==0)
                ret |= FuN(setno , Set(mask , i) , val+vec[i]);
            else if(val+vec[i]==part && Cheek(mask , i)==0)
                ret |= FuN(setno+1 , Set(mask , i) , 0);
        }
        return dp[setno][mask] = ret;
    }

    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int i,j,tot=0;
        n = (int)nums.size();
        vec.clear();
        for(i=0 ; i<n ; i++){
            vec.push_back(nums[i]);
            tot += nums[i];
        }
        if(tot%k != 0)
            return 0;

        ///
        totst = k;
        part = tot/k;
        memset(dp , -1 , sizeof(dp));
        return FuN(0 , 0 , 0);
    }
};
