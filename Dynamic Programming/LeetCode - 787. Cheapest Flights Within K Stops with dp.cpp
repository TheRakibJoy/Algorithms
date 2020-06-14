class Solution {
public:
    #define sz 205
    #define infinity 1<<30
    vector<int>graph[sz],cost[sz];
    long long dest,mxstop,dp[sz][sz];
    bool vis[sz][sz];

    long long FuN(int u,int usedstop,int parent)
    {
        if(u == dest)
            return 0LL;
        if(vis[u][usedstop])
            return dp[u][usedstop];
        long long ret1 = infinity;
        for(int i=0 ; i<(int)graph[u].size() ; i++){
            int v = graph[u][i];
            if(usedstop>0 && v!=parent)
                ret1 = min(ret1 , cost[u][i] + FuN(v , usedstop-1 , u));
        }
        vis[u][usedstop] = 1;
        return dp[u][usedstop] = ret1;
    }

    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        int i,j,u,v,w,m = (int)flights.size();
        for(i=0 ; i<sz ; i++){
            graph[i].clear();
            cost[i].clear();
        }
        for(i=0 ; i<m ; i++){
            u = flights[i][0];
            v = flights[i][1];
            w = flights[i][2];
            graph[u].push_back(v);
            cost[u].push_back(w);
        }
        for(i=0 ; i<sz ; i++){
            for(j=0 ; j<sz ; j++){
                vis[i][j] = 0;
                dp[i][j] = infinity;
            }
        }
        dest = dst;
        long long ans = FuN(src , K+1 , -1);
        if(ans >= infinity)
            return -1;
        else
            return (int)ans;
    }
};
