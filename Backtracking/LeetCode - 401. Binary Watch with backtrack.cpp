class Solution {
public:
    vector<pair<int , int>>v;   ///hour ; minutes

    bool Check(int pos,int mask)
    {
        return (bool)(mask & (1<<pos));
    }

    int Set(int pos,int mask)
    {
        return (mask | (1<<pos));
    }

    void FuN(int movbaki,int now,int mask)
    {
        if(movbaki == 0){
            int hour=0,mn=0;
            for(int i=0 ; i<=9 ; i++){
                int pos = i;
                if(Check(i , mask)){
                    if(i >= 4){
                        pos -= 4;
                        mn += (1<<pos);
                    }
                    else
                        hour += (1<<pos);
                }
            }
            if(hour>11 || mn>59)
                return;
            v.push_back(make_pair(hour,mn));
            return;
        }
        if(now > 9)
            return;
        FuN(movbaki-1 , now+1 , Set(now , mask));
        FuN(movbaki , now+1 , mask);
    }

    vector<string> readBinaryWatch(int num) {
        vector<string>ans;
        FuN(num ,0 ,  0);
        for(int i=0 ; i<(int)v.size() ; i++){
            int hour = v[i].first;
            int mn = v[i].second;

            string temp = "";
            while(hour > 0){
                int digit = hour%10;
                hour /= 10;
                temp += (digit + '0');
            }
            if(temp.empty())
                temp += '0';
            reverse(temp.begin() , temp.end());

            string temp2 = "";
            while(mn > 0){
                int digit = mn%10;
                mn /= 10;
                temp2 += (digit + '0');
            }
            while(temp2.size() < 2)
                temp2 += '0';
            reverse(temp2.begin() , temp2.end());

            temp += ':';
            temp += temp2;
            ans.push_back(temp);
        }
        sort(ans.begin() , ans.end());
        return ans;
    }
};
