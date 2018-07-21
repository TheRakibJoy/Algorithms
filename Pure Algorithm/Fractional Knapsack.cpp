#include<bits/stdc++.h>

using namespace std;
struct Data
{
    int id;
    double weight,profit;
    bool operator<(Data A)
    {
        if((profit/weight) > (A.profit/A.weight))
        {
            return true;
        }
        return false;
    }
};
double KnapSack(Data c[],double capacity,int NumOfProd,double x[])
{
    int n=NumOfProd,i;
    double p=0;
    double u=capacity;
    sort(c,c+n);
    for(i=0;i<n;i++)
    {
        if(c[i].weight > u)
        {
            break;
        }
        else
        {
            x[c[i].id]=1.0;
            p+=(c[i].profit*x[c[i].id]);
            u-=c[i].weight;
        }
    }
    if(i<n)
    {
        x[c[i].id]=(u/c[i].weight);
        p+=(c[i].profit*x[c[i].id]);
    }
    cout<<"Optimal Solution: \n";
    for(i=0;i<n;i++)
    {
        printf("Product id: %d, ratio = %0.2f\n",c[i].id,x[c[i].id]);
    }
    return p;
}
int main()
{
    int n,i,j;
    double capacity;
    cout<<"Enter the number of product: ";
    cin>>n;
    cout<<"Enter the knapsack capacity: ";
    cin>>capacity;
    double x[n];
    Data c[n];
    cout<<"Enter the weight & profit for each product: \n";
    for(i=0;i<n;i++)
    {
        cin>>c[i].weight>>c[i].profit;
        c[i].id=i+1;
        x[i]=0;
    }
    cout<<"Total gained profit: "<<KnapSack(c,capacity,n,x)<<endl;
    return 0;
}

