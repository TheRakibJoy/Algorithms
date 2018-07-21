#include<bits/stdc++.h>

using namespace std;

int state[10];

int main()
{
    int task[] = {0,1,2,3,4,5,6};
    int start[] = {0,3,4,9,7,1,6};
    int finish[]= {2,7,7,11,10,5,8};
    int n = 7;
    for(int i = 0; i < n; i++)
    {
        for(int j = i+1; j < n; j++)
        {
            if(finish[i]>finish[j])
            {
                swap(task[i],task[j]);
                swap(start[i],start[j]);
                swap(finish[i],finish[j]);
            }
        }
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = i+1; j < n; j++)
        {
            if(finish[i]==finish[j])
                if(start[i]>start[j])
                {
                    swap(task[i],task[j]);
                    swap(start[i],start[j]);
                    swap(finish[i],finish[j]);
                }
        }
    }
    int machine[3][7], m[] = {0,0,0}, cnt = 0, mfns;
    for(int i = 0; i < 3; i++)
    {
        mfns = 0;
        for(int j = 0; j < n; j++)
        {
            if(state[j]==0&&mfns<=start[j])
            {
                machine[i][m[i]++] = task[j];
                state[j] = 1;
                mfns = finish[j];
                cnt++;
            }
        }
        if(cnt==7) break;
    }
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < m[i]; j++)
            printf("%c ",machine[i][j]+'a');
        printf("\n");
    }
    return 0;
}
