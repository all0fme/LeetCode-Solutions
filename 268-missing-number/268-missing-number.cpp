class Solution {
public:
    int missingNumber(vector<int>& nums) {
        vector<int> mp(nums.size()+1,0);
        for(int x: nums)
            mp[x]++;
        for(int i=0;i<=nums.size();i++)
            if(mp[i]==0)
                return i;
    return -1;
        
        
    }
};