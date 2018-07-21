#include<bits/stdc++.h>

using namespace std;

struct Data
{
    int id, weight;
    bool operator<(Data A)
    {
        if(weight<A.weight)
            return true;
        return false;
    }
};

void ContainerLoading(Data c[], int capacity, int numberOfContainers, int x[])
{
    int n = numberOfContainers;
    sort(c, c + n);
    for(int i = 0; i < n; i++)
        x[i] = 0;
    for(int i = 0; i < n && c[i].weight <= capacity; i++)
    {
        x[c[i].id] = 1;
        capacity -= c[i].weight;
        cout<<c[i].weight<<' ';
    }
    cout<<endl;
}

int main()
{
    int i,n,capacity;
    cout<<"Enter the number of container: ";
    cin>>n;
    cout<<"Enter the weight of container: ";
    int ar[n];
    for(i=0;i<n;i++)
    {
        cin>>ar[i];
    }
    cout<<"Enter the capacity: ";
    cin>>capacity;
    Data c[n];
    int x[n+1];
    for(i = 0; i < n; i++)
    {
        c[i].id = i + 1;
        c[i].weight = ar[i];
    }
    ContainerLoading(c,capacity,n,x);
    cout<<"Filled up container: ";
    for(i=1;i<=n;i++)
        cout<<x[i]<<" ";
    return 0;
}
