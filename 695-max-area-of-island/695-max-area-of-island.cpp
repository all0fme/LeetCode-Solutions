class Solution {
public:
    int n,m;
    int dfs(vector<vector<int>>& grid,int i,int j)
    {
        if(i>=m || i<0 || j>=n || j<0 || grid[i][j]==0)
            return 0;
        int cc =1;
        grid[i][j]=0;
        
        cc+=dfs(grid,i+1,j);
         cc+=dfs(grid,i-1,j);
         cc+=dfs(grid,i,j+1);
        cc+= dfs(grid,i,j-1);
        return cc;
        
        
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        int ans =0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                {
                   ans=max(ans, dfs(grid,i,j));
                }
            }
        }
        return ans;
    }
};