class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>remainderPrefixSum(n,0);
        unordered_map<int,int>mp;
        
        remainderPrefixSum[0] = nums[0]%k;
        
        for(int i=1;i<n;i++)
        {
            remainderPrefixSum[i] = (remainderPrefixSum[i-1] + nums[i])%k;
        }
        mp[0] = -1;
        for(int i=0;i<n;i++)
        {
            
            if(mp.find(remainderPrefixSum[i])!=mp.end())
            {
                if(i-mp[remainderPrefixSum[i]]>=2)
                 return true;
            }
               
            else
                mp[remainderPrefixSum[i]]=i;
        }
        return false;
    }
};