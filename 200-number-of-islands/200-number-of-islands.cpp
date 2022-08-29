class Solution {
public:
    int m,n;
   
    void dfs(int i,int j, vector<vector<char>>& grid)
    {
        if(i<0 || i>=m || j<0 || j>=n || grid[i][j]=='0')
            return;
          grid[i][j]='0';
       
       
            dfs( i - 1, j,grid);
            dfs(i + 1, j,grid);
            dfs( i, j - 1,grid);
            dfs( i, j + 1,grid);
            
        
         
    }
    int numIslands(vector<vector<char>>& grid) {
         m = grid.size();
         n = grid[0].size();
        //vector<vector<bool>> vis(m,vector<bool>(n,false));
        int cc =0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if( grid[i][j]=='1')
                {
                    dfs(i,j,grid);
                    cc++;
                }
            }
        }
        return cc;
        
    }
};