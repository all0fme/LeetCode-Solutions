class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int ans=0;
        int min_so_far = INT_MAX;
        
        for(int i=0;i<prices.size();i++)
        {
            if(prices[i]<min_so_far)
            {
                min_so_far = prices[i];
            }
            else{
                ans =  max(ans,prices[i]-min_so_far);
            }
        }
        return ans;
        
    }
};