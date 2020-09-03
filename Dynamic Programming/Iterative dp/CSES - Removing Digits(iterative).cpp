#include<bits/stdc++.h>
using namespace std;

int dp[1000005];

int main()
{
    int n;
    cin>>n;

    for(int value=0 ; value<=n ; value++){
        if(value == 0){
            dp[value] = 0;
            continue;
        }

        int ret = 1e9 , temp = value;
        while(temp){
            int digit = temp%10;
            if(digit>0)
                ret = min(ret , 1+dp[value-digit]);
            temp /= 10;
        }
        dp[value] = ret;
    }
    cout<<dp[n]<<endl;

    return 0;
}
