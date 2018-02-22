#include<bits/stdc++.h>

using namespace std;
int f[100];
int fib(int n)
{
    if(n == 0)
        return 0;
    else if(n == 1)
        return 1;
    else if(f[n] != 0)
        return f[n];
    else
        return f[n] = fib(n-1)+fib(n-2);
}
int main()
{
    cout<<fib(8)<<endl;
    return 0;
}
