/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int>graph[1005];
    int cnt=0,dp[3][1005];

    void DFSLL(TreeNode* root , int par)
    {
        int u = ++cnt;
        if(par != -1){
            graph[par].push_back(u); ///unidirectional
        }
        if(root->left != NULL){
            DFSLL(root->left , u);
        }
        if(root->right != NULL){
            DFSLL(root->right , u);
        }
    }

    int FuN(int musttake , int u)
    {
        if((int)graph[u].size()==0){
            if(musttake >= 1)
                return 1;
            else
                return 0;
        }
        if(dp[musttake][u] != -1)
            return dp[musttake][u];
        int ret1 = 1<<28 , ret2 = 1<<28 , ret3 = 1<<28 ,ret4 = 1<<28, ret = 0;
        if(musttake == 2){  ///When you must take it
            ret = 1;
            for(auto v:graph[u]){
                ret += FuN(0 , v);
            }
        }
        else{
            ret = 0; ret3 = 1 , ret4 = 0;
            int v1 = (graph[u].size() >= 1)? graph[u][0] : -1;
            int v2 = (graph[u].size() >= 2)? graph[u][1] : -1;
            if(v1 != -1 && v2 != -1){   ///When u can cover present node by one of its child. Then u can cover its another child by delay 1.
                ret1 = FuN(1 , v1) + FuN(2 , v2);
                ret2 = FuN(2 , v1) + FuN(1 , v2);
            }
            if(v1 != -1){
                ret3 += FuN(0 , v1);    ///Take it
                ret4 += FuN(musttake+1 , v1);   ///Don't take it
            }
            if(v2 != -1){
                ret3 += FuN(0 , v2);    ///Take it
                ret4 += FuN(musttake+1 , v2);   ///Don't take it
            }
            ret += min(ret1 , min(ret2 , min(ret3 , ret4)));
        }
        return dp[musttake][u] = ret;
    }

    int minCameraCover(TreeNode* root) {
        memset(dp , -1 , sizeof(dp));
        for(int i=0 ; i<=1002 ; i++)
            graph[i].clear();
        cnt = 0;

        DFSLL(root , -1);
        return max(1 , FuN(1 , 1));
    }
};
