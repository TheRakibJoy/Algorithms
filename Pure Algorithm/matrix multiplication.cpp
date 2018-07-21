#include<bits/stdc++.h>
using namespace std;

int main()
{
    int r1,c1,r2,c2,i,j,k;
    cout<<"Enter the order of 1st matrix: ";
    cin>>r1>>c1;
    cout<<"Enter the order of 2nd matrix: ";
    cin>>r2>>c2;
    if(c1 != r2)
    {
        cout<<"multiplication can't be possible.\n";
    }
    else
    {
        int mat1[r1][c1],mat2[r2][c2],mul[r1][c2];
        cout<<"Enter the 1st matrix: \n";
        for(i=0;i<r1;i++)
        {
            for(j=0;j<c1;j++)
            {
                cin>>mat1[i][j];
            }
        }
        cout<<"Enter the 2nd matrix: \n";
        for(i=0;i<r2;i++)
        {
            for(j=0;j<c2;j++)
            {
                cin>>mat2[i][j];
            }
        }
        for(i=0;i<r1;i++)
        {
            for(j=0;j<c2;j++)
            {
                mul[i][j]=0;
            }
        }
        for(i=0;i<r1;i++)
        {
            for(j=0;j<c2;j++)
            {
                for(k=0;k<c1;k++)
                {
                    mul[i][j]=mul[i][j] + (mat1[i][k]*mat2[k][j]);
                }
            }
        }
        cout<<"Resultant matrix is :\n";
        for(i=0;i<r1;i++)
        {
            for(j=0;j<c2;j++)
            {
                cout<<mul[i][j]<<"\t";
            }
            cout<<endl;
        }
    }
    return 0;
}

