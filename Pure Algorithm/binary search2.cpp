/**Binary search with if the element has not found,then print the address of nearly larger element**/

#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n,i,res=-1,BEG,END,MID,ITEM;
    cin>>n;
    int a[n];
    for(i=0;i<n;i++)
        cin>>a[i];
    cin>>ITEM;
    BEG=0;
    END=n-1;
    while(BEG<=END)
    {
        MID=BEG+((END-BEG)/2);
        if(a[MID] == ITEM)
        {
            res=MID;
            break;
        }
        else if(ITEM<a[MID])
        {
            res = MID ;
            END=MID-1;
        }
        else
            BEG=MID+1;
    }
    if(res>=0)
        cout<<res+1<<endl;
    else
        cout<<n + 1<<endl;
    return 0;
}
