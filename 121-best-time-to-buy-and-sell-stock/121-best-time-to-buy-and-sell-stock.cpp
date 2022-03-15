class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int ans=0;
        int min_so_far = INT_MAX;
        
        for(int i=0;i<prices.size();i++)
        {
            
                min_so_far = min(prices[i],min_so_far);
            
           
                ans =  max(ans,prices[i]-min_so_far);
            
        }
        return ans;
        
    }
};