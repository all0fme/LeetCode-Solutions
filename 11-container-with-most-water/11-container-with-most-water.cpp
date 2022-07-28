class Solution {
public:
    int maxArea(vector<int>& height) {
        
        int l = 0;
        int r = height.size()-1;
        
        int ans = (r-l)*min(height[l],height[r]);
        
        while(l<r)
        {
            
            int h = min(height[l],height[r]);
            while(height[l]<=h && l<r)l++;
            while(height[r]<=h && l<r)r--;
             ans = max(ans,(r-l)*min(height[l],height[r]));
                
        }
        return ans;
        
        
    }
};