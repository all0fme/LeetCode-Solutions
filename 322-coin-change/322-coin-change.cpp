class Solution {
public:
    
    int solve(vector<int>&coins, int amount,vector<int> &dp)
    {
        if(amount==0)
            return 0;
        if(amount<0)
            return 1e9;
        int ans = 1e9;
        if(dp[amount]!=-1)
            return dp[amount];
        for(int i=0;i<coins.size();i++)
        {
            ans = min(1+solve(coins,amount-coins[i],dp),ans);
        }
        return dp[amount]=ans;
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1,-1);
        int ans =solve(coins,amount,dp);
        return ans>=1e9?-1:ans;
    }
};