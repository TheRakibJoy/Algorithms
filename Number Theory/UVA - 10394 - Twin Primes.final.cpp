#include<bits/stdc++.h>

using namespace std;
long long int ara[1000002];
long long int Prime[20000000],nPrime;
int mark[20000002];
void sieve(long long int n)
{
    int i,j,limit=sqrt(n*1.0)+2;
    mark[1]=1;
    for(i=4;i<=n;i+=2)
        mark[i]=1;
    Prime[nPrime++]=2;
    for(i=3;i<=n;i+=2)
    {
        if(!mark[i])
        {
            Prime[nPrime++]=i;
            if(i<=limit)
            {
                for(j=i*i;j<=n;j+=(i*2))
                    mark[j]=1;
            }
        }
    }
}
int main()
{
    int s,cnt,i,j=1;
    sieve(20000000);
    for(i=0;i<nPrime-1;i++)
    {
        if((Prime[i]+2) == Prime[i+1])
        {
            ara[j]=Prime[i];
            j++;
            ara[j]=Prime[i+1];
            j++;
        }
    }
    while(scanf("%d",&s) != EOF)
    {
        cnt=(2*s)-1;
        printf("(%lld, %lld)\n",ara[cnt],ara[cnt+1]);
    }
    return 0;
}

