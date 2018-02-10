#include<bits/stdc++.h>
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a*b)/gcd(a,b)

using namespace std;
int main()
{
    int n,r,i,j,temp,a;
    while(1)
    {
        scanf("%d %d",&n,&r);
        long long int nCr,ara1[r+2],ara2[r+2],mul1=1,mul2=1;
        if(n==0 && r==0)
            break;
        else
        {
            a=min((n-r),r);
            temp=n-a+1;
            for(i=0; i<a; i++)
            {
                ara1[i]=temp;
                temp++;
            }
            for(i=0; i<a; i++)
            {
                ara2[i]=i+1;
            }
            for(i=0; i<a; i++)
            {

                for(j=0; j<a; j++)
                {
                    temp=gcd(ara1[i],ara2[j]);
                    ara1[i]=ara1[i]/temp;
                    ara2[j]=ara2[j]/temp;
                    if(ara1[i] == 1)
                        break;
                }
            }
            for(i=0; i<a; i++)
                mul1=mul1*ara1[i];
            nCr=mul1;
            printf("%d things taken %d at a time is %lld exactly.\n",n,r,nCr);
        }
    }
    return 0;
}
