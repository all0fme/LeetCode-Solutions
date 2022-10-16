class Solution {
public:
    
    int solve(int d , int idx, vector<int>& jobDifficulty, vector<vector<int>>& dp){
        
        if(d> jobDifficulty.size()-idx)
            return 1e9;
        
        if(d==1)
        {
            int mx = 0;
            while(idx<jobDifficulty.size())
            {
                mx = max(mx,jobDifficulty[idx++]);
            }
            return mx;
        }
        if(dp[d][idx]!=-1)return dp[d][idx];
        int res = 1e9;
        int mx =0;
        for(int i=idx;i<jobDifficulty.size();i++)
        {
            mx = max(mx,jobDifficulty[i]);
            
            res = min(res,mx + solve(d-1,i+1,jobDifficulty,dp));
            
        }
        return dp[d][idx] = res;
    }
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        
        if(d>jobDifficulty.size())
        {
            return -1;
            
        }
        
        vector<vector<int>> dp(d+1,vector<int>(jobDifficulty.size()+1,-1));
         return solve(d, 0, jobDifficulty,dp);
        
        
    }
};