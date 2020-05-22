class Solution {
public:
    int Set(int N, int pos) {return  N = N | (1<<pos);}
    int Reset(int N, int pos) {return  N = N & ~(1<<pos);}
    bool Cheek(int N, int pos) {return  (bool)(N & (1<<pos));}

    int n,dp[13][1<<13] , sz[13] , overlap[13][13];
    string ans;
    int SufPrefMatch(string &s1,string &s2)
    {
        int i,j,match=0,len1=(int)s1.size(),len2=s2.size();
        for(i=0 ; i<len1 ; i++){
            int lenbaki = len1-i;
            if(s1.substr(i , lenbaki) == s2.substr(0 , lenbaki)){
                match = lenbaki;
                break;
            }
        }
        return match;
    }

    vector<string>inp;
    int FuN(int lasttaken , int mask)
    {
        if(mask == (1<<n)-1)
            return 0;
        if(dp[lasttaken][mask] != -1)
            return dp[lasttaken][mask];
        int mn = 1<<28;
        for(int j=0 ; j<n ; j++){
            if(Cheek(mask , j)==0){
                int match = (lasttaken != 12)? overlap[lasttaken][j] : 0;
                int baki = sz[j]-match;
                int ret = baki + FuN(j , Set(mask , j));
                mn = min(mn , ret);
            }
        }
        return dp[lasttaken][mask] = mn;
    }

    void Print(int lasttaken , int mask)
    {
        if(mask == (1<<n)-1)
            return;
        int mn = 1<<28 , go = 0;
        for(int j=0 ; j<n ; j++){
            if(Cheek(mask , j) == 0){
                int match = (lasttaken != 12)? overlap[lasttaken][j] : 0;
                int baki = sz[j]-match;
                int ret = baki + dp[j][Set(mask , j)];
                if(ret < mn){
                    mn = ret;
                    go = j;
                }
            }
        }
        int match = (lasttaken != 12)? overlap[lasttaken][go] : 0;
        int baki = sz[go]-match;
        ans += inp[go].substr(match , match+baki);
        Print(go , Set(mask , go));
    }

    string shortestSuperstring(vector<string>& A) {
        int i,j,match=0;
        memset(overlap , 0 , sizeof(overlap));
        memset(dp , -1 , sizeof(dp));
        memset(sz , 0 , sizeof(sz));
        inp.clear();
        n = (int)A.size();
        for(i=0 ; i<n ; i++){
            inp.push_back(A[i]);
            sz[i] = (int)A[i].size();
            for(j=0 ; j<n ; j++)
                overlap[i][j] = SufPrefMatch(A[i] , A[j]);
        }
        ans = "";
        int ret = FuN(12 , 0);
        Print(12 , 0);
        return ans;
    }
};
