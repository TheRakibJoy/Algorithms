class Solution {
public:

    bool vis[20][20];
    const int mod = 1e9+7;
    long long i,j,k,row,col,mat[20][20];
    pair<long long, long long>dp[20][20];

    pair<long long, long long> FuN(int pos1,int pos2)
    {
        if(pos1==row && pos2==col)
            return make_pair(mat[pos1][pos2] , mat[pos1][pos2]);
        if(vis[pos1][pos2])
            return dp[pos1][pos2];
        pair<long long,long long>pr1,pr2;
        long long mx,mn;

        if(pos1 < row && pos2 < col){
            pr1 = FuN(pos1+1 , pos2);
            pr2 = FuN(pos1 , pos2+1);

            mx = mat[pos1][pos2] * pr1.first;
            mx = max(mx , mat[pos1][pos2] * pr1.second);
            mx = max(mx , mat[pos1][pos2] * pr2.first);
            mx = max(mx , mat[pos1][pos2] * pr2.second);

            mn = mat[pos1][pos2] * pr1.first;
            mn = min(mn , mat[pos1][pos2] * pr1.second);
            mn = min(mn , mat[pos1][pos2] * pr2.first);
            mn = min(mn , mat[pos1][pos2] * pr2.second);
        }
        else if(pos1 < row){
            pr1 = FuN(pos1+1 , pos2);
            mx = max(mat[pos1][pos2]*pr1.first , mat[pos1][pos2]*pr1.second);
            mn = min(mat[pos1][pos2]*pr1.first , mat[pos1][pos2]*pr1.second);
        }
        else{
            pr2 = FuN(pos1 , pos2+1);
            mx = max(mat[pos1][pos2]*pr2.first , mat[pos1][pos2]*pr2.second);
            mn = min(mat[pos1][pos2]*pr2.first , mat[pos1][pos2]*pr2.second);
        }
        vis[pos1][pos2] = 1;
        return dp[pos1][pos2] = make_pair(mx , mn);
    }

    int maxProductPath(vector<vector<int>>& grid) {
        row = grid.size();
        col = grid[0].size();
        memset(vis , 0 , sizeof(vis));
        for(i=1 ; i<=row ; i++){
            for(j=1 ; j<=col ; j++)
                mat[i][j] = grid[i-1][j-1];
        }
        pair<long long , long long> ans = FuN(1 , 1);
        long long mx = max(ans.first , ans.second);
        if(mx < 0)
            return -1;
        return mx % mod;
    }
};
