class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        int l =1;
        int r = 1;
        int n = nums.size();
        int ans =INT_MIN;
        for(int i=0;i<n;i++)
        {
            l*=nums[i];
            r*=nums[n-1-i];
            ans = max({ans,l,r});
            if(l==0)
                l =1;
            if(r==0)
                r =1;
            
            
        }
        return ans;
        
    }
};