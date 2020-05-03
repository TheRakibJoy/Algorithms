#include<bits/stdc++.h>
using namespace std;

#define Output                  freopen("out.txt","w",stdout)

int SF[10000005];        /** Here we store smallest factor for each number **/
void FuN()
{
    for( int i = 2 ; i * i <= 10000000 ; i ++ ){
        if( !SF[i] ){
            for( int j = i ; j <= 10000000 ; j += i ){
                if( !SF[j] ) SF[j] = i ;
            }
        }
    }
    for( int i = 2 ; i <= 1e7 ; i ++ ) if( !SF[i] ) SF[i] = i ;
}
vector<int>Factor;
void getFactor(int n)       /** It will works when prime till n is generated **/
{
    Factor.clear();
    while(n != 1)
    {
        Factor.push_back(SF[n]);
        n/=SF[n];
    }
}
int main()
{
    FuN();
    int i,n;
    while(scanf("%d",&n) != EOF)
    {
        getFactor(n);
        printf("%d = %d",n,Factor[0]);
        for(i=1 ; i<(int)Factor.size() ; i++)
            printf(" x %d",Factor[i]);
        printf("\n");
    }
    return 0;
}

