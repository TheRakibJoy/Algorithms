#include<bits/stdc++.h>
using namespace std;

int Prime[300000],nPrime;
int mark[1000002];
void sieve(int n)
{
    nPrime=0;
    int i,j,limit=sqrt(n*1.0)+2;
    Prime[nPrime++]=1;
    for(i=4; i<=n; i+=2)
        mark[i]=1;
    Prime[nPrime++]=2;
    for(i=3; i<=n; i+=2)
    {
        if(!mark[i])
        {
            Prime[nPrime++]=i;
            if(i<=limit)
            {
                for(j=i*i; j<=n; j+=(i*2))
                    mark[j]=1;
            }
        }
    }
}
int main()
{
    int n,c,center,low,up,i;
    while(scanf("%d %d",&n,&c) != EOF)
    {
        sieve(n);
        center=(nPrime+1)/2;
        cout<<n<<' '<<c<<": ";
        if(n<2)
            cout<<"1"<<endl;
        else if(c==0 && n%2==0)
            cout<<Prime[center]<<endl;
        else if(c==0 && n%2)
            cout<<Prime[center-1]<<endl;
        else if((2*c-1) >= nPrime)
        {
            for(i=0; i<nPrime-1; i++)
                cout<<Prime[i]<<" ";
            cout<<Prime[nPrime-1]<<endl;
        }
        else if((nPrime+1)%2 == 0)
        {
            low=(center - c);
            up=(center+c-1);
            for(i=low; i<up-1; i++)
            {
                cout<<Prime[i]<<" ";
            }
            cout<<Prime[up-1]<<endl;
        }
        else if((nPrime+1)%2 != 0)
        {
            low=(center - c);
            up=(center+c-1);
            for(i=low; i<up; i++)
            {
                cout<<Prime[i]<<" ";
            }
            cout<<Prime[up]<<endl;
        }
        cout<<endl;
    }
    return 0;
}
