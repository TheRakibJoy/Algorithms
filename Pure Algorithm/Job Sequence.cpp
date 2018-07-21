#include<bits/stdc++.h>
using namespace std;

struct Data
{
    int id,d,profit;
};
bool cmp(Data A,Data B)
{
    return A.profit > B.profit;
}
void JS(Data ara[],int n)
{
    int profit=0;
    sort(ara,ara+n,cmp);
    int result[n];
    bool flag[n];
    memset(flag,0,sizeof(flag));

    for(int i=0;i<n;i++)
    {
        for(int j=min(ara[i].d-1,n) ; j>=0 ; j--)
        {
            if(flag[j] == 0)
            {
                result[j]=i;
                flag[j]=1;
                break;
            }
        }
    }
    cout<<"Maximum profit sequence of Job is:\n";
    for(int i=0;i<n;i++)
    {
        if(flag[i])
        {
            cout<<ara[result[i]].id<<"\t";
            profit+=ara[result[i]].profit;
        }
    }
    cout<<"\nTotal profit = "<<profit<<endl;
}

int main()
{
    int i,n;
    cout<<"Enter the number of job: ";
    cin>>n;
    Data job[n];
    cout<<"Enter the profit & deadline of each job :\n";
    for(i=0;i<n;i++)
    {
        cin>>job[i].profit>>job[i].d;
        job[i].id=i+1;
    }
    JS(job,n);
    return 0;
}

/**
5
20 2
15 2
10 1
5 3
1 3
**/
