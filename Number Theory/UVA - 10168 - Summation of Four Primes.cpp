#include<bits/stdc++.h>

using namespace std;
int Prime[1000000],nPrime;
bool mark[10000010];
int sieve()
{
   int n = 10000005;
    nPrime=0;
    int i,j,limit=sqrt(n*1.0)+2;
    mark[1]=1;
    for(i=4; i<=n; i+=2)
        mark[i]=1;
    Prime[nPrime++]=2;
    for(i=3; i<=limit; i+=2)
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
    return nPrime;
}

int main()
{
    int n,num,temp;
    int i;
    num = sieve();
    while(cin>>n)
    {
        int a = 2, b = 2, c = 0, d = 0;
        if(n < 8)
        {
            cout<<"Impossible.\n";
            continue;
        }
        if(n%2==1) b = 3;
        for(i=0;i<num;i++)
        {
            temp=(n-Prime[i]-(a+b));
            if(mark[temp]==0 && temp>0)
            {
                c=Prime[i];
                d=temp;
                break;
            }
        }
        cout<<a<<' '<<b<<' '<<c<<' '<<d<<endl;
    }
    return 0;
}
