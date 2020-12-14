#include<bits/stdc++.h>
using namespace std;

int n,k,ara[105],dp[100009][3];

int main()
{
    cin>>n>>k;
    for(int i=1 ; i<=n ; i++)
        cin>>ara[i];
    sort(ara+1 , ara+n+1);

    ///Base Case
    for(int val=0 ; val<ara[1] ; val++){
        for(int player=0 ; player<2 ; player++)
            dp[val][player] = player^1;
    }

    for(int val=ara[1] ; val<=k ; val++){
        for(int player=0 ; player<2 ; player++){
            int fg;
            if(!player){    ///First player move
                fg = 1;
                for(int i=1 ; i<=n ; i++){
                    if(val-ara[i] >= 0)
                        fg &= dp[val - ara[i]][player^1];
                    else
                        break;
                }
            }
            else{           ///Second player move
                fg = 0;
                for(int i=1 ; i<=n ; i++){
                    if(val-ara[i] >= 0)
                        fg |= dp[val - ara[i]][player^1];
                    else
                        break;
                }
            }
            dp[val][player] = fg;
        }
    }
    if(!dp[k][0])
        printf("First\n");
    else
        printf("Second\n");

    return 0;
}
