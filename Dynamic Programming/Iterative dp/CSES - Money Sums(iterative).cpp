#include<bits/stdc++.h>
using namespace std;

int coin[105],dp[105][1000005];

int main()
{
    int i,j,k,n,ans=0;
    vector<int>vec;
    cin>>n;
    for(i=1 ; i<=n ; i++)   cin>>coin[i];

    dp[n+1][0] = 1;

    for(i=n ; i>=1 ; i--){
        for(j=0 ; j<=1e6 ; j++){
            if(j - coin[i] >= 0)
                dp[i][j] = dp[i+1][j] | dp[i+1][j - coin[i]];
            else
                dp[i][j] = dp[i+1][j];
        }
    }

    for(j=1 ; j<=1e6 ; j++){
        if(dp[1][j])
            vec.push_back(j);
    }

    cout<<(int)vec.size()<<endl;
    for(auto x:vec)
        cout<<x<<' ';
    cout<<endl;

    return 0;
}
