#include<bits/stdc++.h>
using namespace std;

int dp[3005][3005];

///dp[i][j] means longest common substring of s1[i...sz1] & s2[j...sz2]

int main()
{
    int i,j,k,sz1,sz2,lcs;
    string s1,s2,ans="";
    cin>>s1>>s2;
    sz1 = (int)s1.size();
    sz2 = (int)s2.size();

    for(int pos1=sz1-1 ; pos1 >= 0 ; pos1--){
        for(int pos2=sz2-1 ; pos2 >= 0 ; pos2--){
            if(s1[pos1] == s2[pos2])
                dp[pos1][pos2] = 1 + dp[pos1+1][pos2+1];
            else
                dp[pos1][pos2] = max(dp[pos1+1][pos2] , dp[pos1][pos2+1]);
        }
    }

    lcs = dp[0][0];
//    cout<<lcs<<endl;

    i = j = 0;
    while(i<sz1 && j<sz2){
        if(s1[i] == s2[j]){
            ans += s1[i];
            i++; j++;
        }
        else{
            if(dp[i+1][j] > dp[i][j+1])
                i++;
            else
                j++;
        }
    }
    cout<<ans<<endl;

    return 0;
}
