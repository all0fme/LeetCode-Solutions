class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        
        int n = nums.size();
        
        int start=0;
        int end = 0;
        int sum = nums[0];
        unordered_map<int,int> mp;
        mp[nums[0]]++;
        int ans =0;
        while(start<n && end<n)
        {
            if(mp[nums[end]]==1)
            {
                ans = max(ans,sum);
                end++;
                
                if(end<n)
                {
                    mp[nums[end]]++;
                    sum+=nums[end];
                }
            }
            else{
                
                sum-=nums[start];
                mp[nums[start]]--;
                start++;
            }
        }
        return ans;
        
    }
};