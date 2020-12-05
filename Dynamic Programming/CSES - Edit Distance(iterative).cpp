#include<bits/stdc++.h>
using namespace std;

int dp[5005][5005];
string s1,s2;

int FuN()
{
    int sz1 = (int)s1.size();
    int sz2 = (int)s2.size();

    for(int i=1 ; i<=sz1 ; i++){
        for(int j=1 ; j<=sz2 ; j++){
            if(s1[i-1] == s2[j-1])
                dp[i][j] = dp[i-1][j-1];
            else{
                dp[i][j] = 1+dp[i-1][j-1];                  ///Replace Operation
                dp[i][j] = min(dp[i][j] , 1+dp[i-1][j]);    ///Remove Operation
                dp[i][j] = min(dp[i][j] , 1+dp[i][j-1]);    ///Add Operation
            }
        }
    }
}

int main()
{
    cin>>s1>>s2;
    cout<<FuN()<<endl;
    return 0;
}
/**
TWXFUABGBNLTBFNSUVQW
GPNJILFXJUIZPLTVUIB
ANS: 19
**/
