#include<bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template<typename T> using orderset = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

/** You can learn divide & conquer optimization in this video:https://www.youtube.com/watch?v=0BDAXKH2GyQ&t=2636s **/

int h[5005],unhap[5005][5005],dp[5005][5005],opt[5005][5005];

///unhap[i][j] means sum of unhappyNESS if we build a row by taking ith to jth warrior

///dp[i][j] means minimum unhappyNESS if we divide first j warriors into i row.

///opt[i][j] store the value of endOfLast for which dp[i][j] is minimum

int recursiveNaive(int kbaki,int pos)
{
    if(kbaki == 0 || pos == 0){
        if(kbaki == 0 && pos == 0)
            return 0;
        else
            return 1e9;
    }
    if(dp[kbaki][pos] != -1)
        return dp[kbaki][pos];

    int ret = 1e9;
    for(int endoflast=1 ; endoflast <= pos ; endoflast++){
        ret = min(ret , unhap[endoflast][pos] + recursiveNaive(kbaki-1 , endoflast-1));
    }
    return dp[kbaki][pos] = ret;
}

int iterativeNaive(int k , int n)
{
    ///Base Case
    for(int kbaki=1 ; kbaki <= k ; kbaki++)
        dp[kbaki][0] = 1e9;
    for(int pos=1 ; pos <= n ; pos++)
        dp[0][pos] = 1e9;

    for(int kbaki=1 ; kbaki <= k ; kbaki++){
        for(int pos=1 ; pos <= n ; pos++){
            dp[kbaki][pos] = 1e9;

            for(int endoflast=1 ; endoflast <= pos ; endoflast++){
                int temp = unhap[endoflast][pos] + dp[kbaki-1][endoflast-1];

                if(temp < dp[kbaki][pos]){
                    dp[kbaki][pos] = temp;
                    opt[kbaki][pos] = endoflast;
                }
            }
        }
    }
    return dp[k][n];
}

int littleOptimized(int k,int n)
{
    ///Base Case
    for(int kbaki=1 ; kbaki <= k ; kbaki++)
        dp[kbaki][0] = 1e9;
    for(int pos=1 ; pos <= n ; pos++)
        dp[0][pos] = 1e9;

    for(int kbaki=1 ; kbaki <= k ; kbaki++){
        for(int pos=1 ; pos <= n ; pos++){
            dp[kbaki][pos] = 1e9;

            /**
            According to definition of opt[kbaki][pos] we can say that,
            opt[kbaki][pos] <= opt[kbaki][pos+1]

            So, we can iterate endOfLast = [ opt[kbaki][pos-1] , pos ]
            **/

            for(int endoflast=max(1 , opt[kbaki][pos-1]) ; endoflast <= pos ; endoflast++){
                int temp = unhap[endoflast][pos] + dp[kbaki-1][endoflast-1];

                if(temp < dp[kbaki][pos]){
                    dp[kbaki][pos] = temp;
                    opt[kbaki][pos] = endoflast;
                }
            }
        }
    }
    return dp[k][n];
}

void Compute(int kbaki,int l,int r,int optl,int optr)
{
    if(l > r)
        return;

    int mid = (l+r)>>1;

    dp[kbaki][mid] = 1e9;
    int optNow = optl;

    for(int endoflast=optl ; endoflast <= optr && endoflast <= mid ; endoflast++){
        int ret = unhap[endoflast][mid] + dp[kbaki-1][endoflast-1];
        if(ret < dp[kbaki][mid]){
            dp[kbaki][mid] = ret;
            optNow = endoflast;
        }
    }
    Compute(kbaki , l , mid-1 , optl , optNow);
    Compute(kbaki , mid+1 , r , optNow , optr);
}

int OptimizedIterative(int k,int n)
{
    ///Base Case
    for(int kbaki=1 ; kbaki <= k ; kbaki++)
        dp[kbaki][0] = 1e9;
    for(int pos=1 ; pos <= n ; pos++)
        dp[0][pos] = 1e9;

    for(int kbaki=1 ; kbaki <= k ; kbaki++)
        Compute(kbaki , 1 , n , 1 , n);
    return dp[k][n];
}

void Solve()
{
    int i,j,k,n,ans;
    scanf("%d %d",&n,&k);
    for(i=1 ; i<=n ; i++)
        scanf("%d",&h[i]);

    for(i=1 ; i<=n ; i++){
        orderset<pair<int , int>>st;
        st.insert({h[i] , i});
        int sz = 1 , cnt = 0;

        unhap[i][i] = cnt;

        for(j=i+1 ; j<=n ; j++){
            int temp = st.order_of_key({h[j]+1 , 0});

            cnt += sz - temp;
            unhap[i][j] = cnt;

            st.insert({h[j] , j});
            sz++;
        }
    }

    ans = OptimizedIterative(k , n);
    printf("%d\n",ans);
}

int main()
{
    Solve();
    return 0;
}
