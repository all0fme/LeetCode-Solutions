class Solution {
public:
    int maxProduct(vector<int>& nums) {
        make_heap(nums.begin(),nums.end());
        int ans = nums.front()-1;
        pop_heap(nums.begin(),nums.end());
        ans*=nums.front()-1;
        return ans;
         
    }
};