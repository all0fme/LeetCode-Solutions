class Solution {
public:
    int m,n;
    void dfs(vector<vector<int>> &h,vector<vector<int>>&vis,int i,int j){
        
        
      
        vis[i][j]=1;
        if(i+1<m && vis[i+1][j]==0 && h[i+1][j]>=h[i][j])
        dfs(h,vis,i+1,j);
        if(i-1>=0 && vis[i-1][j]==0 && h[i-1][j]>=h[i][j])
            dfs(h,vis,i-1,j);
        if(j+1<n && vis[i][j+1]==0 && h[i][j+1]>=h[i][j])
        dfs(h,vis,i,j+1);
        if(j-1>=0 && vis[i][j-1]==0 && h[i][j-1]>=h[i][j])
            dfs(h,vis,i,j-1);
        
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        m = heights.size();
        n = heights[0].size();
        vector<vector<int>> vis_pacific(m,vector<int>(n,0)), vis_atlantic(m,vector<int>(n,0));
        for(int i=0;i<n;i++)
        {
            dfs(heights,vis_pacific,0,i);
            dfs(heights,vis_atlantic,m-1,i);
        }
        for(int i=0;i<m;i++){
            dfs(heights,vis_pacific,i,0);
            dfs(heights,vis_atlantic,i,n-1);
        }
        vector<vector<int>> ans;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++){
                if(vis_pacific[i][j] && vis_atlantic[i][j] ){
                    ans.push_back({i,j});
                }
            }
        }
        return ans;
        
    }
};