class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int uniq = 0;
        int n= nums.size();
        for(int i=1;i<n;i++)
        {
            if(nums[i]!=nums[i-1])
                uniq++;
           
                nums[uniq] = nums[i];
        }
        return uniq+1;
        
        
        
    }
};