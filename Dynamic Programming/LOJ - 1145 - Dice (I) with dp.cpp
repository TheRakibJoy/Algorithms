#include<bits/stdc++.h>

#define sc                      scanf
#define scin(x)                 sc("%d",&(x))
#define pf                      printf
#define ms(a,b)                 memset(a,b,sizeof(a))
#define MOD                     100000007
#define RUN_CASE(t,T)           for(__typeof(t) t=1;t<=T;t++)

using namespace std;

int dp[3][15009],prefix[15009];

void add(int &x,int inc)
{
    x += inc;
    if(x >= MOD)
        x -= MOD;
}

int FuN(int n,int k,int s)
{
    ms(dp , 0);
    dp[n+1][0] = 1;
    for(int i=n ; i>=1 ; i--){
        for(int j=1 ; j<=s ; j++){
            for(int val=1 ; val<=k ; val++){
                if(j-val >= 0)
                    add(dp[i][j] , dp[i+1][j-val]);
                else
                    break;
            }
        }
    }

    cout<<dp[1][s]<<endl;
    return dp[1][s];
}

int Optimized1(int n,int k,int s)
{
    ms(dp , 0);
    ms(prefix , 0);

    dp[n+1][0] = 1;
    prefix[0] = 1;
    for(int j=1 ; j<=s ; j++)
        prefix[j] = prefix[j-1];

    for(int i=n ; i>=1 ; i--){
        for(int j=1 ; j<=s ; j++){
            int lb = max(0 , j-k);
            int ub = max(0 , j-1);
            int increment = prefix[ub];
            if(lb > 0){
                increment -= prefix[lb-1];
                if(increment < 0)
                    increment += MOD;
            }
            add(dp[i][j] , increment);
        }

        for(int j=0 ; j<=s ; j++){      ///Optimization with prefix sum
            prefix[j] = 0;
            if(j > 0)
                prefix[j] = prefix[j-1];
            add(prefix[j] , dp[i][j]);
        }
    }

    cout<<dp[1][s]<<endl;
    return dp[1][s];
}

int Optimized2(int n,int k,int s)
{
    ms(dp , 0);
    ms(prefix , 0);

    dp[(n+1) & 1][0] = 1;
    prefix[0] = 1;
    for(int j=1 ; j<=s ; j++)
        prefix[j] = prefix[j-1];

    for(int i=n ; i>=1 ; i--){
        for(int j=0 ; j<=s ; j++)
            dp[i & 1][j] = 0;

        for(int j=1 ; j<=s ; j++){
            int lb = max(0 , j-k);
            int ub = max(0 , j-1);
            int increment = prefix[ub];
            if(lb > 0){
                increment -= prefix[lb-1];
                if(increment < 0)
                    increment += MOD;
            }
            add(dp[i & 1][j] , increment);
        }

        for(int j=0 ; j<=s ; j++){      ///Optimization with prefix sum
            prefix[j] = 0;
            if(j > 0)
                prefix[j] = prefix[j-1];
            add(prefix[j] , dp[i & 1][j]);
        }
    }

    return dp[1 & 1][s];
}

void Solve(int t)
{
    int i,j,k,n,s,ans,tot=0;
    sc("%d %d %d",&n,&k,&s);

    ans = Optimized2(n , k , s);
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
