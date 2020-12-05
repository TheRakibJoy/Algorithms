#include<bits/stdc++.h>
using namespace std;

#define ll      long long

struct info
{
    int st,ed,prof;
    info(){}
    info(int _st,int _ed,int _prof)
    {
        st = _st;
        ed = _ed;
        prof = _prof;
    }

    bool operator < (const info &p)const{
        if(st != p.st)
            return st < p.st;
        else
            return ed < p.ed;
    }
};

vector<info>v;
ll n,dp[200005];

ll FuN()
{
    for(ll i=n-1 ; i>=0 ; i--){
        ll lb = lower_bound(v.begin() , v.end() , info(v[i].ed+1 , v[i].ed+1 , 0)) - v.begin();
        ll temp = v[i].prof;
        if(lb < n)
            temp += dp[lb];
        dp[i] = max(dp[i+1] , temp);
    }

    return dp[0];
}

int main()
{
    ll a,b,p;
    cin>>n;
    for(ll i=1 ; i<=n ; i++){
        cin>>a>>b>>p;
        v.push_back(info(a , b , p));
    }
    sort(v.begin() , v.end());

    cout<<FuN()<<endl;
    return 0;
}
