class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]!=0)
            {
                int ptr=i;
                while(ptr>0 && nums[ptr-1]==0)
                    ptr--;
                int temp = nums[ptr];
                nums[ptr] = nums[i];
                nums[i]= temp;
                
                
            }
        }
        
    }
};