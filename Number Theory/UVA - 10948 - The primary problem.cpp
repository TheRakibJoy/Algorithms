#include<bits/stdc++.h>
using namespace std;
long long int Prime[20000000],nPrime;
int mark[20000002];
void sieve(long long int n)
{
    nPrime=0;
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
    int n,p,q,i,dif;
    while(1)
    {
        p=0;
        q=0;
        scanf("%d",&n);
        if(n == 0)
            break;
        else
        {
            sieve(n);
            for(i=0;i<=((nPrime+1)/2);i++)
            {
                dif=fabs(n-Prime[i]);
                if(mark[dif] == 0)
                {
                    p=Prime[i];
                    q=dif;
                    break;
                }
            }
            if(p==0 || q==0)
                printf("%d:\nNO WAY!\n",n);
            else
                printf("%d:\n%d+%d\n",n,p,q);
        }
    }
    return 0;
}
