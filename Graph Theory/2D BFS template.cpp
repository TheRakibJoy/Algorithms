/** 2D BFS template **/
/** Is a node discoverable or not ? **/
#include<bits/stdc++.h>
using namespace std;
const int fx[] = {+1,-1,+0,+0};
const int fy[] = {+0,+0,+1,-1};

char grid[15][15];
int row,col;
int dis[15][15],vis[15][15];

void BFS(int sx,int sy)
{
    int nx,ny;
    queue<pair<int,int> >q;
    q.push(make_pair(sx,sy));
    vis[sx][sy]=1;
    dis[sx][sy]=0;
    while(! q.empty())
    {
        pair<int,int> u = q.front();
        q.pop();
        for(int i=0 ; i<4 ; i++)
        {
            nx=u.first+fx[i];
            ny=u.second+fy[i];
            if(nx>=0 && nx<row && ny>=0 && ny<col && vis[nx][ny]==0 && grid[nx][ny]!='#')
            {
                vis[nx][ny]=1;
                dis[nx][ny]=1+dis[u.first][u.second];
                q.push(make_pair(nx,ny));
            }
        }
    }
}
int main()
{
    int i,j,ans,x,y;
    cout<<"Enter the number of row & column : ";
    cin>>row>>col;
    getchar();
    for(i=0 ; i<row ; i++)
    {
        for(j=0 ; j<col ; j++)
            cin>>grid[i][j];
    }
    cout<<"Enter the co-ordinate of the point u want to discover : ";
    cin>>x>>y;
    BFS(0,0);
    ans = vis[x][y];
    if(ans)
    {
        printf("Discoverable in %d unit distance\n",dis[x][y]);
    }
    else
        printf("Not discoverable\n");
    return 0;
}
