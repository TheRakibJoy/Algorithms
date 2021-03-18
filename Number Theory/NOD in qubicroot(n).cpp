#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define sz 1000009
vector<ll>Prime;
bool mark[sz];

void Sieve(ll n)
{
    mark[0] = mark[1] = 1;
    Prime.push_back(2);
    for(ll i=4 ; i<=n ; i+=2)
        mark[i] = 1;
    for(ll i=3 ; i<=n ; i+=2){
        if(!mark[i]){
            Prime.push_back(i);
            if(i*i <= n){
                for(ll j=i*i ; j<=n ; j+=(2*i))
                    mark[j] = 1;
            }
        }
    }
}

ll NODinQubicRoot(ll n)
{
    ll ret = 1;
    for(ll p : Prime){
        if(p*p*p > n)
            break;
        ll cnt = 1;
        while(n%p == 0){
            n /= p;
            cnt++;
        }
        ret *= cnt;
    }
    int isPrime = (n <= 1000000 && mark[n] == 0) , isSquareOfPrime = 0 , NOT1 = (n != 1);
    for(ll i=0 ; i<(ll)Prime.size() && Prime[i]*Prime[i]<=n ; i++){
        if(Prime[i]*Prime[i] == n)
            isSquareOfPrime = 1;
    }

    if(isPrime)
        ret *= 2;
    else if(isSquareOfPrime)
        ret *= 3;
    else if(NOT1)
        ret *= 4;
    return ret;
}

int main()
{
    Sieve(1000000);

    cout<<NODinQubicRoot(12)<<endl;

    return 0;
}
