class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> ans(n,-1);
        
        for(int b=0;b<n;b++)
        {
            int cur_col = b;
            int cur_row = 0;
            bool stuck = false;
            
            while(cur_row<m && !stuck)
            {
                if(grid[cur_row][cur_col]==1)
                {
                    if(cur_col==n-1 || grid[cur_row][cur_col+1]==-1)
                    {
                        stuck = true;
                    }
                    else{
                        cur_col++;
                        cur_row++;
                    }
                }
                else{
                     if(cur_col==0 || grid[cur_row][cur_col-1]==1)
                    {
                        stuck = true;
                    }
                    else{
                        cur_col--;
                        cur_row++;
                    }
                    
                }
            }
            if(!stuck)
            {
                ans[b] = cur_col;
            }
            
        }
        return ans;
    }
};