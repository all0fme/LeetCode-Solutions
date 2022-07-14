class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>> st;
        sort(nums.begin(),nums.end());
        int  n = nums.size();
        
        int x = (1<<n);
        
        for(int mask = 0;mask<x;mask++)
        {
            vector<int> temp;
            for(int i=0;i<n;i++)
            {
                if(mask&(1<<i))
                    temp.push_back(nums[i]);
            }
            st.insert(temp);
        }
        vector<vector<int>> ans(st.begin(),st.end());
        return ans;
        
    }
};