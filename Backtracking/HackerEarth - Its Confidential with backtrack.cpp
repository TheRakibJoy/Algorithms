#include<bits/stdc++.h>
using namespace std;

string s;
void FuN(int lft,int rgt)
{
    if(lft > rgt)
        return;
    int mid = (lft + rgt)/2;
    printf("%c",s[mid]);
    FuN(lft , mid-1);
    FuN(mid+1 , rgt);
}

int main()
{
    int n,t,T;
    cin>>T;
    for(t=1 ; t<=T ; t++){
        cin>>n>>s;
        FuN(0 , n-1);
        printf("\n");
    }
    return 0;
}
