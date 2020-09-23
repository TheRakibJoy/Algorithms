#include<bits/stdc++.h>
using namespace std;

int N;
const int row = 11;
const int col = 11;

bool isAttacked(int x,int y,int grid[row][col],int n) /// Check the cell(x,y) is available or not?
{
    for(int j=1 ; j<=n ; j++){  ///Check whether it can be attacked horizontally?
        if(grid[x][j])
            return 1;
    }
    for(int i=1 ; i<=n ; i++){  ///Check whether it can be attacked vertically?
        if(grid[i][y])
            return 1;
    }
    ///Check whether it can be attacked diagonally
    for(int i=1 ; i<=n ; i++){
        for(int j=1 ; j<=n ; j++){
            if(i+j == x+y && grid[i][j])
                return 1;
            if(i-j == x-y && grid[i][j])
                return 1;
        }
    }
    return 0;
}

int N_Queen(int grid[row][col],int qbaki)
{
    if(qbaki == 0)
        return 1;
    for(int i=1 ; i<=N ; i++){
        for(int j=1 ; j<=N ; j++){
            if(isAttacked(i , j , grid , N))
                continue;
            grid[i][j] = 1;
            if(N_Queen(grid , qbaki-1))
                return 1;
            grid[i][j] = 0;
        }
    }
    return 0;
}

int main()
{
    int i,j,k,ans;
    cin>>N;
    int grid[row][col];
    memset(grid , 0 , sizeof(grid));
    ans = N_Queen(grid , N);
    if(ans){
        for(i=1 ; i<=N ; i++){
            for(j=1 ; j<=N ; j++){
                printf("%d",grid[i][j]);
                if(j < N)
                    printf(" ");
            }
            printf("\n");
        }
    }
    else
        printf("Not possible\n");
    return 0;
}
