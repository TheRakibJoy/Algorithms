class Solution {
public:
    
    int mn,wt[15];
    pair<int,int>dp[5005];
    string ans = "";
    
    pair<int,int> FuN(int baki)
    {
        if(baki < mn){
            if(baki == 0)
                return dp[baki] = make_pair(1 , 0);
            else
                return dp[baki] = make_pair(0 , 0);
        }
        if(dp[baki] != make_pair(-1 , -1))
            return dp[baki];
        int possible=0,mxlen=0;
        for(int i=1 ; i<=9 ; i++){
            if(baki-wt[i] >= 0){
                pair<int,int> pr = FuN(baki-wt[i]);
                if(pr.first && 1+pr.second>=mxlen){
                    mxlen = 1+pr.second;
                    possible |= pr.first;
                }
            }
        }
        return dp[baki] = make_pair(possible , mxlen);
    }
    
    void Print(int baki)
    {
        if(baki < mn){
            return;
        }
        int possible=0,mxlen=0,digit=0;
        for(int i=1 ; i<=9 ; i++){
            if(baki-wt[i] >= 0){
                pair<int,int> pr = dp[baki-wt[i]];
                if(pr.first && 1+pr.second>=mxlen){
                    mxlen = 1+pr.second;
                    possible |= pr.first;
                    digit = i;
                }
            }
        }
        if(digit > 0){
            ans += (digit+'0');
            Print(baki - wt[digit]);
        }
    }
    
    string largestNumber(vector<int>& cost, int target) {
        mn = 5005;
        ans.clear();
        ans = "";
        for(int i=0 ; i<5005 ; i++)
            dp[i] = make_pair(-1 , -1);
        for(int i=0 ; i<9 ; i++){
            wt[i+1] = cost[i];
            mn = min(mn , cost[i]);
        }
        pair<int,int>ret = FuN(target);
        if(ret.first){
            Print(target);
            return ans;
        }
        else{
            ans += '0';
            return ans;
        }
    }
};
