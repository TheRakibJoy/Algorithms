///****In the name of ALLAH, most Gracious, most Compassionate****//
#include<bits/stdc++.h>

#define ll                      long long int
#define sc                      scanf
#define scin(x)                 sc("%d",&(x))
#define scin2(x,y)              sc("%d %d",&(x),&(y))
#define scln(x)                 sc("%lld",&(x))
#define scln2(x,y)              sc("%lld %lld",&(x),&(y))
#define pf                      printf
#define ms(a,b)                 memset(a,b,sizeof(a))
#define pb(a)                   push_back(a)
#define vi                      vector<int>
#define RUN_CASE(t,T)           for(__typeof(t) t=1;t<=T;t++)

using namespace std;

/**
State-1: is less than limit?
State-2: is current position is starting position?
State-3: current position from left side
State-4: is right side become bigger? IF yes, then you have to make left side smaller
State-5: Position from right
**/

ll dp[2][2][20][2][20];
vi num;

ll FuN(ll isSmall,ll isStart,ll lpos,ll isrbigger,ll rpos)
{
    if(lpos > rpos){
        return ((isrbigger && isSmall) || (!isrbigger));
    }
    if(dp[isSmall][isStart][lpos][isrbigger][rpos] != -1)
        return dp[isSmall][isStart][lpos][isrbigger][rpos];
    ll ret = 0LL , can_be_taken = 0LL;

    if(isSmall)
        can_be_taken = 9;
    else
        can_be_taken = num[lpos];

    if(!isStart){
        for(ll i=0 ; i<=can_be_taken ; i++){
            ll newrbigger;
            if(i < num[rpos])
                newrbigger = 0;
            else if(i > num[rpos])
                newrbigger = 1;
            else
                newrbigger = isrbigger;

            ret += FuN(isSmall|(i<num[lpos]) , 0 , lpos+1 , newrbigger , rpos-1);
        }
    }
    else{
        for(ll i=1 ; i<=can_be_taken ; i++){
            ll newrbigger;
            if(i < num[rpos])
                newrbigger = 0;
            else if(i > num[rpos])
                newrbigger = 1;
            else
                newrbigger = isrbigger;

            ret += FuN(isSmall|(i<num[lpos]) , 0 , lpos+1 , newrbigger , rpos-1);
        }
        ret += FuN(1 , 1 , lpos+1 , isrbigger , rpos);
    }
    return dp[isSmall][isStart][lpos][isrbigger][rpos] = ret;
}

ll Calculate(ll x)
{
    if(x < 0)
        return 0;
    if(x == 0)
        return 1;
    num.clear();
    ms(dp , -1);
    while(x){
        num.pb(x%10);
        x /= 10;
    }
    reverse(num.begin() , num.end());
    return FuN(0 , 1 , 0 , 0 , (ll)num.size()-1);
}

void Solve(int t)
{
    ll i,j,k,lft,rgt,ans;
    scln2(lft , rgt);
    if(lft >= rgt)
        swap(lft , rgt);
    ans = Calculate(rgt) - Calculate(lft-1);
    pf("Case %d: %lld\n",t,ans);
}

int main()
{
    int t,T;
    scin(T);
    RUN_CASE(t,T)
    {
        Solve(t);
    }
    return 0;
}

