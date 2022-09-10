class Solution {
public:
    
    int solve(int i, int k,vector<int>& prices, vector<vector<int>> &dp)
    {
        
        if(i>=prices.size()|| k==0)
            return 0;
        if(dp[i][k]!=-1)
            return dp[i][k];
        int ans =0;
        if(k%2==0)
        {
            //buy
            
            int b = -prices[i]+solve(i+1,k-1,prices,dp);
            
            //don't buy
                int db = solve(i+1,k,prices,dp);
            ans = max(b,db);
        }
        else
        {
            //sell
            
            int s = prices[i] + solve(i+1,k-1,prices,dp);
            
            // don't sell
            int ds = solve(i+1,k,prices,dp);
            ans = max(s,ds);
        }
        return dp[i][k]=ans;
        
    }
    
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        
        vector<vector<int>> dp(n,vector<int>(2*k+1,-1));
        return solve(0,2*k,prices,dp);
    }
};