#include<bits/stdc++.h>
using namespace std;

/** Some observation: ai & ansi = 0 means if any bit of ai is one, then corresponding
bit of ansi will be definitely 0. IF any bit of ai is zero, then corresponding bit of
ansi can be 0 or 1.
That means if bi = invert(ai) then ansi will be a subMask of ai.
Now run SOS to visit all subMask of invert(ai) **/

int Set(int N, int pos) {return  N = N | (1<<pos);}
int Reset(int N, int pos) {return  N = N & ~(1<<pos);}
bool Cheek(int N, int pos) {return  (bool)(N & (1<<pos));}

#define sz 1000009
int supermask = (1<<22)-1 , ara[sz],bra[sz],dp[2][1<<23];
bool fre[5000009];

int helper(int mask,int bitpos)
{
    if(bitpos >= 0)
        return dp[bitpos & 1][mask];
    else{
        if(fre[mask])
            return mask;
        else
            return -1;
    }
}

void FuN()
{
    for(int bitpos=0 ; bitpos <= 22 ; bitpos++){

        for(int mask=0 ; mask <= supermask ; mask++){
            if(Cheek(mask , bitpos))
                dp[bitpos & 1][mask] = max(helper(mask , bitpos-1) , helper(Reset(mask , bitpos) , bitpos-1));
            else
                dp[bitpos & 1][mask] = helper(mask , bitpos-1);
        }
    }
}

void Solve()
{
    int i,j,k,n;
    scanf("%d",&n);

    for(i=1 ; i<=n ; i++){
        scanf("%d",&ara[i]);
        fre[ara[i]] = 1;
        bra[i] = ara[i] ^ supermask;    ///Invert the array element
    }

    FuN();
    for(i=1 ; i<=n ; i++){
        int ansi = helper(bra[i] , 22);
        printf("%d ",ansi);
    }
    printf("\n");
}

int main()
{
    Solve();
    return 0;
}
