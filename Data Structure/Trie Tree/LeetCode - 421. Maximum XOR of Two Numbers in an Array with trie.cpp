class Solution {
public:

    int Set(int N, int pos) {return  N = N | (1<<pos);}
    int Reset(int N, int pos) {return  N = N & ~(1<<pos);}
    bool Cheek(int N, int pos) {return  (bool)(N & (1<<pos));}

    #define sz 1000009
    int tot_node = 1 , to[sz][2] , endmark[sz] , ara[sz];

    void Add(int num)
    {
        int curr = 1;
        for(int i=30 ; i>=0 ; i--){
            int bit = Cheek(num , i);

            if(!to[curr][bit])
                to[curr][bit] = ++tot_node;
            curr = to[curr][bit];
        }
        endmark[curr] = 1;
    }

    int findBest(int num)
    {
        int curr = 1 , ans = 0;
        for(int i=30 ; i>=0 ; i--){
            int bit = Cheek(num , i);

            if(to[curr][bit^1])
                curr = to[curr][bit^1] , ans = Set(ans , i);
            else if(to[curr][bit])
                curr = to[curr][bit];
            else
                break;
        }
        return ans;
    }

    int findMaximumXOR(vector<int>& nums) {
        tot_node = 1;
        memset(to , 0 , sizeof(to));
        memset(endmark , 0 , sizeof(endmark));
        int n = (int)nums.size();

        for(int i=0 ; i<n ; i++){
            ara[i+1] = nums[i];
            Add(nums[i]);
        }

        int ans = 0;
        for(int i=1 ; i<=n ; i++){
            ans = max(ans , findBest(ara[i]));
        }
        return ans;
    }
};
