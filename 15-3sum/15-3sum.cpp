class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int i=0;
        while(i<n)
        {
             if(i<n && i!=0 && nums[i]==nums[i-1])
             {
                 i++;
                 continue;
             }
                
            int x = - nums[i];
            int l = i+1;
            int r = n-1;
            while(l<r)
            {
                if(nums[l]+nums[r]==x)
                {
                    ans.push_back({nums[i],nums[l],nums[r]});
                    l++;
                    r--;
                    while(l<n && l!=i+1 && nums[l]==nums[l-1])
                    l++;
                    while(r>=0 && r!=n-1  && nums[r]==nums[r+1])
                    r--;
                }
                else if(nums[l]+nums[r]<x)
                    l++;
                else
                    r--;
            }
           i++;
        }
        return ans;
        
    }
};