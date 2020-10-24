#include<bits/stdc++.h>

#define ll                      long long int
#define ull                     unsigned long long int
#define sc                      scanf
#define scin(x)                 sc("%d",&(x))
#define scin2(x,y)              sc("%d %d",&(x),&(y))
#define scln(x)                 sc("%lld",&(x))
#define scln2(x,y)              sc("%lld %lld",&(x),&(y))
#define pf                      printf
#define ms(a,b)                 memset(a,b,sizeof(a))
#define MOD                     100000007
#define RUN_CASE(t,T)           for(__typeof(t) t=1;t<=T;t++)

using namespace std;

ll dp[3][15009],prefix[15009],prefpref[15009];

/**
Here, dp[i][j] means sum of score to make summation of all faces = j, considering
ith to nth item.

prefix[j] means (dp[i+1][0] + dp[i+1][1] + --- + dp[i+1][j]).
We can re-write prefix[j] = prefix[j-1] + dp[i+1][j]

PrefPref[j] = PrefPref[j-1] + prefix[j] = (1 * dp[i+1][j]) + (2 * dp[i+1][j-1]) + (3 * dp[i+1][j-2]) + ---

Now, we have to find out ((ub-lb+1)*dp[i+1][lb]) + ((ub-lb)*dp[i+1][lb+1]) + --- + (2*dp[i+1][ub-1]) + (1*dp[i+1][ub])
How can we find it out in O(1) complexity?

Actually this above sequence is equal to
(PrefPref[ub] - PrefPref[lb-1] - ((NumberOfTerms * prefix[lb-1])%MOD) + MOD)%MOD
**/

ll FuN(ll n,ll k,ll s)
{
    ms(dp , 0);
    dp[n+1][0] = 1;
    for(ll i=n ; i>=1 ; i--){
        for(ll j=1 ; j<=s ; j++){
            for(ll val=1 ; val<=k ; val++){
                if(j-val >= 0)
                    dp[i][j] = (dp[i][j] + (val * dp[i+1][j-val])%MOD)%MOD;
                else
                    break;
            }
        }
    }
    return dp[1][s];
}

ll Optimized1(ll n,ll k,ll s)
{
    ms(dp , 0);
    ms(prefix , 0);
    ms(prefpref , 0);

    dp[n+1][0] = 1;
    prefix[0] = 1;
    prefpref[0] = 1;

    for(ll j=1 ; j<=s ; j++){
        prefix[j] = prefix[j-1] + dp[n+1][j];
        prefpref[j] = prefpref[j-1] + prefix[j];
    }

    for(ll i=n ; i>=1 ; i--){
        for(ll j=0 ; j<=s ; j++)
            dp[i&1][j] = 0;

        for(ll j=1 ; j<=s ; j++){
            ll lb = max(0LL , j-k);
            ll ub = max(0LL , j-1);
            ll increment = prefpref[ub];
            ll numberofterms = ub-lb+1;
            if(lb > 0){
                increment = (increment - prefpref[lb-1] + MOD)%MOD;
                increment = (increment - ((numberofterms * prefix[lb-1])%MOD) + MOD)%MOD;
            }
            dp[i][j] = increment;
        }

        for(ll j=0 ; j<=s ; j++){
            prefix[j] = 0;
            prefpref[j] = 0;
            if(j > 0){
                prefix[j] = prefix[j-1];
                prefpref[j] = prefpref[j-1];
            }
            prefix[j] = (prefix[j] + dp[i][j])%MOD;
            prefpref[j] = (prefpref[j] + prefix[j])%MOD;
        }
    }
    return dp[1][s];
}

ll Optimized2(ll n,ll k,ll s)
{
    ms(dp , 0);
    ms(prefix , 0);
    ms(prefpref , 0);

    dp[(n+1) & 1][0] = 1;
    prefix[0] = 1;
    prefpref[0] = 1;

    for(ll j=1 ; j<=s ; j++){
        prefix[j] = prefix[j-1] + dp[(n+1) & 1][j];
        prefpref[j] = prefpref[j-1] + prefix[j];
    }

    for(ll i=n ; i>=1 ; i--){
        for(ll j=0 ; j<=s ; j++)
            dp[i & 1][j] = 0;

        for(ll j=1 ; j<=s ; j++){
            ll lb = max(0LL , j-k);
            ll ub = max(0LL , j-1);
            ll increment = prefpref[ub];
            ll numberofterms = ub-lb+1;
            if(lb > 0){
                increment = (increment - prefpref[lb-1] + MOD)%MOD;
                increment = (increment - ((numberofterms * prefix[lb-1])%MOD) + MOD)%MOD;
            }
            dp[i & 1][j] = increment;
        }

        for(ll j=0 ; j<=s ; j++){
            prefix[j] = 0;
            prefpref[j] = 0;
            if(j > 0){
                prefix[j] = prefix[j-1];
                prefpref[j] = prefpref[j-1];
            }
            prefix[j] = (prefix[j] + dp[i & 1][j])%MOD;
            prefpref[j] = (prefpref[j] + prefix[j])%MOD;
        }
    }
    return dp[1 & 1][s];
}

void Solve(int t)
{
    ll i,j,k,n,s,ans;
    sc("%lld %lld %lld",&n,&k,&s);
    ans = Optimized2(n , k , s);

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
