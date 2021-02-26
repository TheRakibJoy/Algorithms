class Solution {
public:
    ///Sliding window
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<pair<int , int>>dq;   ///value , index; Contain smaller to bigger element
        vector<int>ans;
        
        for(int i=0 ; i<(int)nums.size() ; i++){
            while(!dq.empty() && dq.front().first <= nums[i])   ///If left element is less or equal present value then pop it
                dq.pop_front();
            
            dq.push_front({nums[i] , i});
            
            while(!dq.empty() && dq.back().second <= i-k)       ///Pop out of range element
                dq.pop_back();
            
            if(i >= k-1)
                ans.push_back(dq.back().first);
        }
        return ans;
    }
};
