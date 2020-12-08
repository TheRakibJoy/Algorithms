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
int ara[sz],bra[sz],dp[1<<23][23];
bool fre[5000009],vis[1<<23][23];

int FuN(int mask,int bitpos)   ///Here, bitpos means rightmost bit that can change
{
    if(bitpos == -1){
        if(fre[mask])
            return mask;
        else
            return -1;
    }
    if(vis[mask][bitpos])
        return dp[mask][bitpos];
    int ret1=-1e9 , ret2=-1e9;

    if(Cheek(mask , bitpos)){
        ret1 = FuN(mask , bitpos-1);
        ret2 = FuN(Reset(mask , bitpos) , bitpos-1);
    }
    else
        ret1 = FuN(mask , bitpos-1);

    vis[mask][bitpos] = 1;
    return dp[mask][bitpos] = max(ret1 , ret2);
}

void Solve(int t)
{
    int i,j,k,n,supermask = (1<<22)-1;
    scanf("%d",&n);

    for(i=1 ; i<=n ; i++){
        scanf("%d",&ara[i]);
        fre[ara[i]] = 1;
        bra[i] = ara[i] ^ supermask;  ///Invert the array element
    }

    for(i=1 ; i<=n ; i++){
        int ansi = FuN(bra[i] , 22);
        printf("%d ",ansi);
    }
    printf("\n");
}

int main()
{
    Solve(1);
    return 0;
}

