#include<bits/stdc++.h>
using namespace std;

/** You can learn divide & conquer optimization in this video:https://www.youtube.com/watch?v=0BDAXKH2GyQ&t=2636s **/

bool vis[2][2]; ///I've reduced the size of this array as I won't use this in optimized sol
int opt[2][2];  ///I've reduced the size of this array as I won't use this in optimized sol

int ara[5005],rangeOR[5005][5005];
long long dp[5005][5005];

///dp[i][j] means maximum achievable cost if if we divide first j element into i groups

///opt[i][j] store the value of endOfLast for which dp[i][j] is maximum

long long recursiveNaive(int groupBaki,int pos)
{
    if(groupBaki == 0 || pos == 0){
        if(groupBaki == 0 && pos == 0)
            return 0;
        else
            return -1e18;
    }
    if(vis[groupBaki][pos])
        return dp[groupBaki][pos];

    long long ret = 0LL;
    for(int endOfLast=1 ; endOfLast <= pos ; endOfLast++)
        ret = max(ret , rangeOR[endOfLast][pos]+recursiveNaive(groupBaki-1 , endOfLast-1));

    vis[groupBaki][pos] = 1;
    return dp[groupBaki][pos] = ret;
}

long long iterativeNaive(int k,int n)
{
    for(int groupBaki=1 ; groupBaki <= k ; groupBaki++){
        for(int pos=1 ; pos <= n ; pos++){
            dp[groupBaki][pos] = 0LL;

            for(int endOfLast = 1 ; endOfLast <= pos ; endOfLast++){
                long long temp = rangeOR[endOfLast][pos] + dp[groupBaki-1][endOfLast-1];

                if(temp > dp[groupBaki][pos]){
                    dp[groupBaki][pos] = temp;
                    opt[groupBaki][pos] = endOfLast;
                }
            }
        }
    }
    return dp[k][n];
}

long long littleOptimized(int k,int n)
{
    for(int groupBaki=1 ; groupBaki <= k ; groupBaki++){
        for(int pos=1 ; pos <= n ; pos++){
            dp[groupBaki][pos] = 0LL;

            /**
            According to definition of opt[kbaki][pos] we can say that,
            opt[kbaki][pos] <= opt[kbaki][pos+1]
            So, we can iterate endOfLast = [ opt[kbaki][pos-1] , pos ]
            **/

            for(int endOfLast=max(1 , opt[groupBaki][pos-1]) ; endOfLast <= pos ; endOfLast++){
                long long temp = rangeOR[endOfLast][pos] + dp[groupBaki-1][endOfLast-1];

                if(temp > dp[groupBaki][pos]){
                    dp[groupBaki][pos] = temp;
                    opt[groupBaki][pos] = endOfLast;
                }
            }
        }
    }
    return dp[k][n];
}

void Compute(const int &groupBaki,const int &l,const int &r,const int &optl,const int &optr)
{
    if(l > r)
        return;

    int mid = (l+r)>>1;

    dp[groupBaki][mid] = 0LL;
    int optnow = optl;

    for(int endOfLast=optl ; endOfLast <= optr && endOfLast <= mid ; endOfLast++){
        long long ret = rangeOR[endOfLast][mid] + dp[groupBaki-1][endOfLast-1];
        if(ret > dp[groupBaki][mid]){
            dp[groupBaki][mid] = ret;
            optnow = endOfLast;
        }
    }
    Compute(groupBaki , l , mid-1 , optl , optnow);
    Compute(groupBaki , mid+1 , r , optnow , optr);
}

long long OptimizedIterative(int k,int n)
{
    for(int groupBaki=1 ; groupBaki <= k ; groupBaki++)
        Compute(groupBaki , 1 , n , 1 , n);
    return dp[k][n];
}

void Solve(int t)
{
    int i,j,k,n,OR;
    scanf("%d %d",&n,&k);

    for(j=1 ; j<=n ; j++){
        scanf("%d",&ara[j]);
        OR = 0;

        for(i=j ; i>=1 ; i--){
            OR |= ara[i];
            rangeOR[i][j] = OR;
        }
    }

    long long ans = OptimizedIterative(k , n);
    printf("%lld\n",ans);
}

int main()
{
    int t,T;
    scanf("%d",&T);
    for(t=1 ; t<=T ; t++)
        Solve(t);
    return 0;
}
