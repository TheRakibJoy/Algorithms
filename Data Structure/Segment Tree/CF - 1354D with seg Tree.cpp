#include<bits/stdc++.h>

#define Input                   freopen("in.txt","r",stdin)
#define Output                  freopen("out.txt","w",stdout)
#define ll                      long long int
#define ull                     unsigned long long int
#define pii                     pair<int,int>
#define pll                     pair<ll,ll>
#define sc                      scanf
#define scin(x)                 sc("%d",&(x))
#define scin2(x,y)              sc("%d %d",&(x),&(y))
#define scln(x)                 sc("%lld",&(x))
#define scln2(x,y)              sc("%lld %lld",&(x),&(y))
#define pf                      printf
#define RUN_CASE(t,T)           for(__typeof(t) t=1;t<=T;t++)

using namespace std;

#define sz 1000003
int tree[4*sz];

void Update(int node,int b,int e,int i,int j,int val)
{
    if(b>j || e<i)
        return;
    if(b>=i && e<=j){
        tree[node] += val;
        return;
    }
    int mid = (b+e)>>1;
    Update(node<<1 , b , mid , i , j , val);
    Update(1+(node<<1) , mid+1 , e , i , j , val);
    tree[node] = tree[node<<1]+tree[1+(node<<1)];
}

int Query(int node,int b,int e,int val)
{
    if(b==e)
        return e;
    else{
        if(tree[node<<1] >= val)
            return Query(node<<1 , b , (b+e)>>1 , val);
        else
            return Query(1+(node<<1) , 1+((b+e)>>1) , e , val-tree[node<<1]);

    }
}

void Solve(int t)
{
    int i,k,n,cnt=0,q;
    scin2(n , q);
    for(i=1 ; i<=n ; i++){
        scin(k);
        Update(1 , 1 , 1e6 , k , k , 1);
    }
//    cout<<Query(1 , 1 , 1e6 , 1)<<endl;
    for(i=1 ; i<=q ; i++){
        scin(k);
        if(k < 0){
            int id = Query(1 , 1 , 1e6 , fabs(k));
//            cout<<id<<endl;
            Update(1 , 1 , 1e6 , id , id , -1);
        }
        else{
            Update(1 , 1 , 1e6 , k , k , 1);
        }
    }
    if(tree[1] == 0)
        pf("0\n");
    else{
        int id = Query(1 , 1 , 1e6 , 1);
        pf("%d\n",id);
    }
}

int main()
{
    int t,T;
    T = 1;
//    scin(T);
    RUN_CASE(t,T)
    {
        Solve(t);
    }
    return 0;
}
