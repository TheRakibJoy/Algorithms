#include<bits/stdc++.h>
using namespace std;

int coin[1005];

int main()
{
    int i,j,k,n,ans=0;
    const int sz = 100005;
    bitset<sz>bset;

    cin>>n;
    for(i=1 ; i<=n ; i++) cin>>coin[i];

    bset[0] = 1;
    for(i=1 ; i<=n ; i++)
        bset |= (bset << coin[i]);
    for(i=1 ; i<=1e5 ; i++){
        if(bset[i])
            ans++;
    }
    cout<<ans<<endl;

    return 0;
}
