class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        vector<int> pre(n);
        vector<int> post(n);
        
        pre[0] = nums[0];
        post[n-1] = nums[n-1];
        for(int i=1;i<n;i++)
        {
            pre[i] = min(nums[i],pre[i-1]);
        }
        for(int i=n-2;i>=0;i--)
        {
            post[i] = max(nums[i],post[i+1]);
        }
        for(int i=1;i<n-1;i++)
        {
            if(pre[i-1]<nums[i] && post[i+1]>nums[i])
                return true;
        }
        return false;
        
        
    }
};