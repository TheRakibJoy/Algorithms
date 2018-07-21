#include<bits/stdc++.h>
using namespace std;

int LS(int ara[],int n,int ITEM)
{
    for(int i=0;i<n;i++)
    {
        if(ara[i] == ITEM)
            return i;
    }
    return -1;
}
int main()
{
    int i,n,item,loc;
    cout<<"Enter the size of array: ";
    cin>>n;
    int ara[n];
    cout<<"Enter the array: ";
    for(i=0;i<n;i++)
        cin>>ara[i];
    cout<<"Enter the item to be searched: ";
    cin>>item;
    loc=LS(ara,n,item);
    if(loc == -1)
        cout<<"ITEM not found in the array\n";
    else
        cout<<"Index of "<<item<<" is "<<loc<<endl;
    return 0;
}
