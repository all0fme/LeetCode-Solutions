class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> pre(n+1,1),post(n+1,1),ans(n);
        
        for(int i=0;i<n;i++)
            pre[i+1] = pre[i]*nums[i];
        for(int i=n-1;i>=0;i--)
            post[i] = post[i+1]*nums[i];
        
        for(int i=0;i<n;i++)
            ans[i] = pre[i]*post[i+1];
        return ans;
        
    }
};