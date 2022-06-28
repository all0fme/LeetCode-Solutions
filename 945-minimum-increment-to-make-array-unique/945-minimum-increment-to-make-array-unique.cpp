class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        
        int mx =0;
        int ans=0;
        
        for(int x:nums)
        {
            if(x>mx)
                mx=x+1;
            else{
                ans+=mx-x;
                mx++;
            }
        }
        return ans;
        
    }
};