/** Problem: You're given an array of numbers A[]. You have to answer different queries.
Each query will have one number X. You need to find a number from the array such that
(A[i] ^ X) is maximum **/

#include<bits/stdc++.h>
using namespace std;

int Set(int N, int pos) {return  N = N | (1<<pos);}
int Reset(int N, int pos) {return  N = N & ~(1<<pos);}
bool Cheek(int N, int pos) {return  (bool)(N & (1<<pos));}

#define sz 100009
int tot_node = 1 , to[sz][2] , endmark[sz] , ara[sz];

void Add(int num)
{
    int curr = 1;
    for(int i=30 ; i>=0 ; i--){
        int bit = Cheek(num , i);

        if(!to[curr][bit])
            to[curr][bit] = ++tot_node;
        curr = to[curr][bit];
    }
    endmark[curr] = 1;
}

int findBest(int num)
{
    int curr = 1 , ans = 0;
    for(int i=30 ; i>=0 ; i--){
        int bit = Cheek(num , i);

        if(to[curr][bit^1])
            curr = to[curr][bit^1] , ans = Set(ans , i);
        else if(to[curr][bit])
            curr = to[curr][bit];
        else
            break;
    }
    return ans;
}

void Solve()
{
    int i,x,n,ans,q;
    cin>>n;
    for(i=1 ; i<=n ; i++){
        cin>>ara[i];
        Add(ara[i]);
    }
    cin>>q;
    for(i=1 ; i<=q ; i++){
        cin>>x;
        ans = findBest(x);
        cout<<ans<<endl;
    }
}

int main()
{
    Solve();
    return 0;
}
