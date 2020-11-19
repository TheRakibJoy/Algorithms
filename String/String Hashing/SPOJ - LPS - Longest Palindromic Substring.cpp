#include<iostream>
#include<string.h>
#include<cstdio>

#define ll                      long long int
#define CIN                     ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)

using namespace std;


const int sz = 1e6+9 , mod = 1e9+7 , p = 31;
int len,hashSum[sz],revHashSum[sz],p_pow[sz];
char s[sz];

inline int add(int a, int b) {a += b; return a >= mod ? a - mod : a;}
inline int sub(int a, int b) {a -= b; return a < 0 ? a + mod : a;}
inline int mul(int a, int b) {return (ll) a * b % mod;}

void Power()
{
    p_pow[0] = 1LL;
    for(int i=1 ; i<sz ; i++){
        p_pow[i] = mul(p , p_pow[i-1]);
    }
}

void computeHash()
{
    hashSum[0] = revHashSum[len+1] = 0LL;

    for(int i=0 ; i<len ; i++){
        hashSum[i+1] = hashSum[i];
        hashSum[i+1] = add(hashSum[i+1] , mul(s[i]-'a'+1 , p_pow[i+1]));
    }


    for(int i=len-1, j=0 ; i>=0 ; i-- , j++){
        revHashSum[i+1] = revHashSum[i+2];
        revHashSum[i+1] = add(revHashSum[i+1] , mul(s[i]-'a'+1 , p_pow[j+1]));
    }
}

bool isThere(int &lb1,int &ub1,int &lb2,int &ub2)
{
    int val1 = sub(hashSum[ub1] , hashSum[lb1-1]);
    int val2 = sub(revHashSum[lb2] , revHashSum[ub2+1]);
    int basepow1 = lb1;
    int basepow2 = len-ub2+1;
    if(basepow1 >= basepow2)
        val2 = mul(val2 , p_pow[basepow1 - basepow2]);
    else
        val1 = mul(val1 , p_pow[basepow2 - basepow1]);

    return (val1 == val2);
}

void Solve()
{
    int ans = 0;

    scanf("%d",&len);
    scanf("%s",s);

    computeHash();

    for(int i=1 ; i<=len ; i++){
        ///Compute odd length palindrome
        int lo = 1 , hi = min(i , len-i+1) , mid;
        while(lo <= hi){
            mid = (lo+hi)>>1;
            int lb1 = i-mid+1;
            int ub1 = i;
            int lb2 = i;
            int ub2 = i+mid-1;

            if(isThere(lb1 , ub1 , lb2 , ub2)){
                ans = max(ans , (mid << 1)-1);
                lo = mid+1;
            }
            else
                hi = mid-1;
        }

        if(s[i] != s[i-1])
            continue;

        ///Compute even length palindrome
        lo = 1 , hi = min(i , len-(i+1)+1) , mid;
        while(lo <= hi){
            mid = (lo+hi)>>1;
            int lb1 = i-mid+1;
            int ub1 = i;
            int lb2 = i+1;
            int ub2 = i+1+mid-1;

            if(isThere(lb1 , ub1 , lb2 , ub2)){
                ans = max(ans , (mid << 1));
                lo = mid+1;
            }
            else
                hi = mid-1;
        }
    }
    printf("%d\n",ans);
}

int main()
{
    Power();
    Solve();
    return 0;
}
