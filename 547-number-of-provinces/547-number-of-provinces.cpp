

void dfs(int node,vector<vector<int>>& isConnected,vector<int> &vis ){
    vis[node] = 1;
    
    for(int j = 0;j<isConnected.size();j++)
    {
        if(isConnected[node][j]==1 && vis[j]==0)
        {
            dfs(j,isConnected,vis);
        }
    }
}
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        
        int cc=0;
        vector<int> vis(201,0);
        
        for(int i=0;i<isConnected.size();i++)
        {
            if(vis[i]==0)
            {
                dfs(i,isConnected,vis);
                cc++;
            }
        }
        return cc;
        
        
    }
};