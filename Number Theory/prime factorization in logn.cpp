#include<bits/stdc++.h>
using namespace std;

bool mark[1000005];
int SP[1000005];        /** Here we store smallest factor for each number **/
vector<int> Prime;
void Sieve(int n)
{
    long long int i,j;
    mark[1]=1;
    for(i=4 ; i<=n ; i+=2){
        mark[i]=1;
        SP[i]=2;
    }
    Prime.push_back(2);
    SP[1]=1;
    SP[2]=2;
    for(i=3 ; i<=n ; i+=2)
    {
        if(!mark[i])
        {
            Prime.push_back(i);
            SP[i]=i;
            if(i*i <= n)    /** Can be overflow **/
            {
                for(j=i*i ; j<=n ; j+=(i*2)){
                    mark[j]=1;
                    if(!SP[j])SP[j]=i;
                }
            }
        }
    }
}
vector<int>Factor;
void getFactor(int n)       /** It will works when prime till n is generated **/
{
    Factor.clear();
    while(n != 1)
    {
        Factor.push_back(SP[n]);
        n/=SP[n];
    }
}
int main()
{
    int i,j,n;
    Sieve(100000);
    getFactor(45);
    for(i=0 ; i<Factor.size() ; i++)
    {
        cout<<Factor[i]<<" ";
    }
    return 0;
}
