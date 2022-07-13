class Solution {
public:
    int trap(vector<int>& height) {
        int ans =0;
        int maxR=0;
        int n = height.size();
        vector<int> suf(n);
        
        
        suf[n-1] = height[n-1];
        
        for(int i=n-2;i>=0;i--)
        {
             suf[i] = max(height[i],suf[i+1]);
            
        }
           
        
        for(int i=0;i<n;i++)
        {
            maxR = max(maxR,height[i]);
            ans+=min(maxR,suf[i])-height[i];
        }
        return ans;
        
    }
};