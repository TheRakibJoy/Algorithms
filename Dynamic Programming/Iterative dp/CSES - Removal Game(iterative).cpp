#include<bits/stdc++.h>
using namespace std;

#define ll  long long
ll n,ara[5005],dp[5005][5005];

ll FuN()
{
    for(ll sz=1 ; sz<=n ; sz++){    ///Size of this subArray
        for(ll lft=1 ; lft <= n-sz+1 ; lft++){
            ll rgt = lft+sz-1;
            ll finishElement = n - sz;

            if(finishElement%2 == 0)    ///First Player Move
                dp[lft][rgt] = max(ara[lft]+dp[lft+1][rgt] , ara[rgt]+dp[lft][rgt-1]);
            else
                dp[lft][rgt] = min(dp[lft+1][rgt] , dp[lft][rgt-1]);
        }
    }
    return dp[1][n];
}

int main()
{
    cin>>n;
    for(int i=1 ; i<=n ; i++)
        cin>>ara[i];
    cout<<FuN()<<endl;
    return 0;
}
