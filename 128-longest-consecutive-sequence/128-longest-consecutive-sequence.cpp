class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int> mp;
        int n = nums.size();
        int mn = INT_MAX;
        int ans=0,mxans=0;
        
        for(int i=0;i<n;i++)
        {
            mp[nums[i]]++;
        }
        for(auto k: mp)
        {
            int x = k.first;
            if(mp.find(x-1)==mp.end())
            {
                int curnum =x;
                ans=1;
                while(mp.find(curnum+1)!=mp.end())
                    ans++,curnum++;
            }
            mxans = max(mxans,ans);
        }
        return mxans;
            
    }
};