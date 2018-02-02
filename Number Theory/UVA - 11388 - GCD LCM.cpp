#include<bits/stdc++.h>

using namespace std;

int main()
{
    long long int g,l,gcd,lcm,T,i;
    scanf("%lld",&T);
    for(i=0; i<T; i++)
    {
        scanf("%lld %lld",&g,&l);
        gcd=__gcd(g,l);
        lcm=(g*l)/gcd;
        if(gcd==g && lcm==l)
            printf("%lld %lld\n",g,l);
        else
            printf("-1\n");
    }
    return 0;
}
