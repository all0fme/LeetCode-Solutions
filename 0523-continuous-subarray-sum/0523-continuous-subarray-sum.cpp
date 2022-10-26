class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        //vector<int>remainderPrefixSum(n,0);
        int prev;
        unordered_map<int,int>mp;
         mp[0] = -1;
        prev = nums[0]%k;
        if(prev!=0)
            mp[prev] =0;
        
       
       
        for(int i=1;i<n;i++)
        {
            prev = (prev + nums[i])%k;
            if(mp.find(prev)!=mp.end())
            {
                if(i-mp[prev]>=2)
                 return true;
            }
               
            else
                mp[prev]=i;
        }
        return false;
    }
};