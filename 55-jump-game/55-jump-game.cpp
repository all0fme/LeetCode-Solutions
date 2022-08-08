class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
       
        
        int mx = nums[0];
      
        for(int i=1;i<n;i++)
        {
            if(mx==0)
            return false;
            mx = max(mx-1,nums[i]);
           
        }
        return true;
        
    }
};