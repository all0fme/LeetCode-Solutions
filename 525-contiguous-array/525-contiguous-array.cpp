class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int sum=0;
        int len =0;
        int n = nums.size();
        unordered_map<int,int> mp;
        mp[0]=-1;
        for(int i=0;i<n;i++)
        {
            if(nums[i]==0)
                sum-=1;
            else
                sum+=1;
            
            if(mp.find(sum)==mp.end())
                mp[sum] =i;
            else
                len = max(len,i-mp[sum]);
            
        }
        
        return len;
    }
};