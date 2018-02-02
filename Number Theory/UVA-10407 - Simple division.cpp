#include<bits/stdc++.h>

using namespace std;

int main()
{
    int i,j,k,ara[1005],n,tgcd;
    while(1)
    {
        for(i=0;i<1005;i++)
            ara[i]=0;
        k=0;
        while(1)
        {
            scanf("%d",&n);
            if(n==0)
                break;
            else
            {
                ara[k++]=n;
            }
        }
        if(k==0)
            break;
        else
        {
            int x = ara[0];
            tgcd=0;
            for(i=0;i<k;i++)
            {
                ara[i]=ara[i]-x;
            }
            for(i=1;i<k;i++)
            {
                tgcd=abs(__gcd(tgcd,ara[i]));
            }
            cout<<tgcd<<endl;
        }

    }
    return 0;
}
