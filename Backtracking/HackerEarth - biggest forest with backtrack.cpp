#include<bits/stdc++.h>
using namespace std;

const int fx[] = {+1 , -1 , +0 , +0};
const int fy[] = {+0 , +0 , +1 , -1};
char grid[1005][1005];
int row,col,cnt=0,vis[1005][1005];

void DFS(int x,int y)
{
    vis[x][y] = 1;
    cnt++;
    for(int k=0 ; k<4 ; k++){
        int nx = x + fx[k];
        int ny = y + fy[k];
        if(nx>=1 && nx<=row && ny>=1 && ny<=col && grid[nx][ny] == 'T' && !vis[nx][ny])
            DFS(nx , ny);
    }
}

int main()
{
    int ans = 0;
    cin>>row;
    col = row;
    for(int i=1 ; i<=row ; i++){
        for(int j=1 ; j<=col ; j++)
            cin>>grid[i][j];
    }
    for(int i=1 ; i<=row ; i++){
        for(int j=1 ; j<=col ; j++){
            if(!vis[i][j] && grid[i][j] == 'T'){
                cnt = 0;
                DFS(i , j);
                ans = max(ans , cnt);
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
