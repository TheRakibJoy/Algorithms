#include<bits/stdc++.h>
using namespace std;

unsigned long long int Prime[300000],nPrime;
unsigned long long mark[1000002];
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
    int i,n;
    cin>>n;
    sieve(n);
    cout<<mark[n]<<endl;
    for(i=1;i<=n;i++)
    {
        cout<<mark[i]<<"\t";
    }
    cout<<endl;
    /**for(i=0;i<nPrime;i++)
    {
        cout<<Prime[i]<<"\t";
    }**/
    cout<<endl;
}
