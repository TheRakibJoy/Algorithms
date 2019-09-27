#include<bits/stdc++.h>
using namespace std;

int SF[1000005];        /** Here we store smallest factor for each number **/
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
    int i,j,n;
    FuN(1e7);
    getFactor(45);
    for(i=0 ; i<Factor.size() ; i++)
    {
        cout<<Factor[i]<<" ";
    }
    return 0;
}
