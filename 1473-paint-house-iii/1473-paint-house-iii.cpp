class Solution {
public:
    
    int solve(int i,int j,int target,vector<int>& houses, vector<vector<int>>& cost,vector<vector<vector<int>>> &dp)
    {
        int n = cost[0].size();
         int mn = 1e9;
        
        if(target<0)
            return 1e9;
        if(i>=houses.size() && target!=0)
            return 1e9;
        if(i==houses.size() && target==0)
            return 0;
        if(dp[i][j][target]!=-1)
            return dp[i][j][target];
        if(i==0)
        {
           if(houses[i]==0)
           {
               for(int k=0;k<n;k++)
                mn = min(mn,cost[i][k]+ solve(i+1,k,target-1,houses,cost,dp));
             return dp[i][j][target]=mn ;
           }
            
            else{
                mn= solve(i+1,houses[i]-1,target-1,houses,cost,dp);
                return dp[i][j][target]=mn;
            }
        }
        
        if(houses[i]!=0)
        {
            int col = houses[i];
            col--;
            if(col!=j)
                mn= solve(i+1,col,target-1,houses,cost,dp);
            else
                mn= solve(i+1,col,target,houses,cost,dp);
        }
        else{
         
             for(int k=0;k<n;k++)
            {
                if(k!=j)
                mn= min(mn,cost[i][k] + solve(i+1,k,target-1,houses,cost,dp));
                else{
                    mn= min(mn,cost[i][k] + solve(i+1,k,target,houses,cost,dp));
                }
            }
           
        }
        
        return dp[i][j][target]=mn ;
        
    }
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        
        vector<vector<vector<int>>> dp(m+1,vector<vector<int>>(n+1,vector<int>(target+1,-1)));
        int ans =solve(0,0,target,houses,cost,dp);
        return ans==1e9?-1:ans;
    }
};