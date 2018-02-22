/**sample code for binary search algorithm**/

#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n,i,BEG,END,MID,ITEM;
    cin>>n;
    int a[n];
    for(i=0;i<n;i++)
        cin>>a[i];
    cout<<"enter the integer you want to searched:";
    cin>>ITEM;
    BEG=0;
    END=n-1;
    MID=(BEG+END)/2;
    while(BEG<=END && a[MID]!=ITEM)
    {
        if(ITEM<a[MID])
            END=MID-1;
        else
            BEG=MID+1;
        MID=(BEG+END)/2;
    }
    if(a[MID]==ITEM)
        cout<<"location : "<<MID<<endl;
    else
        cout<<"NOT FOUND\n";
    return 0;
}
