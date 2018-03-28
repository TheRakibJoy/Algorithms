#include<bits/stdc++.h>

using namespace std;
bool check(int N,int pos)
{
    return (bool)(N&(1<<pos));
}
int Set(int N,int pos)
{
    return N=N|(1<<pos);
}
vector<int>prime;
int n=100000000,status[100000000/32];
void sieve()
{
    int i,j,sqrtN;
    sqrtN=int(sqrt(n));
    prime.push_back(2);
    for(i=3;i<=sqrtN;i+=2)
    {
        if(check(status[i/32],i%32) == 0)
        {
            for(j=i*i;j<=n;j+=(2*i))
            {
                status[j/32]=Set(status[j/32],j%32);
            }
        }
    }
    for(i=3;i<=n;i+=2)
    {
        if(check(status[i/32],i%32) == 0)
            prime.push_back(i);
    }
}
int main()
{
    int i;
    sieve();
    for(i=0;i<prime.size();i+=100)
    {
        printf("%d\n",prime[i]);
    }
    return 0;
}
