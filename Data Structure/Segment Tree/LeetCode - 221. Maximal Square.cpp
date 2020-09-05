class Solution {
public:
    
    #define sz 10005
    int tana[sz],tree[4*sz];
    
    void Init(int node,int b,int e)
    {
        if(b == e){
            tree[node] = tana[b];
            return;
        }
        int mid = (b+e)>>1;
        int lft = node<<1;
        int rgt = lft+1;
        Init(lft , b , mid);
        Init(rgt , mid+1 , e);
        tree[node] = min(tree[lft] , tree[rgt]);
    }
    
    int Query(int node,int b,int e,int i,int j)
    {
        if(e<i || b>j)
            return 99999999;
        if(b>=i && e<=j)
            return tree[node];
        int mid = (b+e)>>1;
        int lft = node<<1;
        int rgt = lft+1;
        int p1 = Query(lft , b , mid , i , j);
        int p2 = Query(rgt , mid+1 , e , i , j);
        return min(p1 , p2);
    }
    
    int maximalSquare(vector<vector<char>>& matrix) {
        int i,j,k,ans = 0, row,col;
        memset(tana , 0 , sizeof(tana));
        row = (int)matrix.size();
        if(row == 0)
            return 0;
        col = (int)matrix[0].size();
        
        for(i=0 ; i<row ; i++){
            for(j=0 ; j<col ; j++)
                tana[j+1] = (matrix[i][j] == '0')? 0 : (tana[j+1] + 1);
            Init(1 , 1 , col);
            for(j=0 ; j<col ; j++){
                int lo=j+1,hi=col,mid,res=0;
                while(lo <= hi){
                    mid = (lo+hi)>>1;
                    int mn = Query(1 , 1 , col , j+1 , mid);
                    int dif = mid-(j+1)+1;
                    if(mn >= dif){
                        res = max(res , dif*dif);
                        lo = mid+1;
                    }
                    else
                        hi = mid-1;
                }
                ans = max(ans , res);
            }
        }
        return ans;
    }
};
