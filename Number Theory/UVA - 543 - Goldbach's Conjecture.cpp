#include<bits/stdc++.h>

using namespace std;

int Prime[300000],nPrime;
int mark[1000006];

void sieve()
{
    int i,j,limit=sqrt(1000006.0)+2;
    mark[1]=1;
    for(i=4;i<=1000006;i+=2)
        mark[i]=1;
    Prime[nPrime++]=2;
    for(i=3;i<=1000006;i+=2)
    {
        if(!mark[i])
        {
            Prime[nPrime++]=i;
            if(i<=limit)
            {
                for(j=i*i;j<=1000006;j+=(i*2))
                    mark[j]=1;
            }
        }
    }
}

int main()
{
    sieve();
    int i,n,a,b,cnt;
    while(1)
    {
        cin>>n;
        if(n == 0)
            break;
        else
        {
            cnt=0;
            for(i=2;i<=(n/2.0);i++)
            {
                if(mark[i]==0 && mark[n-i]==0)
                {
                    a=i;
                    b=n-i;
                    cnt=1;
                    break;
                }
            }
            if(cnt == 0)
                cout<<"Goldbach's conjecture is wrong."<<endl;
            else
                cout<<n<<" = "<<a<<" + "<<b<<endl;
        }
    }
    return 0;
}
