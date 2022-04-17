class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int min = prices[0];
        
        int mx = 0;
        
        for(int i=0;i<prices.size();i++)
            {
                if(prices[i]>min)
                {
                    mx = max(mx,prices[i]-min);
                    
                }
            else
                min = prices[i];
            }
        return mx;
        
    }
};