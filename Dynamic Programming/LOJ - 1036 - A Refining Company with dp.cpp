#include<bits/stdc++.h>

#define ll                      long long int
#define sc                      scanf
#define scin(x)                 sc("%d",&(x))
#define scin2(x,y)              sc("%d %d",&(x),&(y))
#define pf                      printf
#define ms(a,b)                 memset(a,b,sizeof(a))
#define RUN_CASE(t,T)           for(__typeof(t) t=1;t<=T;t++)

using namespace std;

int row,col,uranium[505][505],radium[505][505],rowsum[505][505],colsum[505][505],dp[505][505];

int FuN(int pos1,int pos2)
{
    if(pos1==0 || pos2==0)
        return 0;
    if(dp[pos1][pos2] != -1)
        return dp[pos1][pos2];
    int ret1 = 0 , ret2 = 0;
    ret1 = rowsum[pos1][pos2] + FuN(pos1-1 , pos2);    ///Take this row to uranium factory
    ret2 = colsum[pos2][pos1] + FuN(pos1 , pos2-1);
    return dp[pos1][pos2] = max(ret1 , ret2);
}

void Solve(int t)
{
    int i,j,k,ans;
    scin2(row , col);
    ///RowSum[i][j] means cumulative sum of uranium from mat[i][1] to mat[i][j]; i'th row sum
    for(i=1 ; i<=row ; i++){
        for(j=1 ; j<=col ; j++){
            scin(uranium[i][j]);
            rowsum[i][j] = rowsum[i][j-1] + uranium[i][j];
        }
    }
    for(i=1 ; i<=row ; i++){
        for(j=1 ; j<=col ; j++)
            scin(radium[i][j]);
    }

    ///ColSum[i][j] means cumulative sum of radium from mat [1][i] to mat [j][i]; i'th column sum
    for(j=1 ; j<=col ; j++){
        for(i=1 ; i<=row ; i++)
            colsum[j][i] = colsum[j][i-1] + radium[i][j];
    }

    ms(dp , -1);
    ans = FuN(row , col);
    pf("Case %d: %d\n",t,ans);
}

int main()
{
    int t,T;
    scin(T);
    RUN_CASE(t,T)
    {
        Solve(t);
    }
    return 0;
}

