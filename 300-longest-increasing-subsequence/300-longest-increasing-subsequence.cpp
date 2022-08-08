class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        
       
        int len=0;
        
        for(int x :nums){
            if(len==0 || nums[len-1]<x)nums[len++]=x;
            else
                *lower_bound(begin(nums),begin(nums)+len,x) = x;
        }
        return len;
        
    }
};