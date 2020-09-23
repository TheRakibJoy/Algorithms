#include<bits/stdc++.h>
using namespace std;

const int sz = 11;
const int fx[] = {-2 , -2 , -1 , -1 , +2 , +2 , +1 , +1};
const int fy[] = {+1 , -1 , +2 , -2 , +1 , -1 , +2 , -2};
int n;

int FuN(int grid[sz][sz] , int movbaki , int x , int y)
{
    if(movbaki == 0){
        if(grid[x][y] == 0){
            grid[x][y] = 1;
            return 1;
        }
        else
            return 0;
    }
    int ret = 0;
    for(int k=0 ; k<8 ; k++){
        int nx = x+fx[k];
        int ny = y+fy[k];
        if(nx>=1 && nx<=n && ny>=1 && ny<=n){
            ret += FuN(grid , movbaki-1 , nx , ny);
        }
    }
    return ret;
}

int main()
{
    int x,y,ans,mov,grid[sz][sz];
    n = 10;
    memset(grid , 0 , sizeof(grid));
    cin>>x>>y>>mov;
    ans = FuN(grid , mov , x , y);
    cout<<ans<<endl;
    return 0;
}
