class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int dx[] = {1,0,-1,0};
        int dy[] = {0,1,0,-1};
        int time =0;
        int fresh=0;
        queue<pair<int,int>> q;
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==2)
                    q.push({i,j});
                else if(grid[i][j]==1)
                    fresh++;
            }
        }
        int flag=0;
        while(!q.empty())
        {
            flag=0;
            int x = q.size();
            for(int i=0;i<x;i++)
            {
                auto temp = q.front();
                q.pop();
                
                for(int k=0;k<4;k++)
                {
                    int xi = temp.first + dx[k];
                    int yi = temp.second+ dy[k];
                    if(xi<m && xi>=0 && yi<n && yi>=0 && grid[xi][yi]==1)
                    {
                        grid[xi][yi] = 2;
                        q.push({xi,yi});
                        flag=1;
                        fresh--;
                    }
                }
            }
            if(!flag )
                break;
            time++;
            if(!fresh)
                break;
        }
        
        
        if(!fresh)
        return time;
        else
            return -1;
    }
};