#include<bits/stdc++.h>
using namespace std;

#define sz 300005
#define pii pair<int , int>

int h[sz],dp[sz];
pii tree[4*sz]; ///max ; min

void Init(int node,int b,int e)
{
    if(b == e){
        tree[node] = make_pair(h[b] , h[b]);
        return;
    }
    int mid = (b+e)>>1;
    Init(node<<1 , b , mid);
    Init(1+(node<<1) , mid+1 , e);
    tree[node].first = max(tree[node<<1].first , tree[1+(node<<1)].first);
    tree[node].second = min(tree[node<<1].second , tree[1+(node<<1)].second);
}

pii Query(int node,int b,int e,int i,int j)
{
    if(i>e || j<b)
        return make_pair(0 , 1e9+7);
    if(b>=i && e<=j)
        return tree[node];
    int mid = (b+e)>>1;
    pii pr1 = Query(node<<1 , b , mid , i , j);
    pii pr2 = Query(1+(node<<1) , mid+1 , e , i , j);
    return make_pair(max(pr1.first , pr2.first) , min(pr1.second , pr2.second));
}

int GreaterEqualf(int node,int b,int e,int i,int j,int pos) ///[pos+1 , n , pos]
{
    if(e<i || b>j || b>e)
        return 1e9;
    if(b>=i && e<=j){
        if(b == e){
            if(tree[node].first >= h[pos])
                return b;
            else
                return 1e9;
        }
        else{
            int mid = (b+e)>>1;
            if(tree[node<<1].first >= h[pos])
                return GreaterEqualf(node<<1 , b , mid , i , j , pos);
            else if(tree[1+(node<<1)].first >= h[pos])
                return GreaterEqualf(1+(node<<1) , mid+1 , e , i , j , pos);
            else
                return 1e9;
        }
    }
    int mid = (b+e)>>1;
    int p1 = GreaterEqualf(node<<1 , b , mid , i , j , pos);
    int p2 = GreaterEqualf(1+(node<<1) , mid+1 , e , i , j , pos);
    return min(p1 , p2);
}

int LessEqualf(int node,int b,int e,int i,int j,int pos)    ///[pos+1 , n , pos]
{
    if(e<i || b>j || b>e)
        return 1e9;
    if(b>=i && e<=j){
        if(b == e){
            if(tree[node].second <= h[pos])
                return b;
            else
                return 1e9;
        }
        else{
            int mid = (b+e)>>1;
            if(tree[node<<1].second <= h[pos])
                return LessEqualf(node<<1 , b , mid , i , j , pos);
            else if(tree[1+(node<<1)].second <= h[pos])
                return LessEqualf(1+(node<<1) , mid+1 , e , i , j , pos);
            else
                return 1e9;
        }
    }
    int mid = (b+e)>>1;
    int p1 = LessEqualf(node<<1 , b, mid , i , j , pos);
    int p2 = LessEqualf(1+(node<<1) , mid+1 , e , i , j , pos);
    return min(p1 , p2);
}

int Lessb(int node,int b,int e,int i,int j,int pos)    ///[1 , pos-1 , pos]
{
    if(e<i || b>j || b>e)
        return -1;
    if(b>=i && e<=j){
        if(b == e){
            if(h[pos] > tree[node].second)
                return b;
            else
                return -1;
        }
        else{
            int mid = (b+e)>>1;
            if(h[pos] > tree[1+(node<<1)].second)
                return Lessb(1+(node<<1) , mid+1 , e , i , j , pos);
            else if(h[pos] > tree[node<<1].second)
                return Lessb(node<<1 , b , mid , i , j , pos);
            else
                return -1;
        }
    }
    int mid = (b+e)>>1;
    int p1 = Lessb(node<<1 , b , mid , i , j , pos);
    int p2 = Lessb(1+(node<<1) , mid+1 , e , i , j , pos);
    return max(p1 , p2);
}

int Greaterb(int node,int b,int e,int i,int j,int pos)
{
    if(e<i || b>j || b>e)
        return -1;
    if(b>=i && e<=j){
        if(b == e){
            if(h[pos] < tree[node].first)
                return b;
            else
                return -1;
        }
        else{
            int mid = (b+e)>>1;
            if(h[pos] < tree[1+(node<<1)].first)
                return Greaterb(1+(node<<1) , mid+1 , e , i , j , pos);
            else if(h[pos] < tree[node<<1].first)
                return Greaterb(node<<1 , b , mid , i , j , pos);
            else
                return -1;
        }
    }
    int mid = (b+e)>>1;
    int p1 = Greaterb(node<<1 , b , mid , i , j , pos);
    int p2 = Greaterb(1+(node<<1) , mid+1 , e , i , j , pos);
    return max(p1 , p2);
}

int main()
{
    int i,j,k,n,ans,mx=0,mn=1e9+7,mxnear=-1,mnnear=-1;
    cin>>n;
    for(i=1 ; i<=n ; i++){
        cin>>h[i];
        dp[i] = 1e9+7;
    }
    Init(1 , 1 , n);

    dp[n] = 0;

    for(i=n ; i>=1 ; i--){
        if(i == n)
            dp[i] = 0;
        else
            dp[i] = min(dp[i] , 1+dp[i+1]);

        ///
        int id = GreaterEqualf(1 , 1 , n , i+1 , n , i);
        if(id>i && id<=n)
            dp[i] = min(dp[i] , 1+dp[id]);

        ///
        id = Lessb(1 , 1 , n , 1 , i-1 , i);
        if(id>=1 && id<=n && Query(1 , 1 , n , id+1 , i-1).second > h[i])
            dp[id] = min(dp[id] , 1+dp[i]);

        ///
        id = Greaterb(1 , 1 , n , 1 , i-1 , i);
        if(id>=1 && id<=n && Query(1 , 1 , n , id+1 , i-1).first < h[i])
            dp[id] = min(dp[id] , 1+dp[i]);

        ///
        id = LessEqualf(1 , 1 , n , i+1 , n , i);
        if(id>i && id<=n)
            dp[i] = min(dp[i] , 1+dp[id]);
    }

    cout<<dp[1]<<endl;

    return 0;
}

