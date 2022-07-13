class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        
        int l = 0;
        int n = nums.size();
        int mxcnt =0;
        int cnt=0;
        
        while(l<n)
        {
            if(nums[l]==1)
            {
                cnt++;
                mxcnt = max(mxcnt,cnt);
            }
            else{
                cnt =0;
                
            }
            l++;
        }
        return mxcnt;
        
    }
};