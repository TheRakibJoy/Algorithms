#include<bits/stdc++.h>
using namespace std;

#define sz 500005
int n,ara[sz],dp[sz],tree[4*sz];

void Update(int node,int b,int e,int pos,int val)
{
    if(pos<b || pos>e)
        return;
    if(b==pos && e==pos){
        tree[node] = val;
        return;
    }
    int mid = (b+e)>>1;
    Update(node<<1 , b , mid , pos , val);
    Update(1+(node<<1) , mid+1 , e , pos , val);
    tree[node] = max(tree[node<<1] , tree[1+(node<<1)]);
}

int Query(int node,int b,int e,int i,int j)
{
    if(e<i || b>j)
        return 0;
    if(b>=i && e<=j)
        return tree[node];
    int mid = (b+e)>>1;
    int p1 = Query(node<<1 , b , mid , i , j);
    int p2 = Query(1+(node<<1) , mid+1 , e , i , j);
    return max(p1 , p2);
}

int cnt = 0;
map<int , int>compress;
set<int>st;

void FuN()
{
    int LIS = 0;
    for(int i=n ; i>=1 ; i--){
        dp[i] = 1;
        int mx = Query(1 , 1 , cnt , compress[ ara[i] + 1 ] , cnt);
        dp[i] += mx;
        LIS = max(LIS , dp[i]);
        Update(1 , 1 , cnt , compress[ ara[i] ] , dp[i]);
    }
    cout<<LIS<<endl;
}

int main()
{
    cin>>n;
    for(int i=1 ; i<=n ; i++){
        cin>>ara[i];
        st.insert(ara[i]);
        st.insert(ara[i] + 1);
    }
    for(auto it : st){
        compress[it] = ++cnt;
    }
    FuN();
    return 0;
}
