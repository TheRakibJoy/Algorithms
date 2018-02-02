#include<bits/stdc++.h>
using namespace std;

int Prime[300000],nPrime;
int mark[1000002];
void sieve(int n)
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
    int n,cnt,i,dif;
    while(1)
    {
        cnt=0;
        scanf("%d",&n);
        if(n == 0)
            break;
        else
        {
            sieve(n);
            for(i=1;i<=(n/2);i++)
            {
                dif=fabs(n-i);
                if(mark[i]==0 && mark[dif]==0)
                    cnt+=1;
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}
